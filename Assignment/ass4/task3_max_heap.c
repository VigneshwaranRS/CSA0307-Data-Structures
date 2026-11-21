#include <stdio.h>
#include <stdlib.h>

/* Task 3: Heaps and Priority Queues */

#define MAX 100

typedef struct {
    int severity;
    int patient;
} Case;

Case heap[MAX];
int size = 0;

void swap(Case *a, Case *b) {
    Case t = *a;
    *a = *b;
    *b = t;
}

void push(int severity, int patient) {
    if (size == MAX) return;
    heap[size] = (Case){severity, patient};
    int i = size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].severity >= heap[i].severity) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

Case pop(void) {
    Case top = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    for (;;) {
        int l = 2 * i + 1, r = l + 1, largest = i;
        if (l < size && heap[l].severity > heap[largest].severity)
            largest = l;
        if (r < size && heap[r].severity > heap[largest].severity)
            largest = r;
        if (largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
    return top;
}

/* Sift-down for min-heap bottom-up construction */
void min_sift_down(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        min_sift_down(arr, n, smallest);
    }
}

int main(void) {
    // 1. Min-Heap Bottom-up Build-Heap
    int arr[] = {9, 4, 7, 1, 8, 2, 6};
    int n = 7;
    printf("Build-Heap initial array: 9 4 7 1 8 2 6\n");
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_sift_down(arr, n, i);
    }
    printf("Predicted output: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // 2. Emergency Department Max-Heap Priority Queue
    // Severities: [3, 9, 5, 7, 1, 8] for patients [101, 102, 103, 104, 105, 106]
    int severities[] = {3, 9, 5, 7, 1, 8};
    int patients[]   = {101, 102, 103, 104, 105, 106};

    printf("Triage Patient Admissions:\n");
    for (int i = 0; i < 6; i++) {
        push(severities[i], patients[i]);
        printf("Admitted P%d (Severity %d)\n", patients[i], severities[i]);
    }

    printf("\nTreatment Order (Highest Severity First):\n");
    while (size > 0) {
        Case c = pop();
        printf("P%d(%d)%s", c.patient, c.severity, size > 0 ? ", " : "\n");
    }

    return 0;
}
