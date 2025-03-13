#ifndef DEQUE_H
#define DEQUE_H

typedef struct {
    int inicio, fim;   
    int qntd, max;   
    int *vetor;   
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