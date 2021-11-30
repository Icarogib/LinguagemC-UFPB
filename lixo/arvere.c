#include "arvere.h"

ArvRaiz *cria_arv ( ){
	
	ArvRaiz* a = ( ArvRaiz * ) malloc ( sizeof ( ArvRaiz ) ); //aloca espaço e cria uma arvore binária, sua raiz
	
	a -> raiz = NULL;
	puts("criei");
	return a;
}

static ArvBin* busca ( ArvBin *r, int val ) {
	
	if ( r == NULL ) //não achou
		return NULL;
	else
		if ( val > r -> num )		//procura pela direita
			return busca ( r -> dir, val );
			
		else if ( val < r -> num ) 	//procura pela esquerda
			return busca( r -> esq, val );
			
		else 
			return r;	//achou!
}

ArvBin * raizbusc ( ArvRaiz* rz, int val ) {

	return busca ( rz->raiz , val );	

}

static ArvBin *inseregalho (ArvBin* r, int val){

	if ( r == NULL ) { //se vazio, cria um galho novo.

		r = ( ArvBin* ) malloc(sizeof ( ArvBin ) ); 
		
		r-> num = val;
		r-> dir = NULL;
		r-> esq = NULL;
			
	}else if ( val < r -> num ) {//cria um galho à esquerda

		r-> esq = inseregalho( r -> esq, val );
	}
	else if ( val > r-> num ) { //cria um galho à direita

		r-> dir = inseregalho( r -> dir, val );
	}
	return r;	//operação concluída

}

void arvinsere (ArvRaiz* r, int val){

	r -> raiz = inseregalho ( r->raiz ,val );

}

static ArvBin * removegalho (ArvBin * r, int val){
	
	if (r == NULL)

		return NULL;

	else if (r-> num > val)

		r-> esq = removegalho ( r->esq , val );

	else if (r-> num < val)

		r-> dir = removegalho ( r->dir, val );
		
	else { 
	
		//nao possui filhos
		if (r-> esq == NULL && r-> dir == NULL) {
	
	 		free (r);
			r = NULL;
		}
		//filho na direita
		else if (r-> esq == NULL) {
	
			ArvBin* t = r;
			r = r-> dir;
			free (t);
	
		}
		//filho na esquerda
		else if (r-> dir == NULL) {
	
			ArvBin* t = r;
			r = r-> esq;
			free (t);
	
		}
		//tem ambos os filhos
		else {
	
			ArvBin* f = r-> esq;
		
			while (f-> dir != NULL) {
	
				f = f-> dir;
			}
	
			r-> num = f-> num; 
			f-> num = val;
			r-> esq = raizremove (r->esq ,val);
		}
	}
	return r;
}

ArvBin *raizremove (ArvRaiz * r, int val){
	
	r -> raiz = removegalho ( r->raiz, val);
	return r-> raiz;
}

int folhas (ArvBin* a){
	
	if ( a -> esq == NULL && a->dir == NULL ) //se nó sem filhos = folha, retorna 1 para somar.
	
		return 1;
	
	else if ( a->esq != NULL && a -> dir == NULL) //se nó com filhos a esquerda filhos != folha, chama a função para ver o filho a esquerda é uma folha, pode ser chamado multiplas vezes.
	
		return folhas(a->esq);
	
	else if ( a -> esq == NULL && a -> dir != NULL )  //se nó com filhos a direita filhos != folha, chama a função para ver o filho a esquerda é uma folha, pode ser chamado multiplas vezes.
	
		return folhas ( a -> dir );
	
	return folhas( a -> esq ) + folhas( a -> dir );
} 

int folhasRaiz (ArvRaiz *ar){
	
	return folhas( ar -> raiz );
	
}

static void imprime (ArvBin* r){ //utilizando pre-ordem
	printf("<");
	
	if (r != NULL) {

		printf("%d", r -> num);
		
		imprime( r-> esq );
				
		imprime( r-> dir );
	}
	printf(">");
}

void imprimeraiz (ArvRaiz* raiz){

	return imprime(raiz -> raiz);
}

