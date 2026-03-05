#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto];
    int i = baixo - 1;
    
    for(int j = baixo; j < alto; j++) {
        if(vetor[j] < pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    
    trocar(&vetor[i + 1], &vetor[alto]);
    return i + 1;
}

void quickSort(int vetor[], int baixo, int alto) {
    if(baixo < alto) {
        int pi = particionar(vetor, baixo, alto);
        
        quickSort(vetor, baixo, pi - 1);
        quickSort(vetor, pi + 1, alto);
    }
}

int particionarMedio(int vetor[], int baixo, int alto) {
    int meio = baixo + (alto - baixo) / 2;
    trocar(&vetor[meio], &vetor[alto]);
    return particionar(vetor, baixo, alto);
}

void quickSortMedio(int vetor[], int baixo, int alto) {
    if(baixo < alto) {
        int pi = particionarMedio(vetor, baixo, alto);
        
        quickSortMedio(vetor, baixo, pi - 1);
        quickSortMedio(vetor, pi + 1, alto);
    }
}

void exibirVetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor1[] = {10, 7, 8, 9, 1, 5};
    int tamanho1 = sizeof(vetor1) / sizeof(vetor1[0]);
    
    printf("Vetor original: ");
    exibirVetor(vetor1, tamanho1);
    
    quickSort(vetor1, 0, tamanho1 - 1);
    
    printf("Vetor ordenado (pivô último): ");
    exibirVetor(vetor1, tamanho1);
    
    int vetor2[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho2 = sizeof(vetor2) / sizeof(vetor2[0]);
    
    printf("\nVetor original: ");
    exibirVetor(vetor2, tamanho2);
    
    quickSortMedio(vetor2, 0, tamanho2 - 1);
    
    printf("Vetor ordenado (pivô meio): ");
    exibirVetor(vetor2, tamanho2);
    
    int vetor3[] = {5, 4, 3, 2, 1};
    int tamanho3 = sizeof(vetor3) / sizeof(vetor3[0]);
    
    printf("\nPior caso (ordem inversa): ");
    exibirVetor(vetor3, tamanho3);
    
    quickSort(vetor3, 0, tamanho3 - 1);
    
    printf("Vetor ordenado: ");
    exibirVetor(vetor3, tamanho3);
    
    return 0;
}
