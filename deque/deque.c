// deque 1.0 - vetor circular

#include <stdlib.h>
#include "deque.h"

deque inicializar (int max) {
    deque d = (deque)malloc(sizeof(Deque));
    if (!d) return 0;   // se não conseguir alocar memoria
    // os indices inicio e fim sempre indicarao a proxima posicao a ser preenchida
    d->inicio = 0;
    d->fim = 1;
    d->qntd = 0;
    d->max = max;
    d->vetor = (int*)malloc(max * sizeof(int));
    return d;
}

int vazia (deque d) {
    return d->qntd == 0;        // returna 1 se a qntd atual for 0, ou seja, se estiver vazia
}
int cheia (deque d) {
    return d->qntd == d->max;   // returna 1 se a qntd atual for igual a capacidade maxima
}

void destruir (deque d) {
    free(d->vetor);
    free(d);
}

// coloca o elemento no indice inicio e decrementa esse indice
int inserirInicio (deque d, int num) {
    if (cheia(d)) return 0;
    
    d->vetor[d->inicio] = num;
    // subtrai 1 de inicio e se der negativo, volta para o final do vetor com o calculo do resto da divisão
    d->inicio = (d->inicio - 1 + d->max) % d->max;    
    d->qntd++;
    return 1;
}

// coloca o elemento no indice fim e decrementa esse indice
int inserirFim (deque d, int num) {
    if (cheia(d)) return 0;

    d->vetor[d->fim] = num;
    // soma 1 ao fim e se der maior que a capacidade maxima, volta para o inicio do vetor com o calculo do modulo
    d->fim = (d->fim + 1 + d->max) % d->max;    
    d->qntd++;
    return 1;
}

// incrementa o indice inicio (depois o numero é sobrescrito)
int removerInicio (deque d) {
    if (vazia(d)) return 0;

    d->inicio = (d->inicio + 1 + d->max) % d->max;  // incrementa inicio
    d->qntd--;
    return 1;
}

// incrementa o indice fim (depois o numero é sobrescrito)
int removerFim (deque d) {
    if (vazia(d)) return 0;
    
    d->fim = (d->fim - 1 + d->max) % d->max;  // decrementa fim
    d->qntd--;

    return 1;                              
}

//calcula o indice do primeiro/ultimo elemento valido
int primeiroElemento(deque d) {
    return d->vetor[(d->inicio + 1 + d->max) % d->max]; 
}
int ultimoElemento(deque d) {
    return d->vetor[(d->fim - 1 + d->max) % d->max];
}