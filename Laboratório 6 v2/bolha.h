#include <stdio.h>
#include <locale.h>

#include "geracao.h"

#ifndef BOLHA_H_INCLUDED
#define BOLHA_H_INCLUDED

void bolha(int *vetor, int tamanho)
{
    setlocale(LC_ALL, "Portuguese");

    int cont1, cont2;
    int trocas = 0, comparacoes = 0;

    for (cont1 = (tamanho - 1); cont1 > 0; cont1--)
    {
        for (cont2 = 0; cont2 < cont1; cont2++)
        {
            comparacoes++;

            if (vetor[cont2] > vetor[cont2 + 1])
            {
                trocas++;
                swap1(&vetor[cont2], &vetor[cont2 + 1]);
            }
        }
    }

    //printf("Comparações: %i; Trocas: %i; ", comparacoes, trocas);
}

#endif // BOLHA_H_INCLUDED

