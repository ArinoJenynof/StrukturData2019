# TTYSED - Terminal Sederhana
### Ringkasan
6 command

1. _append_, menambahkan data ke belakang.
2. _prepend_, menambahkan data ke depan.
3. _mv_, pindahkan data di _i_ ke index _j_.
4. _cp_, _copy_ data di _i_ ke index _j_.
5. _rm_, hapus data di index _i_.
6. _stop_, berhentikan program.

### `struct` dan fungsi
`struct` linked list
```C
struct node
{
    char nama[MAX_LEN];       //MAX_LEN = panjang maksimum string
    struct node *next, *prev;
};

struct linkedlist
{
    struct node *head, *tail;
    size_t linkedlist_size;
};
```
Fungsi `add_*`
```C
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
```
Fungsi `del_*`
```C
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
```
`mv` dan `cp` _wrapper function_.
```C
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
```
Untuk `rm`, panggil fungsi `del_at()` dengan terlebih dahulu mengecek apakah yang dihapus adalah data yang valid.
