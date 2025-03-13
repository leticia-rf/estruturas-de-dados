//deque 2.0 - fila duplamente encadeada

#include <stdlib.h>
#include "deque2.h"

deque inicializar (int max) {
    deque d = (deque)malloc(sizeof(Deque));

    d->inicio = d->fim = NULL;
    d->qntd = 0;
    d->max = max;
    return d;
}

int vazia (deque d) {
    return d->qntd == 0;       // returna 1 se a qntd atual for 0, ou seja, se estiver vazia
}
int cheia (deque d) {
    return d->qntd == d->max;  // returna 1 se a qntd atual for igual a capacidade maxima, ou seja, se estiver cheia
}

void destruir (deque d) {
    while (!vazia(d)) {
        removerInicio(d);  
    }
    free(d);
}

int inserirInicio (deque d, int num) {
    if (cheia(d)) return 0;
    
    Node *novo = malloc(sizeof(Node));    // aloca memoria para o novo no

    novo->numero = num;              // atribui numero ao novo no
    novo->anterior = NULL;           // o anterior do novo no deve apontar para NULL
    novo->proximo = d->inicio;       // o proximo do novo no sera o atual elemento no inicio

    // se estiver vazia, fim tambem deve apontar para o novo no
    if (d->fim == NULL) d->fim = novo;
    // se não, o anterior do inicio deve apontar de volta para o novo no               
    else d->inicio->anterior = novo;  
    
    d->inicio = novo;                // e inicio aponta para o novo no
    d->qntd++;
    return 1;
}

int inserirFim (deque d, int num) {
    if (cheia(d)) return 0;
    
    Node *novo = malloc(sizeof(Node));
    novo->numero = num;              // atribui numero ao novo no
    novo->anterior = d->fim;         // o anterior do novo no sera o atual elemento no fim
    novo->proximo = NULL;            // o proximo do novo no deve apontar para NULL

    // se estiver vazia, inicio tambem deve apontar para o novo no
    if (d->inicio == NULL) d->inicio = novo;
    // se não, o proximo do fim deve apontar de volta para o novo no            
    else d->fim->proximo = novo;      

    d->fim = novo;                   // e fim aponta para o novo no
    d->qntd++;
    return 1;
}

int removerInicio (deque d) {
    if (vazia(d)) return 0;    

    Node *atual = d->inicio;            // ponteiro atual "segura" elemento no inicio
    d->inicio = atual->proximo;         // inicio aponta para o proximo no

    // quando tiver somente 1 elemento, inicio será igual a fim (devem ambos apontar para NULL)
    if (d->inicio == NULL) d->fim = NULL;                  
    // se não, o atual sera o novo primeiro elemento e o no anterior (novo inicio) deve apontar para NULL
    else d->inicio->anterior = NULL;     

    free(atual);                        // libera a memoria do atual
    d->qntd--;                          // decrementa a quantidade de elementos
    return 1;                                        
}


int removerFim (deque d) {
    if (vazia(d)) return 0;
    
    Node *atual = d->fim;               // ponteiro (no) atual aponta para onde fim aponta
    d->fim = atual->anterior;           // fim aponta para o no anterior

    // quando deque tiver somente 1 elemento, fim será igual a inicio (devem ambos apontar para NULL)
    if (d->fim == NULL) d->inicio = NULL;  
    // se não, o atual sera o novo ultimo elemento e o proximo no (novo fim) deve apontar para NULL
    else d->fim->proximo = NULL;         

    free(atual);                        // libera a memoria do no atual
    d->qntd--;                          // decrementa a quantidade de elementos
    return 1;                         
}

// retorna o primeiro/ultimo elemento
int primeiroElemento(deque d) {
    return d->inicio->numero;
}
int ultimoElemento(deque d) {
    return d->fim->numero;
}