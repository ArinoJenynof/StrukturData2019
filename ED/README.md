# ED - Easy Deque
Soal terinspirasi dari [STACKEZ](https://www.spoj.com/problems/STACKEZ)

Syarat-syarat hampir sama dengan STACKEZ, hanya berbeda di bagian-bagian berikut
1. Nilai yang disimpan berupa bilangan real, bukan integer
2. Print kedua nilai yang ada di depan dan belakang
3. Jika hanya ada satu, maka print satu saja

## `struct` Dan Fungsi
### `struct` deque
```C
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
```
### Fungsi `push_front()`
```C
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
```
### Fungsi `push_back()`
```C
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
```
### Fungsi `pop_front()`
```C
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
```
### Fungsi `pop_back()`
```C
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
```
