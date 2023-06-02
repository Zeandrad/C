/*

Função: rotinas para ler, escrever e excluir registros de empregado
Autor: José Plácido de Andrade Neto 
Data: 21/05/2023
Observações: 

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    char dataNascimento[11];
    char RG[12];
    char dataAdmissao[11];
    float salario;
} Empregado;

void lerEmpregado(Empregado* empregado) {
    printf("Digite o nome do empregado: ");
    scanf("%s", empregado->nome);

    printf("Digite a data de nascimento do empregado: ");
    scanf("%s", empregado->dataNascimento);

    printf("Digite o RG do empregado: ");
    scanf("%s", empregado->RG);

    printf("Digite a data de admissao do empregado: ");
    scanf("%s", empregado->dataAdmissao);

    printf("Digite o salario do empregado: ");
    scanf("%f", &empregado->salario);
}

void escreverEmpregado(const Empregado* empregado) {
    printf("Nome: %s\n", empregado->nome);
    printf("Data de Nascimento: %s\n", empregado->dataNascimento);
    printf("RG: %s\n", empregado->RG);
    printf("Data de Admissao: %s\n", empregado->dataAdmissao);
    printf("Salario: %.2f\n", empregado->salario);
    printf("--------------------------\n");
}

void excluirEmpregado(Empregado* vetor, int* tamanho, int indice) {
    if (indice < 0 || indice >= *tamanho) {
        printf("Indice invalido.\n");
        return;
    }

    for (int i = indice; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    *tamanho -= 1;
    vetor = (Empregado*)realloc(vetor, sizeof(Empregado) * (*tamanho));
}

int main() {
    int tamanho = 0;
    Empregado* vetor = NULL;

    int opcao;
    do {
        printf("1 - Adicionar empregado\n");
        printf("2 - Listar empregados\n");
        printf("3 - Excluir empregado\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Empregado empregado;
                lerEmpregado(&empregado);

                tamanho += 1;
                vetor = (Empregado*)realloc(vetor, sizeof(Empregado) * tamanho);
                vetor[tamanho - 1] = empregado;

                printf("Empregado adicionado com sucesso!\n");
                break;
            }
            case 2: {
                printf("Lista de Empregados:\n");
                for (int i = 0; i < tamanho; i++) {
                    escreverEmpregado(&vetor[i]);
                }
                break;
            }
            case 3: {
                int indice;
                printf("Digite o indice do empregado que deseja excluir: ");
                scanf("%d", &indice);

                excluirEmpregado(vetor, &tamanho, indice);
                printf("Empregado excluido com sucesso!\n");
                break;
            }
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

        printf("--------------------------\n");
    } while (opcao != 4);

    free(vetor);

    return 0;
}