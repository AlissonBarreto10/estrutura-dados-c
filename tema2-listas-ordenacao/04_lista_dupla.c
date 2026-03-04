#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *proximo;
    struct No *anterior;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} ListaDupla;

void inicializar(ListaDupla *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

void inserirInicio(ListaDupla *lista, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = lista->inicio;
    novo->anterior = NULL;
    
    if(lista->inicio != NULL) {
        lista->inicio->anterior = novo;
    } else {
        lista->fim = novo;
    }
    
    lista->inicio = novo;
    lista->tamanho++;
}

void inserirFim(ListaDupla *lista, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    
    if(lista->fim != NULL) {
        lista->fim->proximo = novo;
    } else {
        lista->inicio = novo;
    }
    
    lista->fim = novo;
    lista->tamanho++;
}

int removerInicio(ListaDupla *lista) {
    if(lista->inicio == NULL) {
        return 0;
    }
    
    No *temp = lista->inicio;
    lista->inicio = lista->inicio->proximo;
    
    if(lista->inicio != NULL) {
        lista->inicio->anterior = NULL;
    } else {
        lista->fim = NULL;
    }
    
    free(temp);
    lista->tamanho--;
    return 1;
}

int removerFim(ListaDupla *lista) {
    if(lista->fim == NULL) {
        return 0;
    }
    
    No *temp = lista->fim;
    lista->fim = lista->fim->anterior;
    
    if(lista->fim != NULL) {
        lista->fim->proximo = NULL;
    } else {
        lista->inicio = NULL;
    }
    
    free(temp);
    lista->tamanho--;
    return 1;
}

void exibirFrente(ListaDupla *lista) {
    printf("Lista (frente) [%d]: ", lista->tamanho);
    No *atual = lista->inicio;
    while(atual != NULL) {
        printf("%d <-> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void exibirTras(ListaDupla *lista) {
    printf("Lista (trás) [%d]: ", lista->tamanho);
    No *atual = lista->fim;
    while(atual != NULL) {
        printf("%d <-> ", atual->dado);
        atual = atual->anterior;
    }
    printf("NULL\n");
}

void liberar(ListaDupla *lista) {
    No *atual = lista->inicio;
    while(atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int main() {
    ListaDupla lista;
    inicializar(&lista);
    
    inserirFim(&lista, 10);
    inserirFim(&lista, 20);
    inserirFim(&lista, 30);
    exibirFrente(&lista);
    exibirTras(&lista);
    
    inserirInicio(&lista, 5);
    exibirFrente(&lista);
    
    removerFim(&lista);
    exibirFrente(&lista);
    
    removerInicio(&lista);
    exibirFrente(&lista);
    
    liberar(&lista);
    
    return 0;
}
