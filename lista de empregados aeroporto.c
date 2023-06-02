/*

Função: rotinas para ler, escrever e excluir registros de empregado
Autor: Jose Plácido de Andrade neto
Data: 21/05/2023
Observações: 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Aeroporto
typedef struct {
    char sigla[4];
    char cidade[51];
    char pais[31];
    float taxa;
    int capacidade;
} aeroporto;

typedef aeroporto Aeroporto;

void lerAeroporto(Aeroporto* aero) {
    printf("Digite a sigla do aeroporto: ");
    scanf("%s", aero->sigla);

    printf("Digite a cidade do aeroporto: ");
    scanf(" %[^\n]s", aero->cidade);

    printf("Digite o país do aeroporto: ");
    scanf(" %[^\n]s", aero->pais);

    printf("Digite a taxa do aeroporto: ");
    scanf("%f", &(aero->taxa));

    printf("Digite a capacidade do aeroporto: ");
    scanf("%d", &(aero->capacidade));
}

void escreverAeroporto(const Aeroporto* aero) {
    printf("Sigla: %s\n", aero->sigla);
    printf("Cidade: %s\n", aero->cidade);
    printf("País: %s\n", aero->pais);
    printf("Taxa: %.2f\n", aero->taxa);
    printf("Capacidade: %d\n", aero->capacidade);
    printf("--------------------------\n");
}

// Função para excluir um aeroporto do vetor
void excluirAeroporto(Aeroporto* vetor, int* tamanho, int indice) {
    if (indice < 0 || indice >= *tamanho) {
        printf("Índice inválido.\n");
        return;
    }

    for (int i = indice; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    *tamanho -= 1;
    vetor = (Aeroporto*)realloc(vetor, sizeof(Aeroporto) * (*tamanho));
}

int main() {
    int tamanho = 0;
    Aeroporto* vetor = NULL;

    int opcao;
    do {
        printf("1 - Adicionar aeroporto\n");
        printf("2 - Listar aeroportos\n");
        printf("3 - Excluir aeroporto\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Aeroporto aero;
                lerAeroporto(&aero);

                tamanho += 1;
                vetor = (Aeroporto*)realloc(vetor, sizeof(Aeroporto) * tamanho);
                vetor[tamanho - 1] = aero;

                printf("Aeroporto adicionado com sucesso!\n");
                break;
            }
            case 2: {
                printf("Lista de Aeroportos:\n");
                for (int i = 0; i < tamanho; i++) {
                    escreverAeroporto(&vetor[i]);
                }
                break;
            }
            case 3: {
                int indice;
                printf("Digite o índice do aeroporto que deseja excluir: ");
                scanf("%d", &indice);

                excluirAeroporto(vetor, &tamanho, indice);
                printf("Aeroporto excluído com sucesso!\n");
                break;
            }
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        printf("--------------------------\n");
    } while (opcao != 4);

    free(vetor); // Liberar a memória

    return 0;
}