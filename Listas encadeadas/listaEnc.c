#include <stdio.h>
#include <stdbool.h>
//Exemplo de Lista Encadeada usando n� cabe�a

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


bool removerNoInicio(tipoNo dado, tipoLista *lista){


    if (lista->inicio == NULL)
        return false;


    // definir o que é anterior (ele ira guardar o primeiro nó de fato)

    tipoNo* noAnterior = lista->inicio;
    //agora o inicio sera o proximo no q veio dps dele. 
    lista->inicio = lista->inicio->proxNo; //agora defini que o inicio eh o segundo elemento
    free(noAnterior); //limpo o no anterior que guardava o primeiro no, removendo ele da lista.
    lista->quant--;
    return true;
    
}

bool removerNoFinal(tipoNo dado, tipoLista*lista){

    if(lista->inicio == NULL)
        return false;

    tipoNo* anterior;
    anterior->proxNo = NULL; //o no seguinte do penultimo no deve ser nulo para que ele seja o ultimo no.
    free(lista->fim);
    lista->fim = anterior; //atualiza o ponteiro final da lista para o penultimo no
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

    lista->inicio = NULL;
    lista->quant = 0;

}


int buscarItem(tipoNo* item, tipoLista*lista){


    tipoNo* atual = lista->inicio;

    while(atual != NULL){

        if (atual = item){
            return atual;
        }

        atual = atual->proxNo;


    }


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

}
