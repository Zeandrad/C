/*
** Função : TAD
** Autor : Jose Plácido de Andrade neto
** Data : 22/05/2023
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

struct complexo{
    double re;
    double im;
};

void iniciaComplexo(struct complexo *nc){
    nc->re = 0;
    nc->im = 0;
}

void leiaComplexo(struct complexo *nc){
    scanf("%lf", &nc->re);
    scanf("%lf", &nc->im);
}

void escrevaComplexo(struct complexo *nc){
    printf("%lf %lfi", nc->re, nc->im);
}

struct complexo* somaComplexos(struct complexo *nc, struct complexo *ncA){
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR->re = nc->re + ncA->re;
    ncR->im = nc->im + ncA->im;
    return ncR;
}

struct complexo* subtraiComplexos(struct complexo *nc, struct complexo *ncA){
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR->re = nc->re - ncA->re;
    ncR->im = nc->im - ncA->im;
    return ncR;
}

struct complexo* multiplicaComplexos(struct complexo *nc, struct complexo *ncA){
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR->re = nc->re * ncA->re;
    ncR->im = nc->im * ncA->im;
    return ncR;
}

struct complexo* diviComplexos(struct complexo *nc, struct complexo *ncA){
    struct complexo *ncR = (struct complexo*)malloc(sizeof(struct complexo));
    ncR->re = nc->re / ncA->re;
    ncR->im = nc->im / ncA->im;
    return ncR;
}

int main(){
    struct complexo x, y, *pz;
    leiaComplexo(&x);
    leiaComplexo(&y);
    pz = somaComplexos(&x, &y);
    escrevaComplexo(pz);
    printf("\n");
    pz = subtraiComplexos(&x, &y);
    escrevaComplexo(pz);
    printf("\n");
    pz = multiplicaComplexos(&x, &y);
    escrevaComplexo(pz);
    printf("\n");
    pz = diviComplexos(&x, &y);
    escrevaComplexo(pz);
    
    return 0;
}