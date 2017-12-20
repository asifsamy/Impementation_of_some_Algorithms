#include<stdio.h>
#include<limits.h>

int A[10], n, start, stop;

int KADANES_ALGO()
{
    int max_so_far, max_ending_here, i, tmp, curr_indx, j;
    tmp=INT_MIN;

    max_ending_here = 0;
    max_so_far = 0;
    curr_indx = 1;

    for (i=1;i<=n;i++)
    {
        max_ending_here = max_ending_here+A[i];
        //printf("\n%d", max_ending_here);
        if (max_ending_here<=0)
        {
            max_ending_here = 0;
            curr_indx = i;
        }
        else if (max_so_far<max_ending_here)
        {
            max_so_far = max_ending_here;
            start = curr_indx;
            stop = i;
        }
    }

    if (max_so_far==0)
    {
        for (i=1;i<=n;i++)
        {
            if (tmp<A[i])
            {
                tmp = A[i];
                start = i;
                stop = i;
            }
        }
        return tmp;
    }

    else
        return max_so_far;

}

int main()
{
    int i, ans;

    scanf("%d", &n);

    for (i=1;i<=n;i++)
    {
        scanf("%d", &A[i]);
    }

    ans = KADANES_ALGO();

    printf("\n%d", ans);
    printf("\n%d %d", start, stop);

    return 0;
}
