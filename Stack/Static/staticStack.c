#include "staticStack.h"

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
void imprimi_Pilha(Pilha* pi){
	int i=0;
	if(pi == NULL){
		printf("Erro ao alocar memoria\n");
		return;
	}
	if(Pilha_vazia(pi)){
		printf("A pilha esta vazia!\n");
		return;		
	}
	for(i=pi->topo-1;i>=0;i--){
		printf("%d\n",pi->elementos[i]);
	}
}
