#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int mat[50][50], Q[50];
int n, frnt = -1, rear = -1;

struct Vertex
{
    int vertex_no;
    char color;
    int d;
    int parent;
}vtx[50];

void Enque(int s)
{
    rear++;
    Q[rear] = s;
}

int Deque()
{
    frnt++;
    return Q[frnt];
}

void Create_Graph()
{
    int i, j;
    printf("\nInput Matrix\n");
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void Breath_First_Search(int s)
{
    int i;

    for (i=1;i<=n;i++)
    {
        vtx[i].color = 'w';
        vtx[i].d = INT_MAX;
        vtx[i].parent = -1;
    }

    vtx[s].color = 'g';
    vtx[s].d = 0;
    vtx[s].parent = 0;

    printf("\n%d(%d)\n", s, vtx[s].d);
    Enque(s);
    while(frnt<=rear)
    {
        int u = Deque();
        for(i=1;i<=n;i++)
        {
            if( mat[u][i]==1 && vtx[i].color=='w')
            {
                vtx[i].color = 'g';
                vtx[i].d = vtx[u].d + 1;
                vtx[i].parent = u;
                printf("%d(%d)\n", i, vtx[i].d);
                Enque(i);
             }
        }
        vtx[u].color = 'b';
    }
}

int main()
{
    int i, s, choice;

    printf("\nEnter total number of node: ");
    scanf("%d", &n);

    Create_Graph();

    printf("Enter starting node for Breadth First Search : ");
    scanf("%d", &s);
    Breath_First_Search(s);

    return 0;
}



