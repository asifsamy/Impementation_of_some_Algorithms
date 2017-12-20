#include<stdio.h>
#include<string.h>

int c[100][100], m, n, k, l;
char X[100], Y[100];

void LCS_Calculate();
int PRINT_LCS();
void PRINT(int length);
int PRINT_LCS_Others(int length);

int main()
{
    int length;
    printf("X:");
    scanf("%s", X);

    printf("Y:");
    scanf("%s", Y);

    LCS_Calculate();

    printf("\nLength = %d", PRINT_LCS());

    printf("\n\n\Input Length: ");
    scanf("%d", &length);

    printf("\nTotal Strings of length %d is = %d\n", length, PRINT_LCS_Others(length));

    return 0;
}

void LCS_Calculate()
{
    int i, j;
    m = strlen(X);
    n = strlen(Y);

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
            }
            else
                c[i][j] = 0;
        }
    }

}

int PRINT_LCS()
{
    int i, j, length = 0;
    k = 0; l = 0;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(length<c[i][j])
            {
                length = c[i][j];
                k = i;
                l = j;
            }
        }
    }

    PRINT(length);

    return length;
}

void PRINT(int length)
{
    char p[100];
    int i = 1;
    while(c[k][l]>=1)
    {
        p[i] = X[k-1];
        l--;
        k--;
        i++;
    }
    printf("\nLCS = ");
    for(i=length;i>=1;i--)
    {
        printf("%c", p[i]);
    }
}

int PRINT_LCS_Others(int length)
{
    int i, j, cnt = 0;
    k = 0; l = 0;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(length==c[i][j])
            {
                k = i;
                l = j;
                PRINT(length);
                cnt++;
            }
        }
    }

    return cnt;
}
