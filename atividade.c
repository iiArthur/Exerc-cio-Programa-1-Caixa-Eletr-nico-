/* Aluno1: Arthur Mendes de Azevedo Santos - Número de matrícula: 8162299
Realizado individual.
Exercício-Programa 1 — Caixa Eletrônico
Programação Avançada - 2024 - Professor: Bruno Perillo
Compilador: ... (OnlineGDB) */


#include <stdio.h>

int main() {
    
    int cedulas[8] = {0}; // Vetor para armazenar a quantidade de cada tipo de cédula
    int valores[8] = {100, 50, 20, 10, 5, 2, 1}; // Valores das cédulas
    int operacao, valor, i;

    // Leitura da quantidade inicial de cédulas
    
    printf("Digite a quantidade inicial de cédulas de cada valor:\n");
    for (i = 0; i < 8; i++) {
        scanf("%d", &cedulas[i]);
    }

    // Processamento das operações
    
    while (1) {
        printf("\nDigite a operação (0 - saque, 1 - depósito, -1 - sair): ");
        scanf("%d", &operacao);

        if (operacao == -1) {
            break; // Encerra o loop
        }

        if (operacao == 0) { // Saque
            printf("Digite o valor a ser sacado: ");
            scanf("%d", &valor);

            // Verifica se o valor é válido
            
            if (valor <= 0) {
                printf("Valor inválido.\n");
                continue;
            }

            // Tenta realizar o saque
            
            int valor_restante = valor;
            for (i = 0; i < 8 && valor_restante > 0; i++) {
                while (valor_restante >= valores[i] && cedulas[i] > 0) {
                    cedulas[i]--;
                    valor_restante -= valores[i];
                }
            }

            if (valor_restante == 0) {
                printf("Saque de R$%d realizado com sucesso.\n", valor);
            } else {
                printf("Saque de R$%d não realizado por falta de cédulas.\n", valor);
            }
        } else if (operacao == 1) { // Depósito
            printf("Digite a quantidade de cédulas de cada valor:\n");
            for (i = 0; i < 8; i++) {
                scanf("%d", &valor);
                cedulas[i] += valor;
            }
        } else {
            printf("Operação inválida.\n");
        }

        // Exibe a quantidade atual de cédulas
        
        printf("Quantidade de cédulas:\n");
        for (i = 0; i < 8; i++) {
            printf("%d x R$%d\n", cedulas[i], valores[i]);
        }
    }

    return 0;
}
