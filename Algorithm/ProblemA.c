#include<stdio.h>
#include<limits.h>

int A[100], n;

void Bubble()
{
    int i, j, tmp;
    for (i=1;i<=n-1;i++)
    {
        for (j=n;j>=i+1;j--)
        {
            if (A[j]<A[j-1])
            {
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
    }
}

int main()
{
    int k, i, tmp, ODD[100];
    //tmp = MIN_INT;

    scanf("%d", &n);
    for (i=1;i<=n;i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d", &k);

    Bubble();

    /*for (i=1;i<=n;i++)
    {
        printf("%d  ", A[i]);
    }*/
    //j = 1;
    for (i=n;i>=1;i--)
    {
        if (A[i]%2!=0 && k>0)
        {
            //ODD[j] = A[i];
            printf("%d  ", A[i]);
            k--;
            //j++;
        }
    }
    while(k>0)
    {
        printf(" NULL");
        k--;
    }

    return 0;
}
