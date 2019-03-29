#include <stdlib.h>
#include "ETS.h"

void push(struct linklist *ptr, int n)
{
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->n = n;
	tmp->next = NULL;

	if (ptr->head == NULL)
    {
        ptr->head = ptr->tail = tmp;
    }
    else
    {
        ptr->tail->next = tmp;
        ptr->tail = tmp;
    }
}
