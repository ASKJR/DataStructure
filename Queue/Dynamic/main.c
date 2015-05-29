#include "dynamicQueue.h"

int main(){
	Fila* fi;
	fi = cria_Fila();
	insere_Fila(fi,1);
	insere_Fila(fi,2);
	insere_Fila(fi,3);
	insere_Fila(fi,4);
	insere_Fila(fi,5);
	imprime_Fila(fi);
	inverter_Fila(fi);
	imprime_Fila(fi);
	remove_Fila(fi);
	imprime_Fila(fi);
	libera_Fila(fi);
}