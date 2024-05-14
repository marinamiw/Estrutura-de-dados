#include <stdio.h>
#include <stdlib.h>

void inversolista(int *lista, int tamanho){

    int *inicio = lista;
    int *final = lista + tamanho - 1;
    
    while (inicio < final){
        int temp = *inicio;
        *inicio = *final;
        *final = temp;
        
        inicio++;
        final--;

    }

}


int main(){

    int N;
    printf("qual tamanho da lista? ");
    scanf("%d",&N);

    int *numero = (int*)malloc(N * sizeof(int));

    printf("digite os numeros \n");
    
    for(int i = 0; i < N; i++){
        scanf("%d",&numero[i]);
    }
   
    inversolista(numero,N);

    printf("numeros invertidos\n");
    
    for(int i = 0; i < N; i++){
        printf("%d ",numero[i]);
        printf("\n");
    }

    free(numero);

    return 0;



}