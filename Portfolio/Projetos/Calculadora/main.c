#include <stdio.h>
#include <math.h>
#include "funcoes.c"
#include <string.h>

typedef struct {
    char tipo[30];
    double a, b, resultado;
    int id;
} Operacao;

Operacao historico[100];
int totalOperacoes = 0;


int main(){
    while (1) 
    {
    printf("=====CALCULADORA-CIENTIFICA=====\n");
    printf("Selecione a operação deseja: \n");
    printf("1) Soma\n");
    printf("2) Subtração\n");
    printf("3) Multiplicação\n");
    printf("4) Divisão\n");
    printf("5) Potenciação\n");
    printf("6) Radiciação\n");
    printf("7) Seno\n");
    printf("8) Cosseno\n");
    printf("9) Tangente\n");
    printf("10) Logaritmo\n");
    printf("11) Logaritmo base 10\n");
    printf("12) Hipotenusa\n");
    printf("13) Exponencial\n");
    printf("14) Porcentagem\n");
    printf("15) Modulo\n");
    printf("16) Valor absoluto\n");
    printf("17) Raiz cúbica\n");
    printf("18) Fatorial\n");
    printf("19) Delta\n");
    printf("20) Determinante 2x2\n");
    printf("21) Histórico de operações\n");
    printf("0) Sair\n");

    int calculos;
    printf("Digite a operação desejada: ");
    scanf("%d", &calculos);
    if (calculos > 21 || calculos < 0)
    {
        printf("Operação inválida. Por favor, selecione uma operação entre 0 e 20.\n");
        continue; //nao conhecia, mas serve para voltar pro inicio do codigo 
    }
    
    switch (calculos)
    {
    case 0: {
        printf("Saindo da calculadora... Goodbye!");
        return 0;
    }
        
    case 1: {
        double num1, num2, resultado;

        printf("Digite o primeiro número: ");
        scanf("%lf", &num1);

        printf("Digite o segundo número: ");
        scanf("%lf", &num2);
        resultado = soma(num1,num2);
        printf("O resultado da soma é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Soma (+)"); // Nome da operação
        historico[totalOperacoes].a = num1;             // Primeiro valor
        historico[totalOperacoes].b = num2;             // Segundo valor
        historico[totalOperacoes].resultado = resultado; // Resultado
        historico[totalOperacoes].id = totalOperacoes + 1; // ID automático
        totalOperacoes++; // Próxima posição no histórico

        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
           
    } 
        break;
    case 2: {
        double num1, num2, resultado;

        printf("Digite o primeiro número: ");
        scanf("%lf", &num1);

        printf("Digite o segundo número: ");
        scanf("%lf", &num2);
       resultado = subtracao(num1, num2);
        printf("O resultado da subtração é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Subtração (-)"); 
        historico[totalOperacoes].a = num1;             
        historico[totalOperacoes].b = num2;            
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
    } 
        break;
    case 3: {
        double num1, num2, resultado;

        printf("Digite o primeiro número: ");
        scanf("%lf", &num1);

        printf("Digite o segundo número: ");
        scanf("%lf", &num2);
        resultado = multiplicacao(num1,num2);
        printf("O resultado da multiplicação é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Multiplicação (*)"); 
        historico[totalOperacoes].a = num1;             
        historico[totalOperacoes].b = num2;            
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
    } 
        break;
case 4: {
    double num1, num2, resultado;

    printf("Digite o primeiro número: ");
    scanf("%lf", &num1);

    printf("Digite o segundo número: ");
    scanf("%lf", &num2);
    if (num2 == 0.0) {
        printf("Erro: Divisão por zero não existe. BAKA\n");
    } else {
        resultado = divisao(num1, num2); 
        printf("O resultado da divisão é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Divisão (/)"); 
        historico[totalOperacoes].a = num1;             
        historico[totalOperacoes].b = num2;            
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
    }
    break; 
}
    case 5: {
        double base, expoente, potencia;
        printf("Digite a base: \n");
        scanf("%lf", &base);

        printf("Digite o expoente: \n");
        scanf("%lf", &expoente);

        potencia = potenciacao(base, expoente);
        printf("O resultado da potenciação é: %.2lf\n", potencia);
        strcpy(historico[totalOperacoes].tipo, "Potenciação (^)"); 
        historico[totalOperacoes].a = base;             
        historico[totalOperacoes].b = expoente;            
        historico[totalOperacoes].resultado = potencia; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
        break;
    }
    case 6: { 
        double raiz, resultado;
        printf("Digite o número para calcular a raiz quadrada: \n");
        scanf("%lf", &raiz);
        resultado = raiz_quadrada(raiz);
        printf("O resultado da radiciação é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Raiz Quadrada (√)"); 
        historico[totalOperacoes].a = raiz;             
        historico[totalOperacoes].b = 0;//Só para retornar algo            
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
        break;
    }
    case 7: { 
        double seno, converter, resultado;
        printf("Digite o valor do ângulo em Graus: \n");
        scanf("%lf", &seno);
        converter = seno * 3.14159265358979323846 / 180.0;
        resultado = calc_sen(converter);
        printf("O seno do ângulo é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Seno (sin)"); 
        historico[totalOperacoes].a = seno;             
        historico[totalOperacoes].b = 0;//Só para retornar algo         
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
        break;
    }
    case 8: { 
        double cosseno, converter, resultado;
        printf("Digite o valor do ângulo em Graus: \n");
        scanf("%lf", &cosseno);
        converter = cosseno * 3.14159265358979323846 / 180.0;
        resultado = calc_cos(converter);
        printf("O cosseno do ângulo é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Cosseno (cos)"); 
        historico[totalOperacoes].a = cosseno;             
        historico[totalOperacoes].b = 0;//Só para retornar algo         
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
        break;

    }
    case 9: { 
        double tangente, converter, resultado;
        printf("Digite o valor do ângulo em Graus: \n");
        scanf("%lf", &tangente);
        converter = tangente * 3.14159265358979323846 / 180.0;
        resultado = calc_tan(converter);
        printf("A tangente do ângulo é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Tangente (tan)"); 
        historico[totalOperacoes].a = tangente;             
        historico[totalOperacoes].b = 0;             
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
        break;
    }
    case 10: { 
        double logaritmo, resultado;
        printf("Digite o valor de x para o logaritmo de base e: \n");
        scanf("%lf", &logaritmo);
        resultado = calc_log(logaritmo);
        printf("O resultado do log é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Logaritmo (ln)"); 
        historico[totalOperacoes].a = logaritmo;             
        historico[totalOperacoes].b = 0;            
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
        break;
    }
    case 11: {
        double logaritmo10, resultado;
        printf("Digite o valor de x no logaritmo de base 10: \n");
        scanf("%lf", &logaritmo10);
        resultado = calc_log10(logaritmo10);
        printf("O resultado do log é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Logaritmo base 10 (log10)"); 
        historico[totalOperacoes].a = logaritmo10;             
        historico[totalOperacoes].b = 0;            
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
        break;
    }
    case 12:{
            double cateto1, cateto2, hipotenusa;
            printf("Digite o valor do primeiro cateto: \n");
            scanf("%lf", &cateto1);
            printf("Digite o valor do segundo cateto: \n");
            scanf("%lf", &cateto2);
            hipotenusa = hipo(cateto1, cateto2);
            printf("O valor da hipotenusa é: %.2lf\n", hipotenusa);
            strcpy(historico[totalOperacoes].tipo, "Hipotenusa(Cat1, Cat2)"); 
            historico[totalOperacoes].a = cateto1;             
            historico[totalOperacoes].b = cateto2;            
            historico[totalOperacoes].resultado = hipotenusa; 
            historico[totalOperacoes].id = totalOperacoes + 1; 
            totalOperacoes++;
            printf("Deseja retornar ao menu? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            while (1)
            {
            if (resposta == 's' || resposta == 'S')
            {
                break;
            } else if (resposta == 'n' || resposta == 'N') {
               printf("Saindo da calculadora... Goodbye!");
               return 0; 
            } else {
                printf("Resposta inválida, por favor digite somente s ou n");
                scanf(" %c", &resposta);
                continue;
            }
            }
            break;
    }
    case 13: {
            double expoente, resultado;
            printf("Digite o valor do expoente para calcular o exponencial: \n");
            scanf("%lf", &expoente);
            resultado = calc_expoente(expoente);
            printf("O resultado do exponencial é: %.2lf\n", resultado);
            strcpy(historico[totalOperacoes].tipo, "Exponencial (e^)"); 
            historico[totalOperacoes].a = expoente;             
            historico[totalOperacoes].b = 0;            
            historico[totalOperacoes].resultado = resultado; 
            historico[totalOperacoes].id = totalOperacoes + 1; 
            totalOperacoes++;
            printf("Deseja retornar ao menu? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            while (1)
            {
            if (resposta == 's' || resposta == 'S')
            {
                break;
            } else if (resposta == 'n' || resposta == 'N') {
               printf("Saindo da calculadora... Goodbye!");
               return 0; 
            } else {
                printf("Resposta inválida, por favor digite somente s ou n");
                scanf(" %c", &resposta);
                continue;
            }
            }
            break;
    }
    case 14: {
            double percentual, resultado;
            printf("Digite o valor do percentual (sem o símbolo): \n");
            scanf("%lf", &percentual);
            resultado = calc_percentual(percentual); 
            printf("O valor em porcentagem é: %.2lf\n", resultado);
            strcpy(historico[totalOperacoes].tipo, "Percentual"); 
            historico[totalOperacoes].a = percentual;             
            historico[totalOperacoes].b = 0;            
            historico[totalOperacoes].resultado = resultado; 
            historico[totalOperacoes].id = totalOperacoes + 1; 
            totalOperacoes++;
            printf("Deseja retornar ao menu? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            while (1)
            {
            if (resposta == 's' || resposta == 'S')
            {
                break;
            } else if (resposta == 'n' || resposta == 'N') {
               printf("Saindo da calculadora... Goodbye!");
               return 0; 
            } else {
                printf("Resposta inválida, por favor digite somente s ou n");
                scanf(" %c", &resposta);
                continue;
            }
            }
            break;
    }
    case 15: {
            double numero1, numero2, resultado;
            printf("Digite o primeiro número para calcular o módulo da divisão: \n");
            scanf("%lf", &numero1);

            printf("Agora, digite o segundo número: \n");
            scanf("%lf", &numero2);
            resultado = fmod(numero1, numero2);
            printf("O valor do módulo é: %.2lf\n", resultado);
            strcpy(historico[totalOperacoes].tipo, "Modulo (resto da divisão)"); 
            historico[totalOperacoes].a = numero1;             
            historico[totalOperacoes].b = numero2;            
            historico[totalOperacoes].resultado = resultado; 
            historico[totalOperacoes].id = totalOperacoes + 1; 
            totalOperacoes++;
            printf("Deseja retornar ao menu? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            while (1)
            {
            if (resposta == 's' || resposta == 'S')
            {
                break;
            } else if (resposta == 'n' || resposta == 'N') {
               printf("Saindo da calculadora... Goodbye!");
               return 0; 
            } else {
                printf("Resposta inválida, por favor digite somente s ou n");
                scanf(" %c", &resposta);
                continue;
            }
            }
            break;
    }
    case 16: {
            double valor, resultado;
            printf("Digite um número para calcular o valor absoluto: \n");
            scanf("%lf", &valor);
            resultado = valor_absoluto(valor);
            printf("O valor absoluto é: %.2lf\n", resultado);
            strcpy(historico[totalOperacoes].tipo, "Valor Absoluto (|x|)"); 
            historico[totalOperacoes].a = valor;             
            historico[totalOperacoes].b = 0;            
            historico[totalOperacoes].resultado = resultado; 
            historico[totalOperacoes].id = totalOperacoes + 1; 
            totalOperacoes++;
            printf("Deseja retornar ao menu? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            while (1)
            {
            if (resposta == 's' || resposta == 'S')
            {
                break;
            } else if (resposta == 'n' || resposta == 'N') {
               printf("Saindo da calculadora... Goodbye!");
               return 0; 
            } else {
                printf("Resposta inválida, por favor digite somente s ou n");
                scanf(" %c", &resposta);
                continue;
            }
            }
            break;
    }
    case 17: {
        double numero, resultado;
        printf("Digite um número para calcular a raiz cúbica: \n");
        scanf("%lf", &numero);
        resultado = raiz_cubica(numero);
        printf("A raiz cúbica é: %.2lf\n", resultado);
        strcpy(historico[totalOperacoes].tipo, "Raiz Cúbica (∛)"); 
        historico[totalOperacoes].a = numero;             
        historico[totalOperacoes].b = resultado;            
        historico[totalOperacoes].resultado = resultado; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
        }
        break;
    }
    case 18:{
        int numero;
        long long int resultado;
            printf("Digite um número inteiro de (0 a 20) para calcular o fatorial: \n");
            scanf("%d", &numero);
            resultado = calc_fatorial(numero);
            printf("O fatorial de %d é: %lld\n", numero, resultado);
            strcpy(historico[totalOperacoes].tipo, "Fatorial (!)"); 
            historico[totalOperacoes].a = numero;             
            historico[totalOperacoes].b = 0;            
            historico[totalOperacoes].resultado = resultado; 
            historico[totalOperacoes].id = totalOperacoes + 1; 
            totalOperacoes++;
            printf("Deseja retornar ao menu? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            while (1)
            {
            if (resposta == 's' || resposta == 'S')
            {
                break;
            } else if (resposta == 'n' || resposta == 'N') {
               printf("Saindo da calculadora... Goodbye!");
               return 0; 
            } else {
                printf("Resposta inválida, por favor digite somente s ou n");
                scanf(" %c", &resposta);
                continue;
            }
            }
        }
        break;
    
    case 19: {
        double a, b, c, delta;
        printf("===== Digite o valor de a, b e c da equação ax² + bx + c ===== \n");
        printf("Valor de a: \n");
        scanf("%lf", &a);
        printf("Valor de b: \n");
        scanf("%lf", &b);
        printf("Valor de c: \n");
        scanf("%lf", &c);
        delta = calc_delta(a, b, c);
        printf("O valor de delta é: %.2lf\n", delta);
        strcpy(historico[totalOperacoes].tipo, "Delta (Δ) (só para ax e bx)"); 
        historico[totalOperacoes].a = a;             
        historico[totalOperacoes].b = b;            
        historico[totalOperacoes].resultado = delta; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
        printf("Deseja retornar ao menu? (s/n): ");
        char resposta;
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
       }
       break;
    }
    case 20: {
        double a1, a2, a3, a4, determinante;
        printf("Digite os elementos da matriz 2x2:\n");
        printf("[ a11  a12 ]\n[ a21  a22 ]\n");

        printf("Valor do a11: \n");
        scanf("%lf", &a1);

        printf("Valor do a12): \n");
        scanf("%lf", &a2);

        printf("Valor do a21: \n");
        scanf("%lf", &a3);

        printf("Valor do a22): \n");
        scanf("%lf", &a4);

    determinante = calc_determinante(a1, a2, a3, a4);
    printf("O valor do determinante é: %.2lf\n", determinante);
        strcpy(historico[totalOperacoes].tipo, "Determinante 2x2 (só para a11 e a12)"); 
        historico[totalOperacoes].a = a1;             
        historico[totalOperacoes].b = a2;            
        historico[totalOperacoes].resultado = determinante; 
        historico[totalOperacoes].id = totalOperacoes + 1; 
        totalOperacoes++;
    
    char resposta;
        printf("Deseja retornar ao menu? (s/n): ");
        scanf(" %c", &resposta);
        while (1)
        {
        if (resposta == 's' || resposta == 'S')
        {
            break;
        } else if (resposta == 'n' || resposta == 'N') {
           printf("Saindo da calculadora... Goodbye!");
           return 0; 
        } else {
            printf("Resposta inválida, por favor digite somente s ou n");
            scanf(" %c", &resposta);
            continue;
        }
       }
    break;
        }
        case 21: {
            if (totalOperacoes == 0) {
                printf("Nenhuma operação realizada ainda.\n");
                printf("===== Histórico de Operações =====\n");
            } else {
                for (int i = 0; i < totalOperacoes; i++) {
                    printf("ID: %d | Operação: %s | Valores: %.2lf, %.2lf | Resultado: %.2lf\n",
                           historico[i].id,
                           historico[i].tipo,
                           historico[i].a,
                           historico[i].b,
                           historico[i].resultado);
                    }       
                }
            
            printf("Deseja retornar ao menu? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            while (1)
            {
            if (resposta == 's' || resposta == 'S')
            {
                break;
            } else if (resposta == 'n' || resposta == 'N') {
               printf("Saindo da calculadora... Goodbye!");
               return 0; 
            } else {
                printf("Resposta inválida, por favor digite somente s ou n");
                scanf(" %c", &resposta);
                continue;
            }
            }
        }
    } 
   }
   return 0;
}

 

