#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED

#include "geracao.h"

void insercaoPorCor(int *vetor, int n, int cor, int h)
{
    for(int i = (h + cor); i < n; i+=h)
    {
        int tmp = vetor[i];
        int j = i - h;

        while ((j >= 0) && (vetor[j] > tmp))
        {
            vetor[j + h] = vetor[j];
            j-=h;
        }
        vetor[j + h] = tmp;
    }
}

void shellsort(int *vetor, int n)
{
    int h = 1;

    do
    {
        h = (h * 3) + 1;
    }
    while (h < n);

    do
    {
        h /= 3;
        for(int cor = 0; cor < h; cor++)
        {
            insercaoPorCor(vetor, n, cor, h);
        }
    }
    while (h != 1);
}

#endif // SHELLSORT_H_INCLUDED
