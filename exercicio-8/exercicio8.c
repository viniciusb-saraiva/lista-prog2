/*
8. Histórico utilizando pilha

Implemente uma estrutura de pilha para representar o histórico de páginas visitadas por um usuário.

O sistema deverá permitir:
- visitar uma nova página;
- visualizar a página atual;
- voltar para a página anterior;
- exibir o histórico.

Explique por que uma pilha é adequada para esse problema.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pagina {
  char url[100];
};

// Definição do tipo Pilha
typedef struct elemento *Pilha;

struct elemento {
  struct pagina dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

Pilha *cria_Pilha() {
  Pilha *pi = (Pilha *)malloc(sizeof(Pilha));
  if (pi != NULL)
    *pi = NULL;
  return pi;
}

void libera_Pilha(Pilha *pi) {
  if (pi != NULL) {
    Elem *no;
    while ((*pi) != NULL) {
      no = *pi;
      *pi = (*pi)->prox;
      free(no);
    }
    free(pi);
  }
}

int consulta_topo_Pilha(Pilha *pi, struct pagina *pag) {
  if (pi == NULL)
    return 0;
  if ((*pi) == NULL)
    return 0;
  *pag = (*pi)->dados;
  return 1;
}

// (Operação PUSH em JS)
int insere_Pilha(Pilha *pi, struct pagina pag) {
  if (pi == NULL)
    return 0;
  Elem *no;
  no = (Elem *)malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = pag;
  no->prox = (*pi);
  *pi = no;
  return 1;
}

// Voltar para a página anterior (Operação POP em JS)
int remove_Pilha(Pilha *pi) {
  if (pi == NULL)
    return 0;
  if ((*pi) == NULL)
    return 0;
  Elem *no = *pi;
  *pi = no->prox;
  free(no);
  return 1;
}

int tamanho_Pilha(Pilha *pi) {
  if (pi == NULL)
    return 0;
  int cont = 0;
  Elem *no = *pi;
  while (no != NULL) {
    cont++;
    no = no->prox;
  }
  return cont;
}

int Pilha_cheia(Pilha *pi) {
  return 0;
}

int Pilha_vazia(Pilha *pi) {
  if (pi == NULL)
    return 1;
  if (*pi == NULL)
    return 1;
  return 0;
}

void imprime_Pilha(Pilha *pi) {
  if (pi == NULL || *pi == NULL) {
    printf("\n[ Historico vazio. ]\n");
    return;
  }
  Elem *no = *pi;
  int i = 1;
  printf("\n=== HISTORICO DE PAGINAS (Do mais recente ao mais antigo) ===\n");
  while (no != NULL) {
    printf("%d. %s\n", i++, no->dados.url);
    printf("-------------------------------\n");
    no = no->prox;
  }
}

int main() {
  Pilha *historico = cria_Pilha();
  int opcao;
  struct pagina nova_pag;

  do {
    printf("\n--- NAVEGADOR (HISTORICO PILHA) ---\n");
    printf("1. Visitar uma nova pagina\n");
    printf("2. Visualizar pagina atual\n");
    printf("3. Voltar para a pagina anterior\n");
    printf("4. Exibir o historico\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar(); // Limpa buffer do teclado

    switch (opcao) {
    case 1:
      printf("Digite a URL da pagina (ex: google.com): ");
      fgets(nova_pag.url, 100, stdin);
      nova_pag.url[strcspn(nova_pag.url, "\n")] = '\0'; // Remove o \n do final

      if (insere_Pilha(historico, nova_pag))
        printf("Pagina visitada com sucesso!\n");
      else
        printf("Erro ao alocar memoria.\n");
      break;

    case 2:
      if (consulta_topo_Pilha(historico, &nova_pag)) {
        printf("\n[ Pagina Atual: %s ]\n", nova_pag.url);
      } else {
        printf("\n[ Nenhuma pagina aberta. Tela inicial. ]\n");
      }
      break;

    case 3:
      if (Pilha_vazia(historico)) {
        printf("Nao ha paginas no historico para voltar.\n");
      } else {
        consulta_topo_Pilha(historico, &nova_pag);
        printf("Saindo de: %s...\n", nova_pag.url);

        remove_Pilha(historico);

        if (consulta_topo_Pilha(historico, &nova_pag)) {
          printf("Voltou para: %s\n", nova_pag.url);
        } else {
          printf("Voce voltou para a tela inicial em branco.\n");
        }
      }
      break;

    case 4:
      imprime_Pilha(historico);
      break;

    case 0:
      printf("Saindo do navegador...\n");
      break;

    default:
      printf("Opcao invalida.\n");
    }
  } while (opcao != 0);

  libera_Pilha(historico);
  return 0;
}

// OBS: Para esse desafio, foi implementado uma pilha dinâmica.
// A estrutura pilha é adequada para este problema pois garante LIFO (Last-in, First-out), em que o último dado inserido é obrigatoriamente o primeiro a ser removido. Tal ação é exatamante o que é preciso em um históricos de páginas na web (a última página web acessada na internet representa o estado atual da tela)

// DISCLAIMER: parte do códido fonte foi inspirado no código do curso "Estrutura de Dados em Linguagem C" do Prof. Dr. André Beckes, do canal "Programação Descomplicada | Linguagem C".