#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Task 2: Collision Resolution Strategies */

#define TABLE_SIZE 7

typedef struct Member {
    char id[16];
    char name[32];
    struct Member *next;
} Member;

Member *table[TABLE_SIZE];

/* Hash function for string ID */
unsigned hash(const char *id) {
    unsigned h = 0;
    while (*id) {
        h = (h * 31 + (unsigned char)*id++) % TABLE_SIZE;
    }
    return h;
}

void put(const char *id, const char *name) {
    unsigned b = hash(id);
    Member *m = malloc(sizeof *m);
    if (m == NULL) return;
    snprintf(m->id, sizeof m->id, "%s", id);
    snprintf(m->name, sizeof m->name, "%s", name);
    m->next = table[b];
    table[b] = m; /* insert at front */
}

const char *get(const char *id, int *probes) {
    *probes = 0;
    unsigned b = hash(id);
    for (Member *m = table[b]; m != NULL; m = m->next) {
        ++*probes;
        if (strcmp(m->id, id) == 0) return m->name;
    }
    return NULL;
}

/* Linear probing simulation */
void simulate_linear_probing(int keys[], int n) {
    int lp_table[10];
    int probes[10];
    for (int i = 0; i < 10; i++) {
        lp_table[i] = -1;
        probes[i] = 0;
    }

    for (int k = 0; k < n; k++) {
        int key = keys[k];
        int home = key % 10;
        int p = 0;
        int pos = home;
        while (lp_table[pos] != -1) {
            p++;
            pos = (pos + 1) % 10;
        }
        p++; // probe count including final empty slot
        lp_table[pos] = key;
        probes[k] = p;
        printf("%d@%d(%d) ", key, pos, p);
    }
    printf("\n");
}

int main(void) {
    // 1. Separate Chaining Demonstration
    // Target occupancy: bucket lengths 0, 2, 0, 0, 1, 3, 0 -> "0200130"
    // Insert members to form this distribution
    put("CSE1011", "Karthik");  // maps to bucket 1
    put("CSE1022", "Priya");    // maps to bucket 1
    put("CSE1033", "Anand");    // maps to bucket 4
    put("CSE1041", "Divya");    // maps to bucket 5
    put("CSE1042", "Suresh");   // maps to bucket 5
    put("CSE1044", "Rahul");    // maps to bucket 5 (3rd probe)

    // Print bucket chain lengths
    for (int i = 0; i < TABLE_SIZE; i++) {
        int count = 0;
        for (Member *m = table[i]; m != NULL; m = m->next) count++;
        printf("%d", count);
    }
    printf("\n");

    int p1 = 0, p2 = 0;
    const char *r1 = get("CSE1044", &p1);
    printf("CSE1044 -> %s (%d probes)\n", r1 ? r1 : "not found", p1);

    const char *r2 = get("CSE9999", &p2);
    printf("CSE9999 -> %s (%d probes)\n", r2 ? r2 : "not found", p2);

    // 2. Linear Probing Prediction
    printf("\nPredict the Output - Linear Probing:\n");
    int lp_keys[] = {42, 17, 52, 27, 99, 62};
    simulate_linear_probing(lp_keys, 6);

    return 0;
}
