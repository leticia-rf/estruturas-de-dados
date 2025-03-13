// lista circular duplamente encadeada com sentinela

#include <stdio.h>
#include <stdlib.h>
#include "lista_sent.h"

// aloca a lista e o no sentinela, inicializa os indices e retorna um ponteiro para a lista
Lista* inicializar (int max) {
    Lista *l = malloc(sizeof(Lista));
    l->max = max;
    l->qntd = 0;

    l->sentinela = malloc(sizeof(Node));
    l->sentinela->anterior = l->sentinela->proximo = l->sentinela;
    return l;
}

int vazia (Lista *l) {
    return l->sentinela->proximo == l->sentinela;
}

int cheia (Lista *l) {
    return l->qntd == l->max;
}

void destruir (Lista *l) {
    while (!vazia(l)) {
        removerInicio(l);
    }
    free(l->sentinela);
    free(l);
}

int removerInicio (Lista *l) {
    if (vazia(l)) return 0;

    Node *inicio = l->sentinela->proximo;
    l->sentinela->proximo = inicio->proximo;
    inicio->proximo->anterior = l->sentinela;

    free(inicio);
    l->qntd--;
    return 1;
}

int removerFim (Lista *l) {
    if (vazia(l)) return 0;

    Node *fim = l->sentinela->anterior;
    l->sentinela->anterior = fim->anterior;
    fim->anterior->proximo = l->sentinela;

    free(fim);
    l->qntd--;
    return 1;
}

int inserirInicio (Lista *l, T dado) {
    if (cheia(l)) return 0;

    Node *novo = malloc(sizeof(Node));
    if (!novo) return 0;

    novo->dado = dado;
    novo->anterior = l->sentinela;
    novo->proximo = l->sentinela->proximo;

    l->sentinela->proximo = novo;
    novo->proximo->anterior = novo;

    l->qntd++;
    return 1;
}

int inserirFim (Lista *l, T dado) {
    if (cheia(l)) return 0;

    Node *novo = malloc(sizeof(Node));
    if (!novo) return 0;

    novo->dado = dado;
    novo->proximo = l->sentinela;
    novo->anterior = l->sentinela->anterior;

    l->sentinela->anterior = novo;
    novo->anterior->proximo = novo;

    l->qntd++;
    return 1;
}

T primeiroElemento (Lista *l) {
    return l->sentinela->proximo->dado;
}

T ultimoElemento (Lista *l) {
    return l->sentinela->anterior->dado;
}

int quantidade (Lista *l) {
    return l->qntd;
}

void imprimirLista (Lista *l) {
    Node *n = l->sentinela->proximo;
    while (n != l->sentinela) {
        printf("%d ", n->dado);
        n = n->proximo;
    }
    printf("\n");
}