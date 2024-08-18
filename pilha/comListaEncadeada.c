#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No{

    int dado;
    struct No *proxNo;

}No;


No* criarNo(int valor){
    
    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo == NULL){
        printf("erro ao alocar memoria");
        exit(1);
    }

    novoNo->dado = valor;
    novoNo->proxNo = NULL;
    return novoNo;

}

void push(No **topo, int valor){ //empilhar - o ultimo elemento adicionado é o topo
    
    No *novoNo = criarNo(valor);
    novoNo->proxNo = *topo;
    *topo = novoNo;
    printf("%d empilhado na pilha",valor);
}

// desempilhar
int pop(No **topo){
    
    if(*topo == NULL){
        printf("a pilha esta vazia!");
        exit(1);
    }

    // queremos remover o ultimo no adicionado, isto é, o o topo, e definir o que vem depois como o novo topo
    No *aux;
    aux = *topo; //criamos um no auxiliar para guardar onde o topo esta
    int popped = aux->dado; //guardamos em outra variavel o valor do topo
    *topo = (*topo)->proxNo; //passamos o topo para o proximo nó
    free(aux);//removemos o topo original 
    return popped; //retornar o valor do que foi removido

}

int peek(No *topo){ //retornar valor do topo
    if(topo == NULL){
        printf("lista vazia");
        return -1;
    }
   
    return (topo)->dado;
    
}




int main() {
    int opcao;
    No* topo = NULL;  // Inicializando o topo da pilha como NULL
    int valor;

    do {
        printf("\nOla, o que deseja fazer?\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Verificar o topo\n");
        printf("4 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);  // Corrigido o scanf para pegar o endereço de opcao

        switch (opcao) {
            case 1:
                printf("Qual valor deseja empilhar? ");
                scanf("%d", &valor);  // Corrigido o scanf para pegar o endereço de valor
                push(&topo, valor);
                break;
            case 2:
                valor = pop(&topo);
                if (valor != -1)
                    printf("%d desempilhado da pilha\n", valor);
                break;
            case 3:
                valor = peek(topo);
                if (valor != -1)
                    printf("Elemento do topo: %d\n", valor);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida, tente novamente!\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}