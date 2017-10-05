#include <stdio.h>
#include <stdlib.h>
#define HORAMAX 24 

typedef struct dados
{
	char empresa[60];
	char cidade[50];
	int numpass;
	int horario;
	int ativo;
	int pista;
}dados;


typedef struct nodo
{
	dados inf;
	struct nodo *next; 
}nodo;

typedef nodo* pistas;
typedef nodo* listavoos;
// falta definir o de árvore;


void cria_voo(listavoos*,dados);
void remove_voo(listavoos*,dados);
void gerenciar_pistas(pistas*);
void listar_ult_voos(listavoos);
void listar_prox_voos(listavoos);
void listar_tds_voos(listavoos);
