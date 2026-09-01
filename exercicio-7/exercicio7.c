/*
7. Gerenciador de lista de tarefas

Crie um programa que utilize uma estrutura de dados do tipo lista para armazenar tarefas.

O programa deverá permitir:

adicionar tarefa;

- listar tarefas;

- buscar uma tarefa;

- alterar uma tarefa;

- remover uma tarefa;

- informar a quantidade total de tarefas.

Desafio adicional: permita marcar uma tarefa como concluída.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tarefa {
  int id;
  char objetivo[100];
  bool estaConcluida;
};

typedef struct elemento *Lista;

struct elemento {
  struct tarefa dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

Lista *cria_lista() {
  Lista *li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL)
    *li = NULL;
  return li;
}

void libera_lista(Lista *li) {
  if (li != NULL) {
    Elem *no;
    while ((*li) != NULL) {
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}

int consulta_lista_id(Lista *li, int id, struct tarefa *al) {
  if (li == NULL)
    return 0;
  Elem *no = *li;
  while (no != NULL && no->dados.id != id) {
    no = no->prox;
  }
  if (no == NULL)
    return 0;
  else {
    *al = no->dados;
    return 1;
  }
}

int insere_lista_ordenada(Lista *li, struct tarefa al) {
  if (li == NULL)
    return 0;
  Elem *no = (Elem *)malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = al;
  if ((*li) == NULL) {
    no->prox = NULL;
    *li = no;
    return 1;
  } else {
    Elem *ant, *atual = *li;
    while (atual != NULL && atual->dados.id < al.id) {
      ant = atual;
      atual = atual->prox;
    }
    if (atual == *li) {
      no->prox = (*li);
      *li = no;
    } else {
      no->prox = atual;
      ant->prox = no;
    }
    return 1;
  }
}

int remove_lista(Lista *li, int id) {
  if (li == NULL || (*li) == NULL)
    return 0;
  Elem *ant, *no = *li;
  while (no != NULL && no->dados.id != id) {
    ant = no;
    no = no->prox;
  }
  if (no == NULL)
    return 0;

  if (no == *li)
    *li = no->prox;
  else
    ant->prox = no->prox;
  free(no);
  return 1;
}

int tamanho_lista(Lista *li) {
  if (li == NULL)
    return 0;
  int cont = 0;
  Elem *no = *li;
  while (no != NULL) {
    cont++;
    no = no->prox;
  }
  return cont;
}

int alterar_tarefa(Lista *li, int id, char *novo_objetivo) {
  if (li == NULL)
    return 0;
  Elem *no = *li;
  while (no != NULL && no->dados.id != id) {
    no = no->prox;
  }
  if (no == NULL)
    return 0;

  strcpy(no->dados.objetivo, novo_objetivo);
  return 1;
}

int concluir_tarefa(Lista *li, int id) {
  if (li == NULL)
    return 0;
  Elem *no = *li;
  while (no != NULL && no->dados.id != id) {
    no = no->prox;
  }
  if (no == NULL)
    return 0;

  no->dados.estaConcluida = true;
  return 1;
}

void imprime_lista(Lista *li) {
  if (li == NULL || *li == NULL) {
    printf("\n[ Nenhuma tarefa cadastrada. ]\n");
    return;
  }
  Elem *no = *li;
  printf("\n=== LISTA DE TAREFAS ===\n");
  while (no != NULL) {
    printf("ID: %d\n", no->dados.id);
    printf("Tarefa: %s\n", no->dados.objetivo);
    printf("Status: %s\n", no->dados.estaConcluida ? "[X] Concluida" : "[ ] Pendente");
    printf("-------------------------------\n");
    no = no->prox;
  }
}

int main() {
  Lista *li = cria_lista();
  int opcao, id_busca;
  struct tarefa nova_task;

  do {
    printf("\n--- GERENCIADOR DE TAREFAS ---\n");
    printf("1. Adicionar Tarefa\n");
    printf("2. Listar Tarefas\n");
    printf("3. Buscar Tarefa por ID\n");
    printf("4. Alterar Tarefa\n");
    printf("5. Remover Tarefa\n");
    printf("6. Ver Total de Tarefas\n");
    printf("7. Marcar como Concluida (Desafio)\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); // Limpa o buffer do teclado

    switch (opcao) {
    case 1:
      printf("Digite o ID da tarefa: ");
      scanf("%d", &nova_task.id);
      getchar();
      printf("Digite a descricao: ");
      fgets(nova_task.objetivo, 100, stdin);
      nova_task.objetivo[strcspn(nova_task.objetivo, "\n")] = '\0'; // Remove o \n do final
      nova_task.estaConcluida = false;

      if (insere_lista_ordenada(li, nova_task))
        printf("Tarefa adicionada com sucesso!\n");
      else
        printf("Erro ao adicionar.\n");
      break;

    case 2:
      imprime_lista(li);
      break;

    case 3:
      printf("Digite o ID para buscar: ");
      scanf("%d", &id_busca);
      if (consulta_lista_id(li, id_busca, &nova_task)) {
        printf("\nTarefa Encontrada:\nID: %d\nDescricao: %s\nStatus: %s\n",
               nova_task.id, nova_task.objetivo, nova_task.estaConcluida ? "Concluida" : "Pendente");
      } else {
        printf("Tarefa nao encontrada.\n");
      }
      break;

    case 4:
      printf("Digite o ID da tarefa que deseja alterar: ");
      scanf("%d", &id_busca);
      getchar();
      printf("Digite a nova descricao: ");
      char nova_desc[100];
      fgets(nova_desc, 100, stdin);
      nova_desc[strcspn(nova_desc, "\n")] = '\0';

      if (alterar_tarefa(li, id_busca, nova_desc))
        printf("Tarefa alterada com sucesso!\n");
      else
        printf("Tarefa nao encontrada.\n");
      break;

    case 5:
      printf("Digite o ID da tarefa para remover: ");
      scanf("%d", &id_busca);
      if (remove_lista(li, id_busca))
        printf("Tarefa removida com sucesso!\n");
      else
        printf("Tarefa nao encontrada.\n");
      break;

    case 6:
      printf("\nQuantidade total de tarefas: %d\n", tamanho_lista(li));
      break;

    case 7:
      printf("Digite o ID da tarefa concluida: ");
      scanf("%d", &id_busca);
      if (concluir_tarefa(li, id_busca))
        printf("Tarefa marcada como concluida!\n");
      else
        printf("Tarefa nao encontrada.\n");
      break;

    case 0:
      printf("Saindo...\n");
      break;

    default:
      printf("Opcao invaliva.\n");
    }
  } while (opcao != 0);

  libera_lista(li);
  return 0;
}

// OBS: Para esse desafio, foi implementado uma lista encadeada dinâmica.
// Ela foi escolhida invés de uma lista estática, pois na estática é necessário utilizar um tamanho fixo
// para a lista na declaração da mesma, o que não é necessário na dinâmica.

// DISCLAIMER: parte do códido fonte foi inspirado no código do curso "Estrutura de Dados em Linguagem C" do Prof. Dr. André Beckes, do canal "Programação Descomplicada | Linguagem C".