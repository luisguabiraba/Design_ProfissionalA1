#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    long long steps_cmp;
    long long steps_swap;
} Metrics;

#define COUNT_CMP(m)   ((m)->steps_cmp++)
#define COUNT_SWAP(m)  ((m)->steps_swap++)

// Funções auxiliares
void reset_metrics(Metrics *m) {
    m->steps_cmp = 0;
    m->steps_swap = 0;
}

void swap(int *a, int *b, Metrics *m) {
    int temp = *a;
    *a = *b;
    *b = temp;
    COUNT_SWAP(m);
}

// Bubble Sort
void bubble_sort(int *v, size_t n, Metrics *m) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - 1 - i; j++) {
            COUNT_CMP(m);
            if (v[j] > v[j + 1]) {
                swap(&v[j], &v[j + 1], m);
            }
        }
    }
}

// Insertion Sort
void insertion_sort(int *v, size_t n, Metrics *m) {
    for (size_t i = 1; i < n; i++) {
        int key = v[i];
        size_t j = i;
        while (j > 0) {
            COUNT_CMP(m);
            if (v[j-1] > key) {
                v[j] = v[j-1];
                COUNT_SWAP(m);
                j--;
            } else break;
        }
        v[j] = key;
        COUNT_SWAP(m); // colocar o key na posição correta
    }
}

// Quick Sort (Lomuto)
void quick_sort_rec(int *v, int low, int high, Metrics *m) {
    if (low < high) {
        int pivot = v[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            COUNT_CMP(m);
            if (v[j] <= pivot) {
                i++;
                swap(&v[i], &v[j], m);
            }
        }
        swap(&v[i+1], &v[high], m);
        int pi = i + 1;
        quick_sort_rec(v, low, pi - 1, m);
        quick_sort_rec(v, pi + 1, high, m);
    }
}

void quick_sort(int *v, size_t n, Metrics *m) {
    quick_sort_rec(v, 0, n - 1, m);
}

// Função para rodar um sort e medir tempo
double run_sort(void (*fn)(int*, size_t, Metrics*), int *v, size_t n, Metrics *m) {
    reset_metrics(m);
    clock_t t0 = clock();
    fn(v, n, m);
    clock_t t1 = clock();
    return 1000.0 * (t1 - t0) / CLOCKS_PER_SEC;
}

// Função para gerar vetor aleatório
void generate_random(int *v, size_t n, int min_val, int max_val) {
    for (size_t i = 0; i < n; i++) {
        v[i] = rand() % (max_val - min_val + 1) + min_val;
    }
}

// Função para copiar vetor
void copy_array(int *dest, int *src, size_t n) {
    memcpy(dest, src, n * sizeof(int));
}

// Função principal
int main() {
    srand(time(NULL));
    char rgm[50];
    printf("Digite seu RGM: ");
    scanf("%s", rgm);
    size_t rgm_len = strlen(rgm);

    int rgm_array[50];
    for (size_t i = 0; i < rgm_len; i++) {
        rgm_array[i] = rgm[i] - '0';
    }

    int sort_methods = 3;
    const char *method_names[] = {"bubble", "insertion", "quick"};
    void (*sort_functions[])(int*, size_t, Metrics*) = {bubble_sort, insertion_sort, quick_sort};

    Metrics m;
    int temp[50];
    
    printf("metodo,N,caso,passos,tempo_ms\n");

    // Ordenando RGM
    for (int i = 0; i < sort_methods; i++) {
        copy_array(temp, rgm_array, rgm_len);
        double t = run_sort(sort_functions[i], temp, rgm_len, &m);
        printf("%s,%zu,rgm,%lld,%.3f\n", method_names[i], rgm_len, m.steps_cmp + m.steps_swap, t);
    }

    // Benchmark com vetores aleatórios
    size_t sizes[] = {100, 1000, 10000};
    for (size_t si = 0; si < 3; si++) {
        size_t N = sizes[si];
        int *array = malloc(N * sizeof(int));
        int *array_copy = malloc(N * sizeof(int));
        generate_random(array, N, 0, 10000);

        for (int i = 0; i < sort_methods; i++) {
            long long total_steps = 0;
            double total_time = 0;
            // repetir 5x e tirar média
            for (int run = 0; run < 5; run++) {
                copy_array(array_copy, array, N);
                double t = run_sort(sort_functions[i], array_copy, N, &m);
                total_steps += (m.steps_cmp + m.steps_swap);
                total_time += t;
            }
            printf("%s,%zu,aleatorio,%lld,%.3f\n", method_names[i], N, total_steps/5, total_time/5.0);
        }
        free(array);
        free(array_copy);
    }

    return 0;
}
