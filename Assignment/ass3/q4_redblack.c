#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

struct Node {
    int data, color;
    struct Node *left, *right, *parent;
};

struct Node *NIL;

struct Node* createNode(int data) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = data;
    n->color = RED;
    n->left = n->right = n->parent = NIL;
    return n;
}

void leftRotate(struct Node **root, struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;

    if (y->left != NIL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(struct Node **root, struct Node *y) {
    struct Node *x = y->left;
    y->left = x->right;

    if (x->right != NIL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NIL)
        *root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;

    x->right = y;
    y->parent = x;
}

void fixInsert(struct Node **root, struct Node *z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            struct Node *y = z->parent->parent->right;

            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else {
            struct Node *y = z->parent->parent->left;

            if (y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(struct Node **root, int data) {
    struct Node *z = createNode(data);
    struct Node *y = NIL;
    struct Node *x = *root;

    while (x != NIL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NIL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(root, z);
}

void inorder(struct Node *root) {
    if (root != NIL) {
        inorder(root->left);
        printf("%d(%s) ", root->data, root->color == RED ? "RED" : "BLACK");
        inorder(root->right);
    }
}

int main(void) {
    NIL = malloc(sizeof(struct Node));
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = NULL;

    struct Node *root = NIL;

    int values[] = {10, 20, 30, 15, 25, 7};
    int n = 6;

    for (int i = 0; i < n; i++)
        insert(&root, values[i]);

    printf("Red-Black Tree Inorder:\n");
    inorder(root);
    printf("\n");

    printf("Root Node: %d\n", root->data);
    printf("Root Color: %s\n", root->color == RED ? "RED" : "BLACK");

    return 0;
}
