#include <stdio.h>
#include <stdlib.h>
#define HORAMAX 24 
#define NUMPISTAS 5
typedef struct dados
{
	char empresa[60];
	char cidade[50];
	int horario;
	short int modo;//ida  ou volta (0 é saida, 1 é chegada)
	int pista;
    int num_id;//o número do avião
}dados;


typedef struct nodo
{
	dados inf;
	struct nodo *next; 
}nodo;

typedef nodo* pistas;
typedef nodo* listavoos;
// falta definir o de árvore;

void menu();
void cria_voo(listavoos*,dados);
void remove_voo(listavoos*,dados);
void gerenciar_pistas(pistas*);
void listar_ult_voos(listavoos);
void listar_prox_voos(listavoos);
void listar_tds_voos(listavoos);
