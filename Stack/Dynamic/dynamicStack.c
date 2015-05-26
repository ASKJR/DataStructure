#include "dynamicStack.h"

Pilha* cria_Pilha(){
	Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
	if(pi != NULL)
		*pi = NULL;
	return pi;
}
 
void libera_Pilha(Pilha* pi){
	if(pi != NULL){
		Elem *no;
		while((*pi) != NULL){
			no = *pi;
			*pi = (*pi)->prox;
			free(no);
		}
		free(pi);
	}
}

int tamanho_Pilha(Pilha* pi){
	if(pi == NULL) return 0;
	int cont = 0;
	Elem* no = *pi;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}

int Pilha_vazia(Pilha* pi){
	if(pi == NULL) return 1;
	if(*pi == NULL) return 1;
	return 0;
}

int insere_Pilha(Pilha* pi,int val){
	   if(pi == NULL) return 0;
	   Elem* no = (Elem*) malloc(sizeof(Elem));
   	   if(no == NULL) return 0;
   	   no->dado = val;
       no->prox = (*pi);
       *pi = no;
       return 1;
}

int remove_Pilha(Pilha* pi){
	if(pi == NULL) return 0;    //pilha nao existe
	if((*pi) == NULL) return 0; //pilha vazia
    Elem *no = *pi;
	*pi = no->prox;
	free(no);
	return 1;
}

int consulta_topo_Pilha(Pilha* pi){
	if(pi == NULL){
		   printf("erro pilha\n");
		   return;	
	} 
	if((*pi) == NULL){
		 printf("pilha vazia\n");
		 return;
	}
	return (*pi)->dado;
}

void imprime_Pilha(Pilha* pi){
    Pilha* aux;
    int val;
	aux = cria_Pilha();
	while(!Pilha_vazia(pi)){ 
	    printf("%d\n",consulta_topo_Pilha(pi));
	    insere_Pilha(aux,consulta_topo_Pilha(pi));
	    remove_Pilha(pi);
	}
	while(!Pilha_vazia(aux)){
		val = consulta_topo_Pilha(aux);
		remove_Pilha(aux); 
		insere_Pilha(pi,val);
	}
	return;
}
void inverter_Pilha(Pilha* pi){
	Pilha* aux,aux2;
	aux  = cria_Pilha();
	aux2 = cria_Pilha();
	while(!Pilha_vazia(pi)){
		//printf("%d",consulta_topo_Pilha(pi));
		insere_Pilha(aux,consulta_topo_Pilha(pi));
		remove_Pilha(pi);
	}
	while(!Pilha_vazia(aux)){
		//printf("%d",consulta_topo_Pilha(pi));
		insere_Pilha(aux2,consulta_topo_Pilha(aux));
		remove_Pilha(aux);
	}
	
	while(!Pilha_vazia(aux2)){
		//printf("%d",consulta_topo_Pilha(pi));
		insere_Pilha(pi,consulta_topo_Pilha(aux2));
		remove_Pilha(aux2);
	}

	return;
}
void menu(){
	printf("------Pilha------\n\n");
	printf("1-INSERIR\n2-REMOVER\n3-IMPRIMIR\n4-INVERTER\n5-SAIR\n\n");
	printf("-----------------\n\n\n");
}
