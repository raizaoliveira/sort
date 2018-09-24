#include "load_array.h"


int  *load_file(char *name, unsigned lenght)
{
	FILE *p;
	unsigned i;
	int *ptno = ( int*) calloc (lenght + 1,sizeof (int));
	p = fopen( name, "rb");
	if(!p)
	{
		puts("Nao abriu");
		return NULL;
	}

	else
	{
		for(i = 0; i < lenght; i++)
		{
			fread (&ptno[i], sizeof(int), 1, p);
		}

		return ptno;
	}
	puts(" ");
	fclose(p);
}
