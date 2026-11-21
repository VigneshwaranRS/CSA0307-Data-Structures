#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 26

struct Trie {
    struct Trie *child[SIZE];
    int end;
};

struct Trie* createNode(void) {
    struct Trie *n = calloc(1, sizeof(struct Trie));
    return n;
}

void insert(struct Trie *root, char word[]) {
    struct Trie *current = root;

    for (int i = 0; word[i]; i++) {
        int index = tolower((unsigned char)word[i]) - 'a';

        if (index < 0 || index >= SIZE)
            return;

        if (current->child[index] == NULL)
            current->child[index] = createNode();

        current = current->child[index];
    }

    current->end = 1;
}

int search(struct Trie *root, char word[]) {
    struct Trie *current = root;

    for (int i = 0; word[i]; i++) {
        int index = tolower((unsigned char)word[i]) - 'a';

        if (index < 0 || index >= SIZE || current->child[index] == NULL)
            return 0;

        current = current->child[index];
    }

    return current->end;
}

int prefixSearch(struct Trie *root, char word[]) {
    struct Trie *current = root;

    for (int i = 0; word[i]; i++) {
        int index = tolower((unsigned char)word[i]) - 'a';

        if (index < 0 || index >= SIZE || current->child[index] == NULL)
            return 0;

        current = current->child[index];
    }

    return 1;
}

int main(void) {
    struct Trie *root = createNode();

    // INPUT WORDS
    char words[][20] = {
        "apple", "app", "bat", "ball", "cat"
    };

    int n = 5;
    char searchWord[] = "apple";
    char prefix[] = "ap";

    for (int i = 0; i < n; i++)
        insert(root, words[i]);

    printf("Words inserted successfully.\n");

    printf("Search '%s': %s\n", searchWord,
           search(root, searchWord) ? "Found" : "Not Found");

    printf("Prefix '%s': %s\n", prefix,
           prefixSearch(root, prefix) ? "Exists" : "Does Not Exist");

    return 0;
}
