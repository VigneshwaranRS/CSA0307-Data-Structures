#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* createNode(int key) {
    struct Node *n = malloc(sizeof(struct Node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

struct Node* rightRotate(struct Node *x) {
    struct Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

struct Node* splay(struct Node *root, int key) {
    if (!root || root->key == key)
        return root;

    if (key < root->key) {
        if (!root->left)
            return root;

        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right)
                root->left = leftRotate(root->left);
        }

        return root->left ? rightRotate(root) : root;
    }
    else {
        if (!root->right)
            return root;

        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left)
                root->right = rightRotate(root->right);
        }

        return root->right ? leftRotate(root) : root;
    }
}

struct Node* insert(struct Node *root, int key) {
    if (!root)
        return createNode(key);

    root = splay(root, key);

    if (root->key == key)
        return root;

    struct Node *n = createNode(key);

    if (key < root->key) {
        n->right = root;
        n->left = root->left;
        root->left = NULL;
    }
    else {
        n->left = root;
        n->right = root->right;
        root->right = NULL;
    }
    return n;
}

struct Node* search(struct Node *root, int key) {
    return splay(root, key);
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
    int values[] = {100, 50, 200, 40, 60, 150};
    int n = 6;
    int searchKey = 60;

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Splay Tree Inorder: ");
    inorder(root);
    printf("\n");

    root = search(root, searchKey);
    printf("After searching %d:\n", searchKey);
    printf("New Root: %d\n", root->key);

    return 0;
}
