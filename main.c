#include <stdio.h>
#include <stdlib.h>

int iniciaVetor(int size){
  int *vector = (int *) malloc(size*sizeof(int));
  return &vector;
}

void sort(*vector, sizeV){
  int j, last_element = 0;
  for(int i = 0, i < sizeV, i++){
    last_element = vector[i];
    j = i - 1;
    while((j >= 0) && (vector[j] > last_element)){
      vector[j + 1] = vector[j];
      j -= 1;
    }
    vector[j + 1] = last_element;
  }
}

int interseccao(vectorA, sizeA, vectorB, sizeB, *sizeC){
  int z = 0;
  vectorAux = iniciaVetor(*sizeC);
  for(int i = 0; i < sizeA, i++){
    for (int k = 0; k < sizeB, k++){
      if(vectorA[i] == vectorB[k]){
        * sizeC += 1;
        vectorAux = realloc(vectorAux, *sizeC);
        vectorAux[z] = vectorA[i];
        z ++;
      }
    }
  }
  sort(&vectorAux, sizeC);
  return vectorAux;
}

void remove_duplicated_elements(*vectorA, *sizeA){
  for(i = 0; i < sizeA; i++){
    for(j = i + 1; j < sizeA; ){
      if( vetorA[j] == vetorA[i] ){
        for( k = j; k < sizeA; k++ ){
          vetorA[k] = vetorA[k + 1]
          sizeA--;
        }
      else{
        j++;
      }
      }
    }
  }
}

int uniao(vectorA, sizeA, vectorB, sizeB, *sizeC){
  vectorA = sort(vectorA, sizeA);
  vectorB = sort(vectorB, sizeB);
  remove_duplicated_elements(&vectorA, &sizeA);
  remove_duplicated_elements(&vectorB, &sizeB);
  int sizeAux = sizeA + sizeB;
  vectorAux =  iniciaVetor(sizeAux);
  int i = 0;
  for(i = 0, i < sizeA, i++){
    vectorAux[i] = vectorA[i];
  }
  for(k = 0, k < sizeB, k++){
    vectorAux[i + 1] = vectorB[k];
    i++;
  }
  sort(vectorAux, sizeC);
  return vectorAux;
}

void liberaConjunto(*vector){
  free(*vector);
}

int main(int argc, char * argv[]){
  int* A;
  int* B;
  int* C;
  int* D;
  int nA, nB, nC, nD, aux;
  
  scanf("%d", &nA);
  A = iniciaVetor(nA);
  for(int i = 0; i < nA; i++){
    scanf("%d", &aux);
    A[i] = aux;
  }
  
  scanf("%d", &nB);
  B = iniciaVetor(nB);
  for(int i = 0; i < nB; i++){
    scanf("%d", &aux);
    B[i] = aux;
  }
  
  C = uniao(A, nA, B, nB, &nC);
  imprimeConjunto(C, nC);
  
  D = interseccao(A, nA, B, nB, &nD);
  imprimeConjunto(D, nD);
  
  liberaConjunto(A); 
  liberaConjunto(B); 
  liberaConjunto(C); 
  liberaConjunto(D); 

  return 0;
}
