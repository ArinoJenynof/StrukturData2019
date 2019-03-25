#include <stdio.h>
#include <stdlib.h>

struct node
{
    double val;
    struct node *next, *prev;
};

struct deque
{
    struct node *front, *back;
    size_t size;
};

void push_front(struct deque *dp, double newval)
{
    //New node
    struct node *box = malloc(sizeof *box);
    box->next = box->prev = NULL;
    box->val = newval;

    //Insertion
    if (dp->size == 0)
    {
        //Empty queue
        dp->front = dp->back = box;
        dp->size++;
    }
    else
    {
        //Non-empty queue
        dp->front->prev = box;
        box->next = dp->front;
        dp->front = box;
        dp->size++;
    }
}

void push_back(struct deque *dp, double newval)
{
    //New node
    struct node *box = malloc(sizeof *box);
    box->next = box->prev = NULL;
    box->val = newval;

    //Insertion
    if (dp->size == 0)
    {
        //Empty queue
        dp->front = dp->back = box;
        dp->size++;
    }
    else
    {
        //Non-empty queue
        dp->back->next = box;
        box->prev = dp->back;
        dp->back = box;
        dp->size++;
    }
}

void pop_front(struct deque *dp)
{
    if (dp->size == 0)
    {
        //Empty queue
        return;
    }

    //Non-empty queue
    struct node *tgt = dp->front;
    dp->front = tgt->next;
    dp->size--;
    free(tgt);
}

void pop_back(struct deque *dp)
{
    if (dp->size == 0)
    {
        //Empty queue
        return;
    }

    //Non-empty queue
    struct node *tgt = dp->back;
    dp->back = tgt->prev;
    dp->size--;
    free(tgt);
}

void print(struct deque *dp)
{
    if (dp->size == 0)
        puts("KOSONG");
    else if (dp->size == 1)
        printf("%lf\n", dp->front->val);
    else
        printf("%lf %lf\n", dp->front->val, dp->back->val);
}

int main()
{
    //Variables and other things
    int t, d;
    double val;

    //Queue initialization
    struct deque *dp = malloc(sizeof *dp);
    dp->back = dp->front = NULL;
    dp->size = 0;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &d);
        if (d == 1)
        {
            scanf("%lf", &val);
            push_front(dp, val);
        }
        else if (d == 2)
        {
            scanf("%lf", &val);
            push_back(dp, val);
        }
        else if (d == 3)
        {
            pop_front(dp);
        }
        else if (d == 4)
        {
            pop_back(dp);
        }
        else if (d == 5)
        {
            print(dp);
        }
        else
        {
            printf("Bukan perintah valid\n");
        }
    }
    return 0;
}
