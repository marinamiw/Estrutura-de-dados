#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int id;  // representa o id do documento (valor que será armazenado na array)
} Documento;

typedef struct {
    Documento fila[MAX_SIZE];
    int begin;
    int end;
    int tamanho;
} FilaDeImpressao;

// Função para inicializar a fila
void inicializarFila(FilaDeImpressao* fila) {
    fila->begin = 0;            // a fila irá começar com o begin e o end no índice 0
    fila->end = 0;
    fila->tamanho = 0;
}

// Função para verificar se a fila está cheia
bool estaCheia(FilaDeImpressao* fila) {
    if (fila->tamanho == MAX_SIZE) {  
        return true;
    }
    return false; 
}

// Função para verificar se a fila está vazia
bool estaVazia(FilaDeImpressao* fila) {
    if (fila->tamanho == 0) {
        return true;
    }
    return false; // Adicionado para retornar false se não estiver vazia
}

// função para adicionar um documento à fila
bool adicionarDocumento(FilaDeImpressao* fila, Documento doc) {
    if (estaCheia(fila)) {
        printf("A fila está cheia. Não é possível adicionar o documento.\n");
        return false;
    }

    fila->fila[fila->end] = doc; // adiciona o documento ao último índice disponível, no caso, onde end está encontrado
    fila->end = (fila->end + 1) % MAX_SIZE; // caso o end chegue ao último índice disponível, nesse caso 10 % 10 = 0, ele retorna pro índice 0, mantendo sempre a circularidade da fila
    fila->tamanho++;
    return true;
}

// função para remover (imprimir) um documento da fila
bool imprimirDocumento(FilaDeImpressao* fila, Documento* doc) { // Imprimir o primeiro documento adicionado (encontrado no begin)
    if (estaVazia(fila)) {
        printf("A fila está vazia. Adicione um documento.\n");
        return false;
    }
    
    printf("Imprimindo primeiro documento adicionado...\n");
    *doc = fila->fila[fila->begin];
    fila->begin = (fila->begin + 1) % MAX_SIZE; // atualiza o ponteiro begin de forma circular
    fila->tamanho--;
    return true;
}

// função para mostrar o estado atual da fila
void mostrarFila(FilaDeImpressao* fila) {
    if (estaVazia(fila)) {
        printf("Fila vazia...\n");
        return;
    }

    printf("A fila de impressão é:\n");
    for (int i = 0; i < fila->tamanho; i++) {
        int index = (fila->begin + i) % MAX_SIZE; // Vai passando o begin pro próximo índice conforme o loop avança. note: quando i = 0, begin é onde está mesmo, qd i está no 1, begin incrementa pro próximo valor da fila
        printf("Documento ID: %d\n", fila->fila[index].id);
    }
}

int main() {
    FilaDeImpressao fila;
    inicializarFila(&fila);

    int entrada;
    
    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar documento\n");
        printf("2 - Imprimir documento\n");
        printf("3 - Mostrar fila de impressao\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &entrada);
        
        switch (entrada) {
            case 1: {
                Documento doc;
                printf("Digite o ID do documento para adicionar: ");
                scanf("%d", &doc.id);
                if (adicionarDocumento(&fila, doc)) {
                    printf("Documento adicionado com sucesso.\n");
                }
                break;
            }
            case 2: {
                Documento doc;
                if (imprimirDocumento(&fila, &doc)) {
                    printf("Documento de ID %d impresso\n", doc.id);
                }
                break;
            }
            case 3:
                mostrarFila(&fila);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (entrada != 4);


    getchar();
    getchar();
    return 0;
}
