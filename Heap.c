#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 100

int totalElementos = 0;

int indeceFilhoE(int x)
{
    int indice = (2*x)+1;

    if(x >= totalElementos || indice >= totalElementos)
    {
        return -1;
    }
    else 
        return indice;
}

int indeceFilhoD(int x)
{
    int indice = (2*x)+2;

    if(x>=totalElementos || indice >= totalElementos)
    {
        return -1;
    }
    else 
        return indice;
}

int indicePai(int x)
{
    int indice = (int) floor((x-1)/2);

    if (x <= 0 || x >= totalElementos)
    {
        return -1;
    }
    else
        return indice;
}

void AjustaSubindo(int *heap, int pos)
{
    if(pos != -1)
    {
        int pai = indicePai(pos);
        if(pai != -1)
        {
            if(heap[pos] > heap [pai])
            {
                int aux = heap[pos];
                heap[pos] = heap[pai];
                heap[pai] = aux;
                AjustaSubindo(heap, pai);
            }
        }
    }
}

void AjustaDescendo(int *heap, int pos)
{
    if(pos != -1 && indeceFilhoE(pos) != -1)
    {
        int indiceMaiorFilho = indeceFilhoE(pos);
        if(indeceFilhoD(pos) != -1 && heap[indeceFilhoD(pos)] > heap[indiceMaiorFilho])
        {
            indiceMaiorFilho = indeceFilhoD(pos);
        }
        if(heap[indiceMaiorFilho] > heap[pos])
        {
            int aux = heap[pos];
            heap[pos] = heap[indiceMaiorFilho];
            heap[indiceMaiorFilho] = aux;
            AjustaDescendo(heap, indiceMaiorFilho);
        }
    }
}

void InserirHeap(int *heap, int x)
{
    heap[totalElementos] = x;
    totalElementos++;

    AjustaSubindo(heap, totalElementos-1);
}

int RemoveHeap(int *heap)
{
    if(totalElementos == 0){
        return -1;
    }
    else
    {
        int retorno = heap[0];
        heap[0] = heap[totalElementos-1];
        totalElementos--;
        AjustaDescendo(heap, 0);
        return retorno;
    }
}

void ImprimirHeap(int *heap)
{
    for(int i =0; i < totalElementos; i++)
    {
        printf("%d-", heap[i]);
    }
    printf("\n\n");
}

int main()
{
    int heap[MAX];

    int aux =0;

    while(aux != 4)
    {
        int valor;
        printf("1-Inserir\n2-Remover\n3-Imprimir\n4-Sair\n");
        scanf("%d", &aux);
        switch(aux)
        {
            case 1:
                printf("Valor:");
                scanf("%d", &valor);
                InserirHeap(heap, valor);
                break;
            case 2:
                printf("\nNumero Removido: %d\n\n", RemoveHeap(heap));
                break;
            case 3:
                ImprimirHeap(heap);
                break;
        }
    }
}