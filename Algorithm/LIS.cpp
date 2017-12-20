#include<stdio.h>

int n, A[100], LIS[100], length;

void CalculateLIS();
void PrintLIS();

int main()
{
    int i;

    printf("Size of array: ");
    scanf("%d", &n);

    printf("Input Array: ");
    for (i=0;i<n;i++)
    {
        scanf("%d", &A[i]);
    }

    CalculateLIS();
    printf("\n");

    return 0;
}

void CalculateLIS()
{
    int i, j, maxValue;
    for (i=0;i<n;i++)
    {
        int maxValue = -1;
        for (j=0;j<i;j++)
        {
            if (A[i]>A[j])
            {
                if (maxValue==-1 || maxValue<LIS[j]+1)
                {
                    maxValue = 1+LIS[j];
                }
            }
        }
        if (maxValue==-1)
        {
            maxValue = 1;
        }
        LIS[i] = maxValue;
    }

    PrintLIS();
}

void PrintLIS()
{
    int tmp[100];
    int result = -1, i;
    int index = -1;
    for (i=0; i<n; i++)
    {
        if (result < LIS[i])
        {
            result = LIS[i];
            index = i;
        }
    }

    int j = 0;
    tmp [j] = A[index];
    int res = result-1;
    for (i=index-1; i>=0; i--)
    {
        if(LIS[i]==res)
        {
            res--;
            tmp[j+1] = A[i];
            j++;
        }
    }

    printf("\n\nLongest Increasing subsequence: %d\n", result);
    printf("\nActual Elements: ");
    for (int i = j; i >= 0; i--)
    {
        printf("%d  ", tmp[i]);
    }

}
