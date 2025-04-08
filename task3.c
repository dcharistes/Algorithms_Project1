#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>

int min_distance(int* arr, int N, int *dmin);
int min_distance_opt(int* arr, int N, int *dmin);
void random_num_gen(int* arr, int n);
double measure_t(int (*func)(int*, int, int*), int* arr, int n, int* dmin);
int main() {

    FILE *log_file = fopen("log.csv", "w");
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        return 1;
    }

    // Write CSV header
    fprintf(log_file, "Size,Naive_Avg_Time,Optimized_Avg_Time\n");

    srand(time(NULL));  // Αρχικοποίηση seed για τυχαίους αριθμούς
    
    int sizes[] = {60000, 70000, 80000, 90000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int num_tests = 10;
    int dmin_value = INT_MAX;
    
    printf("Size\tNaive Avg Time\tOptimized Avg Time\tMinimum Distance\n");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = (int*)malloc(n * sizeof(int));
        
        double naive_total = 0.0;
        double optimized_total = 0.0;
        for (int j = 0; j < num_tests; j++) {
            random_num_gen(arr, n);
            
            // time measure for naive algorithm
            naive_total += measure_t(min_distance, arr, n, &dmin_value);

            dmin_value = INT_MAX;
            // time measure for optimized algorithm
            optimized_total += measure_t(min_distance_opt, arr, n, &dmin_value);
        }
        
        //write to console
        printf("%d\t%.4f\t\t%.4f\t\t\t%d\n", n, naive_total/num_tests, optimized_total/num_tests, dmin_value);

        //write to log.csv file
        fprintf(log_file, "%d,%.4f,%.4f\n", n, naive_total/num_tests, optimized_total/num_tests);

        free(arr);
    }

    fclose(log_file);
    return 0;
}

void random_num_gen(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        *(arr+i) = rand() % 1000000;  // random nums from 0 to 999999
    }
}

// time measurement func
double measure_t(int (*func)(int*, int, int*), int* arr, int n, int* dmin) {
    clock_t start = clock();
    int result = func(arr, n, dmin);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}


//time complexity O(n^2-n)=O(n^2)
int min_distance(int* arr, int N, int* dmin){
    int i, j;
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if (i != j && abs(arr[i] - arr[j]) < *dmin) //do not compute the distance if i = j -> avοid comparing an element with itself. 
                *dmin = abs(arr[i] - arr[j]);
        }
    }
    return *dmin;
}

// Comparison function
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

//time complexity O(nlogn)
int min_distance_opt(int* arr, int N, int* dmin){
    int i, j;
    qsort(arr, N, sizeof(int), compare); //we can try mergesort to see if we get even better results. theoretical O(nlogn) complx * O(n)
    for (i = 0; i < N - 1; i++){
            int current_dmin = abs(arr[i]-arr[i+1]); //just cleaner implementation of the min_distance. 
            if (current_dmin < *dmin)
                *dmin = current_dmin;
    }
    return *dmin;
}