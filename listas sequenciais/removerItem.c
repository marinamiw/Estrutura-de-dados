#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef int ITEM;

// struct da lista 
typedef struct{
    ITEM **itens;
    long tamanho;
    long capacidade;
} LISTA ;
////////////////



bool removerDaPos(ITEM *item, int i, LISTA *l){

    if(i < 0  || i >= l->tamanho){  //se a posicao for menor q 0 ou maior q o tamanho da lista em si, a posicao nao existe
        return false; //posicao invalida
    }

    *item = *(l->itens[i]); // copia o item q quer ser removido no parametro



}
