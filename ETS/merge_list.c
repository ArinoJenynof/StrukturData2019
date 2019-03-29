#include <stdlib.h>
#include "ETS.h"

void merge_list(struct linklist *list1, struct linklist *list2, struct linklist *list_merged)
{
    struct node *tmp1 = list1->head;
    struct node *tmp2 = list2->head;

    while (tmp1 != NULL && tmp2 != NULL)
    {
        if (tmp1->n < tmp2->n)
        {
            push(list_merged, tmp1->n);
            tmp1 = tmp1->next;
        }
        else
        {
            push(list_merged, tmp2->n);
            tmp2 = tmp2->next;
        }
    }

    if (tmp1 == NULL)
    {
        while (tmp2 != NULL)
        {
            push(list_merged, tmp2->n);
            tmp2 = tmp2->next;
        }
    }
    else
    {
        while (tmp1 != NULL)
        {
            push(list_merged, tmp1->n);
            tmp1 = tmp1->next;
        }
    }
}
