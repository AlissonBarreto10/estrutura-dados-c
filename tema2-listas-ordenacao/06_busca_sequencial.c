#include <stdio.h>

int buscaSequencial(int vetor[], int tamanho, int valor) {
    for(int i = 0; i < tamanho; i++) {
        if(vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int buscaSequencialComparacoes(int vetor[], int tamanho, int valor, int *comparacoes) {
    *comparacoes = 0;
    for(int i = 0; i < tamanho; i++) {
        (*comparacoes)++;
        if(vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    
    printf("Vetor: ");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");
    
    int valor = 22;
    int posicao = buscaSequencial(vetor, tamanho, valor);
    
    if(posicao != -1) {
        printf("Valor %d encontrado na posição %d\n", valor, posicao);
    } else {
        printf("Valor %d não encontrado\n", valor);
    }
    
    valor = 100;
    posicao = buscaSequencial(vetor, tamanho, valor);
    
    if(posicao != -1) {
        printf("Valor %d encontrado na posição %d\n", valor, posicao);
    } else {
        printf("Valor %d não encontrado\n", valor);
    }
    
    printf("\n=== Análise de Comparações ===\n");
    int comparacoes;
    
    valor = 64;
    posicao = buscaSequencialComparacoes(vetor, tamanho, valor, &comparacoes);
    printf("Buscar %d (primeiro): %d comparações\n", valor, comparacoes);
    
    valor = 50;
    posicao = buscaSequencialComparacoes(vetor, tamanho, valor, &comparacoes);
    printf("Buscar %d (último): %d comparações\n", valor, comparacoes);
    
    valor = 22;
    posicao = buscaSequencialComparacoes(vetor, tamanho, valor, &comparacoes);
    printf("Buscar %d (meio): %d comparações\n", valor, comparacoes);
    
    valor = 999;
    posicao = buscaSequencialComparacoes(vetor, tamanho, valor, &comparacoes);
    printf("Buscar %d (não existe): %d comparações\n", valor, comparacoes);
    
    return 0;
}
