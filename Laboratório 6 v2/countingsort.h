#ifndef COUTINGSORT_H_INCLUDED
#define COUTINGSORT_H_INCLUDED

#include "geracao.h"
#include "countingsort.h"

int getMaior(int *vetor, int n)
{
    int maior = vetor[0];

    for (int i = 0; i < n; i++)
    {
        if(maior < vetor[i])
        {
            maior = vetor[i];
        }
    }

    return maior;
}

void countingsort(int *vetor, int n)
{
    //Array para contar o numero de ocorrencias de cada elemento
    int tamCount = getMaior(vetor, n) + 1;
    int counting[tamCount];
    int ordenado[n];

    //Inicializar cada posicao do vetor de contagem
    for (int i = 0; i < tamCount; counting[i] = 0, i++);

    //Agora, o counting[i] contem o numero de elemento iguais a i
    for (int i = 0; i < n; counting[vetor[i]]++, i++);

    //Agora, o counting[i] contem o numero de elemento menores ou iguais a i
    for(int i = 1; i < tamCount; counting[i] += counting[i-1], i++);

    //Ordenando
    for(int i = n-1; i >= 0; ordenado[counting[vetor[i]]-1] = vetor[i], counting[vetor[i]]--, i--);

    //Copiando para o vetor original
    for(int i = 0; i < n; vetor[i] = ordenado[i], i++);
}

#endif // COUTINGSORT_H_INCLUDED
