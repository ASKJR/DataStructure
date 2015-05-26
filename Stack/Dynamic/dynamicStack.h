#include <stdio.h>
#include <stdlib.h>

typedef struct elemento* Pilha;

struct elemento{
	int dado;
	struct elmento *prox;
};

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int insere_Pilha(Pilha* pi, int val);
int remove_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi);
void imprime_Pilha(Pilha* pi);
void inverter_Pilha(Pilha* pi);
void menu();
typedef struct elemento Elem;