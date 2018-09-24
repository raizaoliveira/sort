/*
Algoritmo bubble Sort versao melhorada
UEMS
Ciencia da computacao- AED II
programadora: Raiza Arteman
rgm: 23428
data da ultima modoficacao : 30/10/2013


*/

#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>
#define true 1
#define false 0

typedef int bool;

int *bubbleSort(int vet[], int N)
{
	bool mudou;
	int n;
	int j, i;
	int guarda;
	int aux;
	mudou = true;
	n = N;
	guarda = n;

	while(mudou)
	{
		j = 0;
		mudou = false;
		while(j < n)
		{

			i = j;
			++i;
			if(vet[j] > vet[i])
			{

				if(i < N)
				{
					aux = vet[j];
					vet[j] = vet[i];
					vet[i] = aux;
				}
				mudou = true;
				guarda = j;

			}
			j += 1 ;
			
		}
		n = guarda;
	}
	return vet;
	
}



void print(int v[], unsigned tam)
{
	unsigned i;
	for(i = 0; i < tam; i++)
	{
		printf("   %d", v[i]);
	}
	puts(" ");

}

int main()
{	

	FILE *p;
	int i;
	int *v;
	unsigned tam;
	char name[100];
	struct timeval ttl;
	double t0,t1;
	double tp[3], media = 0;
	puts("tamanho do vetor");
	scanf(" %u", &tam);
	
	puts("nome do arquivo");
	scanf(" %s", name);

	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);

		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);

		v = bubbleSort(v, tam);

		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);

	
		tp[i] = t1 - t0;
		media+= tp[i];
	
		printf("\nTime: %.6f \n\n", tp[i]);	
	}


	media = media / 3.0;
	
	
	printf("media  %.6f\n", media);

	p = fopen("bubble_com_melhorias.txt", "a");

	
	fprintf(p, "\n %s  \n", name);

	fprintf(p, "%s", "media   " );
	fprintf(p, "%f\n", media);	


	fclose(p);
	return 0;
}


