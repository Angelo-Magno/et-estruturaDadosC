#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void bubblesort(int *v, int n){
	int i,continua,aux,fim = n;
	do{
		continua=0;
		for(i=0;i<fim-1;i++){
			if(v[i] > v[i+1]){
				aux= v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
				continua = i;
			}
		}
		fim--;
		
	} while(continua!=0);
}

void insertionsort(int *v, int n){
	int i,j,aux;
	for(i=0;i<n;i++){
		aux=v[i];
		for(j=i;(j>0) && (aux < v[j-1]);j--){
			v[j]=v[j-1];
		}
		v[j]=aux;
	}
}

void selectionsort(int *v, int n){
	int i,j,menor,troca;
	for(i=0;i<n-1;i++){
		menor=i;
		for(j=i+1;j<n;j++){
			if(v[j]<v[menor]){
				menor=j;
			}
		}
		if(i!=menor){
			troca=v[i];
			v[i]=v[menor];
			v[menor]=troca;
		}
	}
}

int main(){
	int v[TAM],i;
	
	for(i = 0; i < TAM; i++){
  		v[i] = (rand()%TAM)+0;
		printf("[%d]",v[i]);
	}
	
	selectionsort(v,TAM);
	
	printf("\n\n");
	
	for(i = 0; i < TAM; i++){
  	
		printf("[%d]",v[i]);
	}
		
}
