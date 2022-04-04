#ifndef MARGESORT_H_INCLUDED
#define MARGESORT_H_INCLUDED

#include <stdlib.h>

#include "geracao.h"

void mergesort(int *vetor, int n)
{
   mergesortRec(vetor, 0, n-1);
}

void mergesortRec(int *vetor, int esq, int dir)
{
    if (esq < dir)
    {
        int meio = (esq + dir) / 2;

        mergesortRec(vetor, esq, meio);
        mergesortRec(vetor, meio + 1, dir);

        intercalar(vetor, esq, meio, dir);
    }
}

void intercalar(int* vetor, int esq, int meio, int dir)
{
   int n1, n2, i, j, k;

   //Definir tamanho dos dois subarrays
   n1 = meio-esq+1;
   n2 = dir - meio;

   int* a1 = (int*) malloc((n1+1) * sizeof(int));
   int* a2 = (int*) malloc((n2+1) * sizeof(int));

   //Inicializar primeiro subarray
   for(i = 0; i < n1; i++){
      a1[i] = vetor[esq+i];
   }

   //Inicializar segundo subarray
   for(j = 0; j < n2; j++){
      a2[j] = vetor[meio+j+1];
   }

   //Sentinela no final dos dois arrays
   a1[i] = a2[j] = 0x7FFFFFFF;

   //Intercalacao propriamente dita
   for(i = j = 0, k = esq; k <= dir; k++){
      vetor[k] = (a1[i] <= a2[j]) ? a1[i++] : a2[j++];
   }

   free(a1);
   free(a2);
}

#endif // MARGESORT_H_INCLUDED
