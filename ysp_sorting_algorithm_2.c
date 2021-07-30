#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Bubble Sort for 1000
int a = 1000;
void bubbleSort(int* myNums){
	int temp, i, j;
	for (i=0;i < a;i++) {
		for (j = 0; j < a-1; j++) {
			if (myNums[j] > myNums[j+1]) {
				temp = myNums[j+1];
				myNums[j+1] = myNums[j];
				myNums[j] = temp;
			}
		}
	}
}


int main() {
	int x, y;
	for(x=1;x<101;x++) {
		for(y=0;y<3;y++) {
			srand(time(NULL));
			int k, h, m;
			int arr[a];	
			for (k=0;k<a;k++) {
				arr[k]=rand()%a;
			}
				/*printf("Unsorted array: \n");
				for(h=0;h<1000;h++) {
					printf("%d, ",arr[h]);
				}
				printf("\n");
				*/
				double time_spent = 0.0;
				clock_t begin = clock();
				bubbleSort(arr);
				sleep(3);
				clock_t end = clock();
				time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
				/*printf("Sorted array: \n");
				for(m=0;m<1000;m++) {
					printf("%d, ",arr[m]);
				}
				printf("\n");
				*/
				int sum = 1000*x;
				printf("Elapsed time for %d array: %f seconds \n",sum ,time_spent);
		}
		printf("\n");
		a = 1000*x;
	}
	return 0;
}
