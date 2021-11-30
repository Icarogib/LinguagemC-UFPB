#ifndef ARVERE_H
#define ARVERE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvorebin ArvBin;

struct arvorebin {
	int num;
	ArvBin* dir;
	ArvBin* esq;
};

typedef struct raiztot ArvRaiz;

struct raiztot {
	ArvBin* raiz;
};

ArvRaiz *cria_arv ( );

static ArvBin* busca ( ArvBin *r, int val );

ArvBin * raizbusc ( ArvRaiz* rz, int val );

static ArvBin* inseregalho (ArvBin* r, int val);

void arvinsere (ArvRaiz* r, int val);

static ArvBin * removegalho (ArvBin * r, int val);

ArvBin * raizremove (ArvRaiz * r, int val);

int folhas (ArvBin* a);

int folhasRaiz (ArvRaiz *ar);

static void imprime (ArvBin* r);

void imprimeraiz (ArvRaiz* raiz);

#endif
