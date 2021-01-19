#include <stdio.h>
#include <stdlib.h>
#include <time.h>	

int somatorio(int n){
	if(n==0){
		return 0;
	}	
	return somatorio(n-1)+n;
}


int main(){
	int n;
	clock_t t;
	
	printf("Digite um numero:");
	scanf("%d",&n);
	t = clock();
	printf("Somatorio: %d",somatorio(n));
	t = clock() - t;
	printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double


}
