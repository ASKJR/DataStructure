#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct pilha{
	int topo;
	int elementos[MAX];
};

typedef struct  pilha Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi); //retorna tamanho e posição-index disponível na pilha.
int Pilha_cheia(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int insere_Pilha(Pilha* pi, int valor);
int remove_Pilha(Pilha* pi);
void consulta_topo_Pilha(Pilha* pi);
void imprimi_Pilha(Pilha* pi);
