#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int M[500010];

void MERGE(int p, int q, int r)
{
    int i, j, k, n1, n2;
    n1 = q-p+1;
    n2 = r-q;
    int L[n1+1], R[n2+1];

    for (i=1;i<=n1;i++)
    {
        L[i] = M[p+i-1];
    }
    for (j=1;j<=n2;j++)
    {
        R[j] = M[q+j];
    }

    L[n1+1] = 2147483647;
    R[n2+1] = 2147483647;

    i=1;
    j=1;
    for (k=p;k<=r;k++)
    {
        if (L[i]<=R[j])
        {
            M[k] = L[i];
            i=i+1;
        }
        else
        {
            M[k] = R[j];
            j=j+1;
        }
    }

}

void MERGE_SORT(int p, int r)
{
    int q;
    if (p<r)
    {
        q = (p+r)/2;
        MERGE_SORT(p, q);
        MERGE_SORT(q+1, r);
        MERGE(p, q, r);
    }
}

int main()
{
    int i, n;
    double d;
    long time1;
    long start, stop;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    srand(time(NULL));
    printf("\nEnter the numbers: ");
    for (i=1;i<=n;i++)
    {
        //scanf("%d", &M[i]);
        M[i] = rand() % 100;
        //printf("%d   ", M[i]);
    }

    start = clock();
    MERGE_SORT(1, n);
    stop = clock();

    time1 = stop - start;
    d = (double)time1/CLOCKS_PER_SEC;

    printf("\n\n");

    printf("\nThe merged sorted array: ");
    /*for (i=1;i<=n;i++)
    {
        printf("%d   ", M[i]);
    }*/

    printf("\nRunning time for Merge Sort: %lf", d);

    return 0;
}
