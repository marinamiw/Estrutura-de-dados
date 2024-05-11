#include <stdio.h>
#include <stdlib.h>

struct Dados{

        char nome[50];
        int idade;
        float peso;


};


int main(){

    int N;
    printf("Quantos atletas?: ");
    scanf("%d",&N);

    struct Dados *atleta = malloc(N * sizeof(struct Dados));
    
    float somaPeso = 0.0;
    int menorIdade = 0;
    
    for(int i = 0; i < N; i++){

        

        printf("Nome: \n");
        scanf("%s", atleta[i].nome); 
        printf("Peso: \n");
        scanf("%f", &atleta[i].peso);
        printf("Idade: \n");
        scanf("%d", &atleta[i].idade);
         
        somaPeso += atleta[i].peso;
       
        if (atleta[i].idade < 18){
            menorIdade++;
        }
    
    }

    float media_peso = somaPeso / N;


        printf("Informaçoes das pessoas: ");
   
    for(int i= 0; i < N; i++){

        printf("\nNome: %s", atleta[i].nome);
        printf("\nPeso: %f", atleta[i].peso);
        printf("\nIdade: %d", atleta[i].idade);
    }


    printf("\n A media dos pesos dos atletas e: %.2f\n", media_peso);
    printf("\n%d atleta(s) e/sao menor(es) de idade",menorIdade);
    free(atleta);
    return 0;
}