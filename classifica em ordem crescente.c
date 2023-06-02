/*

Função: classifica os elementos de um vetor em ordem crescente usando o algoritmo de "classificação por seleção"
Autor: Jose Plácido de Andrade neto
Data: 21/05/2023
Observações:

*/

#include <stdio.h> 

void ordenarVetor(int vetor[], int tamanho){
  int i, j, indiceMinimo;

  for (i = 0; i < tamanho - 1; i++) {
    indiceMinimo = i;

    for (j = i + 1; j < tamanho; j++) {
      if (vetor[j] < vetor[indiceMinimo])
          indiceMinimo = j;
    }

    int temp = vetor[indiceMinimo];
    vetor[indiceMinimo] = vetor[i];
    vetor[i] = temp;    
  }
}

int main() {
  int i;
  int vetor[] = {9,5,2,7,1,8,3};
  int tamanho = sizeof(vetor) / sizeof(vetor[0]);

  printf("Vetor original: ");
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  ordenarVetor(vetor, tamanho);

  printf("\nVetor ordenado: ");
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }

return 0;
}