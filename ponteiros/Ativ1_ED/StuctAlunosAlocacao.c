#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {

    char nome[50];
    char matricula[50];
    float media;

};


int compararNomes(const void *a, const void *b){

    return strcmp(((struct info*)a) -> nome, ((struct info*)b)-> nome);

}


int compararMedias(const void *a, const void *b){

    const struct info *aluno1 = (const struct info *)a; //convertendo ponteiro a pro ponteiro do tipo struct info pra ter acesso a informaçao da media
    const struct info *aluno2 = (const struct info *)b;//convertendo ponteiro b pro ponteiro do tipo struct info pra ter acesso a informaçao da media

    if (aluno1 -> media < aluno2 -> media) return 1; // se a media do 1 aluno for menor que a do 2 aluno, indicamos 1 pra dizer q o primeiro aluno deve vir depois do segundo na class
    if (aluno1 -> media > aluno2 -> media) return -1; // se a media do 1 aluno for maior q a do 2 aluno, indicamos -1 pra dizer q o primeiro aluno deve vir antes do segundo na classi
    return 0;

}

int main(){

    int N;
    printf("quantos alunos?: ");
    scanf("%d",&N);

    struct info *alunos = malloc(N * sizeof(struct info));

    int opcao1;
    int opcao2;
   
    for(int i = 0; i < N; i++){

        printf("\nNome: ");
        scanf("%s",alunos[i].nome);
        printf("\nMatricula: ");
        scanf("%s",alunos[i].matricula);
        printf("\nMedia: ");
        scanf("%f", &alunos[i].media);

        // nao poderia usar o N pois durante o loop n sabemos todos os nomes de todos os alunos ainda, entao tem q ser
        // feito de forma q va adicionando os nomes conforme o loop avança
        //estamos garantindo que apenas os alunos já inseridos sejam ordenados e exibidos a cada iteração do loop

    

        printf("\nDeseja ver uma das listagens ate agora? 1 - SIM || 2 - NAO  ");
        scanf("%d",&opcao1);

        if(opcao1 == 1){
            
            printf("Deseja ver em ordem alfabetica ou em ordem de classificacao? 1 - Alfabetica || 2 - classificacao  ");
            scanf("%d",&opcao2);

            if (opcao2 == 1){
                qsort(alunos, i+1, sizeof(struct info),compararNomes);  // nao poderia usar o N pois durante o loop n sabemos todos os nomes de todos os alunos ainda, entao tem q ser
                                                                        // feito de forma q va adicionando os nomes conforme o loop avança
                                                                                //estamos garantindo que apenas os alunos já inseridos sejam ordenados e exibidos a cada iteração do loop
                                                                            // nao poderia usar o N pois durante o loop n sabemos todos os nomes de todos os alunos ainda, entao tem q ser
                                                                                                // feito de forma q va adicionando os nomes conforme o loop avança
                                                                                              //estamos garantindo que apenas os alunos já inseridos sejam ordenados e exibidos a cada iteração do 
                 printf("\nAlunos em ordem alfabetica: ");
                
                for(int j = 0; j < N; j++){
                    
                    printf("%s\n", alunos[j].nome);

                }

            }

            else if (opcao2 == 2){
                
                qsort(alunos,i+1,sizeof(struct info),compararMedias);
                printf("\n Alunos em ordem de classificacao\n");
                for (int j = 0; j < N; j++){

            
                    printf("%s\n",alunos[j].nome);

                }

            }

            
        }
        
        else if(opcao1 == 2){
            continue;
        }

    }


    return 0;
}

