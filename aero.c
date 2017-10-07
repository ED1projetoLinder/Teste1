#include "aero.h"


void maketree(ARV_BIN_ENC *t, dados x)
{
	*t = (ARV_BIN_ENC) malloc (sizeof (arv_nodo));
	if (!(*t))
	{
		printf("Erro! Nao existe memoria disponivel!");
		exit (1);
	}
	(*t)->info = x;
	(*t)->left = NULL;
	(*t)->right = NULL;
	(*t)->father = NULL;
}

void ins_ele (ARV_BIN_ENC *arv, dados v)
{
	if (!(*arv))
		maketree(arv, v);
	else
		if (v.horario<(*arv)->info.horario)
			ins_ele(&((*arv)->left), v);
		else
			ins_ele(&((*arv)->right), v);
}	

void insere_fim(lista_voos *l,dados valores)
{
	nodo *novo;
	lista_voos aux;
	novo = (nodo*) malloc(sizeof(nodo));
	if(!novo)
	{
		printf("nao ha memoria no sistema");
	}
	novo->inf=valores;

	for(;aux->next!=NULL;aux=aux->next);
	novo->next=aux->next;
	aux->next=novo;
	free(aux);
}

void lerarquivo(lista_voos *l,FILE *arq)
{
	arq= fopen("listadevoos.dat","rb");
	dados info_voo;
	lista_voos aux=*l;
	if(arq)
	{
		while(!feof(arq))
		{	
				fread(&info_voo,sizeof(dados),1,arq);
				insere_fim(&aux,info_voo);
				aux=aux->next;
		}
	}
	fclose(arq);
}
void salvarlista(lista_voos l,FILE *arq)
{
	
	arq= fopen("listadevoos.dat","ab");
	if(arq)
	{
		while(!l)
		{
			fwrite(&(l->inf),sizeof(dados),1,arq);
			l=l->next;
		}
	}
	
	fclose(arq);

}

void cria_voo(lista_voos *l,FILE *arq,ARV_BIN_ENC *t)
{
	int horavoo=-1,cont;
	nodo *novo;
	lista_voos aux=*l;
	novo=(nodo*) malloc (sizeof (nodo));
	
	if(!novo)//teste de memoria
	{
		printf("falta de memoria\n");
		exit(1);
	}
	else
	{
		do
		{
			printf("\ninforme o horário em que o voo sera inserido(entre 0 e 23), no formato hh. ex: 16 para 16:00 ");
			scanf("%d",&horavoo);
			if(horavoo<0||horavoo>23)
				printf("\nhora invalida, somente valido entre 0 e 23");
		}while(horavoo<0||horavoo>23);
	
	for(;aux->inf.horario<horavoo||aux!=NULL;aux=aux->next);//enquanto os voos forem menor que o horavoo, passa pro próximo, até encontrar a posição
	for(cont=0;aux->inf.horario==horavoo;cont++,aux=aux->next);	//encontrando se tem voos iguais
		
	if(cont>=NUMPISTAS)//se cont for igual ou maior que o numero de pistas, não há pistas disponíveis
	{
		printf("\ntodas as pistas ja estao ocupadas");
		system("PAUSE");
		//menu(); ta dando erro nessa linha
	}
	else
	{
		novo->next=aux->next;
		aux->next=novo;
		do
		{
			printf("\nO voo e de chegada ou saida?(0 pra ida,1 para chegada)       ");
			scanf("%d",&novo->inf.modo);
	 	}while(novo->inf.modo==0||novo->inf.modo==1);
		if(novo->inf.modo==0)
	 	{
			printf("\ndigite qual a cidade destino:    ");
	 	}else
	 	{
	 		printf("\ndigite a cidade de qual o voo vem:    ");
		}
		
		scanf("%s",novo->inf.cidade);
		printf("\ninforme a empresa que fornece o voo:      ");
		scanf("%s",novo->inf.empresa);
		novo->inf.horario=horavoo;
		printf("\ninsira numero de identificacao do aviao utilizado:      ");
		scanf("%d",&novo->inf.num_id);
		novo->inf.pista=cont+1;
		
		salvarlista(*l,arq);
		if(novo->inf.horario);
		free(aux);
	}	
	
	}
}



dados busca_voo(ARV_BIN_ENC t)
{
	int horario,contador;
	char local[50];
	short int ida_volta;
	
	
	do
	{
		printf("\nInforme se o voo esta chegando ou saindo(0 para saida, 1 para chegada)  ");
		scanf("%d",&ida_volta);
	}while(ida_volta!=0||ida_volta!=1);
	
	printf("\ninforme a cidade:   ");
	scanf("%s",local);	
	
	do
	{
		printf("\nselecione o horario do voo procurado:    ");
		scanf("%d",&horario);
	}while(horario<0||horario>23);
	
	while(!t)
	{
		if(horario<t->info.horario)
		{
			t=t->left;
		}else
		{
			if(horario>t->info.horario)
			{
				t=t->right;
			}else
			{
				if(horario==t->info.horario)
				{
					if(t->info.cidade==local)
					 	return t->info;
					else
						t=t->right;
				}else
				{
					printf("nao ha voos neste horario");
					exit(1);
				}
			}
		}
		
	}	
	
}
void listar_voos_empresas(lista_voos l,char empresa[60])
{
	while(!l)
	{
		if(l->inf.empresa==empresa)
		{
			printf("\n%s",l->inf.cidade);
			printf("\n%s",l->inf.empresa);
			printf("\n%d",l->inf.horario);
			if(l->inf.modo==0)
				printf("\nvoo de ida ");
			else
				printf("\nvoo de volta");
				
			printf("\n%d",l->inf.num_id);
			printf("\n%d",l->inf.pista);		
		}
		l=l->next;
	}
	
}

void listar_voos_local(lista_voos l,char local[60])
{
	while(!l)
	{
		if(l->inf.cidade==local)
		{
			printf("\n%s",l->inf.cidade);
			printf("\n%s",l->inf.empresa);
			printf("\n%d",l->inf.horario);
			if(l->inf.modo==0)
				printf("\nvoo de ida ");
			else
				printf("\nvoo de volta");
				
			printf("\n%d",l->inf.num_id);
			printf("\n%d",l->inf.pista);}
		l=l->next;
	}
	
}

