#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    char ISBN[50];
    char nomeLivro[50];
    char nomeAutor[50];
    int quantidade;
    int ano;

}Livro; //um unico livro com todas essas informaçoes devera ficar armazenado num parametro [ i]do struct biblioteca em sua lista de livros


typedef struct {
   
    Livro *livros;
    int tamanho;
    int capacidade;

}Biblioteca;

// preparar a biblioteca para iniciar 
void inicializarBiblioteca(Biblioteca *biblioteca, int capacidadeInicial){
    
    biblioteca->livros = (Livro*)malloc(capacidadeInicial * sizeof(Livro));

    biblioteca->tamanho = 0;
    
    biblioteca->capacidade = capacidadeInicial;

    if(biblioteca->livros == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }
}


void redimensionarBiblioteca(Biblioteca *biblioteca){

    biblioteca->capacidade *= 2; //aumentar a capacidade

    biblioteca->livros = (Livro*)realloc(biblioteca->livros, biblioteca->capacidade * sizeof(Livro)); //realocar a memoria para nova capacidade
    
    if(biblioteca->livros == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }

}


void adicionarLivros(Biblioteca *biblioteca, Livro livro){

    if (biblioteca->tamanho == biblioteca->capacidade){
        redimensionarBiblioteca(biblioteca);
    }

    biblioteca->livros[biblioteca->tamanho] = livro; //adicionar um livro e seus dados a um endereço de memoria da lista livros do struct biblioteca
    biblioteca->tamanho++;

}

void atualizarLivro(Biblioteca *biblioteca, Livro livro, const char *ISBN){

    int encontrado = 0;
    
    for(int i = 0; i < biblioteca -> tamanho; i++){
        
        if(strcmp(biblioteca->livros[i].ISBN,ISBN) == 0){
               
            biblioteca->livros[i] = livro;
            encontrado = 1; 
            printf("Livro atualizado!");
            break;
        }
    
    }
   
    if (!encontrado) {
        printf("Livro com ISBN %s não encontrado.\n", ISBN);
    }
}

void listarLivros(Biblioteca *biblioteca){

    if(biblioteca->tamanho == 0){
        printf("\nAinda nao ha nenhum livro cadastrado! Tente outra coisa\n");
        
        }

    else{

    for(int i =0; i < biblioteca->tamanho; i++){
    
        Livro livro = biblioteca->livros[i]; //um livro corresponde ao i armazenado na lista de livros do struct biblioteca
        printf("\n ISBN: %s \nNome: %s, \nAutor: %s, \nAno de publicacao: %d,\n Quantidade em estoque: %d\n",livro.ISBN,livro.nomeLivro,livro.nomeAutor, livro.ano, livro.quantidade);
    }
    
    }

}

void removerLivro(Biblioteca *biblioteca, const char *ISBN){;

    int encontrado = 0;
    for(int i = 0; i < biblioteca->tamanho; i++){
       
        if(strcmp(biblioteca->livros[i].ISBN,ISBN) == 0){
            encontrado = 1;

        //deslocar os itens seguintes para frente e ocupar o espaço deixado pelo livro removido
        for(int j = i; j < biblioteca->tamanho - 1; j++ ){
            biblioteca->livros[j] = biblioteca->livros[j + 1] ;
        }
       
        biblioteca->tamanho--;
        biblioteca->livros = (Livro*)realloc(biblioteca->livros, biblioteca->tamanho * sizeof(Livro)); // realocando a memoria da lista para seu novo tamanho apos remoçao do livro
        
        printf("Livro removido com sucesso");
        break;
        }
    }

    if (!encontrado) {
        printf("Livro com ISBN %s não encontrado.\n", ISBN);
    }

}

int buscarLivroPorIsbn(Biblioteca *biblioteca, const char *ISBN){
    int encontrado = 0;

    for(int i = 0; i < biblioteca->tamanho; i++){
        if(strcmp(biblioteca->livros[i].ISBN,ISBN) == 0){
            encontrado = 1;
            break;
        }

    }


     return encontrado;
}

int consultarLivro(Biblioteca *biblioteca, const char *ISBN){

    int encontrado = 0;
    for(int i = 0; i < biblioteca->tamanho; i++){
        if(strcmp(biblioteca->livros[i].ISBN,ISBN) == 0){
            encontrado = 1;
        printf("\nNome: %s,\n Autor: %s, \nAno: %d, \nQuantidade: %d",biblioteca->livros[i].nomeLivro,biblioteca->livros[i].nomeAutor,biblioteca->livros[i].ano,biblioteca->livros[i].quantidade);
        break;
        }
    }


return encontrado;
}



int main(){

    Biblioteca biblioteca;
    inicializarBiblioteca(&biblioteca, 2);

    int opcao;
    Livro livro;
    char ISBN[13];

do{
    printf("\nBem vindo a biblioteca! \n");
    
    printf("\nO que voce deseja fazer?");

    printf("\n 1 - ADICIONAR LIVRO  ");
    printf("\n 2 - REMOVER LIVRO  ");
    printf("\n 3 - ATUALIZAR LIVRO  ");
    printf("\n 4 - CONSULTAR LIVRO  ");
    printf("\n 5 - LISTAR TODOS OS LIVROS DISPONIVEIS  ");
    printf("\n 6 - SAIR ");
    scanf("%d",&opcao);

 

    switch (opcao){
        
        case 1:
        
        printf("\nISBN do livro: \n");
            scanf("%s",livro.ISBN);
        printf("\nNome do livro: \n");
            scanf("%s",livro.nomeLivro);
         printf("\nNome do autor: \n");
            scanf("%s",livro.nomeAutor);
        printf("\nAno do livro: \n");
            scanf("%d",&livro.ano);
        printf("\nQuantidade em estoque: \n");
            scanf("%d",&livro.quantidade);
        adicionarLivros(&biblioteca,livro);
        break;
        
        case 2:
            
        printf("\nDigite o ISBN do livro que deseja remover: \n");
            scanf("%s",ISBN);
        removerLivro(&biblioteca,ISBN);
        break;

        case 3:

        printf("\nDigite o ISBN do livro que deseja atualizar: \n");
            scanf("%s",ISBN);


        if (buscarLivroPorIsbn(&biblioteca, ISBN) == 1) {
       
        printf("\nNovos dados do livro:\n");   
        printf("\nISBN do livro: \n");
            scanf("%s",livro.ISBN);
        printf("\nNome do livro: \n");
            scanf("%s",livro.nomeLivro);
         printf("\nNome do autor: \n");
            scanf("%s",livro.nomeAutor);
        printf("\nAno do livro: \n");
            scanf("%d",&livro.ano);
        printf("\nQuantidade em estoque: \n");
            scanf("%d",&livro.quantidade);
        atualizarLivro(&biblioteca,livro,ISBN);}
        else{
            printf("\nLivro com ISBN %s não encontrado.\n", ISBN);
        }
        break;
         
         
        case 4:
        
        printf("\nDgite o ISBN do livro que deseja consultar: \n");
        scanf("%s",ISBN);
        consultarLivro(&biblioteca,ISBN);
        break;

        case 5:
        listarLivros(&biblioteca);
        break;

        case 6:
        printf("saindo...\n");
        break;
        
        default:
            printf("opcao nao existente, tente novamente");
            
         }

} while (opcao != 6);

    free(biblioteca.livros);

    return 0;
}