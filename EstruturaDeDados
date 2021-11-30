#include "arvere.h"

int main() {
	
	ArvRaiz *arvereraiz = cria_arv (); //inicializa a arvore com uma raiz de valor nulo;	
	
	arvinsere ( arvereraiz, 125); //valor da raiz.
	
	arvinsere ( arvereraiz, 200); //aparece a direita (folha)
	arvinsere ( arvereraiz, 165); //aparece a direita 
	arvinsere ( arvereraiz, 67);  //aparece a esquerda
	arvinsere ( arvereraiz, 156); //aparece a direita 
	arvinsere ( arvereraiz, 53);  //aparece a esquerda
	arvinsere ( arvereraiz, 27);  //aparece a esquerda (folha)
	
	
	imprimeraiz(arvereraiz);
	
	printf("\nNumero de folhas: %d \n", folhasRaiz(arvereraiz));
	
	if(raizbusc(arvereraiz, 27))
		puts("\nAchou numero 27!!");
	else
		puts("\nNada do numero 27 nessa!");
	
	raizremove(arvereraiz, 156);
	puts("\nRemovendo numero 156...");
	
	imprimeraiz(arvereraiz);
	
	puts("\n\nInserindo valores: 232, 173, 130.\n\nEm teoria, esses valores criam 2 folhas a mais!\n");
	
	arvinsere ( arvereraiz, 232); //aparece a direita do 200 (vira folha) 
	arvinsere ( arvereraiz, 173); //aparece a direita do 165 (vira folha) 
	arvinsere ( arvereraiz, 130); //aparece a esquerda do 165 (vira folha)
	
	imprimeraiz(arvereraiz);
	
	printf("\nNumero de folhas: %d \n", folhasRaiz(arvereraiz));
	
	puts("\n\nInserindo valores: 61, 82, 97, 70.\n\nEm teoria, esses valores criam 3 folhas a mais! \n");
	
	arvinsere ( arvereraiz, 61); //aparece a direita do 53 (vira folha)
	arvinsere ( arvereraiz, 82); //aparece a direita do 67 (vira no interno)
	arvinsere ( arvereraiz, 97); //aparece a direita do 82 (vira folha)
	arvinsere ( arvereraiz, 70); //aparece a esquerda do 82 (vira folha
	
	imprimeraiz(arvereraiz);
	
	printf("\nNumero de folhas: %d \n", folhasRaiz(arvereraiz));
	
	
	return 0;
}
