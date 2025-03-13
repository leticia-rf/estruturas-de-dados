#include <stdio.h>
#include <string.h>
#include "pilha.h"

int charCorrespondente (char fechado, char aberto);
int balanceada (char str[], pilha p);

int main() {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        
        char string[100000];
        scanf("%s", string);

        pilha p = inicializar();

        if (balanceada(string, p)) 
            printf("S\n");
        else 
            printf("N\n");

        destruir(p);
    }
    return 0;
}

// retorna verdadeiro se o fechado for correspondente ao aberto
int charCorrespondente (char fechado, char aberto) {
    return (aberto == '(' && fechado == ')') || 
           (aberto == '[' && fechado == ']') || 
           (aberto == '{' && fechado == '}');
}

int balanceada (char str[], pilha p) {
    for (int i = 0; str[i] != '\0'; i++) {

        // se for simbolo aberto -> insere na pilha
        // se for simbolo fechado -> remove da pilha, somente se for correspondente ao ultimo na pilha aberto

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            inserir(p, str[i]);
        } 
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            
            // se tentar fechar sem ter aberto antes OU se fechado nao corresponder ao aberto, retorna 0
            if (vazia(p) || !charCorrespondente(str[i], elementoTopo(p))) {
                return 0;
            } else remover(p); // se nao, remove o topo
        }

    }

    // se a pilha estiver vazia no final, entao a string esta balanceada e retorna verdadeiro
    return vazia(p);  
}