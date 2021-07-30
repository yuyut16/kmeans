#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //header file that gives you access to pthread functions


void *entry_point(void *value) {

	printf("hello from the second thread :)\n");
	int *num = (int *) value;
	printf("the value of value is %d", *num);
	return NULL;
}
//main function = main thread
int main(int argc, char **argv) {
	pthread_t thread;
	printf("hello from the first thread :D\n");
	int num = 123;
	pthread_create(&thread, NULL, entry_point, &num);
	pthread_join(thread, NULL);
	//ensures main thread will wait until 2nd thread finishes --> w/o it, the program would exit immediately  
	//pthread_create takes 4 arguments
	return EXIT_SUCCESS;
}


