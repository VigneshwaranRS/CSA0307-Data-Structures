#include <stdio.h>
#include <limits.h>

/* Task B4: Prim's Dynamic MST with Fibre Cable Failure Rerouting */

#define V 5

int compute_mst(int c[V][V], const char *scenario) {
    int key[V], parent[V], in[V] = {0}, total = 0;
    for (int v = 0; v < V; v++) {
        key[v] = INT_MAX;
        parent[v] = -1;
    }
    key[0] = 0;

    for (int k = 0; k < V; k++) {
        int u = -1, min_k = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (!in[v] && key[v] < min_k) {
                min_k = key[v];
                u = v;
            }
        }
        if (u == -1) break;
        in[u] = 1;
        total += min_k;

        for (int v = 0; v < V; v++) {
            if (c[u][v] > 0 && !in[v] && c[u][v] < key[v]) {
                key[v] = c[u][v];
                parent[v] = u;
            }
        }
    }

    printf("--- %s ---\n", scenario);
    for (int v = 1; v < V; v++) {
        if (parent[v] != -1)
            printf("%d-%d(%d) ", parent[v], v, c[parent[v]][v]);
    }
    printf("\nTotal Fibre Cost = Rs. %d Lakh\n\n", total);
    return total;
}

int main(void) {
    int c[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    compute_mst(c, "Initial Optimal Fibre MST");

    /* Simulate failure of primary cable between 0 and 1 */
    c[0][1] = c[1][0] = 0;
    compute_mst(c, "Recomputed MST after Cable Failure (0-1 disconnected)");

    return 0;
}
