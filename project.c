#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> // Added math library for exp function
#include "sorting_functions.h"

#define SMALL_SIZE 100
#define MEDIUM_SIZE 1000
#define LARGE_SIZE 10000

#define NUM_ALGORITHMS 6

// Wrapper function for mergeSort
void wrapperMergeSort(int arr[], int size) {
    mergeSort(arr, 0, size - 1);
}

// Wrapper function for quickSort
void wrapperQuickSort(int arr[], int size) {
    quickSort(arr, 0, size - 1);
}

// Wrapper function for heapSort
void wrapperHeapSort(int arr[], int size) {
    heapSort(arr, size);
}

// Function to generate a random array of a given size
int* generateRandomArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand();  // Generates random integers
    }
    return arr;
}

// Function to generate a sorted array in ascending order
int* generateAscendingArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

// Function to generate a sorted array in descending order
int* generateDescendingArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
    return arr;
}

// Function to generate a mixed array with both positive and negative numbers
int* generateMixedArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = (i % 2 == 0) ? rand() : -rand();
    }
    return arr;
}

// Function to free the memory allocated for an array
void freeArray(int* arr) {
    free(arr);
}

// Function to measure the execution time of a sorting function
double measureSortingTime(void (*sortingFunction)(int[], int), int arr[], int size) {
    clock_t start_time = clock();
    sortingFunction(arr, size);
    clock_t end_time = clock();
    double sorting_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    return sorting_time;
}

// Function to save timing data to a CSV file
void saveTimingData(double data[][NUM_ALGORITHMS], int sizes[], int numSizes, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write CSV header
    fprintf(file, "Array Size, Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort, Heap Sort\n");

    // Write timing data
    for (int i = 0; i < numSizes; i++) {
        fprintf(file, "%d", sizes[i]);
        for (int j = 0; j < NUM_ALGORITHMS; j++) {
            fprintf(file, ", %f", data[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    int sizes[] = {SMALL_SIZE, MEDIUM_SIZE, LARGE_SIZE};
    double randomTimingData[sizeof(sizes) / sizeof(sizes[0])][NUM_ALGORITHMS];
    double bestCaseTimingData[sizeof(sizes) / sizeof(sizes[0])][NUM_ALGORITHMS];
    double worstCaseTimingData[sizeof(sizes) / sizeof(sizes[0])][NUM_ALGORITHMS];
    double mixedCaseTimingData[sizeof(sizes) / sizeof(sizes[0])][NUM_ALGORITHMS];

    const char* sortingFunctionNames[] = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Merge Sort", "Quick Sort", "Heap Sort"};

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        int* arr = generateRandomArray(sizes[i]);

        // Corrected function pointer declaration
        void (*sortingFunctions[])(int[], int) = {bubbleSort, selectionSort, insertionSort, wrapperMergeSort, wrapperQuickSort, wrapperHeapSort};

        for (int j = 0; j < NUM_ALGORITHMS; j++) {
            // Measure and compare sorting times for random, best-case, and worst-case scenarios
            randomTimingData[i][j] = measureSortingTime(sortingFunctions[j], arr, sizes[i]);

            int* bestCaseArray = generateAscendingArray(sizes[i]);
            int* worstCaseArray = generateDescendingArray(sizes[i]);
            int* mixedCaseArray = generateMixedArray(sizes[i]);

            bestCaseTimingData[i][j] = measureSortingTime(sortingFunctions[j], bestCaseArray, sizes[i]);
            worstCaseTimingData[i][j] = measureSortingTime(sortingFunctions[j], worstCaseArray, sizes[i]);
            mixedCaseTimingData[i][j] = measureSortingTime(sortingFunctions[j], mixedCaseArray, sizes[i]);

            freeArray(bestCaseArray);
            freeArray(worstCaseArray);
            freeArray(mixedCaseArray);
        }

        freeArray(arr);
    }

    // Store the timing data in separate CSV files
    saveTimingData(randomTimingData, sizes, sizeof(sizes) / sizeof(sizes[0]), "random_data.csv");
    saveTimingData(bestCaseTimingData, sizes, sizeof(sizes) / sizeof(sizes[0]), "best_case_data.csv");
    saveTimingData(worstCaseTimingData, sizes, sizeof(sizes) / sizeof(sizes[0]), "worst_case_data.csv");
    saveTimingData(mixedCaseTimingData, sizes, sizeof(sizes) / sizeof(sizes[0]), "mixed_case_data.csv");

    return 0;
}
