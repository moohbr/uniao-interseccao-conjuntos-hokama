#include <stdio.h>
#include <stdlib.h>

int* iniciaVetor(int size){
  int* vector = (int *) malloc(size * sizeof(int));

  return vector;
}

void imprimeConjunto(int* vector, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", vector[i]);
	}
  printf("\n");
}

void sort(int* vector, int sizeV){
  int j, last_element = 0;

  for(int i = 0; i < sizeV; i++){
    last_element = vector[i];
    j = i - 1;

    while((j >= 0) && (vector[j] > last_element)){
      vector[j + 1] = vector[j];
      j -= 1;
    }

    vector[j + 1] = last_element;
  }
}


void removeDuplicatedElements(int *vector, int *size){
  sort(vector, *size);

  for(int i = 0; i < *size; i++){
    for(int j = i + 1; j < *size; j++){
      if(vector[j] == vector[i]){
        for(int k = j; k < *size; k++){
          vector[k] = vector[k + 1];
        }

        (*size)--;
        j--;
      }
    }
  }
}

/* void tryRealloc(int* vector, int size){
  long* errorFlag;
  do{
    errorFlag = realloc(*vector, size  * sizeof(int));
  }
  while (errorFlag == NULL);
} */

int* interseccao(int* vectorA, int sizeA, int* vectorB, int sizeB, int *sizeC){
  int z = 0;
  (*sizeC) = sizeA + sizeB;
  int* vectorAux = iniciaVetor(*sizeC);
  for(int i = 0; i < sizeA; i++){
    for (int k = 0; k < sizeB; k++){
      if(vectorA[i] == vectorB[k]){
        vectorAux[z] = vectorB[k];
        z ++;
        break;
      }
    }
  }
  (*sizeC) = z;
  sort(vectorAux, *sizeC);
  return vectorAux;
}

int* uniao(int* vectorA, int sizeA, int* vectorB, int sizeB, int* sizeC){
  removeDuplicatedElements(vectorA, &sizeA);
  removeDuplicatedElements(vectorB, &sizeB);

  int sizeAux = sizeA + sizeB;

  int* vectorAux = iniciaVetor(sizeAux);
  
  int i;

  for(i = 0; i < sizeA; i++){
    vectorAux[i] = vectorA[i];
  }

  for(int j = 0; j < sizeB; j++){
    vectorAux[i + j] = vectorB[j];
  }

  removeDuplicatedElements(vectorAux, &sizeAux);

  *sizeC = sizeAux;

  return vectorAux;
}

void liberaConjunto(int* vector){
  free(vector);
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