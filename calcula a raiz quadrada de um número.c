/*

Função: calcula a raiz quadrada de um número
Autor: Jose Plácido de Andrade neto
Data: 21/05/2023
Observações: 

*/

#include <stdio.h>
#include <math.h>

double calcular_raiz_quadrada(double numero, double precisao) {
    if (numero < 0) {
        printf("A raiz quadrada não está definida para números negativos.\n");
        return -1;
    }
    double x = numero;
    double raiz_aproximada = x;

    while (1) {
        raiz_aproximada = 0.5 * (x + numero / x);
        
        if (fabs(raiz_aproximada - x) < precisao)
            break;
        
        x = raiz_aproximada;
    }
    return raiz_aproximada;
}
int main() {
    double numero, precisao;
    
    printf("Digite um número: ");
    scanf("%lf", &numero);
    
    printf("Digite a precisão desejada: ");
    scanf("%lf", &precisao);
    
    double raiz = calcular_raiz_quadrada(numero, precisao);
    printf("A raiz quadrada de %.2f é aproximadamente: %.4f\n", numero, raiz);
    
return 0;
}