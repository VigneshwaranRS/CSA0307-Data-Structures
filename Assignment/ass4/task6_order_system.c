#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Task 6: Design Challenge - Food Delivery Platform */

#define HASH_SIZE 101
#define MAX_ORDERS 1000

typedef enum { PLACED, ASSIGNED, CANCELLED } Status;

typedef struct Order {
    char id[16];
    char restaurant[32];
    int amount;
    int promised_time;
    int current_time;
    int lateness;
    int heap_index;
    Status status;
    struct Order *next_hash;
} Order;

Order *hash_table[HASH_SIZE];
Order *heap[MAX_ORDERS];
int heap_size = 0;

/* FNV-1a Hash */
unsigned hash(const char *id) {
    unsigned h = 2166136261u;
    while (*id) {
        h ^= (unsigned char)*id++;
        h *= 16777619u;
    }
    return h % HASH_SIZE;
}

void swap_heap(int i, int j) {
    Order *t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
    heap[i]->heap_index = i;
    heap[j]->heap_index = j;
}

void sift_up(int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p]->lateness >= heap[i]->lateness) break;
        swap_heap(p, i);
        i = p;
    }
}

void sift_down(int i) {
    for (;;) {
        int l = 2 * i + 1, r = l + 1, largest = i;
        if (l < heap_size && heap[l]->lateness > heap[largest]->lateness)
            largest = l;
        if (r < heap_size && heap[r]->lateness > heap[largest]->lateness)
            largest = r;
        if (largest == i) break;
        swap_heap(i, largest);
        i = largest;
    }
}

void place_order(const char *id, const char *restaurant, int amount, int promised, int current) {
    Order *ord = malloc(sizeof *ord);
    snprintf(ord->id, sizeof ord->id, "%s", id);
    snprintf(ord->restaurant, sizeof ord->restaurant, "%s", restaurant);
    ord->amount = amount;
    ord->promised_time = promised;
    ord->current_time = current;
    ord->lateness = (current > promised) ? (current - promised) : 0;
    ord->status = PLACED;

    /* Insert into hash table */
    unsigned b = hash(id);
    ord->next_hash = hash_table[b];
    hash_table[b] = ord;

    /* Insert into lateness max-heap */
    ord->heap_index = heap_size;
    heap[heap_size++] = ord;
    sift_up(ord->heap_index);

    printf("Placed Order [%s] at %s (Amt: $%d, Lateness: %d min)\n",
           id, restaurant, amount, ord->lateness);
}

Order* assign_next_rider(void) {
    if (heap_size == 0) return NULL;
    Order *top = heap[0];
    top->status = ASSIGNED;

    /* Remove root from heap */
    heap[0] = heap[--heap_size];
    heap[0]->heap_index = 0;
    sift_down(0);

    return top;
}

int cancel_order(const char *id) {
    unsigned b = hash(id);
    Order *curr = hash_table[b];
    while (curr) {
        if (strcmp(curr->id, id) == 0 && curr->status == PLACED) {
            curr->status = CANCELLED;
            int idx = curr->heap_index;
            heap[idx] = heap[--heap_size];
            heap[idx]->heap_index = idx;
            sift_down(idx);
            sift_up(idx);
            return 1;
        }
        curr = curr->next_hash;
    }
    return 0;
}

int main(void) {
    printf("=== Food Delivery Platform Dispatch Simulation ===\n\n");

    place_order("ORD-101", "BurgerKing", 450, 30, 45); // lateness 15
    place_order("ORD-102", "Dominos",    620, 25, 55); // lateness 30
    place_order("ORD-103", "KFC",        380, 40, 42); // lateness 2
    place_order("ORD-104", "Dominos",    290, 20, 58); // lateness 38
    place_order("ORD-105", "Subway",     180, 35, 35); // lateness 0

    printf("\n[Action] Cancel ORD-103: %s\n\n",
           cancel_order("ORD-103") ? "Cancelled successfully" : "Failed");

    printf("Assigning Orders to Available Riders by Highest Lateness:\n");
    while (heap_size > 0) {
        Order *ord = assign_next_rider();
        printf("-> Assigned %s (%s, Lateness: %d min, Amt: $%d)\n",
               ord->id, ord->restaurant, ord->lateness, ord->amount);
    }

    return 0;
}
