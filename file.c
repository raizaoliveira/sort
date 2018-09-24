#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void create(char *name, unsigned lenght)
{
	int *pv;
	
	FILE *pt;	
	
	register int i;	

	pv = (int *) calloc(lenght + 1, sizeof(int));

	srand(time(NULL));
	for(i = 0; i < lenght; i++)
	{
		pv[i] = rand()% lenght;
	}
	
	pt = fopen( name, "wb");

	if(!pt)
	{
		puts("Nao abriu");
	}
	else
	{
		
		fwrite(pv, sizeof(int), lenght, pt);
		fclose(pt);
	}
	free(pv);
}

void testa_arq(char *name, unsigned lenght)
{
	FILE *p;
	int i;
	int *ptno = ( int*) calloc (lenght + 1,sizeof (int));
	p = fopen( name, "rb");
	if(!p)
	{
		puts("Nao abriu");
	}

	else
	{
		for(i = 0; i < lenght; i++)
		{
			fread (&ptno[i], sizeof(int), 1, p);
			printf("%d , ", ptno[i]);
		}
	}
	puts(" ");
	fclose(p);
}



int main()
{
	int resp;
	long int tam;
	char nome[100];
	do{

		printf("tamanho:  ");
		scanf(" %lu", &tam);
		printf("nome:    ");
		scanf(" %s", nome);
		create(nome, tam);
	
		/*testa_arq(nome, tam);*/

		printf("Sair 1\n");
		scanf(" %d", &resp);
	}while(resp != 1);
	return 0;
}








