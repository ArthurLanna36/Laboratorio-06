#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <locale.h>

//Bibliotecas para medir gasto de tempo e processamento para funcionamento dos algoritmos de ordenação:
#include <windows.h>
#include <winbase.h>
#include <psapi.h>
#include <time.h>

//Algoritmos de ordenação:
#include "bolha.h"
#include "countingsort.h"
#include "heapsort.h"
#include "insercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selecao.h"
#include "shellsort.h"

double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));

    return (double)info.PeakWorkingSetSize / (1024 * 1024);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "Portuguese");

    clock_t start_time, end_time;
    double cpu_time_used, memory_used;
    size_t peakSize;

    int tamanho;

    FILE *arquivo;

    arquivo = fopen("Dados dos Algoritmos v2.txt", "w");

    //testando se o arquivo foi realmente criado
    if(arquivo == NULL)
    {
        printf("Erro na abertura do arquivo!");

        return 1;
    }

    /*
    for(int tipo_algoritmo = 1; tipo_algoritmo <= 3; tipo_algoritmo++)
    {
        for(int tipo_geracao = 1; tipo_geracao <= 3; tipo_geracao++)
        {
            for(int cont_tamanho = 1; cont_tamanho <= 7; cont_tamanho++)
            {
                tamanho = 200 * pow(2, cont_tamanho);

                int *vetor = calloc(tamanho, sizeof(int));

                //Melhor caso:
                if(tipo_geracao == 1)
                {
                    for(int cont = 0; cont < tamanho; cont++)
                    {
                        vetor[cont] = cont;
                    }

                    if(cont_tamanho == 1)
                    {
                        printf("Geracao: crescente (melhor caso).\n");
                    }
                }
                else if(tipo_geracao == 2)
                {
                    for(int cont = 0; cont < tamanho; cont++)
                    {
                        vetor[cont] = cont;
                    }

                    srand(time(NULL));

                    for(int cont = 0; cont < tamanho; cont++)
                    {
                        swap1(&vetor[tamanho], &vetor[rand() % tamanho]);
                    }

                    if(cont_tamanho == 1)
                    {
                        printf("Geracao: aleatoria (caso medio).\n");
                    }
                }
                else if(tipo_geracao == 3)
                {
                    for(int cont = 0; cont < tamanho; cont++)
                    {
                        vetor[cont] = (tamanho - cont);
                    }

                    if(cont_tamanho == 1)
                    {
                        printf("Geracao: decrescente (pior caso).\n");
                    }
                }

                if(tipo_algoritmo == 1)
                {
                    start_time = clock();

                    bolha(vetor, tamanho);

                    end_time = clock();

                    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                    memory_used = get_memory_used_MB();

                    if(cont_tamanho == 1)
                    {
                        printf("Algoritmo: bolha.\n\n");
                    }
                }
                else if(tipo_algoritmo == 2)
                {
                    start_time = clock();

                    selecao(vetor, tamanho);

                    end_time = clock();

                    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                    memory_used = get_memory_used_MB();

                    if(cont_tamanho == 1)
                    {
                        printf("Algoritmo: selecao.\n\n");
                    }
                }
                else if(tipo_algoritmo == 3)
                {
                    start_time = clock();

                    insercao(vetor, tamanho);

                    end_time = clock();

                    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                    memory_used = get_memory_used_MB();

                    if(cont_tamanho == 1)
                    {
                        printf("Algoritmo: insercao.\n\n");
                    }
                }

                printf("\n");
                fprintf(arquivo, "\n");
            }
            printf("Tempo gasto: %.2lf; Memoria gasta: %.2lf\n", cpu_time_used, memory_used);
            fprintf(arquivo, "Tempo gasto: %.2lf; Memoria gasta: %.2lf\n", cpu_time_used, memory_used);

            printf("--------------------------------------------------\n\n");
            fprintf(arquivo, "--------------------------------------------------\n\n");
        }
*/
        int tipo_algoritmo = 1;
        int tipo_geracao = 3;

        for(int cont_tamanho = 1; cont_tamanho <= 7; cont_tamanho++)
        {
            tamanho = pow(2, cont_tamanho) * 600;

            int *vetor = calloc(tamanho, sizeof(int));

            if(tipo_geracao == 1)
            {
                for(int cont = 0; cont < tamanho; cont++)
                {
                    vetor[cont] = cont;
                }

                if(cont_tamanho == 1)
                {
                    printf("Geracao: crescente (melhor caso).\n");
                }
            }
            else if(tipo_geracao == 2)
            {
                for(int cont = 0; cont < tamanho; cont++)
                {
                    vetor[cont] = cont;
                }

                srand(time(NULL));

                for(int cont = 0; cont < tamanho; cont++)
                {
                    swap1(&vetor[cont], &vetor[rand() % tamanho]);
                }

                if(cont_tamanho == 1)
                {
                    printf("Geracao: aleatoria (caso medio).\n");
                }
            }
            else if(tipo_geracao == 3)
            {
                for(int cont = 0; cont < tamanho; cont++)
                {
                    vetor[cont] = (tamanho - 1 - cont);
                }

                if(cont_tamanho == 1)
                {
                    printf("Geracao: decrescente (pior caso).\n");
                }
            }

            if(tipo_algoritmo == 1)
            {
                start_time = clock();

                bolha(vetor, tamanho);

                end_time = clock();

                cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                memory_used = get_memory_used_MB();

                if(cont_tamanho == 1)
                {
                    printf("Algoritmo: bolha.\n\n");
                }
            }
            else if(tipo_algoritmo == 2)
            {
                start_time = clock();

                selecao(vetor, tamanho);

                end_time = clock();

                cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                memory_used = get_memory_used_MB();

                if(cont_tamanho == 1)
                {
                    printf("Algoritmo: selecao.\n\n");
                }
            }
            else if(tipo_algoritmo == 3)
            {
                start_time = clock();

                insercao(vetor, tamanho);

                end_time = clock();

                cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
                memory_used = get_memory_used_MB();

                if(cont_tamanho == 1)
                {
                    printf("Algoritmo: insercao.\n\n");
                }
            }

            printf("Tempo gasto: %.2lf; Memoria gasta: %.2lf\n", cpu_time_used, memory_used);
            fprintf(arquivo, "Tempo gasto: %.2lf; Memoria gasta: %.2lf\n", cpu_time_used, memory_used);
        }


        fclose(arquivo);

        return 0;
    }

