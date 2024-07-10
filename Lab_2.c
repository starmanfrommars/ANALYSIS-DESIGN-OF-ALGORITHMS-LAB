#include<stdio.h>

int visited[10]={0}, min, mincost=0, cost[10][10],i,j,v,u,n,ne=1,a,b;

void main() {
	printf("Enter the number of nodes : ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix : \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	visited[1]=1;
	printf("\n");
	
	while(ne<n) {
		for(i=1,min=999; i<=n ; i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min)
					if(visited[i]!=0){
						min = cost[i][j];
						a = u = i;
						b = v = j;
					}
		if(visited[u]==0 || visited[v]==0){
			printf("\nEdge %d : (%d,%d) Cost : %d",ne++,a,b,min);
			mincost += min;
			visited[b]=1;
		}
		cost[a][b] = cost[b][a] = 999;
	}
	printf("\nMinimum cost = %d\n",mincost);
}
