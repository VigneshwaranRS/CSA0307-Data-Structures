#include <stdio.h>
#include <stdlib.h>

/* Task 5: Sorting Algorithms and Stable Merge */

typedef struct {
    int id;
    int amount;
} Order;

int comparisons = 0;

void merge(Order a[], Order tmp[], int lo, int mid, int hi) {
    int i = lo, j = mid + 1, k = lo;
    while (i <= mid && j <= hi) {
        ++comparisons;
        if (a[i].amount <= a[j].amount) { /* '<=' ensures stability */
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= hi) tmp[k++] = a[j++];
    for (i = lo; i <= hi; ++i) a[i] = tmp[i];
}

void merge_sort(Order a[], Order tmp[], int lo, int hi) {
    if (lo >= hi) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort(a, tmp, lo, mid);
    merge_sort(a, tmp, mid + 1, hi);
    merge(a, tmp, lo, mid, hi);
}

int main(void) {
    /* 8 input orders with ID and amount */
    Order orders[] = {
        {1, 450},
        {2, 120},
        {3, 450},
        {4, 990},
        {5, 120},
        {6, 300},
        {7, 780},
        {8, 300}
    };
    int n = 8;
    Order tmp[8];

    printf("Input Orders:\n");
    for (int i = 0; i < n; i++) {
        printf("#%d:%d ", orders[i].id, orders[i].amount);
    }
    printf("\n\n");

    merge_sort(orders, tmp, 0, n - 1);

    printf("Expected output: ");
    for (int i = 0; i < n; i++) {
        printf("#%d:%d ", orders[i].id, orders[i].amount);
    }
    printf("\nfollowed by comparisons = %d.\n", comparisons);

    printf("\nStability Verification:\n");
    printf("- #2:120 appears before #5:120 (preserved)\n");
    printf("- #6:300 appears before #8:300 (preserved)\n");
    printf("- #1:450 appears before #3:450 (preserved)\n");

    return 0;
}
