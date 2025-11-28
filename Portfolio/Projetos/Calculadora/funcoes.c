#include <stdio.h>
#include <math.h>

double soma (double a, double b) {
    return a + b;
}

double subtracao (double a, double b) {
    return a - b;
}

double multiplicacao (double a, double b) {
    return a * b;
}

double divisao (double a, double b) {
    if (b == 0.0) {
        printf("Erro: Divisão por zero não existe. BAKA\n");
        return -1; 
    }
    return a / b;
}

double potenciacao (double base, double expoente) {
    return pow(base, expoente);
}

double raiz_quadrada (double numero) {
    if (numero < 0.0) {
        printf("Erro: Não é possível calcular a raiz quadrada de um número negativo.\n");
        return -1; // Retorna -1 para indicar erro
    }
    return sqrt(numero);
}

double calc_sen (double angulo) {
    return sin(angulo);
}

double calc_cos (double angulo) {
    return cos(angulo);
}

double calc_tan (double angulo) {
    return tan(angulo);
}

double calc_log (double numero) {
    if (numero <= 0.0) { //If para evitar logaritmo de números não positivos
        printf("Erro: Logaritmo errado para números menores ou iguais a zero.\n");
        return -1; 
    }
    return log(numero); //devolve o logaritmo natural (base e)
}

double calc_log10 (double numero) {
    if (numero <= 0.0) { 
        printf("Erro: Logaritmo erradon para números menores ou iguais a zero.\n");
        return -1; 
    }
    return log10(numero); //devolve o logaritmo de base 10
}

double hipo (double cateto1, double cateto2) {
    return sqrt(pow(cateto1, 2) + pow(cateto2, 2));
}

double calc_expoente (double expoente) { 
    return exp(expoente);
}

double calc_percentual (double porcentagem) {
    return porcentagem / 100.0;
}

double valor_absoluto (double numero) {
    return fabs(numero);
}

double raiz_cubica (double numero) {
    return cbrt(numero);
}

double calc_fatorial (int numero) {
    if (numero < 0 || numero > 20) {
        printf("Erro: Fatorial não definido para números negativos.\n");
        return -1; 
    } else {     
    long long int fatorial = 1;
    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }
    return fatorial;
    }
}   

double calc_delta (double a, double b, double c) {
    return b * b - 4 * a * c;
}

double calc_determinante(double a1, double a2, double a3, double a4) {
    return a1*a4 - a2*a3;
}