#include <stdio.h>
#include <stdlib.h>
 
 
 float CalculoMedia(float *numeros, int quantidade){
   
    float soma = 0.0;
    float *ptr = numeros;
   
     for(int i=0; i < quantidade; i++){
     soma += *ptr;
     ptr++;
}
     float media = soma / quantidade;

    return media;

}


float* MultiplosDe6(float *numeros, int quantidade, int *quantidadeMultiplos){ //*quantideMultiplos é um ponteiro q vai armazenar a quantidade de multiplos de 6 presentes na lista 


    float *multiplos = (float*)malloc(quantidade * sizeof(float)); //alocar dinamicamente durante a execuçao a quantidade de numeros q sera recebido quando a funçao for chamada
    float *ptr = numeros;
    int contador = 0;
   
    for(int i = 0; i < quantidade; i++){
  
        int valor_inteiro = (int)(*ptr);
        if(valor_inteiro % 6 == 0){
            
            multiplos[contador] = *ptr; // se for multiplo de 6 a lista multiplos vai receber o numero do ponteiro q foi digitado no momento e ira armazenar no contador(que ira para a qtde Multiplos)
            // a gente precisa definir esse contador pois ele é quem ira representar a quantidade de multiplos q tem na lista numeros
            contador++;

        }
       
        ptr++;// e entao vai passar pro prox valor do ponteiro e reiniciar o laço

    }

    // usa realloc para valores q ja foram previamente alocados com malloc ou calloc, realocando para um novo bloco de memoria . No caso multiplos ja tinha sido
    //alocado com a funçao malloc, pois inicialmente não sabemos quantos múltiplos de 6 encontraremos. agora a gente adapta ela usando realloc e levando em consideraçao o contador 
    //e nao mais a quantidade de numeros da lista, agr a quantidade de numeros Multiplos
    multiplos = (float*)realloc(multiplos, contador * sizeof(float));
    
    *quantidadeMultiplos = contador; //definimos contador como a quantidade de multiplos enfim.
    return multiplos; //agora a variavel multiplos esta alocada corretamente 


}

int main(){
   
    
    int N;
  
    printf("Quantos numeros voce quer adicionar? :  ");
    scanf("%d",&N);
        
    // utilizando alocaçao dinamica de memoria, funçao malloc, para podermos alocar a qtde de memoria DURANTE a execução do programa.
       
       //sizeof de cada nmr float no caso quanto cada numero flutuante ocupa em bytes multiplicando quantos numeros serao (N), resulta na
       // quantd de bytes que serao alocados durante a execução
    
     float *numeros = (float*)malloc(N * sizeof(float)); //Juntos, N * sizeof(float) determina o número total de bytes de memória que serão alocados.
     
        printf("adicione os numeros:" );
        
        for(int i=0; i < N; i++){
 
            scanf("%f", &numeros[i]);
            
    }
        
        float resultadoMedia = CalculoMedia(numeros,N);
        printf("A media eh: %.2f\n", resultadoMedia);
        
       
       // n precisamos utilizar o malloc aqui como no da media pois usei o malloc na funçao ja, usando os argumentos: a lista e a quantidade de numeros e depois o realloc que
       // realoca com base nos multiplos de 6 encontrados
        int quantidadeMultiplos; //define o terceiro argumento da funçao q precisamos para realocar na memoria os multiplos q foram encontrados 
        float *resultadoMultiplo = MultiplosDe6(numeros, N, &quantidadeMultiplos);

        if(quantidadeMultiplos > 0){

        
        printf("Os multiplos de 6 que voce digitou sao: \n");
        for(int j = 0; j < quantidadeMultiplos; j++){

            printf("%.2f\n",resultadoMultiplo[j]);
        }
        }
        else printf("Nao ha multiplos de 6");
        free(numeros);
        free(resultadoMultiplo);
        
return 0;
}