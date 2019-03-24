#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50

struct node
{
    char nama[MAX_LEN];
    struct node *next, *prev;
};

struct linkedlist
{
    struct node *head, *tail;
    size_t linkedlist_size;
};

void add_front(struct linkedlist *lp, char n[])
{
    struct node *box = malloc(sizeof *box);
    strcpy(box->nama, n);
    box->next = box->prev = NULL;

    if (lp->linkedlist_size == 0)
    {
        lp->head = lp->tail = box;
        lp->linkedlist_size++;
    }
    else
    {
        box->next = lp->head;
        lp->head->prev = box;
        lp->head = box;
        lp->linkedlist_size++;
    }
}

void add_back(struct linkedlist *lp, char n[])
{
    struct node *box = malloc(sizeof *box);
    strcpy(box->nama, n);
    box->next = box->prev = NULL;

    if (lp->linkedlist_size == 0)
    {
        lp->head = lp->tail = box;
        lp->linkedlist_size++;
    }
    else
    {
        box->prev = lp->tail;
        lp->tail->next = box;
        lp->tail = box;
        lp->linkedlist_size++;
    }
}

void add_at(struct linkedlist *lp, char n[], int idx)
{
    struct node *box = malloc(sizeof *box);
    box->next = box->prev = NULL;
    strcpy(box->nama, n);

    if (lp->linkedlist_size == 0)
    {
        lp->head = lp->tail = box;
        lp->linkedlist_size++;
    }
    else if (idx == 0)
    {
        add_front(lp, n);
    }
    else if (idx >= lp->linkedlist_size)
    {
        add_back(lp, n);
    }
    else
    {
        int i;
        struct node *tmp = lp->head;
        for (i = 0; i < idx - 1; i++)
        {
            tmp = tmp->next;
        }
        tmp->next->prev = box;
        box->next = tmp->next;
        tmp->next = box;
        box->prev = tmp;
        lp->linkedlist_size++;
    }
}

void del_front(struct linkedlist *lp)
{
    if (lp->linkedlist_size == 0)
        return;

    struct node *tmp = lp->head;
    lp->head = tmp->next;
    lp->head->prev = NULL;
    tmp->next = tmp->prev = NULL;
    free(tmp);
    lp->linkedlist_size--;
}

void del_back(struct linkedlist *lp)
{
    if (lp->linkedlist_size == 0)
        return;

    struct node *tmp = lp->tail;
    lp->tail = tmp->prev;
    lp->tail->next = NULL;
    tmp->next = tmp->prev = NULL;
    free(tmp);
    lp->linkedlist_size--;
}

void del_at(struct linkedlist *lp, int idx)
{
    if (lp->linkedlist_size == 0)
        return;

    if (idx == 0)
    {
        del_front(lp);
    }
    else if (idx >= lp->linkedlist_size - 1)
    {
        del_back(lp);
    }
    else
    {
        int i;
        struct node *tgt = lp->head;
        for (i = 0; i < idx; i++)
        {
            tgt = tgt->next;
        }
        tgt->prev->next = tgt->next;
        tgt->next->prev = tgt->prev;
        tgt->next = tgt->prev = NULL;
        free(tgt);
        lp->linkedlist_size--;
    }
}

void mv(struct linkedlist *lp, int now, int then)
{
    if (lp->linkedlist_size == 0)
        return;

    int i;
    struct node *iter = lp->head;
    for (i = 0; i < now && iter->next != NULL; i++)
    {
        iter = iter->next;
    }
    char cp_nama[MAX_LEN];
    strcpy(cp_nama, iter->nama);
    del_at(lp, now);
    add_at(lp, cp_nama, then);
}

void cp(struct linkedlist *lp, int now, int then)
{
    if (lp->linkedlist_size == 0)
        return;

    int i;
    struct node *iter = lp->head;
    for (i = 0; i < now && iter->next != NULL; i++)
    {
        iter = iter->next;
    }
    char cp_nama[MAX_LEN];
    strcpy(cp_nama, iter->nama);
    add_at(lp, cp_nama, then);
}

void print_list(struct linkedlist *lp)
{
    struct node *tmp = lp->head;
    printf("%Iu\n", lp->linkedlist_size);
    while (tmp != NULL)
    {
        printf("%s\n", tmp->nama);
        tmp = tmp->next;
    }
}

int main()
{
    int i, j;
    char nama[MAX_LEN], cmd[10];
    struct linkedlist *list_nama = malloc(sizeof *list_nama);
    list_nama->head = list_nama->tail = NULL;
    list_nama->linkedlist_size = 0;

    scanf("%s", cmd);
    getchar();
    while (strcmp(cmd, "stop") != 0)
    {
        if (strcmp(cmd, "append") == 0)
        {
            gets(nama);
            add_back(list_nama, nama);
        }
        else if (strcmp(cmd, "prepend") == 0)
        {
            gets(nama);
            add_front(list_nama, nama);
        }
        else if (strcmp(cmd, "mv") == 0)
        {
            scanf("%d %d", &i, &j);
            mv(list_nama, i, j);
        }
        else if (strcmp(cmd, "cp") == 0)
        {
            scanf("%d %d", &i, &j);
            cp(list_nama, i, j);
        }
        else if (strcmp(cmd, "rm") == 0)
        {
            scanf("%d", &i);
            if (i < list_nama->linkedlist_size)
                del_at(list_nama, i);
        }
        else
        {
            printf("Bukan perintah valid\n");
        }
        scanf("%s", cmd);
        getchar();
    }
    print_list(list_nama);
}
