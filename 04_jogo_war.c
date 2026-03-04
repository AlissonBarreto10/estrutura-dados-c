#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void cadastrarTerritorios(Territorio *territorios, int quantidade) {
    for(int i = 0; i < quantidade; i++) {
        printf("\n=== Território %d ===\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", territorios[i].nome);
        printf("Cor do exército: ");
        scanf(" %[^\n]", territorios[i].cor);
        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }
}

void exibirTerritorios(Territorio *territorios, int quantidade) {
    printf("\n=== TERRITÓRIOS CADASTRADOS ===\n");
    for(int i = 0; i < quantidade; i++) {
        printf("\nTerritório %d:\n", i+1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }
}

void atacar(Territorio *atacante, Territorio *defensor) {
    printf("\n=== ATAQUE ===\n");
    printf("%s (Tropas: %d) ataca %s (Tropas: %d)\n", 
           atacante->nome, atacante->tropas, 
           defensor->nome, defensor->tropas);
    
    if(atacante->tropas <= 1) {
        printf("Tropas insuficientes para atacar!\n");
        return;
    }
    
    int dado_atacante = (rand() % 6) + 1;
    int dado_defensor = (rand() % 6) + 1;
    
    printf("Dado do atacante: %d\n", dado_atacante);
    printf("Dado do defensor: %d\n", dado_defensor);
    
    if(dado_atacante > dado_defensor) {
        defensor->tropas--;
        printf("%s perdeu 1 tropa!\n", defensor->nome);
    } else {
        atacante->tropas--;
        printf("%s perdeu 1 tropa!\n", atacante->nome);
    }
    
    printf("\nTropas após ataque:\n");
    printf("%s: %d tropas\n", atacante->nome, atacante->tropas);
    printf("%s: %d tropas\n", defensor->nome, defensor->tropas);
}

int verificarVitoria(Territorio *territorios, int quantidade) {
    for(int i = 0; i < quantidade; i++) {
        if(territorios[i].tropas == 0) {
            printf("\n%s foi conquistado!\n", territorios[i].nome);
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    
    int num_territorios = 5;
    Territorio *territorios = (Territorio*) malloc(num_territorios * sizeof(Territorio));
    
    if(territorios == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    
    cadastrarTerritorios(territorios, num_territorios);
    exibirTerritorios(territorios, num_territorios);
    
    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Atacar\n");
        printf("2. Ver territórios\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        if(opcao == 1) {
            int atac, def;
            printf("\nEscolha o território atacante (1-%d): ", num_territorios);
            scanf("%d", &atac);
            printf("Escolha o território defensor (1-%d): ", num_territorios);
            scanf("%d", &def);
            
            if(atac >= 1 && atac <= num_territorios && 
               def >= 1 && def <= num_territorios && atac != def) {
                atacar(&territorios[atac-1], &territorios[def-1]);
                verificarVitoria(territorios, num_territorios);
            } else {
                printf("Territórios inválidos!\n");
            }
        } else if(opcao == 2) {
            exibirTerritorios(territorios, num_territorios);
        }
    } while(opcao != 3);
    
    free(territorios);
    
    return 0;
}
