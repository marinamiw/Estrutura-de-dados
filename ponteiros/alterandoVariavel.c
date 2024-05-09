#include <stdio.h>

int main(){

        int x = 0;
        int *ptr;

        ptr  = &x; //ponteiro correspondendo ao endereço de memoria da variavel x (& significa endereço de memoria)
        *ptr = 20;
        
        printf("O valor de x e: %d",x);





    return 0;
}
