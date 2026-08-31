/*
1. Função para análise de números
Crie um programa que receba uma lista de números inteiros e utilize funções para
determinar:
a) o maior valor;
b) o menor valor;
c) a média dos valores;
d) a quantidade de números pares;
e) a quantidade de números ímpares.
Cada operação deve ser implementada em uma função diferente.
*/

#include <stdio.h>

int encontrarMaiorValor(int lista[], int tamanho) {
  int maiorValor = lista[0];

  for (int i = 0; i < tamanho; i++) {
    if (lista[i] > maiorValor) {
      maiorValor = lista[i];
    }
  }

  return maiorValor;
}

int encontrarMenorValor(int lista[], int tamanho) {
  int menorValor = lista[0];

  for (int i = 0; i < tamanho; i++) {
    if (lista[i] < menorValor) {
      menorValor = lista[i];
    }
  }

  return menorValor;
}

float calcularMediaValores(int lista[], int tamanho) {
  int somaValores = 0;

  for (int i = 0; i < tamanho; i++) {
    somaValores += lista[i];
  }

  float mediaValores = (float)somaValores / tamanho;

  return mediaValores;
}

int acharQtdNumerosPares(int lista[], int tamanho) {
  int qtdPares = 0;

  for (int i = 0; i < tamanho; i++) {
    if (lista[i] % 2 == 0) {
      qtdPares++;
    }
  }

  return qtdPares;
}

int acharQtdNumerosImpares(int lista[], int tamanho) {
  int qtdImpares = 0;

  for (int i = 0; i < tamanho; i++) {
    if (lista[i] % 2 != 0) {
      qtdImpares++;
    }
  }

  return qtdImpares;
}

int main() {
  int tamanhoLista;

  printf("\n -INPUT- \n");
  printf("Informe o tamanho da lista: ");
  scanf("%d", &tamanhoLista);

  int lista[tamanhoLista];

  for (int i = 0; i < tamanhoLista; i++) {
    printf("Insira o %d° elemento da lista: ", i + 1);
    scanf("%d", &lista[i]);
  }

  printf("\n -OUTPUT-");
  printf("\nMaior valor da lista: %d", encontrarMaiorValor(lista, tamanhoLista));
  printf("\nMenor valor da lista: %d", encontrarMenorValor(lista, tamanhoLista));
  printf("\nMédias dos valores da lista: %.2f", calcularMediaValores(lista, tamanhoLista));
  printf("\nQuantidade de números pares na lista: %d", acharQtdNumerosPares(lista, tamanhoLista));
  printf("\nQuantidade de números ímpares na lista: %d", acharQtdNumerosImpares(lista, tamanhoLista));
  return 0;
}
