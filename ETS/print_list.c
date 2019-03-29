#include <stdio.h>
#include <stdlib.h>
#include "ETS.h"

void print_list(struct linklist *ptr)
{
	struct node *tmp = ptr->head;
	while (tmp != NULL)
	{
		printf("%d ", tmp->n);
		tmp = tmp->next;
	}
}
