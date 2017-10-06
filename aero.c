#include "aero.h"


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

void cria_voo(lista_voos *l,FILE *arq)
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
		
		scanf("%s",&novo->inf.cidade);
		printf("\ninforme a empresa que fornece o voo:      ");
		scanf("%s",&novo->inf.empresa);
		novo->inf.horario=horavoo;
		printf("\ninsira numero de identificacao do aviao utilizado:      ");
		scanf("%s",&novo->inf.num_id);
		novo->inf.pista=cont+1;
		
		salvarlista(*l,arq);
		free(aux);
	}	
	
	}
}
