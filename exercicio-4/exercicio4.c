/*
4. Fatorial recursivo

Implemente uma função recursiva que calcule o fatorial de um número inteiro não negativo.

Exemplo:

Além do programa, responda:

- 1. Qual é o caso-base da função?

- 2. O que aconteceria se o caso-base não existisse?

- 3. Qual seria uma versão não recursiva do mesmo algoritmo?
*/

#include <stdio.h>

int calcularFatorialRecursivo(int num) {
  if (num == 1 || num == 0) {
    return 1;
  }

  return num * calcularFatorialRecursivo(num - 1);
}

int calcularFatorialRepeticao(int num) {
  int resultado = 1;

  for (int i = num; i > 0; i--) {
    resultado *= i;
  }

  return resultado;
}

int main() {
  int num;

  // Dado o enunciado da questão, a variável não foi tratada para caso seja negativa e/ou não inteira
  printf("Informe o número em que seu fatorial será calculado: ");
  scanf("%d", &num);

  // Recursão
  printf("%d! = %d\n", num, calcularFatorialRecursivo(num));

  // Laço de repetição
  printf("%d! = %d\n", num, calcularFatorialRepeticao(num));

  return 0;
}