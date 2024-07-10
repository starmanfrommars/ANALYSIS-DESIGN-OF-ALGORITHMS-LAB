#include<stdio.h>

int s[10],d,n,set[10],count=0,flag=0;

void display(int count) {
	printf(" {");
	for(int i=0;i<count;i++)
		printf("%d,",set[i]);
	printf("\b} ");
}

int subset(int sum,int i){
	if(sum==d){
		flag = 1;
		display(count);
		return 1;
	}
	if(sum > d || i>=n ) return 0;
	else {
		set[count] = s[i];
		count++;
		subset(sum+s[i], i+1);
		count--;
		subset(sum,i+1);
	}
	return 0;
}


void main() {

	printf("Enter the number of set elements : ");
	scanf("%d",&n);
	
	printf("Enter the set elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",&s[i]);
	
	printf("Enter the total sum : ");
	scanf("%d",&d);
	
	printf("The program output is : ");
	subset(0,0);
	if(flag==0)
		printf("There is no solution\n");
	printf("\n");
}

