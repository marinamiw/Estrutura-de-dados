#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int dado;
    struct no *proxNo;
}TipoNo;

typedef struct lista{
    TipoNo *inicio;
    TipoNo *final;
    int tamanho;
}TipoLista;

void inicializaLista(TipoLista *lista){
    lista->inicio = NULL;
    lista->final = NULL;
    lista->tamanho = 0;
}

bool insereListaVazia(TipoLista *lista, int valor){ // caso a lista esteja vazia ele insere um elemento
    TipoNo *NovoNo;
    NovoNo = (TipoNo*) malloc(sizeof(NovoNo));
    
    if (NovoNo == NULL){
        return false;
    }

    NovoNo->dado = valor;
    NovoNo->proxNo = NULL;
    lista->inicio = NovoNo;
    lista->final = NovoNo;
    lista->tamanho++;
    return true;
}


bool insereInicio(TipoLista *lista, int valor){
    TipoNo *NovoNo;
    NovoNo = (TipoNo*) malloc(sizeof(NovoNo));

    if(NovoNo == NULL){
        return false;
    }

    if(lista->inicio == NULL){
        insereListaVazia(lista,valor);
    }

    NovoNo->dado = valor;
    NovoNo->proxNo = lista->inicio;
    lista->inicio = NovoNo;
    lista->tamanho++;
    return true;
}

bool insereFinal(TipoLista *lista, int valor){
    TipoNo *NovoNo;
    NovoNo = (TipoNo*) malloc(sizeof(TipoNo));
    
    if (NovoNo == NULL){
        return false;
    }

    if(lista->inicio == NULL){
        insereListaVazia(lista, valor);
        return true;
    }

    NovoNo->dado = valor;
    NovoNo->proxNo = NULL;
    lista->final->proxNo = NovoNo;
    lista->final = NovoNo;
    lista->tamanho++;
    return true;
}

void exibeLista(TipoLista *lista){
    TipoNo *atual;
    if(lista->inicio == NULL){
        printf("A lista esta vazia.");
        exit(0);
    }
    atual = lista->inicio;
    while(atual != NULL){
        printf("%d",atual->dado);
        atual = atual->proxNo;
    }
}

bool removerInicio(TipoLista *lista){
    
    if(lista->inicio == NULL){
        printf("A lista esta vazia.");
        return false;
    }

    TipoNo *AntigoInicio;
    AntigoInicio = lista->inicio;
    lista->inicio = lista->inicio->proxNo;
    free(AntigoInicio);
    lista->tamanho--;
    return true;
}

bool removerFinal(TipoLista *lista){
    
    if (lista->inicio == NULL){
        printf("a lista esta vazia");
        return false;
    }

    TipoNo *anterior;
    anterior = lista->final;
    anterior->proxNo = NULL;
    free(lista->final);
    lista->tamanho--;
    return true;

}

bool buscaLista(TipoLista *lista, int posicao){
    TipoNo *atual;
    atual = lista->inicio;
    int contador = 0;
    while(atual != NULL){
        if(contador == posicao){
            printf("Posicao encontrada. Seu valor é: %d",atual->dado);
            return true;
        }
        atual = atual->proxNo;
        contador++;
    }
}

bool inserirNaPos(TipoLista *lista, int posicao, int valor){

    TipoNo *NovoNo;
    NovoNo = (TipoNo*) malloc(sizeof(TipoNo));
    TipoNo *atual;
    TipoNo *anterior;
    atual = lista->inicio;
    anterior = NULL;
    NovoNo->dado = valor;
    int contador = 1;

    if(posicao < 0 || posicao > lista->tamanho){
        printf("posicao invalida. insira outra");
        return false;
    }


    if(NovoNo == NULL){
        return false;
    }

    if(lista->inicio == NULL){
        insereListaVazia(lista, valor);
        return true;
    }

    if (posicao == 0){
        insereInicio(lista,valor);
    }
    
    while(atual != NULL && contador < posicao){
        anterior = atual;
        atual = atual->proxNo;
        contador++;
        }

    if(contador == posicao){
        NovoNo->proxNo = atual;
        anterior->proxNo = NovoNo;
        lista->tamanho++;
        return true;
    }

    free(NovoNo);
    return false;
}

