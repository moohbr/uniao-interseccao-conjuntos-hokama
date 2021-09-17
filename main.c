#include <stdio.h>
#include <stdlib.h>

//Implemente as funcoes necessarias


//NAO ALTERE A MAIN
int main(int argc, char * argv[]){
  int* A;
  int* B;
  int* C;
  int* D;
  int nA, nB, nC, nD, aux;
  
  //inicializando e lendo o conjunto A
  scanf("%d", &nA);
  A = iniciaVetor(nA);
  for(int i = 0; i < nA; i++){
    scanf("%d", &aux);
    A[i] = aux;
  }
  
  //inicializando e lendo o conjunto B
  scanf("%d", &nB);
  B = iniciaVetor(nB);
  for(int i = 0; i < nB; i++){
    scanf("%d", &aux);
    B[i] = aux;
  }
  
  //calcula e imprime a uniao e a interseccao
  C = uniao(A, nA, B, nB, &nC);
  imprimeConjunto(C, nC);
  
  D = interseccao(A, nA, B, nB, &nD);
  imprimeConjunto(D, nD);
  
  //libera a memoria dos 4 vetores
  liberaConjunto(A); 
  liberaConjunto(B); 
  liberaConjunto(C); 
  liberaConjunto(D); 

  return 0;
}
