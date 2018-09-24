#include <stdio.h>
#include <stdlib.h>
#include "load_array.h"
#include <sys/time.h>

void print(unsigned v[], unsigned tam)
{
	unsigned i;
	printf("Tamanho: %u\n", tam);
	for(i = 1; i <= tam; i++)
	{
		printf("v[%u] =  %u\n", i,v[i]);
	}
	puts(" ");

}


unsigned *aux(unsigned array[], unsigned tam)
{
	register unsigned i, k = 0;

	for(i = tam; i > 0; i--)
	{
		k = i -1;
		array[i] = array[k];
	}

	return array;
}

void change(unsigned *n1, unsigned *n2)
{
	unsigned tp;
	tp = *n1;
	*n1 = *n2;
	*n2 = tp;
}

unsigned index_son_left(unsigned i)
{
	return (2 * i);
}

unsigned index_son_right(unsigned i)
{
	return (2 * i + 1);
}

void pushdown(unsigned i, unsigned heap[], unsigned tam)
{
	unsigned H_left, H_right;

	H_left = 0; 
	H_right = 0;
	
	if(index_son_left(i) <= tam)
	{
		H_left = 1;
	}
	
	if(index_son_right(i) <= tam)
	{
		H_right = 1;
	}
	
	if(H_left && !H_right)
	{
		if(heap[i] < heap[index_son_left(i)])
		{
			change(&heap[index_son_left(i)], &heap[i]);
			pushdown( index_son_left(i), heap, tam);

		}
	}
	else
	{
		if(H_left && H_right)
		{
			if(( heap[i] < heap[index_son_left(i)]) || (heap[i] < heap[index_son_right(i)]))
			{
				if(heap[index_son_left(i)] > heap[index_son_right(i)])
				{
					change(&heap[index_son_left(i)], &heap[i]);
					i = index_son_left(i);
				}
				else
				{
					change(&heap[index_son_right(i)], &heap[i]);
					i = index_son_right(i);
				}
				pushdown(i, heap, tam);
			}
		}
	}
}

void makeheap(unsigned heap[], unsigned tam)
{
	unsigned i;

	for(i = tam/2; i >= 1; i--)
	{
		pushdown(i, heap, tam);	
	}
}

void crashheap(unsigned heap[], unsigned tam)
{
	unsigned i;
	unsigned n = tam;
	for(i = 1; i <= n; i++)
	{
		change(&heap[1], &heap[tam]);
		tam--;
		pushdown(1, heap, tam);	
	}
}

unsigned *heapSort(unsigned array[], unsigned tam)
{
	makeheap(array, tam);
	crashheap(array, tam);
	return array;

}

int main()
{
	int i;
	FILE *p;
	double media, tp[3]; 
	unsigned *v;
	unsigned tam;
	char name[100];
	struct timeval ttl;
	double t0,t1;
	puts("tamanho do vetor");
	scanf(" %u", &tam);
	
	puts("nome do arquivo");
	scanf(" %s", name);

	for(i = 0; i < 3; i++)
	{
		v = load_file(name, tam);
		v = aux( v, tam);

		gettimeofday(&ttl, 0);
		t0 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);

		v = heapSort(v, tam);

		gettimeofday(&ttl, 0);
		t1 = ttl.tv_sec + (ttl.tv_usec / 1000000.0);

	
		tp[i] = t1 - t0;
		media+= tp[i];
		printf("\nTime: %.6f \n\n", tp[i]);


	}	

	media = media / 3.0;
	
	
	printf("media  %.6f\n", media);

	p = fopen("HeapSort.txt", "a");

	
	fprintf(p, "\n %s  \n", name);

	fprintf(p, "%s", "media   " );
	fprintf(p, "%f\n", media);	

	free(v);
	fclose(p);

	return 0;


}


