#include<stdio.h>

int my_max(int a,int b){
	return (a>b)?a:b;
}

int val[20],wt[20],n,c,v[20][20];
int knap(){
	int i,j;
	for(i=0;i<=n;i++)
	for(j=0;j<=c;j++)
	if(i==0||j==0)
		v[i][j]==0;
	else
		if(wt[i]>j)
			v[i][j] = v[i-1][j];
		else
			v[i][j] = my_max(v[i-1][j],(v[i-1][j-wt[i]]+val[i]));
	return v[n][c];
}

int main() {
	int opt,i,j;
	printf("Enter the number of items in knapsack : ");
	scanf("%d",&n);
	printf("Enter the values(profit) of %d elements : ",n);
	for(i=1;i<=n;i++)
		scanf("%d",&val[i]);
	printf("Enter the weight of %d elements : ",n);
	for(i=1;i<=n;i++)
		scanf("%d",&wt[i]);
	printf("Enter the capacity of knapsack : ");
	scanf("%d",&c);
	opt = knap();
	printf("\nCapacity");
	for(j=0;j<=c;j++)
		printf("%4d",j);
	printf("\n");
	for(i=0;i<=n;i++){
		printf("\nItem- %2d : ",i);
		for(j=0;j<=c;j++)
			printf("%4d",v[i][j]);
	}
	printf("\nOptimal solution is : %d",opt);
	printf("\nThe selected items are : ");
	while(n>0){
		if(v[n][c]!=v[n-1][c]){
			printf("%d\t",n);
			c = c - wt[n];
		}n--;
	}
	printf("\n");
	return 0;
}
