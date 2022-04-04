#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include <stdio.h>

#include "geracao.h"

void quicksortRec(int *vetor, int esq, int dir)
{
    int i = esq, j = dir;
    int pivo = vetor[(dir+esq)/2];

    while(i <= j)
    {
        while(vetor[i] < pivo) i++;
        while(vetor[j] > pivo) j--;

        if(i <= j)
        {
            swap1(vetor + i, vetor + j);
            i++;
            j--;
        }
    }

    if(esq < j)
    {
        quicksortRec(vetor, esq, j);
    }

    if(i < dir)
    {
        quicksortRec(vetor, i, dir);
    }
}

void quicksort(int *vetor, int n)
{
    quicksortRec(vetor, 0, n-1);
}

#endif // QUICKSORT_H_INCLUDED
