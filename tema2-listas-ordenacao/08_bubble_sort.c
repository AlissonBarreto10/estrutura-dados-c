#include <stdio.h>

void bubbleSort(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            if(vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void bubbleSortOtimizado(int vetor[], int tamanho) {
    int trocou;
    for(int i = 0; i < tamanho - 1; i++) {
        trocou = 0;
        for(int j = 0; j < tamanho - i - 1; j++) {
            if(vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocou = 1;
            }
        }
        if(!trocou) {
            break;
        }
    }
}

void bubbleSortComEstatisticas(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            (*comparacoes)++;
            if(vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

void exibirVetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor1[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(vetor1) / sizeof(vetor1[0]);
    
    printf("Vetor original: ");
    exibirVetor(vetor1, tamanho);
    
    bubbleSort(vetor1, tamanho);
    
    printf("Vetor ordenado: ");
    exibirVetor(vetor1, tamanho);
    
    int vetor2[] = {64, 34, 25, 12, 22, 11, 90};
    int comparacoes, trocas;
    
    bubbleSortComEstatisticas(vetor2, tamanho, &comparacoes, &trocas);
    
    printf("\n=== Estatísticas ===\n");
    printf("Comparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
    
    int vetor3[] = {1, 2, 3, 4, 5};
    int tamanho3 = sizeof(vetor3) / sizeof(vetor3[0]);
    
    printf("\n=== Melhor Caso (já ordenado) ===\n");
    printf("Vetor: ");
    exibirVetor(vetor3, tamanho3);
    
    bubbleSortComEstatisticas(vetor3, tamanho3, &comparacoes, &trocas);
    printf("Comparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
    
    int vetor4[] = {5, 4, 3, 2, 1};
    int tamanho4 = sizeof(vetor4) / sizeof(vetor4[0]);
    
    printf("\n=== Pior Caso (ordem inversa) ===\n");
    printf("Vetor: ");
    exibirVetor(vetor4, tamanho4);
    
    bubbleSortComEstatisticas(vetor4, tamanho4, &comparacoes, &trocas);
    printf("Comparações: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
    
    return 0;
}
