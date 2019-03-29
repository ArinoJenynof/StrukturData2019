#ifndef ETS_H
#define ETS_H

/* Header file */

struct node
{
	int n;
	struct node *next;
};

struct linklist
{
	struct node *head, *tail;
};

void input_data(struct linklist*, char[]);
void push(struct linklist*, int);
void print_list(struct linklist*);
void merge_list(struct linklist*, struct linklist*, struct linklist*);

#endif
