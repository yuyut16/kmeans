/*
*  _   _ _   _  ____    _    ____
* | \ | | | | |/ ___|  / \  |  _ \
* |  \| | | | | |     / _ \ | |_) |
* | |\  | |_| | |___ / ___ \|  _ <
* |_| \_|\___/ \____/_/   \_\_| \_\
*/

#include "functions.h"
#include <time.h>

char FILENAME[] = "../data/tumor.csv";

double start, finish, total;
double CLOCK() {
        struct timespec t;
        clock_gettime(CLOCK_MONOTONIC,  &t);
        return (t.tv_sec * 1000)+(t.tv_nsec*1e-6);
}


int main() {
   //float **input_data;
   int *ground_truth;
   //printf("allocate_matrix_and_vector \n");
   allocate_matrix_and_vector(&input_data, &ground_truth);
   //printf("read_data \n");
   read_data(FILENAME, input_data, ground_truth);

   
   mal_centroid = (float *) malloc(NUMBER_OF_FEATURES * sizeof(float));
   ben_centroid = (float *) malloc(NUMBER_OF_FEATURES * sizeof(float));
   //printf("initialize_centroids \n");
   initialize_centroids(mal_centroid, ben_centroid, input_data);
   classification_global = (int *) malloc(DATAPOINTS * sizeof(int));
   int number_of_iterations = 8;
    printf("Threads: %d\n", total_threads);
   start = CLOCK();
   //print_centroids(mal_centroid, ben_centroid);
   //printf("Beginning iterations \n");
   for (int iter=0; iter < number_of_iterations; iter++) {
     // printf("classify_points for iter:%d \n", iter);
      classify_points(mal_centroid, ben_centroid, input_data, classification_global);
      //printf("check_accuracy for iter:%d \n", iter);
      check_accuracy(classification_global, ground_truth);
      //printf("compute_new_centroids for iter:%d \n", iter);
      compute_new_centroids(&mal_centroid, &ben_centroid, input_data, classification_global);
      print_centroids(mal_centroid, ben_centroid);
     // printf("\n");
   }
   //printf("Completed iterations \n");
   finish = CLOCK();
   total = finish - start;
   printf("\n");
   printf("Time: %lf milliseconds\n", total);
   printf("-----------");  
    return 0;
}


