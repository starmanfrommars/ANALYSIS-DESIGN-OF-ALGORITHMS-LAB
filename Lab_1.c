#include<stdio.h>
#include<stdlib.h>

int i,j,a,b,u,v,n,min,mincost=0,cost[10][10],parent[10];

int find(int i){
	while(parent[i])
		i = parent[i];
	return i;
}

int uni(int i,int j){
	if(i!=j){
		parent[j] = i;
		return i;
	}
	return 0;
}

void main() {
	int ne;
	printf("Implementation of krusals Algorithm\n");
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the cost adjacency matrix : \n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
			
	printf("The edges of the minimum cost spanning tree : \n");
	ne=1;
	while(ne<n){
		for(i=1,min=999;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min){
					min = cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u = find(u);
		v = find(v);
		if(uni(u,v)){
			printf("Edge %d - (%d,%d) = %d\n",ne++,a,b,min);
			mincost += min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("The cost of MST is : %d\n",mincost);
}
