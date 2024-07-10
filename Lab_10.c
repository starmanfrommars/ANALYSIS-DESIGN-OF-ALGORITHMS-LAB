#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int A[],int left,int right){
	int i = left;
	int j = right;
	int pivot = A[left];
	while(i<j){
	
		do{
			i++;
		}while(A[i]<=pivot);
		
		do{
			j--;
		}while(A[j]>pivot);
		
		if(i<j){
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[left],&A[j]);
	return j;
}

void quickSort(int A[],int left,int right){
	if(left<right){
	
		int s = partition(A,left,right);
		quickSort(A,left,s);
		quickSort(A,s+1,right);
		
	}
}

void main() {
	int *A,n,left,right,k,i;
	printf("Enter the number of elements : ");
    scanf("%d",&n);
    
    A = (int*)malloc(n*sizeof(int));
    left = 0;
    right = n;
    
    printf("The array elements are : ");
    for(k=0;k<n;k++){
        A[k] = rand()%1000;
 		printf("%d ",A[k]);
    }
    printf("\n\n\n");
    
    clock_t start = clock();
    quickSort(A,left,right);
    clock_t end = clock();
    
    double duration = (((double)(end-start))/CLOCKS_PER_SEC * 1000000000);
    
    printf("Time for sorting is : %0.2f nano seconds\n\n\n",duration);
    
    printf("The sorted array is : ");
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n\n");

}
