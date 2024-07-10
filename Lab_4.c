#include<stdio.h>
#include<stdlib.h>
#define INFINITY 99

int MinVertex();

int dist[10],p[10],visit[10];
int wt[10][10],n,edge;

int MinVertex() {
    int min = INFINITY;
    int u,i;
    for(i=1;i<=n;i++){
    	if((dist[i]<min)&&(visit[i]==0)){
    		min = dist[i];
    		u=i;
    	}
    }
	return u;
}

void printpath(int s){
    int i,t;
    for(i=1;i<=n;i++){
        if(visit[i]==1 && i!=s){
            printf("vertex-> %d length %d path : ",i,dist[i]);
            t = p[i];
            printf("%d",i);
            while(t!=s){
                printf("<--%d",t);
                t = p[t];
            }
            if(t==s)
                printf("<--%d\n",s);
        }
    }
}

void dijkstra(int s){
    int i,j,step,u;
    for(i=1;i<=n;i++){
        dist[i] = wt[s][i];
        if(dist[i]==INFINITY)
        p[i]=0;
        else
        p[i]=s;
    }
    visit[s] = 1;
    dist[s] =0;
    for(step=2;step<=n;step++){
        u = MinVertex();
        visit[u] =1;
        for(j=1;j<=n;j++)
        if(((dist[u]+wt[u][j])<dist[j])&& !visit[j]){
            dist[j] = dist[u]+wt[u][j];
            p[j]=u;
        }
    }   
}

int main() {
    int i,j,s;
    printf("Enter the number of vertices in a graph : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        dist[i]=visit[i]=p[i]=0;
    }
    printf("Enter the matrix : \n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&wt[i][j]);
    printf("Enter the source vertex : ");
    scanf("%d",&s);
    printf("\n\nShortest path from vertex %d are \n\n",s);
    dijkstra(s);
    printpath(s);
    return 0;
}