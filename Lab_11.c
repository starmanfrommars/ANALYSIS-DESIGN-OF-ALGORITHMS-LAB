#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 10000

int merge(int A[],int low,int mid,int high){
	int i=low,j=mid+1,k=low,*rA;
	rA = (int*)malloc((high+1)*sizeof(int));
	
	while(i<=mid && j<=high){
		if(A[i]<A[j]){
			rA[k++] = A[i++];
		}
		else {
			rA[k++] = A[j++];
		}
	}
	
	while(i<=mid){
		rA[k++] = A[i++];
	}
	while(j<=high){
		rA[k++] = A[j++];
	}
	for(int m=low;m<=high;m++){
		A[m] = rA[m];
	}
}

void mergeSort(int A[],int low,int high){
	if(low<high){
		int mid = (low+high)/2;
		mergeSort(A,low,mid);
		mergeSort(A,mid+1,high);
		merge(A,low,mid,high);
	}
}

void main() {
	int *A,n,k,i;
	printf("Enter the number of elements : ");
    scanf("%d",&n);
    
    A = (int*)malloc(n*sizeof(int));

    printf("The array elements are : ");
    for(k=0;k<n;k++){
        A[k] = rand()%1000;
 		printf("%d ",A[k]);
    }
    printf("\n\n\n");
    
    clock_t start = clock();
    mergeSort(A,0,n-1);
    clock_t end = clock();
    
    double duration = (((double)(end-start))/CLOCKS_PER_SEC * 1000000000);
    printf("\n\nTime for sorting is : %0.2f nano seconds\n\n\n",duration);
    printf("The sorted array is : ");
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n\n");
}
