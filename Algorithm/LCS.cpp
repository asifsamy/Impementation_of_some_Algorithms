#include<stdio.h>
#include<string.h>

int b[20][20], c[20][20], m, n;
char X[20], Y[20];

void LCS_LENGTH()
{
    int i, j;
    m = strlen(X);
    n = strlen(Y);

    //int b[m][n], c[m+1][n+1];

    //printf("\nm = %d", m);
    //printf("\nn = %d", n);

    for (i=0;i<=m;i++)
    {
        c[i][0] = 0;
    }
    for (j=0;j<=n;j++)
    {
        c[0][j] = 0;
    }
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (X[i-1]==Y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }
            else if (c[i-1][j]>=c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }

}

void PRINT_LCS(int i, int j)
{
    if (i==0 || j==0)
        return;
    if (b[i][j]==1)
    {
        PRINT_LCS(i-1, j-1);
        printf("%c", X[i-1]);
    }
    else if (b[i][j]==2)
        PRINT_LCS(i-1, j);
    else
        PRINT_LCS(i, j-1);
}

int main()
{
    printf("X:");
    scanf("%s", X);

    printf("Y:");
    scanf("%s", Y);


    LCS_LENGTH();

    printf("\n%d", c[m][n]);

    printf("\n");

    PRINT_LCS(m, n);

    return 0;
}
