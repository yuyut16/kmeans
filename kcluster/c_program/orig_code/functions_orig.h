/*
*  _   _ _   _  ____    _    ____
* | \ | | | | |/ ___|  / \  |  _ \
* |  \| | | | | |     / _ \ | |_) |
* | |\  | |_| | |___ / ___ \|  _ <
* |_| \_|\___/ \____/_/   \_\_| \_\
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants
#define DATAPOINTS 699
#define BUFFER_SIZE 1000
#define NUMBER_OF_FEATURES 9
#define GROUND_TRUTH_POSITION 10
#define BENIGN 2
#define MALIGN 4

// Function Declarations
int read_data(char *file_name, float **input_data, int *ground_truth);
void fill_single_datapoint(char *line_data, float **input_data, int *ground_truth, int line_iterator);
int allocate_matrix_and_vector(float ***input_data, int **ground_truth);
float euclidean_distance(float *point_A, float *point_B);


int read_data(char *file_name, float **input_data, int *ground_truth) {
   FILE *file_obj = fopen ( file_name, "r" );

   if (file_obj == NULL) {
      printf("ERROR: Could not find file: %s.", file_name);
      return -1;
   }

   if (file_obj != NULL) {
      char line_data[BUFFER_SIZE];
      // Remove header
      fgets(line_data, sizeof line_data, file_obj);
      // Iterate over data.
      int line_iterator=0;
      while(fgets(line_data, sizeof line_data, file_obj)!= NULL) {
         fill_single_datapoint(line_data, input_data, ground_truth, line_iterator);
         line_iterator++;
      }
      fclose(file_obj);
   }

   return 0;
}

void fill_single_datapoint(char *line_data, float **input_data, int *ground_truth, int line_iterator) {
   char *cut_line;
   float float_data;
   // Remove ID
   cut_line = strtok (line_data, ",\n");
   for (int i=0; i < NUMBER_OF_FEATURES; i++) {
      cut_line = strtok (NULL, ",\n");
      float_data = atof(cut_line);
      input_data[line_iterator][i] = float_data;
   }
   cut_line = strtok (NULL, ",\n");
   ground_truth[line_iterator] = atoi(cut_line);
}

int allocate_matrix_and_vector(float ***input_data, int **ground_truth) {
   *input_data = (float **) malloc(DATAPOINTS * sizeof(float *));
    for (int index=0; index<DATAPOINTS; index++) {
         (*input_data)[index] = malloc(NUMBER_OF_FEATURES * sizeof(float));
    }
    *ground_truth = (int *) malloc(DATAPOINTS * sizeof(int));

    return 0;
}

void initialize_centroids(float *mal_centroid, float *ben_centroid, float **input_data) {
   int mal_datapoint = 7;
   int ben_datapoint = 8;
   for (int i=0; i<NUMBER_OF_FEATURES; i++) {
      mal_centroid[i] = input_data[mal_datapoint][i];
   }
   for (int i=0; i<NUMBER_OF_FEATURES; i++) {
      ben_centroid[i] = input_data[ben_datapoint][i];
   }
}

float euclidean_distance(float *point_A, float *point_B) {
   float distance = 0.0;
   for (int i=0; i < NUMBER_OF_FEATURES; i++) {
      distance += ((point_A[i] - point_B[i]) * ((point_A[i] - point_B[i])));
   }
   distance = sqrt(distance);
   return(distance);
}

void classify_points(float *mal_centroid, float *ben_centroid, float **input_data, int *classification) {
   float mal_dist, ben_dist;
   int total_mal_points = 0;
   int total_ben_points = 0;
   float total_mal_distance = 0.0;
   float total_ben_distance = 0.0;
   float avg_mal_distance;
   float avg_ben_distance;
   for (int i=0; i < DATAPOINTS; i++) {
      mal_dist = euclidean_distance(mal_centroid, input_data[i]);
      ben_dist = euclidean_distance(ben_centroid, input_data[i]);
      if (mal_dist < ben_dist) {
         classification[i] = MALIGN;
         total_mal_points++;
         total_mal_distance += mal_dist;
      } else {
         classification[i] = BENIGN;
         total_ben_points++;
         total_ben_distance += ben_dist;
      }
   }
   avg_mal_distance = total_mal_distance / total_mal_points;
   avg_ben_distance = total_ben_distance / total_ben_points;
   printf("Avg Mal:%f Avg Ben:%f Total Mal:%d Total Ben:%d\n", avg_mal_distance, avg_ben_distance, total_mal_points, total_ben_points);
}


void compute_new_centroids(float **mal_centroid, float **ben_centroid, float **input_data, int *classification) {
   float mal_updated_centroid[NUMBER_OF_FEATURES];
   float ben_updated_centroid[NUMBER_OF_FEATURES];
   int total_mal_points = 0;
   int total_ben_points = 0;
   
   for (int i=0; i < NUMBER_OF_FEATURES; i++) {
      mal_updated_centroid[i] = 0.0;
      ben_updated_centroid[i] = 0.0;
   }

   for (int i=0; i < DATAPOINTS; i++) {
      if (classification[i] == MALIGN) {
         // Point is MALIGN
         total_mal_points++;
         for (int j=0; j < NUMBER_OF_FEATURES; j++) {
            mal_updated_centroid[j] += input_data[i][j];
         }
      } else {
         // Point is BENIGN
         total_ben_points++;
         for (int j=0; j < NUMBER_OF_FEATURES; j++) {
            ben_updated_centroid[j] += input_data[i][j];
         }
      }
   }
   // Average out the centroids
   for (int i=0; i < NUMBER_OF_FEATURES; i++) {
      mal_updated_centroid[i] = mal_updated_centroid[i]/total_mal_points;
      ben_updated_centroid[i] = ben_updated_centroid[i]/total_ben_points;
   }
   // Copy the updated centroids to original centroids
   for (int i=0; i < NUMBER_OF_FEATURES; i++) {
      (*mal_centroid)[i] = mal_updated_centroid[i];
      (*ben_centroid)[i] = ben_updated_centroid[i];
   }
}
float check_accuracy(int *classification, int *ground_truth) {
   int correct_count = 0;
   int incorrect_count = 0;
   // for (int i=0; i < 20; i++) {
   //    printf("i:%d\tclass:%d\ttruth:%d\n", i, classification[i], ground_truth[i]);
   // }
   for (int i=0; i < DATAPOINTS; i++) {
      if (classification[i] == ground_truth[i]) {
         correct_count++;
      } else {
         incorrect_count++;
      }
   }
   float mal_count_float = (float) correct_count;
   float accuracy;
   accuracy = (mal_count_float/DATAPOINTS) * 100.0;
   if (accuracy <= 50.0) {
      accuracy = 100 - accuracy;
   }
   printf("Accuracy: %f \%\n", accuracy);
   return (accuracy);
}

void print_centroids(float *mal_centroid, float *ben_centroid) {
   printf("Mal Centroid: ");
   for (int i=0; i < NUMBER_OF_FEATURES; i++) {
      printf("%f\t", mal_centroid[i]);
   }
   printf("\n");
   printf("Ben Centroid: ");
   for (int i=0; i < NUMBER_OF_FEATURES; i++) {
      printf("%f\t", ben_centroid[i]);
   }
   printf("\n");
}

#endif