/*

Função: Quick sort
Autor: Jose Plácido de Andrade neto
Data: 21/05/2023
Observações: 

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int vet[], int i, int j){
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

int part(int vet[], int in, int fim){
    int pivo, pivoI, i;
   
    pivo = vet[fim];
    pivoI = in;
   
    for(i = in; i < fim; i++){
        if(vet[i] <= pivo){
            troca(vet, i, pivoI);
            pivoI++;
        }
    }
    troca(vet, pivoI, fim);
   
    return pivoI;
}

int partRand(int vet[], int in, int fim){
    int pivoI = (rand() % (fim - in + 1)) + in;
    
    troca(vet, pivoI, fim);
    
    return part(vet, in, fim);
}

void quickSort(int vet[], int in, int fim){
    if(in < fim){
        int pivoI = partRand(vet, in, fim);
        
        quickSort(vet, in, pivoI - 1);
        quickSort(vet, pivoI + 1, fim);
    }
}

int main(){
    int vet[] = {1, 5, 3, 10, 20, 15, 50, 55, 40, 45, 21};
    int random[10];
    int tam = sizeof(vet) / sizeof(int);
    int i;
    
    srand(time(NULL));
    
    for(i = 0; i < tam; i++){
        random[i] = rand() % 100;
    }
    
    quickSort(vet, 0, tam - 1);
    quickSort(random, 0, tam - 1);
    
    for(i = 0; i < tam; i++){
        printf("vetor:%d\n", vet[i]);
    }
    for(i = 0; i < tam; i++){
        printf("random:%d\n", random[i]);
    }

    return 0;
}