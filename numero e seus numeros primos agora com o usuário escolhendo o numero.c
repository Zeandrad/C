/*

Função: rotinas para ler, escrever e excluir registros de empregado
Autor: Jose Plácido de Andrade neto
Data: 21/05/2023
Observações: 

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    int n;

    printf("Digite o número desejado: ");
    scanf("%d", &n);

    for (int num = 2; num <= n; num += 2) {
        encontrarPrimosGoldbach(num);
    }

    return 0;
}