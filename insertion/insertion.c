#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>


int *aux(int array[], int tam)
{
	int i, k = 0;

	for(i = tam; i > 0; i--)
	{
		k = i -1;
		array[i] = array[k];
	}

	return array;
}


void print(int v[], int tam)
{
	int i;
	for(i = 0; i < tam; i++)
	{
		printf("%d     ", v[i]);
	}
	puts(" ");

}


int  *insertion(int vet[], int N)
{
	int i, j;
	int atual;
	for(j = 1; j < N; j++)
	{
		atual = vet[j];
		i = j - 1;

		while((i >= 0) && (vet[i] > atual))
		{
			vet[i + 1] = vet[i];
			i--;
		}
	vet[i + 1] = atual;
	}

	return vet;
}

int main()
{
	FILE *p;
	int *v;
	int tam;
	char name[100];
	struct timeval ttl;
	double t0,t1;
	int i;
	double tp[3], media = 0;
	puts("tamanho do vetor");
	scanf(" %d", &tam);
	
	puts("nome do arquivo");
	scanf(" %s", name);

	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);

		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);

		v = insertion(v , tam);	

		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
	
		tp[i] = t1 - t0;
		media+= tp[i];
		printf("\nTime: %.6f \n\n", tp[i]);	
	}

	
	media = media / 3.0;
	
	
	printf("media  %.6f\n", media);

	p = fopen("InsertionSort.txt", "a");

	
	fprintf(p, "\n %s  \n", name);
	
	fprintf(p, "%s", "media   " );
	fprintf(p, "%f\n", media);	

	free(v);
	fclose(p);
	return 0;
}


