#include <stdio.h>
#include <stdlib.h>

/* Task 4: Sorting Forensics - Partition and Defects */

int partition_lomuto(int a[], int lo, int hi, int *swaps_out) {
    int pivot = a[hi];
    int i = lo;
    int swaps = 0;

    for (int j = lo; j < hi; j++) {
        if (a[j] < pivot) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            swaps++;
        }
    }
    int t = a[i];
    a[i] = a[hi];
    a[hi] = t;

    *swaps_out = swaps;
    return i;
}

int main(void) {
    // Supplied array: [7, 2, 9, 4, 3, 8, 5] with pivot 5
    int a[] = {7, 2, 9, 4, 3, 8, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int swaps = 0;

    printf("Initial Array: ");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    int p = partition_lomuto(a, 0, n - 1, &swaps);

    printf("Predict the Output - Partition:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("| pivot at %d, swaps %d\n", p, swaps);

    printf("\nForensics Analysis (n = 10,000):\n");
    printf("- Already sorted array comparisons: n(n-1)/2 = 49,995,000\n");
    printf("- Maximum recursion depth: ~10,000 calls\n");
    printf("- Random permutation expected comparisons: ~184,200 (O(n log n))\n");

    return 0;
}
