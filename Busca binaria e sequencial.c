#include <stdio.h>
int busca_sequencial(int *v,int n, int chave){
	int x;
	for(x=0;x<n;x++){
		if(chave==v[x]){
			return x+1;
		}
	}
	return -1;
}

int busca_binaria(int *v,int n, int chave){
	int i,inicio,meio,final;
	inicio=0;
	final=n-1;
	
	while(inicio<=final){
		i++;
		meio=(inicio+final)/2;
		if(chave<v[meio]){
			final=meio-1;
		}else if(chave>v[meio]){
			inicio=meio+1;
		}else return i;
	}
	return -1;
}


int main(){
	int v[6]={1,2,3,4,5,6},s=0,chave;
	
	printf("Valor a ser encontrado:");
	scanf("%d",&chave);
	
	s=busca_binaria(v,6,chave);
	if(s!=-1){
		printf("Compracoes busca binaria:%d",s);
	} else {
	printf("valor não encontrado");}
		s=busca_binaria(v,6,chave);
	
	s=busca_sequencial(v,6,chave);
	if(s!=-1){
		printf("\nCompracoes busca sequancial: %d",s);
	} else {
	printf("valor não encontrado");}
}
