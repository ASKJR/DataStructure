#include "dynamicQueue.h"

int main(){
	Fila* fi;
	fi = cria_Fila();
	insere_Fila(fi,3);
	insere_Fila(fi,4);
	insere_Fila(fi,5);
	imprime_Fila(fi);
	printf("\n\n");
	imprime_Fila(fi);
	remove_Fila(fi);
	printf("\n\n");
	imprime_Fila(fi);
	libera_Fila(fi);
}