// fila com alocacao dinamica e sequencial - armazena qualquer tipo de dados

#include <stdlib.h>
#include <stdio.h>
#include "fila_seq.h"

Fila *inicializar(int max) {
    Fila *f = malloc(sizeof(Fila));
    if (!f) return NULL;

    f->inicio = 0;
    f->fim = 1;
    f->qntd = 0;
    f->max = max;
    f->vetor = (T *)malloc(max*sizeof(T));
    return f;
}

int vazia(Fila *f) {
    return f->qntd == 0;
}

int cheia(Fila *f) {
    return f->qntd == f->max;
}

void destruir(Fila *f) {
    free(f->vetor);
    free(f);
}

int inserir(Fila *f, T dado) {
    if (fila_cheia(f)) return 0;

    f->vetor[f->fim] = dado;
    f->fim = (f->fim + 1) % f->max;
    f->qntd++;
    return 1;
}

int remover(Fila *f) {
    if (fila_vazia(f)) return 0;

    f->inicio = (f->inicio + 1) % f->max;
    f->qntd--;
    return 1;
}

T primeiroElemento(Fila *f) {
    return f->vetor[(f->inicio + 1) % f->max];
}

T ultimoElemento(Fila *f) {
    return f->vetor[(f->fim - 1) % f->max];
}

int quantidade(Fila *f) {
    return f->qntd;
}

void imprimirFila(Fila *f, void (*print)(T)) {
    for (int i = (f->inicio + 1) % f->max; i != f->fim; i = (i + 1) % f->max) {
        print (f->vetor[i]); // chama a função de impressão passada como parâmetro
    }
}