# ⚡ Algoritmos de Ordenação Eficientes em C++

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-11%2B-blue.svg?style=flat-square&logo=cplusplus)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg?style=flat-square)](LICENSE)
[![Algorithms](https://img.shields.io/badge/Algorithms-Divide%20%26%20Conquer-orange.svg?style=flat-square)](#)

Este repositório contém implementações claras, limpas e otimizadas de dois dos principais algoritmos de ordenação baseados no paradigma **Divisão e Conquista** (<i>Divide and Conquer</i>): **Merge Sort** e **Quick Sort**. 

---

## 📌 Sumário
- [Conceito Gerais](#-conceito-gerais)
- [🧩 1. Merge Sort](#-1-merge-sort)
  - [Como Funciona](#como-funciona)
  - [Detalhamento do Código](#detalhamento-do-código)
- [⚡ 2. Quick Sort](#-2-quick-sort)
  - [Como Funciona](#como-funciona-1)
  - [Detalhamento do Código](#detalhamento-do-código-1)
- [📊 Análise de Complexidade](#-análise-de-complexidade)
- [⚔️ Tabela Comparativa](#️-tabela-comparativa)
- [🛠️ Como Compilar e Executar](#️-como-compilar-e-executar)

---

## 🧠 Conceito Gerais

Ambos os algoritmos utilizam a estratégia de **Divisão e Conquista**, dividindo a tarefa de ordenação em subtarefas menores e encadeando os resultados:

1. **Dividir**: Quebra o problema original em subproblemas menores.
2. **Conquistar**: Resolve os subproblemas de forma recursiva.
3. **Combinar**: Junta as soluções dos subproblemas para resolver o problema original.

---

## 🧩 1. Merge Sort

O **Merge Sort** é um algoritmo de ordenação estável que garante desempenho consistente $O(n \log n)$ em todos os casos.

### Como Funciona
1. Divide o vetor original iterativamente em duas metades até obter subvetores unitários.
2. Intercala (*merge*) as metades já ordenadas para formar subvetores maiores também ordenados.

### Detalhamento do Código

#### `void merge(vector<int>& vetorItems, int left, int meio, int right)`
Esta função junta duas partes ordenadas adjacentes do vetor:
* **Criação dos vetores temporários**: Separa os elementos nas partes `esquerda` e `direita`.
* **Intercalação**: Utiliza dois ponteiros (`i` e `j`) para comparar o menor elemento entre os dois vetores e inseri-lo de volta no vetor original na posição `k`.
* **Resíduos**: Adiciona quaisquer elementos remanescentes que sobraram no vetor esquerdo ou direito.

#### `void mergeSort(vector<int>& vetorItems, int left, int right)`
Função recursiva principal:
* **Condição de Parada**: `if (left >= right)` interrompe a recursão quando o subarray possui $1$ ou $0$ elementos.
* **Cálculo do Meio**: `int meio = left + (right - left) / 2;` evita *overflow* de inteiros.
* **Recursão & Junção**: Ordena a metade esquerda, a metade direita e invoca `merge`.

---

## ⚡ 2. Quick Sort

O **Quick Sort** é um dos algoritmos de ordenação mais rápidos e amplamente utilizados na prática devido ao seu baixo overhead e excelente performance de memória (in-place).

### Como Funciona
1. Escolhe um elemento chamado **pivô** (nesta implementação, o último elemento do subarray).
2. **Particiona** o vetor: coloca todos os elementos menores ou iguais ao pivô à sua esquerda e os maiores à sua direita.
3. Aplica recursivamente o processo nas partições esquerda e direita.

### Detalhamento do Código

#### `int partition(vector<int>& vetorItems, int left, int right)`
Reorganiza o subarray em torno do pivô selecionado (`vetorItems[right]`):
* **Índice de Separação (`i`)**: Marca o limite dos elementos menores ou iguais ao pivô.
* **Varredura (`j`)**: Percorre o vetor; se um elemento for $\le \text{pivô}$, incrementa `i` e faz a troca (`swap`).
* **Posicionamento Final**: Troca o pivô (`vetorItems[right]`) com o primeiro elemento maior (`vetorItems[i + 1]`), fixando o pivô em sua posição definitiva.

#### `void quickSort(vector<int>& vetorItems, int left, int right)`
Função recursiva responsável pelo fluxo:
* **Condição de Parada**: Retorna se a partição tiver tamanho $0$ ou $1$.
* **Particionamento**: Executa `partition` para encontrar a posição correta do pivô.
* **Recursão**: Chama `quickSort` para os elementos à esquerda (`pivo - 1`) e à direita (`pivo + 1`).

---

## 📊 Análise de Complexidade

| Algoritmo | Complexidade de Tempo (Melhor) | Complexidade de Tempo (Médio) | Complexidade de Tempo (Pior) | Complexidade Espacial (Auxiliar) |
| :--- | :---: | :---: | :---: | :---: |
| **Merge Sort** | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n)$ |
| **Quick Sort** | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(\log n)$ |

> **Nota:** No Quick Sort, o pior caso $\mathcal{O}(n^2)$ ocorre quando o pivô escolhido é repetidamente o maior ou menor elemento (ex: vetor já ordenado ou invertido com escolha de pivô nas extremidades).

---

## ⚔️ Tabela Comparativa

| Característica | Merge Sort | Quick Sort |
| :--- | :--- | :--- |
| **Estabilidade** | **Estável** (Preserva a ordem relativa de elementos iguais) | **Não estável** (Pode alterar a ordem relativa) |
| **Uso de Memória** | Requer memória extra $\mathcal{O}(n)$ para vetores temporários | **In-place** (Usa apenas a pilha de execução da recursão) |
| **Previsibilidade** | Desempenho idêntico em qualquer cenário | Desempenho depende substancialmente da escolha do pivô |
| **Aplicações Típicas** | Estruturas encadeadas (LinkedLists) e dados massivos externos | Arrays em memória principal (geralmente mais rápido na prática) |

---

## 🛠️ Como Compilar e Executar

Certifique-se de ter um compilador C++ instalado (como o `g++`).

### Otimização de E/S (`IOFAST`)
Ambos os arquivos incluem a macro de otimização de entrada e saída em C++:
```cpp
#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);
```

### 🔨 Compilando via Terminal

#### Para o Merge Sort:
```bash
# Compilação
g++ -O2 mergeSort.cpp -o mergeSort

# Execução (Linux/macOS)
./mergeSort

# Execução (Windows)
.\mergeSort.exe
```

#### Para o Quick Sort:
```bash
# Compilação
g++ -O2 quickSort.cpp -o quickSort

# Execução (Linux/macOS)
./quickSort

# Execução (Windows)
.\quickSort.exe
```

---
*Criado com a finalidade de documentar a implementação dos algoritmos de ordenação em C++.*
