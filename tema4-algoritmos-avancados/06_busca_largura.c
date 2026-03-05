#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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

void bfs(Grafo *g, int inicio) {
    int visitado[MAX] = {0};
    int fila[MAX];
    int frente = 0, tras = 0;
    
    visitado[inicio] = 1;
    fila[tras++] = inicio;
    
    printf("BFS a partir do vértice %d: ", inicio);
    
    while(frente < tras) {
        int vertice = fila[frente++];
        printf("%d ", vertice);
        
        No *atual = g->lista[vertice];
        while(atual != NULL) {
            if(!visitado[atual->vertice]) {
                visitado[atual->vertice] = 1;
                fila[tras++] = atual->vertice;
            }
            atual = atual->proximo;
        }
    }
    printf("\n");
}

void bfsComNivel(Grafo *g, int inicio) {
    int visitado[MAX] = {0};
    int nivel[MAX] = {0};
    int fila[MAX];
    int frente = 0, tras = 0;
    
    visitado[inicio] = 1;
    nivel[inicio] = 0;
    fila[tras++] = inicio;
    
    printf("\nBFS com níveis a partir do vértice %d:\n", inicio);
    
    while(frente < tras) {
        int vertice = fila[frente++];
        printf("Vértice %d (Nível %d)\n", vertice, nivel[vertice]);
        
        No *atual = g->lista[vertice];
        while(atual != NULL) {
            if(!visitado[atual->vertice]) {
                visitado[atual->vertice] = 1;
                nivel[atual->vertice] = nivel[vertice] + 1;
                fila[tras++] = atual->vertice;
            }
            atual = atual->proximo;
        }
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
    inicializar(&g, 7);
    
    adicionarAresta(&g, 0, 1);
    adicionarAresta(&g, 0, 2);
    adicionarAresta(&g, 1, 3);
    adicionarAresta(&g, 1, 4);
    adicionarAresta(&g, 2, 5);
    adicionarAresta(&g, 2, 6);
    
    bfs(&g, 0);
    bfsComNivel(&g, 0);
    
    liberar(&g);
    
    return 0;
}
