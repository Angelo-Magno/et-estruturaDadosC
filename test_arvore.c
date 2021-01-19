#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int info;
	struct no *esq;
	struct no *dir;
}no, *arvbin;

//criação da arvore
arvbin *cria_arvbin(){
	arvbin *raiz = (arvbin*) malloc(sizeof(arvbin));
	if(raiz != NULL){
		*raiz = NULL;
	}
	return raiz;
}

//liberar arvorer (excluir toda arvore)
void libera_no(struct no *n){
	if(n == NULL){
		return;
	}
	libera_no(n->esq);
	libera_no(n->dir);
	free(n);
	n= NULL;
}
void libera_arvbin(arvbin *raiz){
	if(raiz == NULL){
		return;
	}
	libera_no(*raiz);//libera cada nó
	free(raiz);//libera raiz
}

//PERCONRRENDO A ARVORE

//Pre-ordem
void preordem(arvbin *raiz){
	if(raiz==NULL)
		return;
	if(*raiz != NULL){
		printf("%d\n",(*raiz)->info);
		preordem(&((*raiz)->esq));
		preordem(&((*raiz)->dir));
	}
}
//Em ordem
void emordem(arvbin *raiz){
	if(raiz==NULL)
		return;
	if(*raiz != NULL){
		emordem(&((*raiz)->esq));
		printf("%d\n",(*raiz)->info);
		emordem(&((*raiz)->dir));
	}
}
//Pos-ordem
void posordem(arvbin *raiz){
	if(raiz==NULL)
		return;
	if(*raiz != NULL){
		posordem(&((*raiz)->esq));
		posordem(&((*raiz)->dir));
		printf("%d\n",(*raiz)->info);
	}
}

//Inserção de valores
int insere_arvbin(arvbin *raiz, int valor){
	if(raiz==NULL){	
		return 0;
	}
	struct no *novo;
	novo = (struct no*) malloc(sizeof(struct no));
	if(novo== NULL){
		return 0;
	}
	novo->info = valor;
	novo->dir = NULL;
	novo->esq = NULL;
	
	if(*raiz == NULL){
		*raiz = novo;
	}
	else{
		struct no* atual= *raiz;
		struct no *ant = NULL;
		while(atual != NULL){
			ant = atual;
			if(valor==atual->info){
				free(novo);
				return 0;//Elemento já existe
			}
			if(valor > atual->info){
				atual = atual->dir;
			}else {
				atual = atual->esq;
			}
		}		
		if(valor > ant->info){
			ant->dir = novo;
		}else{
			ant->esq = novo;
		}
	}
	return 1;
}

//Remoção
struct no* remove_atual(struct no* atual){
	struct no *no1, *no2;
	if(atual->esq == NULL){
		no2 = atual->dir;
		free(atual);
		return no2;
	}
	no1=atual;
	no2=atual->esq;
	while(no2->dir != NULL){
		no1 = no2;
		no2 = no2->dir;
	}
	
	if(no1 != atual){
		no1->dir = no2->esq;
		no2->esq = atual->esq;
	}
	no2->dir = atual->dir;
	free(atual);
	return no2;
}

int remove_arvbin(arvbin *raiz, int valor){
	if(raiz == NULL) return 0;
	struct no *ant= NULL;
	struct no *atual = *raiz;
	while(atual != NULL){
		if(atual == atual->info){
			if(atual == *raiz){
				*raiz = remove_atual(atual);
			}else{
				if(ant->dir == atual){
					ant->dir = remove_atual(atual);
				}else{
					ant->esq = remove_atual(atual);
				}
			}
			return 1;
		}
		ant = atual;
		if(valor > atual->info){
			atual = atual->dir;
		}else{
			atual = atual->esq;
		}
	}
	return 0;
}


int main() {
	
	
	arvbin *raiz = cria_arvbin();
}
