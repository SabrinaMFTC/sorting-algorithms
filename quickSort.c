#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int* a, int start, int end) {
    int pIndex = start;
    int pivot = a[end];
    
    for (int i = start; i < end; ++i) {
        if (a[i] <= pivot) swap(&a[i], &a[pIndex++]);
    }

    swap(&a[pIndex], &a[end]);
    return pIndex;
}

void quickSort(int* a, int start, int end) {
    if (start < end) {
        int pIndex = partition(a, start, end);
        // Recursive call for left side of the array
        quickSort(a, start, pIndex-1);
        // Recusrive call for right side of the array
        quickSort(a, pIndex+1, end);
    }
}

void printArray(int* a, int n) {
    printf("Sorted Array = [ ");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("]\n");
}

int main() {
    // Reseting random seed
    srand(time(NULL));

    // Dynamically allocating memory for the array
    int n = 10;
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) a[i] = (rand() % 100) + 1;

    quickSort(a, 0, n-1);
    printArray(a, n);
    free(a);

    return 0;
}
