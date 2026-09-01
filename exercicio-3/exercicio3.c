/*
3. Calculadora modular

Construa uma calculadora utilizando funções para realizar as operações:

- soma;

- subtração;

- multiplicação;

- divisão;

- potência;

- resto da divisão.

O programa deverá apresentar um menu e permitir que o usuário execute várias operações até escolher a opção de encerrar.

Trate situações inválidas, como divisão por zero.
*/

#include <math.h>
#include <stdio.h>

float calcularSoma(float num1, float num2) {
  return num1 + num2;
}

float calcularSubtracao(float num1, float num2) {
  return num1 - num2;
}

float calcularMultiplicacao(float num1, float num2) {
  return num1 * num2;
}

float calcularDivisao(float num1, float num2) {
  return num1 / num2;
}

float calcularPotencia(float num1, float num2) {
  return pow(num1, num2);
}

float calcularRestoDivisao(float num1, float num2) {
  // num1 % num2 para inteiros (% não funciona para pegar o resto da divisão de tipos decimais);
  return fmod(num1, num2);
}

int main() {
  int escolha;
  float num1, num2;

  do {
    printf("\n---------CALCULADORA---------\n");
    printf("1. Soma\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Potência\n");
    printf("6. Resto da divisão\n");
    printf("7. Encerrar\n");
    printf("Escolha qual operação deseja realizar: ");
    scanf("%d", &escolha);

    if (escolha == 7) {
      printf("Encerrando o programa...");
      break;
    }

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    switch (escolha) {
    case 1:
      printf("Resultado da Soma: %.2f\n", calcularSoma(num1, num2));
      break;

    case 2:
      printf("Resultado da Subtração: %.2f\n", calcularSubtracao(num1, num2));
      break;

    case 3:
      printf("Resultado da Multiplicação: %.2f\n", calcularMultiplicacao(num1, num2));
      break;

    case 4:
      if (num2 == 0) {
        printf("Divisão por 0: Indeterminado\n");
        break;
      }
      printf("Resultado da Divisão: %.2f\n", calcularDivisao(num1, num2));
      break;

    case 5:
      printf("Resultado da Potência: %.2f\n", calcularPotencia(num1, num2));
      break;

    case 6:
      printf("Resultado do Resto da Divisão: %.2f\n", calcularRestoDivisao(num1, num2));
      break;

    default:
      break;
    }
  } while (escolha != 7);

  return 0;
}