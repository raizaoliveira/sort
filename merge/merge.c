#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>

void print(int v[], unsigned tam)
{
	unsigned i;
	for(i = 0; i <= tam + 2; i++)
	{
		printf("%d     ", v[i]);
	}
	puts(" ");

}



void intercalar(int v[], int aux[], int ini1, int ini2, int fim2)
{
	int in1 = ini1, in2 = ini2, fim1 = in2 - 1, au = 0;
	int i;

	
	while(in1 <= fim1  && in2 <= fim2)
	{
		if(v[in1] < v[in2])
		{
			aux[au++] = v[in1++];
		}
		else
		{
			aux[au++] = v[in2++];
		}
	}
	while(in1 <= fim1)
	{
		aux[au++] = v[in1++];
	}
	while(in2 <= fim2)
	{
		aux[au++] = v[in2++];
	}
	
	for(i = 0; i < au; i++)
	{
		v[i + ini1] = aux[i];
	}


}

int  *mergeSort(int v[], int aux[], int esq, int dir)
{
	int meio;

	if(esq < dir)
	{
		meio = (esq + dir)/ 2;
		mergeSort(v, aux, esq, meio);
		mergeSort(v, aux, meio + 1, dir);
		intercalar(v, aux, esq, meio + 1, dir);

	}


	return v;

}



int main()
{
	FILE *p;
	int *v, *aux;
	unsigned tam;
	char name[100];
	struct timeval ttl;
	double t0,t1;
	int i;
	double tp[3], media = 0;
	puts("tamanho do vetor");
	scanf(" %u", &tam);
	
	puts("nome do arquivo");
	scanf(" %s", name);

	for(i = 0; i < 3; i++)
	{
		aux = (int *) calloc(tam + 1, sizeof(int));
		v = load_file(name, tam);

		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);

		v = mergeSort(v, aux, 0, tam - 1);

		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
	
		tp[i] = t1 - t0;
		media+= tp[i];
		printf("\nTime: %.6f \n\n", tp[i]);	
	}

	
	media = media / 3.0;
	
	
	printf("media  %.6f\n", media);

	p = fopen("merge.txt", "a");
	
	fprintf(p, "\n %s  \n", name);

	fprintf(p, "%s", "media   " );
	fprintf(p, "%f\n", media);	


	fclose(p);
	free(v);
	free(aux);
	return 0;
}


