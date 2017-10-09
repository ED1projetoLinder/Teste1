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
	struct nodo *ant;
}nodo;

typedef struct arv_nodo
{
	dados info;
	struct node *left;
	struct node *right;
	struct node *father;
}arv_nodo;


typedef nodo* pistas;
typedef nodo* lista_voos;
typedef arv_nodo* ARV_BIN_ENC;

void maketree(ARV_BIN_ENC *,dados);
void ins_ele(ARV_BIN_ENC*,dados);
void insere_fim(lista_voos *,dados inf);
void salvarlista(lista_voos ,FILE *);
void lerarquivo(lista_voos *,FILE *);
void cria_voo(lista_voos*,FILE *,ARV_BIN_ENC *,lista_voos*m,int);
void remove_voo(lista_voos*,dados);
dados busca_voo(ARV_BIN_ENC t);
void gerenciar_pistas(pistas*);
void listar_voos_empresas(lista_voos,char[]);
void listar_voos_locais(lista_voos,char[]);
void listar_voos_inat(lista_voos);
void listar_voos_espera(lista_voos);
