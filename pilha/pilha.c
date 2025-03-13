// pilha com alocacao dinamica e encadeamento simples

#include <stdlib.h>
#include "pilha.h"

pilha inicializar () {
    pilha p = (pilha)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void destruir (pilha p) {
    while (!vazia(p))
        remover(p);
    free(p);
}

int vazia (pilha p) {
    return p->topo == NULL;
}

void inserir (pilha p, T data) {
    Node *novo = malloc(sizeof(Node));
    novo->item = data;
    novo->next = p->topo;   // novo no aponta para onde o topo apontava
    p->topo = novo;         // topo aponta para o novo no
}

void remover (pilha p) {
    Node *aux = p->topo;    // auxiliar "segura" o topo
    p->topo = aux->next;    // topo aponta para o proximo no
    free(aux);              // remove o no atual (aux)
}

T elementoTopo (pilha p) {
    return p->topo->item;
}