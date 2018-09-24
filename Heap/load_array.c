#include "load_array.h"


unsigned  *load_file(char *name, unsigned lenght)
{
	FILE *p;
	unsigned i;
	unsigned *ptno = ( unsigned*) calloc (lenght + 1,sizeof (unsigned));
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
			fread (&ptno[i], sizeof(unsigned), 1, p);
		}

		return ptno;
	}
	puts(" ");
	fclose(p);
}
