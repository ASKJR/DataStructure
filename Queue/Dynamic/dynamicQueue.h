#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;

struct fila{
	   struct elemento *inicio;
	   struct elemento *final;	
};
struct elemento{
	int dado;
	struct elemento *prox;	
};
typedef struct elemento Elem;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int insere_Fila(Fila* fi,int valor);
int remove_Fila(Fila* fi);
int consulta_Fila(Fila* fi); //cosulta o inicio da fila
void imprime_Fila(Fila* fi);
void inverter_Fila(Fila* fi);
void menu();