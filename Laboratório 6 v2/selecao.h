#ifndef SELECAO_H_INCLUDED
#define SELECAO_H_INCLUDED

#include "geracao.h"

void selecao(int *vetor, int tamanho)
{
    for (int cont1 = 0; cont1 < (tamanho - 1); cont1++)
    {
        int menor = cont1;

        for (int cont2 = (cont1 + 1); cont2 < tamanho; cont2++)
        {
            if (vetor[menor] > vetor[cont2])
            {
                menor = cont2;
            }
        }

        swap1(&vetor[menor], &vetor[cont1]);
    }
}

#endif // SELECAO_H_INCLUDED
