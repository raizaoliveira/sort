#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>

int *bubbleSort(int array[], unsigned lenght)
{
	unsigned i, j;
	int aux;

	for(i = 0; i < lenght; i++)
	{
		for(j = 0; j < lenght - 1 ; j++)
		{
			if(array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
	}
	return array;
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

	int *v;
	unsigned tam;
	char name[100];
	struct timeval ttl;
	double t0,t1;
	puts("tamanho do vetor");
	scanf(" %u", &tam);
	
	puts("nome do arquivo");
	scanf(" %s", name);

	v = load_file(name, tam);

	gettimeofday(&ttl, 0);
	t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);

	v = bubbleSort(v, tam);

	gettimeofday(&ttl, 0);
	t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);
	
	printf("\nTime: %.10f \n\n", t1 - t0);	
	
	return 0;
}




