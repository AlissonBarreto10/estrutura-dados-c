#include <stdio.h>

#define MAX 10

typedef struct {
    int matriz[MAX][MAX];
    int numVertices;
} Grafo;

void inicializar(Grafo *g, int numVertices) {
    g->numVertices = numVertices;
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0; j < numVertices; j++) {
            g->matriz[i][j] = 0;
        }
    }
}

void adicionarAresta(Grafo *g, int origem, int destino) {
    if(origem >= 0 && origem < g->numVertices && 
       destino >= 0 && destino < g->numVertices) {
        g->matriz[origem][destino] = 1;
        g->matriz[destino][origem] = 1;
    }
}

void adicionarArestaDirecionada(Grafo *g, int origem, int destino) {
    if(origem >= 0 && origem < g->numVertices && 
       destino >= 0 && destino < g->numVertices) {
        g->matriz[origem][destino] = 1;
    }
}

void removerAresta(Grafo *g, int origem, int destino) {
    if(origem >= 0 && origem < g->numVertices && 
       destino >= 0 && destino < g->numVertices) {
        g->matriz[origem][destino] = 0;
        g->matriz[destino][origem] = 0;
    }
}

int verificarAresta(Grafo *g, int origem, int destino) {
    if(origem >= 0 && origem < g->numVertices && 
       destino >= 0 && destino < g->numVertices) {
        return g->matriz[origem][destino];
    }
    return 0;
}

void exibir(Grafo *g) {
    printf("\nMatriz de Adjacência:\n");
    printf("   ");
    for(int i = 0; i < g->numVertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for(int i = 0; i < g->numVertices; i++) {
        printf("%2d ", i);
        for(int j = 0; j < g->numVertices; j++) {
            printf("%2d ", g->matriz[i][j]);
        }
        printf("\n");
    }
}

void exibirAdjacentes(Grafo *g, int vertice) {
    printf("\nVértices adjacentes a %d: ", vertice);
    for(int i = 0; i < g->numVertices; i++) {
        if(g->matriz[vertice][i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
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
    
    exibirAdjacentes(&g, 1);
    
    if(verificarAresta(&g, 0, 1)) {
        printf("\nExiste aresta entre 0 e 1\n");
    }
    
    printf("\nRemovendo aresta entre 1 e 4...\n");
    removerAresta(&g, 1, 4);
    exibir(&g);
    
    return 0;
}
