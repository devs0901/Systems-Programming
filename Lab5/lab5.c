#include<stdio.h>

//Swap function used for bubble sort
void swap(int *ap, int *bp){
	int buf = *ap;
	*ap = *bp;
	*bp = buf;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n){
	int i, j;
	for (i=0; i < n-1; i++){
		for (j=0; j < n-i-1; j++){
			if (arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

//main function
int main (){
	
	//initialize counters
	int num, x, y;
	
	//ask user to input how many elements to be sorted
	printf("Enter number of elements: \n");
	scanf("%d", &num);
	//initialize array and the size of it
	int *arr= malloc(num);
	
	//for loop, allows the user to input in num occurrences
	printf("Enter %d integers\n", num);
	for(x=0; x < num; x++){
		scanf("\n%d", &arr[x]);
	}
	
	//call bubbleSort function
	bubbleSort (arr, num);
	
	//print the sorted algorithm 
	printf("Sorted list in ascending order");
	for (y=0; y < num; y++){
		printf("\n%d", arr[y]);
	}
free(arr);
}
