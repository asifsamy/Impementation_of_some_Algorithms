#include<stdio.h>
#include<stdlib.h>

#define N 10

int Q[N], rear = 0, frnt = 0;

void Enqueue(int e)
{
    if(rear==N)
        printf("\nQueue is full\n");
    else if(frnt==0 && rear==0)
    {
        Q[frnt] = e;
        frnt++;
        Q[rear] = e;
        rear++;
    }
    else
    {
        Q[rear] = e;
        rear++;
    }
}

int Dequeue()
{
    int tmp;
    if (frnt<0)
        printf("\nQueue is empty\n");
    else
    {
        tmp = Q[frnt];
        frnt++;
        return tmp;
    }
}

void DisplayQueue()
{
    int i;
    if(frnt<0)
        printf("\nQueue is empty\n");
    else
    {
        printf("\nThe queue lists: ");
        for (i=frnt-1;i<rear;i++)
        {
            printf("%d", Q[i]);
        }
    }
}

int main()
{
    int key, element;
    system("cls");
    do
    {
        printf("\nPress 1 for Enqueue an element");
        printf("\nPress 2 for Dequeue an element");
        printf("\nPress 3 for Display the queue");
        printf("\nPress 4 for Exit");
        scanf("%d", &key);
        switch(key)
        {
        case 1:
            printf("\nInput the element: ");
            scanf("%d", &element);
            Enqueue(element);
            break;
        case 2:
            printf("\nDequeued element is = %d",Dequeue());
            break;
        case 3:
            DisplayQueue();
            break;
        }
    }while(key!=4);
}
