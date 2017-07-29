/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: DOGLAS ANDRÉ FINCO
 ALUNO: FELIPE AUGUSTO DA SILVA
 EMAIL: felipeaugustosilva94@gmail.com
 DESENVOLVIDO NO AMBIENTE LINUX */

/*TRABALHO 7 - BUSCA BINARIA */

#include <stdlib.h>
#include <stdio.h>

//Declaração das funções
void Insertion_Sort ( int v[], int num );
void Busca_Binaria ( int v[], int inicio, int fim, int p );



//Função Principal
int main() {

  int vetor[10], i, p;

  printf("Insira os valores no vetor:\n" );
  for(i = 0; i < 10; i++){
    printf("Posição %d: ", i );
    scanf(" %d", &vetor[i] );
  }

  Insertion_Sort ( vetor, 10);

  //Printa os elementos
  for(i = 0; i < 10; i++){
    printf(" %d", vetor[i] );
  }
  printf("\n" );

  printf("Qual elemento deseja buscar: " );
  scanf(" %d", &p );

  Busca_Binaria( vetor, 0, 9, p);

  return 0;
}


//Função para ordernar elementos dentro do vetor
void Insertion_Sort ( int v[], int num ) {
  int i, j, aux;

  for(i = 1; i < num; i++ ){
    aux = v[i];
    for(j = i; (j > 0) && (aux < v[j - 1]); j--){
      v[j] = v[j - 1];
    }
    v[j] = aux;
  }
}

//Função que busca o elemento no vetor
void Busca_Binaria ( int v[], int inicio, int fim, int p ) {

  int meio;
  static int cont = 0;

  meio = ((fim - inicio) / 2);
  meio = (meio + inicio);

  if( v[meio] == p ) {

    printf("Elemento encontrado na posição: %d\n", meio );

  } else {

    if( meio != 0 && cont < 4){
      cont++;

      if( v[meio] > p ) {

        Busca_Binaria ( v, inicio, meio, p );

      } else {

        Busca_Binaria ( v, meio, fim, p);

      }
    } else {

      printf("Elemento não encontrado\n" );

    }
  }

}
