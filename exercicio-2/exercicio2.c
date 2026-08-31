/*
2. Validação utilizando funções

Desenvolva um programa de cadastro de usuário que solicite:

- a) nome;

- b) idade;

- c) e-mail;

- d) senha.

Implemente funções independentes para validar cada informação.

Regras mínimas:

- o nome não pode estar vazio;

- a idade deve estar entre 14 e 120 anos;

- o e-mail deve possuir um formato minimamente válido;

- a senha deve possuir pelo menos 8 caracteres.

O programa somente deverá concluir o cadastro quando todos os dados forem válidos.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool nomeEValido(char *nome) {
  return nome[0] != '\0';
}

bool idadeEValida(int idade) {
  if (idade < 14 || idade > 120) {
    return false;
  }

  return true;
}

bool emailEValido(char *email) {
  int arrobaContador = 0;
  int pontoContador = 0;
  int tamanhoEmail = strlen(email);

  if (tamanhoEmail < 5) {
    return false;
  }

  for (int i = 0; i < tamanhoEmail; i++) {
    char ch = email[i];

    if (ch == '@') {
      arrobaContador++;
    }
    if (ch == '.') {
      pontoContador++;
    }

    if (!(isalnum(ch) || ch == '@' || ch == '.' || ch == '-' || ch == '_')) {
      return false;
    }
  }

  if (arrobaContador != 1 || pontoContador == 0) {
    return false;
  }

  return true;
}

bool senhaEValida(char *senha) {
  if (strlen(senha) < 8) {
    return false;
  }

  return true;
}

int main() {
  char nome[100], email[255], senha[100];
  int idade;

  printf("\n-CADASTRO DE USUÁRIO-\n");

  printf("Digite seu nome: ");
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = '\0';

  while (!nomeEValido(nome)) {
    printf("Nome vazio, tente novamente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
  }

  printf("Email: ");
  fgets(email, sizeof(email), stdin);
  email[strcspn(email, "\n")] = '\0';

  while (!emailEValido(email)) {
    printf("Email inválido, tente novamente: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
  }

  printf("Senha: ");
  fgets(senha, sizeof(senha), stdin);
  senha[strcspn(senha, "\n")] = '\0';

  while (!senhaEValida(senha)) {
    printf("Senha inválida, tente novamente: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';
  }

  printf("Idade: ");
  scanf("%d", &idade);

  while (!idadeEValida(idade)) {
    printf("Idade inválida, tente novamente: ");
    scanf("%d", &idade);
  }

  printf("\nCadastro finalido\n");
  printf("Nome: %s\n", nome);
  printf("Email: %s\n", email);
  printf("Senha: %s\n", senha);
  printf("Idade: %d\n", idade);

  return 0;
}