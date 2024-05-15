#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef int ITEM;

// struct da lista 
typedef struct {
    ITEM *itens;
    long tamanho;
    long capacidade;
} LISTA;


int buscarEm(ITEM item, int inicio, int fim, LISTA *l)
{
    for(int pos = inicio; pos < fim; pos++){
       if(l->itens[pos] == item){
        return pos;
       }
    }
    return -1;
}

int main()
{
    int i, N;
    printf("Qual item voce deseja buscar? ");
    scanf("%d", &i);

    printf("Tamanho da lista: ");
    scanf("%d", &N);

    LISTA l;
    l.itens = (int*)malloc(N * sizeof(int));
    l.tamanho = N;
    l.capacidade = N;

    printf("Digite os numeros: ");
    for(int j = 0; j < N; j++){
        scanf("%d", &l.itens[j]);
    }


    int inicio = 0;
    int fim = l.tamanho - 1;

    int posicao = buscarEm(i, inicio, fim, &l);
    
    printf("Posicao do item: %d\n", posicao);

    free(l.itens);  // Free allocated memory
    return 0;
}
