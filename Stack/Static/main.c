#include "staticStack.h"

int main(){
	//ponteiro que aponta para estrutura da pilha
	Pilha* pi;
	pi = cria_Pilha();
	insere_Pilha(pi,5);
	insere_Pilha(pi,7);
	insere_Pilha(pi,56);
	insere_Pilha(pi,3);
	imprimi_Pilha(pi);
	printf("\n\n");
	remove_Pilha(pi);
	insere_Pilha(pi,2);
	insere_Pilha(pi,4);
	imprimi_Pilha(pi);
	libera_Pilha(pi);
	return 0;
}