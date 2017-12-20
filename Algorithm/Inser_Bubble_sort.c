#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int A[5100000],B[5100000],n;

void InsertionSort()
{
    int tmp, i, j;
    for(j=2;j<=n;j++)
    {
        tmp = A[j];
        i = j-1;
        while(i>0 && A[i]>tmp)
        {
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = tmp;
    }
}

void BubbleSort()
{
    int tmp,i,j;
    for(i=1;i<=n-1;i++)
    {
        for(j=n;j>=i+1;j--)
        {
            if(B[j]<B[j-1])
            {
                tmp = B[j];
                B[j] = B[j-1];
                B[j-1] = tmp;
            }
        }
    }
}

int main()
{
    int i;
    long time1, time2;
    double d1, d2;
    clock_t start1, stop1, start2, stop2;
    printf("Enter the size: ");
    scanf("%d", &n);

    srand(time(NULL));
    //printf("Input data set: ");
    for(i=1;i<=n;i++)
    {
        A[i] = rand() % 100;
        B[i] = A[i];
        //printf("%d   ", A[i]);
    }

    printf("\nAfter Bubble sorting");
    start1 = clock();
    BubbleSort();
    stop1 = clock();

    time1 = stop1 - start1;
    d1 = (double)time1/CLOCKS_PER_SEC;
    printf("\nExecution time for bubble sort: %lf", d1);

    printf("\n\n");

    /*for(i=1;i<=n;i++)
    {
        printf("%d  ", B[i]);
    }*/

    printf("\nAfter Insertion Sort");
    start2 = clock();
    InsertionSort();
    stop2 = clock();

    time2 = stop2 - start2;
    d2 = (double)time2/CLOCKS_PER_SEC;
    printf("\nExecution time for insertion sort: %lf", d2);

    /*printf("\n\n");

    for(i=1;i<=n;i++)
    {
        printf("%d  ", A[i]);
    }*/

    return 0;
}

