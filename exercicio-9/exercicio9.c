/*
9. Sistema de atendimento utilizando fila
Implemente um sistema de atendimento utilizando uma fila.

Cada pessoa deverá possuir:
- número da senha;
- nome;
- horário de entrada.

O sistema deverá permitir:
- adicionar uma pessoa à fila;
- chamar a próxima pessoa;
- consultar quem será o próximo;
- mostrar toda a fila;
- informar quantas pessoas estão aguardando.

Explique por que uma fila é mais adequada que uma pilha neste problema.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
  int senha;
  char nome[50];
  char horario_entrada[10]; // Ex: "14:30"
};

// Definição do tipo Fila
struct elemento {
  struct pessoa dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

// Definição do Nó Descritor da Fila
struct fila {
  struct elemento *inicio;
  struct elemento *final;
  int qtd;
};
typedef struct fila Fila;

Fila *cria_Fila() {
  Fila *fi = (Fila *)malloc(sizeof(Fila));
  if (fi != NULL) {
    fi->final = NULL;
    fi->inicio = NULL;
    fi->qtd = 0;
  }
  return fi;
}

void libera_Fila(Fila *fi) {
  if (fi != NULL) {
    Elem *no;
    while (fi->inicio != NULL) {
      no = fi->inicio;
      fi->inicio = fi->inicio->prox;
      free(no);
    }
    free(fi);
  }
}

// Permite: consultar quem será o próximo
int consulta_Fila(Fila *fi, struct pessoa *pes) {
  if (fi == NULL)
    return 0;
  if (fi->inicio == NULL)
    return 0;
  *pes = fi->inicio->dados;
  return 1;
}

int insere_Fila(Fila *fi, struct pessoa pes) {
  if (fi == NULL)
    return 0;
  Elem *no = (Elem *)malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = pes;
  no->prox = NULL;
  if (fi->final == NULL)
    fi->inicio = no;
  else
    fi->final->prox = no;
  fi->final = no;
  fi->qtd++;
  return 1;
}

// Permite: chamar a próxima pessoa (remover da fila)
int remove_Fila(Fila *fi) {
  if (fi == NULL)
    return 0;
  if (fi->inicio == NULL)
    return 0;
  Elem *no = fi->inicio;
  fi->inicio = fi->inicio->prox;
  if (fi->inicio == NULL)
    fi->final = NULL;
  free(no);
  fi->qtd--;
  return 1;
}

int tamanho_Fila(Fila *fi) {
  if (fi == NULL)
    return 0;
  return fi->qtd;
}

int Fila_vazia(Fila *fi) {
  if (fi == NULL)
    return 1;
  if (fi->inicio == NULL)
    return 1;
  return 0;
}

int Fila_cheia(Fila *fi) {
  return 0;
}

void imprime_Fila(Fila *fi) {
  if (fi == NULL || fi->inicio == NULL) {
    printf("\n[ Fila de espera vazia. ]\n");
    return;
  }
  Elem *no = fi->inicio;
  printf("\n=== PESSOAS AGUARDANDO ATENDIMENTO ===\n");
  while (no != NULL) {
    printf("Senha: %d\n", no->dados.senha);
    printf("Nome: %s\n", no->dados.nome);
    printf("Horario de Entrada: %s\n", no->dados.horario_entrada);
    printf("-------------------------------\n");
    no = no->prox;
  }
}

int main() {
  Fila *fila_atendimento = cria_Fila();
  int opcao;
  struct pessoa nova_pessoa;

  do {
    printf("\n--- SISTEMA DE ATENDIMENTO ---\n");
    printf("1. Adicionar pessoa a fila (Gerar Senha)\n");
    printf("2. Chamar proxima pessoa\n");
    printf("3. Consultar quem sera o proximo\n");
    printf("4. Mostrar toda a fila\n");
    printf("5. Informar quantas pessoas aguardam\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); // Limpa buffer do teclado

    switch (opcao) {
    case 1:
      printf("Digite o numero da senha: ");
      scanf("%d", &nova_pessoa.senha);
      getchar();
      printf("Digite o nome da pessoa: ");
      fgets(nova_pessoa.nome, 50, stdin);
      nova_pessoa.nome[strcspn(nova_pessoa.nome, "\n")] = '\0';
      printf("Digite o horario de entrada (ex: 14:30): ");
      fgets(nova_pessoa.horario_entrada, 10, stdin);
      nova_pessoa.horario_entrada[strcspn(nova_pessoa.horario_entrada, "\n")] = '\0';

      if (insere_Fila(fila_atendimento, nova_pessoa))
        printf("Pessoa adicionada a fila com sucesso!\n");
      else
        printf("Erro ao alocar memoria.\n");
      break;

    case 2:
      if (consulta_Fila(fila_atendimento, &nova_pessoa)) {
        printf("\n[ CHAMANDO: Senha %d - %s ]\n", nova_pessoa.senha, nova_pessoa.nome);
        remove_Fila(fila_atendimento);
      } else {
        printf("Nao ha ninguem na fila para chamar.\n");
      }
      break;

    case 3:
      if (consulta_Fila(fila_atendimento, &nova_pessoa)) {
        printf("\nProximo a ser chamado:\nSenha: %d\nNome: %s\nHorario: %s\n",
               nova_pessoa.senha, nova_pessoa.nome, nova_pessoa.horario_entrada);
      } else {
        printf("Fila vazia. Nao ha proximo.\n");
      }
      break;

    case 4:
      imprime_Fila(fila_atendimento);
      break;

    case 5:
      printf("\nTotal de pessoas aguardando: %d\n", tamanho_Fila(fila_atendimento));
      break;

    case 0:
      printf("Encerrando o sistema...\n");
      break;

    default:
      printf("Opcao invalida.\n");
    }
  } while (opcao != 0);

  libera_Fila(fila_atendimento);
  return 0;
}

// Um sistema de atendimento exige um critério de justiça cronológica, onde a ordem de chegada determina a ordem de serviço. A estrutura de fila atende perfeitamente a esse requisito por seguir a lógica FIFO (First-in, First-out): a primeira pessoa que entra na estrutura (chega no local) é obrigatoriamente a primeira a ser removida (atendida).

// Se utilizássemos uma pilha, a política seria LIFO (Last-In, First-Out), o que significaria que a última pessoa a chegar e retirar uma senha passaria na frente de todos os outros.

// DISCLAIMER: parte do códido fonte foi inspirado no código do curso "Estrutura de Dados em Linguagem C" do Prof. Dr. André Beckes, do canal "Programação Descomplicada | Linguagem C".