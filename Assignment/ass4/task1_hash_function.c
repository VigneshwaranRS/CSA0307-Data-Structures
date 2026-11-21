#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Task 1: Hash Function Design Review & Repair */

/* Flawed hash function using only first two characters */
unsigned hash_poor(const char *s, unsigned table_size) {
    return ((unsigned char)s[0] + (unsigned char)s[1]) % table_size;
}

/* Repaired design: FNV-1a 32-bit hash */
unsigned hash_fnv1a(const char *s, unsigned table_size) {
    uint32_t h = 2166136261u;
    while (*s) {
        h ^= (unsigned char)*s++;
        h *= 16777619u;
    }
    return h % table_size;
}

/* Alternative: Polynomial Rolling Hash (h = h * 31 + c) */
unsigned hash_polynomial(const char *s, unsigned table_size) {
    unsigned long h = 0;
    while (*s) {
        h = h * 31 + (unsigned char)*s++;
    }
    return h % table_size;
}

int main(void) {
    const char *plates[] = {
        "TN09AB1234",
        "TN09AB1235",
        "TN09AB1236",
        "KL07CD5678",
        "KA01EF9012"
    };
    int n = 5;

    printf("--- Poor Hash: (reg[0]+reg[1]) %% 1000 ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s -> Bucket: %u\n", plates[i], hash_poor(plates[i], 1000));
    }

    printf("\n--- Repaired FNV-1a Hash %% 1000 ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s -> Bucket: %u\n", plates[i], hash_fnv1a(plates[i], 1000));
    }

    printf("\n--- Polynomial Rolling Hash %% 1000 ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s -> Bucket: %u\n", plates[i], hash_polynomial(plates[i], 1000));
    }

    return 0;
}
