#include "dynamicStack.h"

int main(){
	int op,val;
	Pilha* pi;
	
	
	pi = cria_Pilha();
	menu();
	
	while(1){
		printf("Operacao desejada(1-5): ");	
		scanf("%d",&op);
		if(op==5) break;
		switch(op){
			case 1:
				printf("Digite o valor p/ inserir: ");
				scanf("%d",&val);	
				insere_Pilha(pi,val);
				break;
			case 2:
				if(!Pilha_vazia(pi)){
					remove_Pilha(pi);	
				}
				else{
					printf("Pilha vazia!\n");	
				}
				break;
			case 3:
				if(!Pilha_vazia(pi)){
					imprime_Pilha(pi);
				}
				else{
					printf("Pilha Vazia!\n");
				}
				break;
			case 4:
				if(!Pilha_vazia(pi)){
					inverter_Pilha(pi);	
				}
				else{
					printf("Pilha Vazia!\n");
				}
				break;
			default:
				printf("Operacao invalida!!\n");
				break;
		}
	}
	libera_Pilha(pi);
	return 0;
}