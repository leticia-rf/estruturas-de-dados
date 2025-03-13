#ifndef PILHA_H
#define PILHA_H

typedef char T;

typedef struct node {
    T item;
    struct node *next;
} Node;

typedef struct{
    Node *topo;
} Pilha;

typedef Pilha *pilha;

pilha inicializar ();
void destruir (pilha p);
int vazia (pilha p);
void inserir (pilha p, T data);
void remover (pilha p);
T elementoTopo (pilha p);

#endif