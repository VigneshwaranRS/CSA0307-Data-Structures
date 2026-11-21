#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key, height;
    struct Node *left, *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct Node *n) {
    return n ? n->height : 0;
}

struct Node* createNode(int key) {
    struct Node *n = malloc(sizeof(struct Node));
    n->key = key;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

int balance(struct Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node* insert(struct Node *root, int key) {
    if (!root) return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int b = balance(root);

    if (b > 1 && key < root->left->key)
        return rightRotate(root);

    if (b < -1 && key > root->right->key)
        return leftRotate(root);

    if (b > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main(void) {
    struct Node *root = NULL;
    int values[] = {10, 20, 30, 40, 50, 25};
    int n = 6;

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("AVL Tree Inorder: ");
    inorder(root);
    printf("\nRoot Node: %d\n", root->key);

    return 0;
}
