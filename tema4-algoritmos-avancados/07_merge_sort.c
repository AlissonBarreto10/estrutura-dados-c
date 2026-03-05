#include <stdio.h>
#include <stdlib.h>

void merge(int vetor[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));
    
    for(int i = 0; i < n1; i++) {
        L[i] = vetor[esquerda + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = vetor[meio + 1 + j];
    }
    
    int i = 0, j = 0, k = esquerda;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(int vetor[], int esquerda, int direita) {
    if(esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        mergeSort(vetor, esquerda, meio);
        mergeSort(vetor, meio + 1, direita);
        
        merge(vetor, esquerda, meio, direita);
    }
}

void exibirVetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor1[] = {38, 27, 43, 3, 9, 82, 10};
    int tamanho1 = sizeof(vetor1) / sizeof(vetor1[0]);
    
    printf("Vetor original: ");
    exibirVetor(vetor1, tamanho1);
    
    mergeSort(vetor1, 0, tamanho1 - 1);
    
    printf("Vetor ordenado: ");
    exibirVetor(vetor1, tamanho1);
    
    int vetor2[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 23, 67, 1, 99, 5};
    int tamanho2 = sizeof(vetor2) / sizeof(vetor2[0]);
    
    printf("\nVetor grande original: ");
    exibirVetor(vetor2, tamanho2);
    
    mergeSort(vetor2, 0, tamanho2 - 1);
    
    printf("Vetor grande ordenado: ");
    exibirVetor(vetor2, tamanho2);
    
    return 0;
}