bool removerNaPos(TipoLista *lista, int pos,int valor){

    TipoNo *atual,*anterior;

    if(lista->inicio == NULL){
        return false;
    }

    if(pos < 0 || pos >= lista->tamanho){
        printf("posicao invalida");
        return false;
    }

    if(pos == 0){
        removerInicio(lista);
        return true;
    }

    atual = lista->inicio;
    anterior = NULL;
    int contador = 0;
    while (atual != NULL && contador < pos){
        anterior = atual;
        atual = atual->proxNo;
        contador++;
    }

    if(atual == NULL){
        return false;
    }


    if(contador == pos){
        anterior->proxNo = atual->proxNo;
        free(atual);
        lista->tamanho--;
        return true;
    }

return false;
}

bool destruirlista(TipoLista *lista){

    if (lista->inicio == NULL){
        printf("A lista ta vazia");
        return false;
    }

    TipoNo *atual;
    TipoNo *prox;
    atual = lista->inicio;
    
    while(atual != NULL){
        prox = atual->proxNo;
        free(atual);
        atual = prox;
    }
    
    lista->inicio = NULL;
    lista->tamanho = 0;
    return true;
}

bool insereOrdenado(TipoLista *lista, int valor){

    TipoNo *novoNo;
    novoNo = (TipoNo*) malloc(sizeof(TipoNo));
    
    if(novoNo == NULL){
        return false;
    }

    novoNo->dado = valor;
    TipoNo *atual, *anterior;
    atual = lista->inicio;
    anterior = NULL;
    
    if(valor < atual->dado){
        insereInicio(lista,valor);
        return true;
    }

    while(atual->dado < valor && atual->proxNo != NULL){
        anterior = atual;
        atual = atual->proxNo;
    }
    if(atual->dado > novoNo->dado){
        anterior->proxNo = novoNo;
        novoNo->proxNo = atual;
        lista->tamanho++;

    }
    else{
        insereFinal(lista,valor);
    }
return true;
}




int main(){

    TipoLista lista;
    inicializaLista(&lista);
    int opcao, pos, valor;


do {
        printf("\nO que deseja fazer?");
        printf("\n1- Adicionar valor");
        printf("\n2- Remover valor");
        printf("\n3- Destruir lista");
        printf("\n4- Buscar por posição");
        printf("\n5- Exibir lista");
        printf("\n6- Sair");
        printf("\nDigite sua opção: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                printf("\nDigite o valor que deseja adicionar: ");
                scanf("%d", &valor);
                printf("\nDigite a posição onde deseja adicionar: ");
                scanf("%d", &pos);
                if (inserirNaPos(&lista, pos, valor)) {
                    printf("\nValor adicionado com sucesso!");
                } else {
                    printf("\nErro ao adicionar valor.");
                }
                break;

            case 2:
                printf("\nDigite a posição do valor que deseja remover: ");
                scanf("%d", &pos);
                if (removerNaPos(&lista, pos, valor)) {
                    printf("\nValor removido com sucesso!");
                } else {
                    printf("\nErro ao remover valor.");
                }
                break;

            case 3:
                if (destruirlista(&lista)) {
                    printf("\nLista destruída com sucesso!");
                } else {
                    printf("\nErro ao destruir a lista ou a lista já está vazia.");
                }
                break;

            case 4:
                printf("\nDigite a posição que deseja buscar: ");
                scanf("%d", &pos);
                if (!buscaLista(&lista, pos)) {
                    printf("\nPosição não encontrada.");
                }
                break;

            case 5:
                printf("\nLista: ");
                exibeLista(&lista);
                break;

            case 6:
                printf("\nSaindo...");
                break;

            default:
                printf("\nOpção inválida!");
                break;
        }
    } while (opcao != 6);



    getchar();
    getchar();


    return 0;
}
