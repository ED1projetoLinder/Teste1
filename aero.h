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
typedef nodo* lista_voos;
// falta definir o de árvore;

void insere_fim(lista_voos *,dados inf);
void salvarlista(lista_voos l,FILE *);
void menu();
void cria_voo(lista_voos*,FILE *);
void remove_voo(lista_voos*,dados);
void gerenciar_pistas(pistas*);
void listar_ult_voos(lista_voos);
void listar_prox_voos(lista_voos);
void listar_tds_voos(lista_voos);
