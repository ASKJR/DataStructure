#include "dynamicStack.h"

int main(){
	Pilha* pi;
	pi = cria_Pilha();
	insere_Pilha(pi,1);
	insere_Pilha(pi,2);
	insere_Pilha(pi,3);
	insere_Pilha(pi,4);
	remove_Pilha(pi);
	remove_Pilha(pi);
	consulta_topo_Pilha(pi);
	printf("%d\n",tamanho_Pilha(pi));
	libera_Pilha(pi);
	return 0;
}