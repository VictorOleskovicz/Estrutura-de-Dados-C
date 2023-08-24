#include <stdio.h>
#include <stdlib.h>

//PROGRAMA QUE IMPLEMENTA UMA FILA

struct no{
	int numero;
	struct no *proximo;
};

//DECLARACAO DA CABECA
	struct no *cabeca = NULL;
	
void inserir(int numero) {
	//alocar uma nova memória
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));  //cria uma area da memória e alloca
	novoNo -> numero = numero;  //aloca o valor do ponteiro
	novoNo -> proximo = NULL;    //adicona o valor do proximo ponteiro
	
	novoNo -> proximo = cabeca;
	cabeca = novoNo;
}
	
	//remover um no da fila

int remover() {
	int retorno = -1;
	
	if (cabeca != NULL) {
		if (cabeca -> proximo == NULL) {
			retorno = cabeca -> numero;
			free(cabeca);
			cabeca = NULL;
		} else {
			struct no *ponteiro = cabeca;
			
			//chega ate o penultimo numero
			while(ponteiro -> proximo -> proximo != NULL) {
				ponteiro = ponteiro -> proximo;
			}
			
			//retorna o ultimo numero 
			retorno = ponteiro -> proximo -> numero;
			free(ponteiro -> proximo);
			ponteiro -> proximo = NULL;
		}
	}
	
	return retorno;
}

int main() {
	printf("%d\n", remover());
	printf("============================\n");
	
	inserir(1);
	printf("%d\n", remover());
	printf("============================\n");
	
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	printf("%d\n", remover());
	printf("%d\n", remover());
	printf("%d\n", remover());
	printf("%d\n", remover());
	printf("%d\n", remover());


}



	
