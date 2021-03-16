#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v);
int main()
{int v;
printf("Enter no of vertices in the graph")		;
scanf("%d",&n);
printf("enter adjacency matrix:");
for(i=0;i<n;i++)
{
{for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}
}
printf("enter the starting vertex:");
scanf("%d",&v);
for(i=0;i<n;i++)
{
q[i]=0;
visited[i]=0;

}
bfs(v);
printf("\nThe reachable nodes are:");
for(i=0;i<n;i++)
{
	if(visited[i])
	printf("%d ",i);
	else
	{
	printf("BFS is not possible .Not all nodes are reachable");
	break;
}
}

	return 0;
}
void bfs(int v)
{
	for(i=0;i<n;i++)

    if(a[v][i]  && !visited[i])
    q[++r]=i;

if(f<=r)
{
	visited[q[f]]=1;
	bfs(q[f++]);
}

}
