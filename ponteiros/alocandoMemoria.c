#include <stdio.h>

int main(){


        int a = 20;
        int b,c;

        b = 30;
        c = a + b;

        printf("&a : %p || a : %d\n",&a,a); //onde esta alocado (cada slot de memoria custa 4 bytes) || valor da variavel 
        printf("&b : %p || b : %d\n",&b,b);
        printf("&c : %p || c : %d\n",&c,c);



    return 0;
}