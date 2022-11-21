#define MaxN 50
#define BASE 10
#define LEN sizeof(struct node)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int k;
    struct node *link;
} QLINK;

void rsort(QLINK *front, int n, int d);

int main(int argc, char const *argv[])
{
    int arr[] = {134, 891, 215, 7865, 308,10,3};
    int n = 6;
    QLINK *front = NULL, *rear = NULL;
    for (int i = 0; i < n; i++)
    {
        struct node *l = (struct node *)malloc(LEN);
        l->k = arr[i];
        if (rear == NULL)
        {
            front = rear = l;
        }
        else
        {
            rear->link = l;
            rear = rear->link;
        }
    }

    QLINK *p = front;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p->k);
        p = p->link;
    }
    rsort(front, n, 4);
    p = front;
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p->k);
        p = p->link;
    }
    return 0;
}

int breakI(QLINK *q, int i)
{
    return (q->k / ((int)pow(10, i - 1))) % 10;
}

void rsort(QLINK *front, int n, int d)
{
    QLINK *F[MaxN], *E[MaxN], *q, *rear;
    int j, u;
    for (int i = 1; i <= d; i++)
    {
        for (j = 0; j < BASE; j++)
        {
            F[j] = NULL;
            E[j] = NULL;
        }
        q = front;
        while (q != NULL)
        {
            u = breakI(q, i);
            if (F[u] == NULL)
            {
                F[u] = q;
            }
            else
            {
                E[u]->link = q;
            }
            E[u] = q;
            q = q->link;
        }
        j = 0;
        while (F[j] == NULL)
        {
            j++;
        }
        front = F[j];
        rear = E[j];
        F[j] = NULL;
        for (u = j + 1; u < BASE; u++)
        {
            if (F[u] != NULL)
            {
                rear->link = F[u];
                rear = E[u];
                F[u] = NULL;
            }
        }
        rear->link = NULL;
    }
}
