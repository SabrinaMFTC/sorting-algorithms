#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* l, int lenL, int* r, int lenR, int* a, int lenA) {
    // i = pointer for left array; j = pointer for right array; k = pointer for final array
    int i = 0, j = 0, k = 0;

    while (i < lenL && j < lenR) {
        if (l[i] <= r[j]) a[k++] = l[i++];
        else a[k++] = r[j++];
    }

    // Adding leftover elements to final array
    while (i < lenL) a[k++] = l[i++];
    while (j < lenR) a[k++] = r[j++];
}

void mergeSort(int* a, int n) {
    // Base condition
    if (n < 2) return;

    int m = n/2;
    int* l = (int*)malloc(m * sizeof(int));
    int* r = (int*)malloc((n-m) * sizeof(int));

    for (int i = 0; i < m; ++i) l[i] = a[i];
    for (int i = m; i < n; ++i) r[i-m] = a[i];

    // Recursive call
    mergeSort(l, m);
    mergeSort(r, n-m);

    // Merging left and right arrays
    merge(l, m, r, n-m, a, n);

    free(l);
    free(r);
}

void printArray(int* a, int n) {
    printf("Sorted Array = [ ");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("]\n");
}

int main () {
    // Reseting random seed
    srand(time(NULL));

    // Dynamically allocating memory for the array
    int n = 10;
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) a[i] = (rand() % 100) + 1;

    mergeSort(a, n);
    printArray(a, n);
    free(a);

    return 0;
}
