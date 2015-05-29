#include "dynamicQueue.h"

/* 
	29/05/2015
	Estrutura de dados - TADS - UFPR
*/

int main(){
	Fila* fi;
	fi = cria_Fila();
	int op,in;
	menu();
	
	while(1){
		printf("Op (1-5) > ");
		scanf("%d",&op);
		//Finalizar programa
		if(op==5)
			break;
		//Operacoes sobre a FILA
		switch(op){
			case 1:
				printf("Digite um valor para ser inserido na fila > ");
				scanf("%d",&in);
				insere_Fila(fi,in);
				break;
			case 2:
				if(remove_Fila(fi))
					printf("removido com sucesso!\n");
				else
					printf("Erro,ou FILA vazia!\n");
				
				break;
			case 3:
				if(!Fila_vazia(fi))
					imprime_Fila(fi);
				else
					printf("Fila vazia!\n");
				break;
			case 4:
				if(!Fila_vazia(fi))
					inverter_Fila(fi);
				else
					printf("Fila vazia!\n");
				break;
			default:
				printf("Operacao invalida!\n");
				break;
		}
		
	}
	libera_Fila(fi);
	return 0;
}