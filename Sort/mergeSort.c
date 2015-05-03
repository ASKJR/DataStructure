#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100000

void merge(int *V,int inicio, int meio, int fim);
void mergeSort (int *V,int inicio, int fim);

void mergeSort (int *V,int inicio, int fim){//dividir os dados
	if(inicio<fim){
		int meio = (inicio+fim)/2;
		mergeSort(V,inicio,meio);
		mergeSort(V,meio+1,fim);
		merge(V,inicio,meio,fim);
	}
}
void merge(int *V,int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1 = 0 , fim2 = 0 ;
	
	tamanho= fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	
	temp = (int *) malloc(tamanho*sizeof(int));
	
	if(temp != NULL){
		for(i=0;i<tamanho;i++){
			if(!fim1 && !fim2){
				if(V[p1]<V[p2]){
					temp[i] = V[p1++];
				}
				else{
					temp[i] = V[p2++];	   	
				}
				if(p1>meio) fim1 = 1;
				if(p2>fim)  fim2 = 1;
			}
			else{
				if(!fim1)
					temp[i] = V[p1++];
				else
					temp[i] = V[p2++];
			}
		}
		for(j=0,k=inicio;j<tamanho;j++,k++){
			V[k] = temp[j];
		}
	}
	free(temp);
}

int main(){
	int N,i,par[MAX],impar[MAX],in,indP=0,indI=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&in);
		if(in%2==0){
			par[indP] = in;
			indP++;
		}
		else{
			impar[indI] = in;
			indI++;
		}
	}

	mergeSort(par,0,indP-1);
    mergeSort(impar,0,indI-1);
    
    for(i=0;i<indP;i++){
		printf("%d\n",par[i]);
	}
    for(i=indI-1;i>=0;i--){
		printf("%d\n",impar[i]);
	}
	return 0;

}
