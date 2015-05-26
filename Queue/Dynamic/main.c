#include "dynamicQueue.h"

int main(){
	Fila* fi;
	fi = cria_Fila();
	insere_Fila(fi,3);
	insere_Fila(fi,4);
	insere_Fila(fi,5);
	printf("%d\n",consulta_Fila(fi));
	printf("Tam %d\n",tamanho_Fila(fi));
	remove_Fila(fi);
	printf("Tam %d\n",tamanho_Fila(fi));
	printf("%d\n",consulta_Fila(fi));
	libera_Fila(fi);
}