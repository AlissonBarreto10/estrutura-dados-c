#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elementos;
    int tamanho;
    int capacidade;
} ListaDinamica;

void inicializar(ListaDinamica *lista, int capacidade_inicial) {
    lista->elementos = (int*) malloc(capacidade_inicial * sizeof(int));
    lista->tamanho = 0;
    lista->capacidade = capacidade_inicial;
}

int inserir(ListaDinamica *lista, int valor) {
    if(lista->tamanho >= lista->capacidade) {
        lista->capacidade *= 2;
        lista->elementos = (int*) realloc(lista->elementos, lista->capacidade * sizeof(int));
        if(lista->elementos == NULL) {
            return 0;
        }
    }
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
    return 1;
}

int remover(ListaDinamica *lista, int posicao) {
    if(posicao < 0 || posicao >= lista->tamanho) {
        return 0;
    }
    for(int i = posicao; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
    return 1;
}

void exibir(ListaDinamica *lista) {
    printf("Lista [%d/%d]: ", lista->tamanho, lista->capacidade);
    for(int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

void liberar(ListaDinamica *lista) {
    free(lista->elementos);
    lista->elementos = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
}

int main() {
    ListaDinamica lista;
    inicializar(&lista, 3);
    
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);
    exibir(&lista);
    
    inserir(&lista, 40);
    inserir(&lista, 50);
    exibir(&lista);
    
    inserir(&lista, 60);
    inserir(&lista, 70);
    inserir(&lista, 80);
    exibir(&lista);
    
    remover(&lista, 3);
    exibir(&lista);
    
    liberar(&lista);
    
    return 0;
}
