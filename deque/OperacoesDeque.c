#include <stdio.h>
#include <string.h>
#include "deque.h"

int main() {

    int n_operacoes, n_max;
    char operacao[10];
    int numero;

    scanf("%d %d", &n_operacoes, &n_max);
    
    deque d = inicializar (n_max);

    for (int i = 0; i < n_operacoes; i++) {
        scanf("%s", operacao);

        if (!strcmp(operacao, "insereI")) {
            scanf("%d", &numero);

            if (!inserirInicio(d, numero)) printf("cheia\n");
        }

        else if (!strcmp(operacao, "insereF")) {
            scanf("%d", &numero);

            if (!inserirFim(d, numero)) printf("cheia\n");
        }

        else if (!strcmp(operacao, "removeI")) {
            if (!vazia(d)) {
                printf ("%d\n", primeiroElemento(d));
                removerInicio(d);
            }
            else printf("vazia\n");
        }

        else if (!strcmp(operacao, "removeF")) {
            if (!vazia(d)) {
                printf ("%d\n", ultimoElemento(d));
                removerFim(d);
            }
            else printf("vazia\n");
        }
    }

    destruir(d);

    return 0;
}