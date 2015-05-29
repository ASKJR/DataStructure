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
	return 1;
}

int consulta_Fila(Fila* fi){
	if(fi == NULL) return -1;
	if(fi->inicio == NULL) return -1;
	return fi->inicio->dado;
}

void imprime_Fila(Fila* fi){
	Fila* aux;
	aux = cria_Fila();
	while(!Fila_vazia(fi)){
		printf("%d ",consulta_Fila(fi));
		insere_Fila(aux,consulta_Fila(fi));
		remove_Fila(fi);
	}
	printf("\n");
	while(!Fila_vazia(aux)){
		insere_Fila(fi,consulta_Fila(aux));
		remove_Fila(aux);
	}
	libera_Fila(aux);	
}
void inverter_Fila(Fila* fi){
	int tam,val,i,val2;
	Fila* aux;
	aux = cria_Fila();
	//Cópia par aux;
	while(!Fila_vazia(fi)){
		insere_Fila(aux,consulta_Fila(fi));
		remove_Fila(fi);
	}
	//Invertendo
	while(!Fila_vazia(aux)){
		val = consulta_Fila(aux);
		insere_Fila(fi,val);
        tam = tamanho_Fila(fi);
		for(i=0;i<tam-1;i++){
			val2 = consulta_Fila(fi);
			remove_Fila(fi);
			insere_Fila(fi,val2);
		}
		remove_Fila(aux);
	}
	libera_Fila(aux);
}
void menu(){
	printf("-----------FILA-----------\n\n");
	printf("1-INSERIR\n");
	printf("2-REMOVER\n");
	printf("3-IMPRIMIR\n");
	printf("4-INVERTER\n");
	printf("5-SAIR\n\n");
	printf("--------------------------\n\n");
}