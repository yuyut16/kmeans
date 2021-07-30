/*
*  _   _ _   _  ____    _    ____
* | \ | | | | |/ ___|  / \  |  _ \
* |  \| | | | | |     / _ \ | |_) |
* | |\  | |_| | |___ / ___ \|  _ <
* |_| \_|\___/ \____/_/   \_\_| \_\
*/

#include "functions.h"


char FILENAME[] = "../data/tumor.csv";

int main() {
   float **input_data;
   int *ground_truth;
   allocate_matrix_and_vector(&input_data, &ground_truth);
   read_data(FILENAME, input_data, ground_truth);

   
   float *mal_centroid = (float *) malloc(NUMBER_OF_FEATURES * sizeof(float));
   float *ben_centroid = (float *) malloc(NUMBER_OF_FEATURES * sizeof(float));
   initialize_centroids(mal_centroid, ben_centroid, input_data);
   int *classification = (int *) malloc(DATAPOINTS * sizeof(int));
   int number_of_iterations = 8;
   for (int iter=0; iter < number_of_iterations; iter++) {
      classify_points(mal_centroid, ben_centroid, input_data, classification);
      check_accuracy(classification, ground_truth);
      compute_new_centroids(&mal_centroid, &ben_centroid, input_data, classification);
      // print_centroids(mal_centroid, ben_centroid);
   }

   return 0;
}


