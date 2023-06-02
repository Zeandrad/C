/*

Função: rotinas para ler, escrever e excluir registros de empregado
Autor: Jose Plácido de Andrade neto
Data: 21/05/2023
Observações: 

*/

#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool ehPrimo(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }

    return true;
}

void encontrarPrimosGoldbach(int num) {
    printf("Número par: %d\n", num);

    for (int i = 2; i <= num / 2; i++) {
        if (ehPrimo(i) && ehPrimo(num - i)) {
            printf("Primos: %d + %d\n", i, num - i);
        }
    }

    printf("--------------------------\n");
}

int main() {
    int inicio = 700;
    int fim = 1100;

    for (int num = inicio; num <= fim; num += 2) {
        encontrarPrimosGoldbach(num);
    }

    return 0;
}