#include <stdio.h>
#include <stdlib.h>

struct no {
    int numero;
    struct no *anterior;
    struct no *proximo;
};

struct no *cabeca = NULL;

void inserir(int numero) {
    struct no *novoNO;
    novoNO = (struct no *)malloc(sizeof(struct no));
    novoNO->numero = numero;
    novoNO->anterior = NULL;
    novoNO->proximo = NULL;

    if (cabeca == NULL) {
        cabeca = novoNO;
    } else {
        struct no *ponteiro = cabeca;

        while (ponteiro->proximo != NULL) {
            ponteiro = ponteiro->proximo;
        }
        ponteiro->proximo = novoNO;
        novoNO->anterior = ponteiro;
    }
}

void imprimir() {
    printf(" ------------------------- \n");
    struct no *ponteiro = cabeca;

    while (ponteiro != NULL) {
        printf("%d\n", ponteiro->numero);
        ponteiro = ponteiro->proximo;
    }
}

void remover(int numero) {
    struct no *ponteiroExcluir = cabeca;

    // Handle removal of the head node
    if (cabeca->numero == numero) {
        struct no *novoCabeca = cabeca->proximo;
        if (novoCabeca != NULL) {
            novoCabeca->anterior = NULL;
        }
        free(cabeca);
        cabeca = novoCabeca;
        return;
    }

    // Search for the node to remove
    while (ponteiroExcluir != NULL) {
        if (ponteiroExcluir->numero == numero) {
            struct no *anterior = ponteiroExcluir->anterior;
            struct no *proximo = ponteiroExcluir->proximo;

            // Update pointers of surrounding nodes
            if (anterior != NULL) {
                anterior->proximo = proximo;
            }
            if (proximo != NULL) {
                proximo->anterior = anterior;
            }

            free(ponteiroExcluir);
            return;
        }
        ponteiroExcluir = ponteiroExcluir->proximo;
    }
}

int main() {
    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    imprimir();

    remover(1);
    remover(3);
    remover(5);
    imprimir();
}

