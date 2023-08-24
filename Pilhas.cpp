#include <stdio.h>
#include <stdlib.h>

//PROGRAMA QUE IMPLEMENTA UMA FILA

struct no{
	int numero;
	struct no *proximo;
};

//DECLARACAO DA CABECA
	struct no *cabeca = NULL;
	
void push(int numero) {
	//alocar uma nova memória
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));  //cria uma area da memória e alloca
	novoNo -> numero = numero;  //aloca o valor do ponteiro
	novoNo -> proximo = NULL;    //adicona o valor do proximo ponteiro
	
	//empilhamento
		novoNo -> proximo = cabeca;
	cabeca = novoNo;
}

//verificacao do primeiro da fila

int top() {
	int retorno = -1;
	if(cabeca != NULL) {
		retorno = cabeca -> numero;
	}
	return retorno;
}

int pop() {
	int retorno = -1;
	
	if (cabeca != NULL) {
		struct no *ponteiroExcluir = cabeca;
		retorno = cabeca -> numero;
		cabeca = cabeca -> proximo;
		free(ponteiroExcluir);
	}
	return retorno;
}

int main() {
	printf("%d\n", pop());
	printf("============================\n");
	
	push(1);
	printf("%d\n", pop());
	printf("============================\n");
	
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);

	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());

	


}

	

