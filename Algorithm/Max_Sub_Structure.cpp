#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>

int A[200000];

struct MaxSubArray
{
    int Start;
    int End;
    int MaxSum;
};


struct MaxSubArray BRUTE_FORCE(int n)
{
    struct MaxSubArray result;
    int Sum,Start,End,Max;
    Max = INT_MIN;
    for(int i=1; i<=n-1; i++)
    {
        Sum = 0;
        for(int j=i; j<=n; j++)
        {
            Sum = Sum + A[j];
            if(Max<Sum)
            {
                Max = Sum;
                Start=i;
                End=j;
            }
        }
    }
    result.MaxSum=Max;
    result.Start=Start;
    result.End=End;

    return result;
}


struct MaxSubArray FIND_MAX_CROSSING_SUBARRAY(int low,int mid, int high)
{
    int max_left, max_right, l_sum, r_sum, sum, i, j;
    struct MaxSubArray result;

    l_sum = INT_MIN;
    sum = 0;
    for(int i=mid; i>=low; i--)
    {
        sum = sum + A[i];
        if(sum>l_sum)
        {
            l_sum = sum;
            max_left = i;
        }
    }

    r_sum = INT_MIN;
    sum = 0;
    for(j=mid+1;j<=high;j++)
    {
        sum = sum + A[j];
        if(sum>r_sum)
        {
            r_sum = sum;
            max_right = j;
        }
    }

    result.Start = max_left;
    result.End = max_right;
    result.MaxSum = l_sum+r_sum;

    return result;
}


struct MaxSubArray FIND_MAXIMUM_SUBARRAY(int low,int high)
{
    if(low==high)
    {
        struct MaxSubArray result;
        result.MaxSum = A[low];
        result.Start = low;
        result.End = low;

        return result;
    }

    struct MaxSubArray left,right,cross;
    int mid;
    mid = (low+high)/2;

    left = FIND_MAXIMUM_SUBARRAY(low, mid);
    right = FIND_MAXIMUM_SUBARRAY(mid+1, high);
    cross = FIND_MAX_CROSSING_SUBARRAY(low, mid, high);

    if (left.MaxSum >= right.MaxSum  &&  left.MaxSum >= cross.MaxSum)
    {
        return left;
    }
    else if(right.MaxSum >= left.MaxSum  &&  right.MaxSum >= cross.MaxSum)
    {
        return right;
    }
    else
    {
        return cross;
    }
}


int main()
{
    int n, i;
    struct MaxSubArray result1, result2;

    double d1, d2;
    long time1, time2;
    long start1, stop1, start2, stop2;

    printf("Size of Array: ");
    scanf("%d", &n);

    srand(time(NULL));
    printf("\nArray Elements: ");
    for(i=1;i<=n;i++)
    {
        //A[i] = rand() % 200 + (-100);
        scanf("%d", &A[i]);
        //printf("%d    ", A[i]);
    }

    start1 = clock();
    result1 = BRUTE_FORCE(n);
    stop1 = clock();
    time1 = stop1 - start1;
    d1 = (double)time1/CLOCKS_PER_SEC;

    printf("\n\n\nApplying Brute-force algorithm: Max sum %d (from %d to %d)", result1.MaxSum, result1.Start, result1.End);
    printf("\nClock Ticks: %d", time1);
    printf("\nTime: %lf", d1);

    start2 = clock();
    result2 = FIND_MAXIMUM_SUBARRAY(1, n);
    stop2 = clock();
    time2 = stop2 - start2;
    d2 = (double)time2/CLOCKS_PER_SEC;

    printf("\n\nApplying Recursive algorithm: Max sum %d (from %d to %d)\n", result2.MaxSum, result2.Start, result2.End);
    printf("\nClock Ticks: %d", time2);
    printf("\nTime: %lf\n", d2);

    return 0;
}

