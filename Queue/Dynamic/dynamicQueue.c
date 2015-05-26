#include "dynamicQueue.h"

Fila* cria_Fila(){
	Fila* fi = (Fila*) malloc(sizeof(Fila));
	if(fi!=NULL){
		fi->inicio = NULL;
		fi->final  = NULL;
	}
	return fi;
}
void libera_Fila(Fila* fi){
	if(fi!=NULL){
		Elem* no;
		while(fi->inicio != NULL){
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}
int tamanho_Fila(Fila* fi){
	if(fi==NULL) return 0;
	int cont = 0;
	Elem* no = fi->inicio;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}

int Fila_vazia(Fila* fi){
	if(fi==NULL) return 1;
	if(fi->inicio == NULL) return 1;
	return 0;
}

int insere_Fila(Fila* fi,int valor){
	if(fi == NULL) return 0;
	Elem* no = (Elem*) malloc(sizeof(Elem));
	if(no == NULL) return 0;
	no->dado = valor;
	no->prox = NULL;
	if(fi->final == NULL) //fila vazia
		fi->inicio = no;
	else
		fi->final->prox = no;
	fi->final = no;
	return 1;
}
int remove_Fila(Fila* fi){
	if(fi == NULL) 
		return 0;
	if(fi->inicio == NULL) 
		return 0; //fila vazia
	Elem* no = fi->inicio;
	fi->inicio = fi->inicio->prox;
	if(fi->inicio == NULL)//fila ficou vazia
		fi->final = NULL;
	free(no);
}

int consulta_Fila(Fila* fi){
	if(fi == NULL) return -1;
	if(fi->inicio == NULL) return -1;
	return fi->inicio->dado;
}