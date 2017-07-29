/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: DOGLAS ANDRÉ FINCO
 ALUNO: FELIPE AUGUSTO DA SILVA
 EMAIL: felipeaugustosilva94@gmail.com
 DESENVOLVIDO NO AMBIENTE LINUX */

/*TRABALHO - LISTA SIMPLESMENTE ENCADEADA */

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
 struct nodo *prox;

} tp_nodo;

//Declaração de Funções
tp_nodo *push ( tp_nodo *lista );
void display ( tp_nodo *lista );
tp_nodo *pop ( tp_nodo *lista );


//Função Principal
int main () {
  int n;
  tp_nodo *lista = NULL;

  while ( 1 ) {
    printf("\n        Menu Principal\n\n");

    printf("1 - Inserir produtos na lista\n" );
    printf("2 - Remover produtos da lista\n" );
    printf("3 - Imprimir produtos da lista\n" );
    printf("0 - Para finalizar o programa\n" );
    printf("Digite uma opção: ");
    scanf(" %d", &n );

    switch ( n ) {
      case 1:
        lista = push ( lista );
      break;

      case 2:
        lista = pop ( lista );
      break;

      case 3:
        display ( lista );
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

//Função para inserir elementos na lista
tp_nodo *push ( tp_nodo *lista ) {
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

  novo->prox = lista;

return novo;
}

//Função para exibir elementos da lista
void display ( tp_nodo *lista ) {
  tp_nodo *aux = lista, *prox = NULL;

  if ( lista == NULL) {
    printf("\nLista não possui elementos\n" );
    return;

  }

  while ( aux != NULL ) {
    printf("\nCodigo: %d\n", aux->produto.cod );
    printf("Produto: %s\n", aux->produto.nome );
    printf("Preço: %.2f\n", aux->produto.preco );

    prox = aux->prox;
    aux = prox;
  }
}

//Função para excluir elemestos da lista
tp_nodo *pop ( tp_nodo *lista ) {
  tp_nodo *aux = lista , *ant = NULL;
  int elem;

  if( lista == NULL ) {
    printf("\nLista não possui elemestos\n" );
    return lista;

  }

  printf("\nCodigo do elemento que deseja excluir: " );
  scanf(" %d", &elem );

  while ( aux != NULL) {
    if( aux->produto.cod == elem ){
      break;
    }
    ant = aux;
    aux = aux->prox;
  }

  if( aux == NULL){
    printf("\nElemento não encontrado na lista\n" );
  }

  if( ant == NULL ){
    lista = lista->prox;
    printf("\nElemento excluido da lista\n" );

  } else {
    if(aux != NULL) {
      ant->prox = aux->prox;
      printf("\nElemento excluido da lista\n" );
      free(aux);
    }
  }

return lista;
}
