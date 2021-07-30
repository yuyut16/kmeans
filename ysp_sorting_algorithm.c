#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int* myNums[100]){
	int* ,temp, i, j, myNums;
	for (i=0;i < 100;i++) {
		for (j = 0; j < 100-1; j++) {
			if (myNums[j] > myNums[j+1]) {
				temp = myNums[j+1];
				myNums[j+1] = myNums[j];
				myNums[j] = temp;
			}
		}
	}
}


int main() {
	int k, h, m, myNums;
	int myNums = 100;
	int arr[100];
	for (k=0;k<100;k++) {
			arr[k]=rand()%100;
		}
	printf("Unsorted array: \n");
	for(h=0;h<100;h++) {
		printf("%d, ",arr[h]);
	}
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(100);
	printf("Sorted array: \n");
	for(m=0;m<100;m++) {
		printf("%d, ",arr[m]);
	}
	return 0;
}
