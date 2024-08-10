#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct No{

    char *nome;
    struct No *prox;

}TipoNo;

typedef struct ListaGerenciada{

    TipoNo *inicio;
    TipoNo *final;
    int tamanho;

}TipoLista;

void InicializaLista(TipoLista *lista){
   
    lista->inicio = NULL;
    lista->final = NULL;
    lista->tamanho = 0;

}

TipoNo *CriarNo(char *nome, TipoNo *prox){

    TipoNo *p = (TipoNo*)malloc(sizeof(TipoNo));

    if(p == NULL){
        printf("NAO FOI POSSIVEL CRIAR ESSE NO");
        exit(EXIT_FAILURE);
    }
 
    p->nome = (char*)malloc(strlen(nome) + 1);
    strcpy(p->nome,nome);
    p->prox = prox;
    

    return p;

}


bool inserirNo(char *nome, TipoLista *l){ //inserindo no inicio da lista 

    TipoNo *q = CriarNo(nome, l->inicio);
    
    if(l->tamanho == 0){

        l->inicio = q;
        l->final = q;
        q->prox = q;

    }

    else{
        q->prox = l->inicio;
        l->final->prox = q;
        l->inicio = q;
    }

     l->tamanho++;
    return true;

}

TipoNo *posicaoNo(int posicao, TipoLista *l){
    if (posicao < 0 || posicao >= l->tamanho) {
        printf("POSICAO INVALIDA\n");
        return NULL;
    }

    int i = 0;
    TipoNo *p = l->inicio;
    do {
        if (i == posicao) {
            return p;
        }
        p = p->prox;
        i++;
    } while (p != l->inicio);

    return NULL;
}


char *removerNo(char *nome, TipoLista *l){
    if (l->tamanho == 0) {
        return NULL;
    }

    TipoNo *anterior = l->final;
    TipoNo *atual = l->inicio;

    do {
        if (strcmp(atual->nome, nome) == 0) {
            anterior->prox = atual->prox;
            if (atual == l->inicio) {
                l->inicio = atual->prox;
            }
            if (atual == l->final) {
                l->final = anterior;
            }
            char *NoRemovido = atual->nome;
            free(atual);
            l->tamanho--;
            return NoRemovido;
        }
        anterior = atual;
        atual = atual->prox;
    } while (atual != l->inicio);

    return NULL;
}


char *removerPosicao(int posicao, TipoLista *l){
    TipoNo *p = posicaoNo(posicao, l);
    if (p != NULL) {
        return removerNo(p->nome, l);
    }
    return NULL;
}

void imprimirLista(TipoLista *l) {
    if (l->tamanho == 0) {
        printf("A lista está vazia.\n");
        return;
    }

    TipoNo *p = l->inicio;
    do {
        printf("%s, ", p->nome);
        p = p->prox;
    } while (p != l->inicio);
    printf("\n");
}

int main(){


    TipoLista lista;
    InicializaLista(&lista);

    int n;
    char nome[50];
    
    printf("Bem vindo ao sorteio da nossa Agencia de viagens! \n");

    printf("Quantos participantes deseja adicionar? ");
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        printf("Digite o nome: ");
        scanf("%s",nome);
        inserirNo(nome,&lista);
    }

    printf("Participantes iniciais: ");
    imprimirLista(&lista);

    srand(time(NULL));  

    while (lista.tamanho > 1) {
        int m = rand() % lista.tamanho; 
        char *nomeRemovido = removerPosicao(m, &lista);
        printf("Numero sorteado: %d\n", m);
        printf("Removido: %s\n", nomeRemovido);
        printf("Participantes restantes: ");
        imprimirLista(&lista);
        free(nomeRemovido);  
    }

    if (lista.tamanho == 1) {
        printf("Vencedor: %s\n", lista.inicio->nome);
    }

   
    while (lista.tamanho > 0) {
        free(removerPosicao(0, &lista)); 
    }

    getchar();
    getchar();

    return 0;
}
     
