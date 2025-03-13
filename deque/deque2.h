#ifndef DEQUE_H
#define DEQUE_H

typedef struct node {
    int numero;                          // armazena o dado (número inteiro)
    struct node *proximo, *anterior;     // ponteiros para o proximo no e o anterior
} Node;

typedef struct {
    Node *inicio, *fim;   // ponteiros para o primeiro e o ultimo no da deque
    int qntd, max;        // quantidade atual de elementos e capacidade maxima
} Deque;

typedef Deque *deque;

deque inicializar (int max);
int vazia (deque d);
int cheia (deque d);
void destruir (deque d);
int inserirInicio (deque d, int num);
int inserirFim (deque d, int num);
int removerInicio (deque d);
int removerFim (deque d);
int primeiroElemento(deque d);
int ultimoElemento(deque d);


#endif