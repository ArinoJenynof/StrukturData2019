#include <stdio.h>
#include <stdlib.h>
#include "ETS.h"

void input_data(struct linklist *ptr, char dir[])
{
	int n;
	FILE *in = fopen(dir,"r");
	if (in == NULL)
	{
		printf("File failed to open\n");
	}
	while (fscanf(in, "%d", &n) != EOF)
	{
		push(ptr, n);
	}
}
