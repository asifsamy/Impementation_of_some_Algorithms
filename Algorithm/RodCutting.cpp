#include<stdio.h>
#include<limits.h>

int P[50], n;

struct CutRod
{
    int r[50];
    int s[50];
};

struct CutRod EXTENDED_BOTTOM_UP_CUT_ROD()
{
    struct CutRod result;
    int q, i, j, k, r[n+1], s[n+1];
    r[0] = 0;
    result.r[0] = r[0];

    for(j=1;j<=n;j++)
    {
        q = INT_MIN;
        printf("\ns[%d] = ", j);
        for (i=1; i<=j; i++)
        {
            if (q<P[i]+r[j-i])
            {
                q = P[i]+r[j-i];
                s[j] = i;
                result.s[j] = s[j];
            }
        }
        printf(" %d  ", result.s[j]);
        r[j] = q;
        result.r[j] = r[j];
        //printf(" %d  ", result.r[j]);
    }

    printf("\n\nr =");
    for (k=0;k<=n;k++)
    {
        printf(" %d  ", result.r[k]);
    }

    return result;

}

void PRINT_CUT_ROD_SOLUTION()
{
    struct CutRod result;
    result = EXTENDED_BOTTOM_UP_CUT_ROD();
    printf("\n\nMaximum achievable revenue: %d", result.r[n]);
    printf("\n\nOptimal solutions: ");
    while(n>0)
    {
        printf("%d  ", result.s[n]);
        n = n - result.s[n];
    }
    printf("\n");
    //return result;
}

int main()
{
    //struct CutRod result;
    int i;
    printf("length: ");
    scanf("%d", &n);

    printf("Prices of pieces: ");
    for(i=0;i<=n;i++)
    {
        scanf("%d", &P[i]);
    }

    PRINT_CUT_ROD_SOLUTION();


    return 0;

}
