//Escreva uma função que recebe um array de inteiros e seu tamanho como argumentos, 
// e retorna a soma de todos os elementos do array. Use ponteiros para iterar pelo array.


#include <stdio.h>

     int SomaArray(int *array, int tamanho) {

            int soma = 0;
            int *ponteiro = array;

            for (int i = 0; i < tamanho; i++){

                soma += *ponteiro;
                ponteiro++;

            }

        return soma;
     }
       
        int main(){
           
            int array[] = {1,3,5,7,8};
            int tamanho = sizeof(array) / sizeof(array[0]);
            int resultado = SomaArray(array,tamanho);
            printf("A soma dos elementos da array e: %d",resultado);


    return 0;
}