#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *A,n=0,min,temp,i,k;

void selectionSort() {
	int temp;
	for(int i=0;i<n-1;i++){
        min = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[min]){
                min = j;
            }
        }
        
       temp = A[i];
       A[i] = A[min];
       A[min] = temp;
    }
}

void main() {  
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
    selectionSort();
    clock_t end = clock();
    
    double duration = (((double)(end-start))/CLOCKS_PER_SEC * 1000000000);
    
    printf("Time for sorting is : %0.2f nano seconds\n\n\n",duration);
    printf("The sorted array is : ");
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n\n\n");     
}

