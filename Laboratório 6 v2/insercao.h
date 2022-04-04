#ifndef INSERCAO_H_INCLUDED
#define INSERCAO_H_INCLUDED

#include "geracao.h"

void insercao(int *vetor, int tamanho)
{
    for (int cont1 = 1; cont1 < tamanho; cont1++)
    {
        int temp = vetor[cont1];
        int cont2 = (cont1 - 1);

        while ((cont2 >= 0) && (vetor[cont2] > temp))
        {
            vetor[cont2 + 1] = vetor[cont2];
            cont2--;
        }

        vetor[cont2 + 1] = temp;
    }
}

#endif // INSERCAO_H_INCLUDED
