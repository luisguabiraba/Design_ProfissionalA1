# Algoritmos e Pensamento Computacional

Este repositório reúne minhas atividades e projetos da disciplina **Algoritmos e Pensamento Computacional**, cursada no 1º semestre de ADS (UDF).  

## Sobre a disciplina

Durante o semestre, desenvolvemos habilidades essenciais para qualquer programador:

- Lógica de programação com foco em resolução de problemas  
- Tipos de dados e operadores  
- Estruturas condicionais (`if`, `else`)  
- Estruturas de repetição (`for`, `while`)  
- Vetores e matrizes  
- Modularização com funções  
- Introdução à análise de algoritmos  
- Pensamento computacional aplicado a problemas reais  
- Ordenação (incluindo **Bubble Sort**, visto na prática)

## Projeto – Ordenação de Dígitos do RGM

Como projeto da disciplina, desenvolvemos um programa em C para **ordenar os dígitos de um RGM** usando três algoritmos de ordenação diferentes e comparar o desempenho de cada um deles.

### Objetivo

- Ordenar os dígitos do RGM com os três métodos:  
  **Bubble Sort**, **Insertion Sort** e **Quick Sort (Lomuto)**  
- Contar o número total de passos (comparações + trocas)  
- Medir o tempo de execução  
- Comparar o comportamento dos algoritmos em vetores de tamanhos diferentes  
- Rodar benchmarks com vetores aleatórios de:  
  **N = 100, 1000 e 10000**

---

## Algoritmos utilizados

### Bubble Sort
- Simples, intuitivo e didático  
- Complexidade O(n²)  
- Ótimo para entender lógica de comparação e troca  

### Insertion Sort
- Também O(n²), mas muito mais eficiente que o bubble  
- Excelente para vetores pequenos ou quase ordenados (como o RGM)  

### Quick Sort (Lomuto)
- O(n log n) na média  
- Extremamente rápido para vetores grandes  
- Mostra bem a diferença entre algoritmos quadráticos e eficientes  

---

## 📈 Execução dos testes

O programa mede:

- Comparações  
- Trocas  
- Tempo em milissegundos  
- Média baseada em **5 execuções por caso**
