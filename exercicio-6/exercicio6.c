/*
6. Soma recursiva de uma lista
Implemente uma função recursiva que receba uma lista de números e retorne a soma de todos os seus elementos.

Exemplo:

Entrada: [10, 20, 5, 3]

Saída: 38

Não utilize estruturas de repetição dentro da função recursiva.
*/

#include <stdio.h>

float somaRecursivaNumerosLista(float lista[], int tamanho) {
  if (tamanho <= 0)
    return 0.0;

  return lista[tamanho - 1] + somaRecursivaNumerosLista(lista, tamanho - 1);
}

int main() {
  int tamanho;

  printf("Informe o tamanho da lista: ");
  scanf("%d", &tamanho);

  float lista[tamanho];

  for (int i = 0; i < tamanho; i++) {
    printf("Digite o elemento %d da lista: ", i + 1);
    scanf("%f", &lista[i]);
  }

  printf("Soma recursiva dos elemenos da lista: %.2f", somaRecursivaNumerosLista(lista, tamanho));
}