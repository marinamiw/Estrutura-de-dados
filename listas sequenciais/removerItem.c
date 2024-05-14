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

bool removerDaPos(ITEM *item, int i, LISTA *l) {
    if (i < 0 || i >= l->tamanho) {  
        // se a posição for menor que 0 ou maior ou igual ao tamanho da lista em si, a posição não existe
        return false; // posição inválida
    }

    *item = l->itens[i]; // copia o item que quer ser removido no parâmetro, atribuindo a ele o valor do item na posição i da lista.

    for (int j = i; j < l->tamanho - 1; j++) { 
        // j começa com o valor da posição que queremos remover (i) e enquanto j for menor que o 
        // tamanho da lista - 1 (último índice válido da lista) porque os elementos começam na posição 0, a lista será percorrida
        l->itens[j] = l->itens[j + 1]; // aqui diz que o elemento na posição j terá agora o elemento que viria depois dele, 
                                       // então a lista está basicamente "adiantando" as posições para ocupar o espaço que foi removido (o item i)
    }
    
    l->tamanho--; // diminuindo o tamanho da lista em 1
    return true;
}

int main() {
    int N, i;
    printf("Qual tamanho da lista? ");
    scanf("%d", &N);

    LISTA lista; // criaçao da variavel lista num struct
    lista.itens = malloc(N * sizeof(ITEM)); // alocando dinamicamente o tamanho de itens que tera nessa lista
    lista.tamanho = N;
    lista.capacidade = N;

    printf("Digite os valores da lista: ");
    for (int j = 0; j < N; j++) {
        scanf("%d", &lista.itens[j]); // guardando os valores dos itens no loop
    }

    printf("Qual a posicao do item que voce deseja remover? ");
    scanf("%d", &i); 

    if (removerDaPos(&i, i, &lista)) {      // se for true a funçao funcionar, no caso  com o endereço da onde o item se encontra (ja q o primeiro argumento da funçao é o ponteiro
                                                                    // o item em si (posiçao dele) e o endereço da lista)
        printf("Item removido com sucesso!\n");
        for(int i = 0; i < lista.tamanho; i++){ // imprime a lista com o item removido
            printf("\n%d",lista.itens[i]);
        }
    } else {
        printf("Falha ao remover o item. A posicao nao existe na lista.\n");
    }

    // Libere a memória alocada para os itens
    free(lista.itens);

    return 0;
}


