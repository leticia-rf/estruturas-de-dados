#include <stdio.h>
#include "fila.h"

void lerFila (Fila *f, int n);
void inverterFila (Fila *f, int qntd);

int main () {
    int n_max; 
    scanf("%d", &n_max);

    Fila* f = inicializar (n_max);

    lerFila (f, n_max);
    
    inverterFila(f, quantidade(f));

    imprimirFila(f);

    destruir(f);

    return 0;
}

void lerFila (Fila *f, int n) {
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        inserirFim(f, num);
    }
}

void inverterFila (Fila *f, int qntd) {
    if (qntd <= 0) return;

    int atual = primeiroElemento(f);

    removerInicio(f); 
    inverterFila (f, qntd - 1);
    inserirFim(f, atual);
}