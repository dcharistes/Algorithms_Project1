#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min_distance(int* arr, int N, int *dmin);
int min_distance_impr(int* arr, int N, int *dmin);
int main() {
    int i, N;
    int dmin_value;

    printf("Enter array size: ");
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("Enter values: ");
    for (i = 0; i < N; i++)
        scanf("%d", arr+i);
    
    dmin_value = abs(arr[0]-arr[1]);
    min_distance(arr, N, &dmin_value);
    printf("dmin = %d\n", dmin_value);
    min_distance_impr(arr, N, &dmin_value);
    printf("dmin_impr = %d\n", dmin_value);

    free(arr);
    return 0;
}

int min_distance(int* arr, int N, int* dmin){
    int i, j;
    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if (i != j && abs(arr[i] - arr[j]) < *dmin) //do not compute the distance if i = j -> avid comparing an element with itself. 
                *dmin = abs(arr[i] - arr[j]);
        }
    }
    return *dmin;
}

int min_distance_impr(int* arr, int N, int* dmin){
    int i, j;
    for (i = 0; i < N; i++){
        for(j = i + 1; j < N; j++){
            int current_dmin = abs(arr[i]-arr[j]); //just cleaner implementation of the min_distance. not an actual improve
            if (current_dmin < *dmin)
                *dmin = current_dmin;
        }
    }
    return *dmin;
}