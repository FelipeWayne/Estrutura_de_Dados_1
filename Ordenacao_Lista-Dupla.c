/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: DOGLAS ANDRÉ FINCO
 ALUNO: FELIPE AUGUSTO DA SILVA
 EMAIL: felipeaugustosilva94@gmail.com
 DESENVOLVIDO NO AMBIENTE LINUX */

/*TRABALHO 6 - MÉTODOS DE ORDENAÇÃO EM LISTA DUPLAMENTE ENCADEADA */

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
void Menu_Secundario ( tp_nodo *lista, tp_lista *cabeca );
tp_nodo *Insertion_Sort ( tp_lista *cabeca );
tp_nodo *Selection_Sort ( tp_lista *cabeca );


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
    printf("5 - Ordenar\n" );
    printf("0 - Para finalizar o programa\n" );
    printf("Digite uma opção: ");
    scanf(" %d", &n );

    //Função executa comando Clear para limpar a tela
    system("clear");

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

      case 5:
        Menu_Secundario ( lista, cabeca );
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

//Menu Secundario
void Menu_Secundario ( tp_nodo *lista, tp_lista *cabeca ) {
  int k;

  printf("\n        Menu Secundario\n\n");

  printf("1 - Ordenar via Insertion Sort\n" );
  printf("2 - Ordenar via Selection Sort\n" );
  printf("3 - Ordenar via Quick Sort\n" );
  printf("4 - Ordenar via Merge Sort\n" );
  printf("5 - Voltar ao Menu Principal\n" );
  printf("Digite uma opção: ");
  scanf(" %d", &k );

  switch ( k ) {
    case 1:
      lista = Insertion_Sort ( cabeca);
    break;

    case 2:
      lista = Selection_Sort ( cabeca );
    break;

    case 3:
    break;

    case 4:
    break;

    case 5:
      //Finaliza a função Menu_Secundario
      system("clear");
    break;

    default:
      printf("Opção Invalida\n");
    break;
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

  //Percorre a lista até encontrar o elemento
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

  //Quando o elemento não é encontrado na lista
  if( aux->produto.cod != elem && aux->next == NULL){
    printf("\nElemento não encontrado na lista\n" );
  } else {
    //Quando o elemento é o primeiro item da lista
    if( prev == NULL ){
      cabeca->first = cabeca->first->next;
      printf("\nElemento excluido da lista\n" );
      cabeca->nItens--;

    } else {
      //Quando o elemento é o ultimo item da lista
      if( next == NULL ) {
        prev->next = NULL;
        cabeca->last = prev;
        printf("\nElemento excluido da lista\n" );
        cabeca->nItens--;

      } else {
        //Quando o elemento está no meio da lista
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
  //int cont = 0;

  if ( aux == NULL) {
    printf("\nLista não possui elementos\n" );
    return;
  }

  while ( aux != NULL ) {
    /*if(cont == cabeca->nItens){
      break;
    }*/
    printf("\nCodigo: %d\n", aux->produto.cod );
    printf("Produto: %s\n", aux->produto.nome );
    printf("Preço: %.2f\n", aux->produto.preco );

    prox = aux->next;
    aux = prox;
  //cont++;
  }
}


//Função para Ordenar elementos via Selection Sort
tp_nodo *Selection_Sort ( tp_lista *cabeca ){
  tp_nodo *aux, *aux2, *troca, *menor, *ant, *dep, *ant2, *dep2;
  int i;

  //Verifica se a lista possui elemestos para Ordenar
  if( cabeca->first == NULL || cabeca->nItens < 2 ) {

    printf("\nLista não possui elemestos para Ordenar\n" );

  } else {

    for(aux = cabeca->first; aux->next != NULL; aux = aux->next){

      for(aux2 = aux->next; aux2 != NULL; aux2 = aux2->next){

        i = aux->produto.cod;

        //Verifica se os elementos são iguais
        if( i == aux2->produto.cod){
          aux2 = aux2->next;
        }

        //Faz a verificação se o elemento é menor antes de fazer a troca
        if(i > aux2->produto.cod){

          //Definindo as variaveis auxiliares
          troca = aux;
          menor = aux2;

          ant = aux->prev;
          dep = aux->next;

          ant2 = aux2->prev;
          dep2 = aux2->next;

          //Verificações para localizar elementos da lista que serão trocados

          //Trata o caso de apenas dois elementos na lista
          if( aux->prev == NULL && aux2->next == NULL && cabeca->nItens == 2 ) {

            aux->next = NULL;
            aux->prev = aux2;
            aux2->next = aux;
            aux2->prev = NULL;

            cabeca->first = aux2;
            cabeca->last = aux;

            aux2 = troca;
            aux = menor;


          } else {

            //Quando é o primeiro e o ultimo elemento da lista
            if(aux->prev == NULL && aux2->next == NULL){

              aux->next = dep2;
              aux->prev = ant2;
              ant2->next = aux;

              aux2->next = dep;
              dep->prev = aux2;
              aux2->prev = ant;

              cabeca->first = aux2;
              cabeca->last = aux;

              aux2 = troca;
              aux = menor;


            } else {

              //Quando é o primeiro da lista e troca pelo proximo
              if( aux->prev == NULL && aux->next == aux2 ) {

                aux->next = dep2;
                aux->prev = aux2;

                dep2->prev = aux;
                aux2->next = aux;
                aux2->prev = NULL;

                cabeca->first = aux2;

                aux2 = troca;
                aux = menor;


              } else {

                //Quando é o primeiro da lista e troca por um no meio da lista
                if( aux->prev == NULL && aux2->next != NULL ){

                  aux->next = dep2;
                  dep2->prev = aux;
                  aux->prev = ant2;
                  ant2->next = aux;

                  aux2->next = dep;
                  dep->prev = aux2;
                  aux2->prev = ant;

                  cabeca->first = aux2;

                  aux2 = troca;
                  aux = menor;

                } else {

                  //Quando é o ultimo da lista e troca pelo seu anterior
                  if( aux2->next == NULL && aux2->prev == aux ) {

                    aux->next = NULL;
                    aux->prev = aux2;

                    aux2->next = aux;
                    aux2->prev = ant;
                    ant->next = aux2;


                    cabeca->last = aux;

                    aux2 = troca;
                    aux = menor;



                  } else {

                    //Quando o ultimo da lista é trocado por um no meio da lista
                    if(aux->prev != NULL && aux2->next == NULL){

                      aux->next = dep2;
                      aux->prev = ant2;
                      ant2->next = aux;

                      aux2->next = dep;
                      dep->prev = aux2;
                      aux2->prev = ant;
                      ant->next = aux2;

                      cabeca->last = aux;

                      aux2 = troca;
                      aux = menor;

                    } else {

                      //Quando os dois elemestos estão em seguencia no meio da lista
                      if( aux->prev != NULL && aux2->next != NULL && aux == aux2->prev ) {

                        aux->next = dep2;
                        aux->prev = aux2;
                        dep2->prev = aux;
                        aux2->prev = aux;

                        aux2->next = aux;
                        aux2->prev = ant;
                        ant->next = aux2;

                        aux2 = troca;
                        aux = menor;

                      } else {

                        //Quando os dois elemestos estão no meio da lista e não estão em seguencia
                        if(aux->prev != NULL && aux2->next != NULL){

                          aux->next = dep2;
                          dep2->prev = aux;
                          aux->prev = ant2;
                          ant2->next = aux;

                          aux2->next = dep;
                          dep->prev = aux2;
                          aux2->prev = ant;
                          ant->next = aux2;


                          aux2 = troca;
                          aux = menor;


                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    printf("\nLista ordenada com sucesso\n" );
  }

return cabeca->first;
}

//Função para Ordenar elementos via Insertion Sort
tp_nodo *Insertion_Sort ( tp_lista *cabeca ) {
  tp_nodo *aux, *aux2, *ant, *ant2, *dep, *dep2;
  int i;


  //Verifica se a lista possui elemestos para Ordenar
  if( cabeca->first == NULL || cabeca->nItens < 2 ) {

    printf("\nLista não possui elemestos para Ordenar\n" );

  } else {

    for(aux = cabeca->first->next; aux != NULL; aux = aux->next){

      for(aux2 = cabeca->first; aux2 != aux; aux2 = aux2->next ){

        i = aux->produto.cod;

        //Trata o caso de apenas dois elementos na lista
        if( aux2->prev == NULL && aux->next == NULL && cabeca->nItens == 2 ) {

          if(i < aux2->produto.cod){

            aux2->next = NULL;
            aux2->prev = aux;
            aux->next = aux2;
            aux->prev = NULL;

            cabeca->first = aux;
            cabeca->last = aux2;

            break;
          }

        } else {

          //Trata o caso em que são os dois primeiros
          if( aux == cabeca->first->next ){

            //Definindo as variaveis auxiliares
            dep = aux->next;

            if(i < aux2->produto.cod){

              aux->prev = NULL;
              aux->next = aux2;

              dep->prev = aux2;
              aux2->next = dep;
              aux2->prev = aux;

              cabeca->first = aux;

              aux = aux2;

              break;

            }

          } else {

            if(i < aux2->produto.cod) {


              //Definindo as variaveis auxiliares

              ant = aux->prev;
              dep = aux->next;

              ant2 = aux2->prev;
              dep2 = aux2->next;

              //Troca o primeiro elemento pelo ultimo da lista
              if(i < aux2->produto.cod && aux2->prev == NULL && aux->next == NULL) {

                ant->next = NULL;
                aux->prev = NULL;

                aux->next = aux2;
                aux2->prev = aux;

                cabeca->last = ant;
                cabeca->first = aux;

                break;

              } else {

                //Se o elemento for menor que o primeiro da lista
                if(i < aux2->produto.cod && aux2->prev == NULL) {

                  ant->next = dep;
                  dep->prev = ant;

                  aux->next = aux2;
                  aux2->prev = aux;
                  aux->prev = NULL;

                  cabeca->first = aux;

                  aux = ant;

                  break;


                } else {

                  //Se o elemento for menor no meio da lista e Troca não é o ultimo elemento
                  if(i > aux2->prev->produto.cod && i < aux2->produto.cod && aux->next != NULL) {

                    ant->next = dep;
                    dep->prev = ant;

                    ant2->next = aux;
                    aux2->prev = aux;
                    aux->next = aux2;
                    aux->prev = ant2;

                    aux = ant;

                    break;

                  } else {

                    //Se o elemento for menor no meio da lista e Troca é o ultimo elemento
                    if( i > aux2->prev->produto.cod && i < aux2->produto.cod && aux->next == NULL ) {

                      ant->next = NULL;

                      ant2->next = aux;
                      dep2->prev = aux;
                      aux->next = dep;
                      aux->prev = ant;

                      cabeca->last = ant2;

                      break;

                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    printf("\nLista ordenada com sucesso\n" );

  }

return cabeca->first;
}
