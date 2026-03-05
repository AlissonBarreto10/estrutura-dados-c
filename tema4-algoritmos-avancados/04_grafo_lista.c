#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int vertice;
    struct No *proximo;
} No;

typedef struct {
    No **lista;
    int numVertices;
} Grafo;

No* criarNo(int vertice) {
    No *novo = (No*) malloc(sizeof(No));
    novo->vertice = vertice;
    novo->proximo = NULL;
    return novo;
}

void inicializar(Grafo *g, int numVertices) {
    g->numVertices = numVertices;
    g->lista = (No**) malloc(numVertices * sizeof(No*));
    for(int i = 0; i < numVertices; i++) {
        g->lista[i] = NULL;
    }
}

void adicionarAresta(Grafo *g, int origem, int destino) {
    No *novo = criarNo(destino);
    novo->proximo = g->lista[origem];
    g->lista[origem] = novo;
    
    novo = criarNo(origem);
    novo->proximo = g->lista[destino];
    g->lista[destino] = novo;
}

void adicionarArestaDirecionada(Grafo *g, int origem, int destino) {
    No *novo = criarNo(destino);
    novo->proximo = g->lista[origem];
    g->lista[origem] = novo;
}

void exibir(Grafo *g) {
    printf("\nLista de Adjacência:\n");
    for(int i = 0; i < g->numVertices; i++) {
        printf("Vértice %d: ", i);
        No *atual = g->lista[i];
        while(atual != NULL) {
            printf("%d -> ", atual->vertice);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

void liberar(Grafo *g) {
    for(int i = 0; i < g->numVertices; i++) {
        No *atual = g->lista[i];
        while(atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(g->lista);
}

int main() {
    Grafo g;
    inicializar(&g, 5);
    
    adicionarAresta(&g, 0, 1);
    adicionarAresta(&g, 0, 4);
    adicionarAresta(&g, 1, 2);
    adicionarAresta(&g, 1, 3);
    adicionarAresta(&g, 1, 4);
    adicionarAresta(&g, 2, 3);
    adicionarAresta(&g, 3, 4);
    
    exibir(&g);
    
    printf("\nGrafo Direcionado:\n");
    Grafo gDir;
    inicializar(&gDir, 4);
    
    adicionarArestaDirecionada(&gDir, 0, 1);
    adicionarArestaDirecionada(&gDir, 0, 2);
    adicionarArestaDirecionada(&gDir, 1, 2);
    adicionarArestaDirecionada(&gDir, 2, 0);
    adicionarArestaDirecionada(&gDir, 2, 3);
    adicionarArestaDirecionada(&gDir, 3, 3);
    
    exibir(&gDir);
    
    liberar(&g);
    liberar(&gDir);
    
    return 0;
}
