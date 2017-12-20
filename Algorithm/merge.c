#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int M[100];

void MERGE_SORT(int temp[], int p, int r)

{
    int q;
    if (r > p)
    {
        q = (r + p) / 2;
        MERGE_SORT(temp, p, q);
        MERGE_SORT(temp, q+1, r);
        Merge(temp, p, q+1, r);
    }

}

void Merge(int temp[], int p, int q, int r)
{
    int i, n1, n2, tmp_pos;

    n1 = q - 1;
    tmp_pos = p;
    n2 = r - p + 1;

    while ((p <= n1) && (q <= r))
    {
        if (M[p] <= M[q])
        {
            tmp[tmp_pos] = M[p];
            tmp_pos = tmp_pos + 1;
            p = p +1;
        }
        else
        {
            tmp[tmp_pos] = M[q];
            tmp_pos = tmp_pos + 1;
            q = q + 1;
        }
    }

    while (p <= n1)
    {
        tmp[tmp_pos] = M[p];
        p = p + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (q <= r)
    {
        tmp[tmp_pos] = M[q];
        q = q + 1;
        tmp_pos = tmp_pos + 1;
    }

    for (i = 0; i <= n2; i++)
    {
        M[r] = tmp[r];
        r = r - 1;
    }
}

int main()
{
    int i, n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int tmp[n+1];

    printf("\nEnter the numbers: ");
    for (i=1; i<=n; i++)
    {
        scanf("%d", &M[i]);
    }

    MERGE_SORT(tmp, 1, n);

    printf("\nThe merged sorted array: ");
    for (i=1; i<=n; i++)
    {
        printf("%d   ", M[i]);
    }

    return 0;
}

/*
 #include<stdio.h>
    #include<stdlib.h>
    #include<limits.h>

void merge(int a[], int p, int q, int r)
{
    int n1,n2;
    int i,j,k;
    int *l,*m;

    n1 = q - p + 1;
    n2 = r - q;
    l = (int*)malloc(sizeof(int)*(n1+1));
    m = (int*)malloc(sizeof(int)*(n2+1));

    for(i=0; i<n1; i++)
        l[i] = a[p+i];
    for(j=0; j<n2; j++)
            m[j] = a[q+j+1];
    l[i] = INT_MAX;
    m[j] = INT_MAX;

    i = j = 0;
    for(k=p; k<r+1; k++){

        if(l[i] <= m[j]){
            a[k] = l[i];
            i++;
        }

        else{
            a[k] = m[j];
            j++;
        }

    }
}

void merge_sort(int a[],int p, int r)
{
    int q;

    if(p<r){
        q = (p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}
int main()
{
    int *num,n;
    int i;

    printf("Enter number of digits:");
    scanf("%d",&n);
    num = (int*)malloc(sizeof(int)*n);
    printf("Enter numbers:");
    for(i=0 ; i<n; i++){
        scanf("%d",&num[i]);
    }
    merge_sort(num,0,n-1);
    printf("Sorted array:\n");
    for(i=0; i<n; i++)
        printf("%d ",num[i]);
    free(num);
    return 0;
}

*/
