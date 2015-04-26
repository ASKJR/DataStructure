#include <stdio.h>
#include <stdlib.h>
#include "staticStack.h"

struct pilha{
	int topo;
	int elementos[MAX];
};

Pilha* cria_Pilha(){
	Pilha* pi;
	pi  = (Pilha*) malloc(sizeof(struct pilha));
	if(pi!=NULL){
		pi->topo = 0;
	}
	return pi;
}
void libera_Pilha(Pilha* pi){
	   free(pi);	
}

int tamanho_Pilha(Pilha* pi){
	if(pi == NULL)
		return -1;
	else
		return pi->topo;
}

int Pilha_cheia(Pilha* pi){
	if(pi == NULL)
		return -1;
	else
		return (pi->topo == MAX);
}

int Pilha_vazia(Pilha* pi){
	if(pi == NULL)
		return -1;
	return (pi->topo == 0);
}

int insere_Pilha(Pilha* pi, int valor){
	if(pi == NULL) return 0;
	if(Pilha_cheia(pi)) return 0;
	pi->elementos[pi->topo] = valor;
	pi->topo++;
	return 1;	
}

int remove_Pilha(Pilha* pi){
	if(pi == NULL || pi->topo == 0) return 0;
	pi->topo--;
	return 1;
}
void consulta_topo_Pilha(Pilha* pi){
	if(pi == NULL || pi->topo==0)
		printf("Pilha vazia, ou erro alocacao!\n");
	else printf("Topo: %d\n",pi->elementos[pi->topo-1]);
}


int main(){
	//ponteiro que aponta para estrutura da pilha
	Pilha* pi;
	pi = cria_Pilha();
	insere_Pilha(pi,5);
	insere_Pilha(pi,7);
	insere_Pilha(pi,56);
	insere_Pilha(pi,3);
	consulta_topo_Pilha(pi);
	remove_Pilha(pi);
	consulta_topo_Pilha(pi);
	remove_Pilha(pi);
	printf("Tamanho pilha: %d\n",tamanho_Pilha(pi));
	consulta_topo_Pilha(pi);
	insere_Pilha(pi,99);
	consulta_topo_Pilha(pi);
	printf("Tamanho pilha: %d\n",tamanho_Pilha(pi));
	libera_Pilha(pi);
	return 0;
}