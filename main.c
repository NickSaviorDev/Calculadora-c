#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>


void imprimir_numero_formatado(float num) {
    if (floor(num) == num) {
        printf("%.0f", num);
    } else {
        printf("%.2f", num);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Define UTF-8 no console
    while (1) {
        int option, check_zero = 1;
        float num1, num2, result;
        char op[2];
        char repeat;

        printf(
            "===============================\n"
            "    Calculadora Simples\n"
            "===============================\n"
            "Selecione uma operação:\n"
            "1. Adição\n"
            "2. Subtração\n"
            "3. Multiplicação\n"
            "4. Divisão\n"
            "5. Sair\n"
            "Opção: "
        );

        while (1) {
            scanf("%d", &option);
            if (option < 1 || option > 5) {
                printf("Opção inválida, escolha novamente.\n");
                printf("Opção: ");
            } else break;
        }

        if (option == 5) {
            printf("Obrigado por usar a calculadora! Até a próxima.");
            return 0;
        }

        printf("Digite o primeiro número: ");
        scanf("%f", &num1);

        printf("Digite o segundo número: ");
        scanf("%f", &num2);

        switch (option) {
            case 1:
                op[1] = '+';
                result = num1 + num2;
                break;
            case 2:
                op[1] = '-';
                result = num1 - num2;
                break;
            case 3:
                op[1] = '*';
                result = num1 * num2;
                break;
            case 4:
                op[1] = '/';
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    printf("Erro: Divisão por zero não é permitida.\n");
                    check_zero = 0;
                }
                break;
            default:
                printf("Opção inválida, escolha novamente.\n");
        }

        if (check_zero) {
            printf("Resultado: ");
            imprimir_numero_formatado(num1);
            printf(" %c ", op[1]);
            imprimir_numero_formatado(num2);
            printf(" = ");
            imprimir_numero_formatado(result);
            printf("\n");
        }

        while (1) {
            printf("Deseja realizar outra operação? (s/n): ");
            scanf(" %c", &repeat);
            if (repeat == 'n' || repeat == 'N') {
                printf("Obrigado por usar a calculadora! Até a próxima.");
                return 0;
            } else if (repeat == 's' || repeat == 'S') {
                system("cls");
                break;
            } else {
                printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        }
    }
}