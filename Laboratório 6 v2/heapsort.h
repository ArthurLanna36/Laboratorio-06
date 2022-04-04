#ifndef HEADSORT_H_INCLUDED
#define HEADSORT_H_INCLUDED

#include <stdint.h>
#include <stdlib.h>

#include "geracao.h"

void constroi(uint64_t *vetor, uint64_t tamHeap)
{
    for(uint64_t i = tamHeap; i > 1 && vetor[i] > vetor[i/2]; i /= 2)
    {
        swap2(vetor + i, vetor + i/2);
    }
}

int getMaiorFilho(uint64_t *vetor, uint64_t i, uint64_t tamHeap)
{
    uint64_t filho;

    if (2*i == tamHeap || vetor[2*i] > vetor[2*i+1])
    {
        filho = 2*i;
    }
    else
    {
        filho = 2*i + 1;
    }

    return filho;
}

void reconstroi(uint64_t *vetor, uint64_t tamHeap)
{
    uint64_t i = 1;

    while(i <= (tamHeap/2))
    {
        int filho = getMaiorFilho(vetor, i, tamHeap);
        if(vetor[i] < vetor[filho])
        {
            swap2(vetor + i, vetor + filho);
            i = filho;
        }
        else
        {
            i = tamHeap;
        }
    }
}

void heapsort(uint64_t *vetor, uint64_t n)
{
    //Alterar o vetor ignorando a posicao zero
    uint64_t *arrayTmp = malloc((n+1)*sizeof(uint64_t));

    for(uint64_t i = 0; i < n; i++)
    {
        arrayTmp[i+1] = vetor[i];
    }

    //Contrucao do heap
    for(uint64_t tamHeap = 2; tamHeap <= n; tamHeap++)
    {
        constroi(arrayTmp, tamHeap);
    }

    //Ordenacao propriamente dita
    uint64_t tamHeap = n;

    while(tamHeap > 1)
    {
        swap2(arrayTmp + 1, arrayTmp + tamHeap--);
        reconstroi(arrayTmp, tamHeap);
    }

    //Alterar o vetor para voltar a posicao zero
    for(uint64_t i = 0; i < n; i++)
    {
        vetor[i] = arrayTmp[i+1];
    }

    free(arrayTmp);
}

#endif // HEADSORT_H_INCLUDED
