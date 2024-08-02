#include <stdio.h>
#include <stdbool.h>
//Exemplo de Lista Encadeada usando nó cabeça

typedef struct no{
int dado;
struct no *proxNo;
}tipoNo;

typedef struct listaGerenciada{
  tipoNo *inicio;
  tipoNo *fim;
  int quant;
  }tipoLista;

void inicializa(tipoLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quant = 0;
}


bool removerNoInicio(tipoLista *lista){


    if (lista->inicio == NULL)
        return false;


    // definir o que é anterior (ele ira guardar o primeiro nó de fato)

    tipoNo* noAnterior = lista->inicio;
    //agora o inicio sera o proximo no q veio dps dele. 
    lista->inicio = lista->inicio->proxNo; //agora define que o inicio eh o segundo elemento
    free(noAnterior); //limpo o no anterior que guardava o primeiro no, removendo ele da lista.
    lista->quant--;
    return true;
    
}

bool removerNoFinal(tipoLista*lista){

    if(lista->inicio == NULL)
        return false;

    tipoNo* anterior;
    anterior->proxNo = NULL; //guarda um valor para ser o novo 'ultimo' ,uma vez que o ultimo nó for apagado. o ultimo valor sempre aponta para o nulo.
   
    free(lista->fim); //apaga o ultimo No de fato
    lista->fim = anterior; //atualiza o ponteiro final da lista para o no que foi guardado, tornando ele o ultimo
    lista->quant--;
    return true;

}

void destruir(tipoLista*lista){

    if(lista->inicio == NULL)
        return;
    
    tipoNo* atual = lista->inicio;
   
    while(atual != NULL) //lista percorrida ate que o atual seja nulo,indicando seu fim
    {
        tipoNo* prox = atual->proxNo; //guardando o proximo
        free(atual); //limpando o atual
        atual = prox; //passando para o proximo
    }
    printf("Lista destruída com sucesso");
    lista->inicio = NULL;
    lista->quant = 0;

}


int buscarItem(tipoNo* item, tipoLista*lista){

    tipoNo* atual = lista->inicio;
    tipoNo* anterior = NULL;

int i = 0;

    while(atual != NULL){

        if (atual->dado == item){
            printf("item encontrado na posicao %d\n",i);   //se o dado do nó atual corresponder ao valor interessado, ok
        }
        
        anterior = atual;
        atual = atual->proxNo;
        
        i++;
    }
    
    if (atual == NULL){
        printf("Nao existe esse item na lista dada");
    }
    
}

bool RemoverPosicao(tipoNo *posicao, tipoLista*lista){

    if (lista->inicio == NULL){
        return false;
    }
    
    int i = 0; //contador para acompanhar a posiçao no loop
    tipoNo *atual = lista->inicio;
    tipoNo *anterior = NULL;
    
    while(atual != NULL){
       
        if(i == posicao){
            anterior->proxNo = atual->proxNo;  // como estamos removendo um nó, precisamos que o anterior desse nó agora aponte para o próximo desse nó, uma vez que deixaria um 'vacuo' entre eles qd removido
            free(atual);
            printf("item removido com sucesso na posicao dada");
            return true;
        }
        anterior = atual;
        atual = atual->proxNo;
        i++;
    }
    lista->quant--;
}


bool inserirPosicao(tipoNo *posicao, tipoLista *lista){

     if (lista->inicio == NULL){
        return false;
    }

    int i = 0;
    tipoNo *atual = lista->inicio;
    tipoNo *anterior = NULL;

    while(atual != NULL){

        if (i == posicao){
            posicao->proxNo = atual; // quando o nó for inserido na posicao desejada, queremos que o nó novo aponte para o no q estava na posicao anteriormente 
                                            // e o anterior desse mesmo no aponte para o no inserido e nao mais para o antigo
            anterior->proxNo = posicao;
            return true;
            printf("Item adicionado com sucesso na posicao");
        }
        anterior = atual;
        atual = atual->proxNo;
        i++;
    }
    lista->quant++;

}


int insereListaVazia(tipoLista *lista, int valor){
tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
if(novoNo == NULL)
    return 0;
novoNo->dado = valor;
novoNo->proxNo = NULL;
lista->inicio = novoNo;
lista->fim = novoNo;
lista->quant++;
}

int insereNaFrente(tipoLista *lista, int valor){
tipoNo *novoNo;
if(lista->inicio == NULL)
    insereListaVazia(&lista ,valor);
else{
    novoNo = (tipoNo*)malloc(sizeof(tipoNo));
    if(novoNo==NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = lista->inicio;
    lista->inicio = novoNo;
    return 1;
}
}

/*Fun��o de exibi��o da lista simplesmente encadeada*/
int exibeLista(tipoLista *lista){
tipoNo *atual;  //Vari�vel que ser� usada para percorrer a lista*/
if(lista->inicio == NULL)
    return 0;
atual = lista->inicio;
printf("\nLista encadeada: ");
while(atual !=NULL){
    printf("%8d",atual->dado);
    atual = atual->proxNo;
    }
return 1;
}

void main(){
tipoLista lista;
inicializa(&lista);
int leitor;
printf("Digite um elemento: ");
scanf("%d",&leitor);
int resp = insereListaVazia(&lista, leitor);

if(!resp)
   printf("Memoria nao alocada!");
printf("Elemento guardado: %d",lista.inicio->dado);

printf("\nDigite outro elemento: ");
scanf("%d",&leitor);
resp = insereNaFrente(&lista,leitor);
exibeLista(&lista);

printf("Digite uma lista: ");
scanf("%d",&lista);
resp = removerNoInicio(&lista);

printf("Digite uma lista: ");
scanf("%d",&lista);
resp = removerNoFinal(&lista);

printf("Digite uma lista: ");
scanf("%d",&lista);
destruir(&lista);

printf("Digite um valor que deseja buscar: ");
scanf("%d",&leitor);
resp = buscarItem(leitor,&lista);

printf("Digite uma posicao que deseja inserir na lista: ");
scanf("%d",&leitor);
resp = inserirPosicao(leitor,&lista);

printf("Digite uma posicao que deseja remover da lista: ");
scanf("%d",&leitor);
resp = RemoverPosicao(leitor,&lista);


}
