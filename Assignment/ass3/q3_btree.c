#include <stdio.h>
#include <stdlib.h>

#define T 3

struct Node {
    int keys[2*T - 1];
    struct Node *child[2*T];
    int n;
    int leaf;
};

struct Node* createNode(int leaf) {
    struct Node *x = malloc(sizeof(struct Node));
    x->n = 0;
    x->leaf = leaf;
    for (int i = 0; i < 2*T; i++)
        x->child[i] = NULL;
    return x;
}

void traverse(struct Node *root) {
    if (!root) return;
    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf)
            traverse(root->child[i]);
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf)
        traverse(root->child[i]);
}

struct Node* search(struct Node *root, int key) {
    if (!root) return NULL;
    int i = 0;
    while (i < root->n && key > root->keys[i])
        i++;
    if (i < root->n && key == root->keys[i])
        return root;
    if (root->leaf)
        return NULL;
    return search(root->child[i], key);
}

void splitChild(struct Node *parent, int i, struct Node *full) {
    struct Node *right = createNode(full->leaf);
    right->n = T - 1;

    for (int j = 0; j < T - 1; j++)
        right->keys[j] = full->keys[j + T];

    if (!full->leaf) {
        for (int j = 0; j < T; j++)
            right->child[j] = full->child[j + T];
    }

    full->n = T - 1;

    for (int j = parent->n; j >= i + 1; j--)
        parent->child[j + 1] = parent->child[j];

    parent->child[i + 1] = right;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = full->keys[T - 1];
    parent->n++;
}

void insertNonFull(struct Node *node, int key) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n++;
    } else {
        while (i >= 0 && key < node->keys[i])
            i--;
        i++;
        if (node->child[i]->n == 2 * T - 1) {
            splitChild(node, i, node->child[i]);
            if (key > node->keys[i])
                i++;
        }
        insertNonFull(node->child[i], key);
    }
}

void insert(struct Node **root, int key) {
    if (*root == NULL) {
        *root = createNode(1);
        (*root)->keys[0] = key;
        (*root)->n = 1;
        return;
    }

    if ((*root)->n == 2 * T - 1) {
        struct Node *s = createNode(0);
        s->child[0] = *root;
        splitChild(s, 0, *root);
        int i = 0;
        if (s->keys[0] < key)
            i++;
        insertNonFull(s->child[i], key);
        *root = s;
    } else {
        insertNonFull(*root, key);
    }
}

int main(void) {
    struct Node *root = NULL;
    int values[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int n = 8;
    int searchKey = 12;

    for (int i = 0; i < n; i++)
        insert(&root, values[i]);

    printf("B-Tree Traversal: ");
    traverse(root);
    printf("\n");

    printf("Search %d: %s\n", searchKey, search(root, searchKey) ? "Found" : "Not Found");

    return 0;
}
