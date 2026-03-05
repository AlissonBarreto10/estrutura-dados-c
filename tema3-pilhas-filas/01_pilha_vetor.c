#include <stdio.h>

#define MAX 10

typedef struct {
    int elementos[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *pilha) {
    pilha->topo = -1;
}

int vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int cheia(Pilha *pilha) {
    return pilha->topo == MAX - 1;
}

int empilhar(Pilha *pilha, int valor) {
    if(cheia(pilha)) {
        return 0;
    }
    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;
    return 1;
}

int desempilhar(Pilha *pilha, int *valor) {
    if(vazia(pilha)) {
        return 0;
    }
    *valor = pilha->elementos[pilha->topo];
    pilha->topo--;
    return 1;
}

int topo(Pilha *pilha, int *valor) {
    if(vazia(pilha)) {
        return 0;
    }
    *valor = pilha->elementos[pilha->topo];
    return 1;
}

void exibir(Pilha *pilha) {
    if(vazia(pilha)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Pilha [%d elementos]:\n", pilha->topo + 1);
    for(int i = pilha->topo; i >= 0; i--) {
        printf("  [%d]: %d\n", i, pilha->elementos[i]);
    }
}

int main() {
    Pilha pilha;
    inicializar(&pilha);
    
    empilhar(&pilha, 10);
    empilhar(&pilha, 20);
    empilhar(&pilha, 30);
    empilhar(&pilha, 40);
    exibir(&pilha);
    
    int valor;
    if(topo(&pilha, &valor)) {
        printf("\nTopo: %d\n", valor);
    }
    
    printf("\nDesempilhando:\n");
    while(desempilhar(&pilha, &valor)) {
        printf("Removido: %d\n", valor);
    }
    
    exibir(&pilha);
    
    return 0;
}
