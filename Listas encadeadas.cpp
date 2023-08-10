//lista de encadeamento simples
#include <stdio.h>
#include <stdlib.h>

struct node {
	int numero;
	struct node *proximo;
};

struct node *cabeca = NULL;

void inserir(int parametronumero) {
	//alocar uma nova memória
	struct node *novoNo = (struct node*) malloc(sizeof(struct node));  //cria uma area da memória e alloca
	novoNo -> numero = parametronumero;  //aloca o valor do ponteiro
	novoNo -> proximo = NULL;    //adicona o valor do proximo ponteiro


	
	if (cabeca == NULL) {
		//lista vazia
		cabeca = novoNo;            //apontar cabeca para novo no
	} else {
		//caso a lista ja tenha algum node
		struct node *ponteiro;
		ponteiro = cabeca;  //apontar para onde a cabeca esta apontando
		while (ponteiro -> proximo != NULL) {  //apontar para o ponteiro proximo 
			ponteiro = ponteiro -> proximo;
		}
		
		ponteiro -> proximo = novoNo;
	}
}

//funcao que imprime a lista na tela 

void imprimir() {
	struct node *ponteiro;
	
	ponteiro = cabeca;
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
	
}
int main() {
	int i;
	for (i = 0; i < 10000 ; i++) {
		inserir(i);
	}
	imprimir();
}
