#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node *root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int search(struct Node *root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

struct Node* minimum(struct Node *root) {
    while (root->left)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node *root, int key) {
    if (!root) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(void) {
    struct Node *root = NULL;

    // INPUT VALUES
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;
    int searchKey = 40;
    int deleteKey = 30;

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("BST Inorder: ");
    inorder(root);

    printf("\nSearch %d: ", searchKey);
    printf("%s\n", search(root, searchKey) ? "Found" : "Not Found");

    root = deleteNode(root, deleteKey);
    printf("After deleting %d: ", deleteKey);
    inorder(root);
    printf("\n");

    return 0;
}
