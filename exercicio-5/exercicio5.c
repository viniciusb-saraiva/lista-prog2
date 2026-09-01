/*
5. Sequência de Fibonacci
- Crie uma função recursiva que calcule o n-ésimo termo da sequência de Fibonacci.
- Depois, implemente uma segunda versão utilizando repetição.
- Compare as duas soluções e explique qual tende a ser mais eficiente para valores elevados de n.
*/

// RESPOSTA: PERGUNTA PERFORMANCE
// A versão iterativa tende a performar extremamente melhor com valores elevados, pois sua complexidade é de tempo linear O(n), ou seja, seu tempo de execução aumenta de proporcional conforme o aumento do input (n = 50, 50 repetições). Em contrapartida, a versão recursiva possui complexidade exponecial O(2 elevado a n), onde seu tempo de execução aumenta de forma drástica conforme o aumento do input (n = 50, 2 elevado a 50 (+1 trilhão) de número de chamadas à função.)

#include <stdio.h>

int calcularFibonacciRecursao(int num) {
  if (num == 0)
    return 0;

  if (num == 1)
    return 1;

  return calcularFibonacciRecursao(num - 1) + calcularFibonacciRecursao(num - 2);
}

int calcularFibonacciRepeticao(int num) {
  if (num == 0)
    return 0;

  if (num == 1)
    return 1;

  int arr[num + 1];
  arr[0] = 0;
  arr[1] = 1;

  for (int i = 2; i <= num; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  return arr[num];
}

int main() {
  int num;

  printf("Digite um número para calcular a Sequência de Fibonacci: ");
  scanf("%d", &num);

  printf("Termo na posição %d-ésimo: %d\n", num, calcularFibonacciRecursao(num));
  printf("Termo na posição %d-ésimo: %d", num, calcularFibonacciRepeticao(num));

  return 0;
}
