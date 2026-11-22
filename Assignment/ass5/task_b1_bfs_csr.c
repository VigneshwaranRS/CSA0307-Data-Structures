#include <stdio.h>

/* Task B1: Metro Network BFS Traversal in CSR (Compressed Sparse Row) Form */

#define V 7

const char *name[V] = {
    "Airport", "Guindy", "Saidapet", "Central", "Egmore", "Vadapalani", "Koyambedu"
};
int start[V + 1] = {0, 1, 4, 6, 8, 10, 12, 14};
int adj[14] = {1, 0, 2, 5, 1, 3, 2, 4, 3, 6, 1, 6, 4, 5};

int main(void) {
    int dist[V], parent[V], queue[V], head = 0, tail = 0;
    for (int v = 0; v < V; v++) dist[v] = -1;
    dist[0] = 0;
    parent[0] = -1;
    queue[tail++] = 0;

    // Standard BFS using CSR representation
    while (head < tail) {
        int u = queue[head++];
        printf("%s ", name[u]);
        for (int e = start[u]; e < start[u + 1]; e++) {
            int w = adj[e];
            if (dist[w] == -1) {
                dist[w] = dist[u] + 1;
                parent[w] = u;
                queue[tail++] = w;
            }
        }
    }

    printf("\nKoyambedu is %d stops away via:", dist[6]);
    for (int v = 6; v != -1; v = parent[v])
        printf(" %s", name[v]);
    printf("\n");
    return 0;
}
