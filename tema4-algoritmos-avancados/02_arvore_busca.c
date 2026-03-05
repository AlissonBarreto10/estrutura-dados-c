#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir(No *raiz, int valor) {
    if(raiz == NULL) {
        return criarNo(valor);
    }
    
    if(valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if(valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    return raiz;
}

No* buscar(No *raiz, int valor) {
    if(raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    
    if(valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}

No* encontrarMinimo(No *raiz) {
    while(raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

No* remover(No *raiz, int valor) {
    if(raiz == NULL) {
        return NULL;
    }
    
    if(valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if(valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if(raiz->esquerda == NULL) {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        } else if(raiz->direita == NULL) {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        
        No *temp = encontrarMinimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    
    return raiz;
}

void emOrdem(No *raiz) {
    if(raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void liberar(No *raiz) {
    if(raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

int main() {
    No *raiz = NULL;
    
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);
    
    printf("Árvore em ordem: ");
    emOrdem(raiz);
    printf("\n");
    
    int valor = 40;
    No *encontrado = buscar(raiz, valor);
    if(encontrado != NULL) {
        printf("\nValor %d encontrado!\n", valor);
    } else {
        printf("\nValor %d não encontrado!\n", valor);
    }
    
    printf("\nRemovendo 20...\n");
    raiz = remover(raiz, 20);
    printf("Árvore em ordem: ");
    emOrdem(raiz);
    printf("\n");
    
    printf("\nRemovendo 30...\n");
    raiz = remover(raiz, 30);
    printf("Árvore em ordem: ");
    emOrdem(raiz);
    printf("\n");
    
    printf("\nRemovendo 50...\n");
    raiz = remover(raiz, 50);
    printf("Árvore em ordem: ");
    emOrdem(raiz);
    printf("\n");
    
    liberar(raiz);
    
    return 0;
}
