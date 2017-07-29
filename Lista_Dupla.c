/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: DOGLAS ANDRÉ FINCO
 ALUNO: FELIPE AUGUSTO DA SILVA
 EMAIL: felipeaugustosilva94@gmail.com
 DESENVOLVIDO NO AMBIENTE LINUX */

/*TRABALHO - LISTA DUPLAMENTE ENCADEADA */

#include <stdlib.h>
#include <stdio.h>
#define TAM 50

//Declaração de estrutura Produto
typedef struct produto {
 int cod;
 char nome[TAM];
 float preco;

} tp_produto;

//Declaração de estrutura da Lista
typedef struct nodo {
  tp_produto produto;
  struct nodo *next;
  struct nodo *prev;

} tp_nodo;

//Declaração de estrutura da Cabeça da Lista
typedef struct lista {
  int nItens;
  tp_nodo *first;
  tp_nodo *last;

} tp_lista;

//Declaração de Funções
tp_nodo *push_inicio ( tp_nodo *lista, tp_lista *cabeca );
tp_nodo *push_fim ( tp_nodo *lista, tp_lista *cabeca );
tp_nodo *pop ( tp_lista *cabeca );
void display ( tp_lista *cabeca );

//Função Principal
int main () {
  int n;

  //Alocando Dinaicamente Cabeça da lista
  tp_lista *cabeca = ( tp_lista* ) malloc(sizeof(tp_lista));

  if(cabeca == NULL) {
    printf("Memoria insufiente\n" );
    return 0;
  }

  cabeca->nItens = 0;
  cabeca->first = NULL;
  cabeca->last = NULL;

tp_nodo *lista = NULL;

 //Menu Principal
  while ( 1 ) {
    printf("\n        Menu Principal\n\n");

    printf("1 - Inserir no inicio da lista\n" );
    printf("2 - Inserir no fim da lista\n" );
    printf("3 - Remover produtos da lista\n" );
    printf("4 - Imprimir produtos da lista\n" );
    printf("0 - Para finalizar o programa\n" );
    printf("Digite uma opção: ");
    scanf(" %d", &n );

    switch ( n ) {
      case 1:
        lista = push_inicio ( lista, cabeca );
      break;

      case 2:
        lista = push_fim ( lista, cabeca );
      break;

      case 3:
        lista = pop ( cabeca );
      break;


      case 4:
        display ( cabeca );
      break;

      case 0:
        return 0;
      break;

      default:
        printf("Opção Invalida\n");
      break;
    }
  }
}

//Função de inserção no inicio
tp_nodo *push_inicio ( tp_nodo *lista, tp_lista *cabeca ) {
  tp_nodo *novo;

  novo = ( tp_nodo *) malloc(sizeof(tp_nodo));

  if(novo == NULL) {
    printf("Memoria insufiente\n" );
    exit (1);
  }

  printf("\nCódigo do produto: " );
  scanf(" %d", &novo->produto.cod);

  printf("Nome do produto: " );
  scanf(" %49[^\n]", novo->produto.nome );

  printf("Preço do produto: " );
  scanf(" %f", &novo->produto.preco );

  if( cabeca->nItens == 0 ) {
    cabeca->first = novo;
    cabeca->last = novo;
    novo->next = NULL;
    novo->prev = NULL;
    cabeca->nItens++;
  } else {
    cabeca->first = novo;
    novo->next = lista;
    novo->prev = NULL;
    lista->prev = novo;
    cabeca->nItens++;
  }

return novo;
}

//Função de inserção no fim
tp_nodo *push_fim ( tp_nodo *lista, tp_lista *cabeca ){
  tp_nodo *novo;

  novo = ( tp_nodo *) malloc(sizeof(tp_nodo));

  if(novo == NULL) {
    printf("Memoria insufiente\n" );
    exit (1);
  }

  printf("\nCódigo do produto: " );
  scanf(" %d", &novo->produto.cod);

  printf("Nome do produto: " );
  scanf(" %49[^\n]", novo->produto.nome );

  printf("Preço do produto: " );
  scanf(" %f", &novo->produto.preco );

  if( cabeca->nItens == 0 ) {
    cabeca->first = novo;
    cabeca->last = novo;
    novo->next = NULL;
    novo->prev = NULL;
    cabeca->nItens++;
  } else {
    novo->next = NULL;
    novo->prev = cabeca->last;
    cabeca->last->next = novo;
    cabeca->last = novo;
    cabeca->nItens++;
  }

return cabeca->first;
}


//Função para excluir elemestos da lista
tp_nodo *pop ( tp_lista *cabeca ) {
  tp_nodo *aux = cabeca->first, *prev = NULL, *next = NULL;
  int elem;

  if( cabeca->first == NULL ) {
    printf("\nLista não possui elemestos\n" );
    return cabeca->first;

  }

  printf("\nCodigo do elemento que deseja excluir: " );
  scanf(" %d", &elem );

  while ( aux != NULL) {
    if( aux->produto.cod == elem ){
      break;
    } else {
      if( aux->produto.cod != elem && aux->next == NULL ) {
        break;
      }
    }

    prev = aux;
    aux = aux->next;
    next = aux->next;
  }

  if( aux->produto.cod != elem && aux->next == NULL){
    printf("\nElemento não encontrado na lista\n" );
  } else {
    if( prev == NULL ){
      cabeca->first = cabeca->first->next;
      printf("\nElemento excluido da lista\n" );
      cabeca->nItens--;

    } else {
      if( next == NULL ) {
        prev->next = NULL;
        cabeca->last = prev;
        printf("\nElemento excluido da lista\n" );
        cabeca->nItens--;

      } else {
        if(aux != NULL) {
          prev->next = aux->next;
          printf("\nElemento excluido da lista\n" );
          cabeca->nItens--;

        }
      }
    }
  }

return cabeca->first;
}


//Função para exibir elemestos da lista
void display ( tp_lista *cabeca ) {
  tp_nodo *aux = cabeca->first, *prox = NULL;

  if ( aux == NULL) {
    printf("\nLista não possui elementos\n" );
    return;
  }

  while ( aux != NULL ) {
    printf("\nCodigo: %d\n", aux->produto.cod );
    printf("Produto: %s\n", aux->produto.nome );
    printf("Preço: %.2f\n", aux->produto.preco );

    prox = aux->next;
    aux = prox;
  }
}
