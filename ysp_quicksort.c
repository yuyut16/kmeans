#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define BILLION 1000000000.0
void swap(int *a, int *b) {
	int t =  *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high) {

int pivot = arr[high];
int i = (low - 1);
int j;

for (j = low; j<=high- 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}	
swap(&arr[i+1], &arr[high]);
return(i+1);
}

void quickSort(int arr[], int first, int last) {
	if (first < last) {
int pi = partition(arr, first, last);
quickSort(arr, first, pi-1);
quickSort(arr, pi + 1, last);
	}
}

void printArray(int arr[], int size) {
	int i;
	for(i=0; i <size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int a, x, y, k, i;
	for(x=1;x<101;x++) {
		for(y=0;y<3;y++) {
			srand(time(NULL));
			int arr[a];
				for (k=0;k<a;k++) {
					arr[k] = rand()%100000;
				}
			/*int n = sizeof(arr)/sizeof(arr[0]);
			printf("\n Unsorted array: ");
			for(i=0;i<g;i++) {
				printf(" %d \t", arr[i]);
			} */
			/*double time_spent = 0.0;
			clock_t begin = clock(); */
			struct timespec start, end;
			clock_gettime(CLOCK_REALTIME, &start);
			quickSort(arr, 0, a-1);
			//sleep(3);
			/*clock_t end = clock(); */
			clock_gettime(CLOCK_REALTIME, &end);
			double time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;

			/*time_spent += (double)(end - begin) / CLOCKS_PER_SEC; */
			int sum = 1000*x;
			printf("Elapsed time for %d array: %0.9f seconds \n", sum, time);
			/* printf("\n Sorted array: ");
			printArray(arr, n); */
		}
		printf("\n");
		a = 1000*x;
	}
	return 0;
}
