# Estrutura de Dados em C

Repositório com implementações completas de estruturas de dados e algoritmos em linguagem C, baseado nos conceitos estudados na disciplina de Estrutura de Dados.

## 📚 Conteúdo

### Tema 1: Estruturas de Dados - Conceitos e Representação
- Structs e encapsulamento
- Ponteiros e manipulação de memória
- Alocação dinâmica (malloc, calloc, realloc, free)
- Vetores e arrays
- Projeto: Jogo WAR simplificado

### Tema 2: Listas e Ordenação
- Listas lineares (estáticas e dinâmicas)
- Listas encadeadas (simples, dupla, circular)
- Algoritmos de busca (sequencial e binária)
- Algoritmos de ordenação (Bubble Sort, Selection Sort, Insertion Sort)
- Projeto: Sistema de inventário (Free Fire)

### Tema 3: Pilhas e Filas
- Pilha (LIFO) com vetor e lista encadeada
- Fila (FIFO) com vetor circular e lista encadeada
- Aplicações práticas (calculadora, verificador de parênteses)
- Projeto: Jogo Tetris Stack

### Tema 4: Algoritmos Avançados
- Árvores binárias
- Árvores de busca binária (BST)
- Grafos (matriz e lista de adjacência)
- Busca em profundidade (DFS) e largura (BFS)
- Algoritmos de ordenação avançados (Merge Sort, Quick Sort)
- Projeto: Detective Quest

## 🗂️ Estrutura do Repositório

```
estrutura-dados-c/
├── README.md
├── tema1-conceitos/
│   ├── 01_structs_basico.c
│   ├── 02_ponteiros.c
│   ├── 03_alocacao_dinamica.c
│   └── 04_jogo_war.c
├── tema2-listas-ordenacao/
│   ├── 01_lista_estatica.c
│   ├── 02_lista_dinamica.c
│   ├── 03_lista_encadeada.c
│   ├── 04_lista_dupla.c
│   ├── 05_lista_circular.c
│   ├── 06_busca_sequencial.c
│   ├── 07_busca_binaria.c
│   ├── 08_bubble_sort.c
│   ├── 09_selection_sort.c
│   └── 10_insertion_sort.c
├── tema3-pilhas-filas/
│   ├── 01_pilha_vetor.c
│   ├── 02_pilha_encadeada.c
│   ├── 03_fila_vetor.c
│   ├── 04_fila_encadeada.c
│   └── 05_calculadora_pilha.c
└── tema4-algoritmos-avancados/
    ├── 01_arvore_binaria.c
    ├── 02_arvore_busca.c
    ├── 03_grafo_matriz.c
    ├── 04_grafo_lista.c
    ├── 05_busca_profundidade.c
    ├── 06_busca_largura.c
    ├── 07_merge_sort.c
    └── 08_quick_sort.c
```

## 🚀 Como Compilar e Executar

### Compilar um arquivo:
```bash
gcc nome_do_arquivo.c -o nome_do_programa
```

### Executar:
```bash
./nome_do_programa
```

### Exemplo:
```bash
gcc tema1-conceitos/01_structs_basico.c -o structs
./structs
```

## 📖 Conceitos Abordados

### Estruturas de Dados Lineares
- Listas estáticas e dinâmicas
- Listas encadeadas (simples, dupla, circular)
- Pilhas (LIFO)
- Filas (FIFO)

### Estruturas de Dados Não-Lineares
- Árvores binárias
- Árvores de busca binária (BST)
- Grafos (direcionados e não-direcionados)

### Algoritmos de Busca
- Busca sequencial
- Busca binária
- Busca em profundidade (DFS)
- Busca em largura (BFS)

### Algoritmos de Ordenação
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort

## 🎯 Complexidade dos Algoritmos

### Busca
| Algoritmo | Melhor Caso | Caso Médio | Pior Caso |
|-----------|-------------|------------|-----------|
| Sequencial | O(1) | O(n) | O(n) |
| Binária | O(1) | O(log n) | O(log n) |

### Ordenação
| Algoritmo | Melhor Caso | Caso Médio | Pior Caso |
|-----------|-------------|------------|-----------|
| Bubble Sort | O(n) | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |

## 💡 Boas Práticas Utilizadas

- Código limpo e organizado
- Funções modulares e reutilizáveis
- Gerenciamento adequado de memória
- Verificação de erros
- Estruturas de dados eficientes

## 🛠️ Tecnologias

- Linguagem C (C11)
- GCC Compiler
- Biblioteca padrão C (stdio.h, stdlib.h, string.h)

## 📝 Autor

Alisson Barreto
- GitHub: [@AlissonBarreto10](https://github.com/AlissonBarreto10)
- LinkedIn: [Alisson Barreto](https://www.linkedin.com/in/alisson-barreto-6b0090257/)

## 📄 Licença

Este projeto é de código aberto e está disponível para fins educacionais.

---

⭐ Obrigado pela atenção.
