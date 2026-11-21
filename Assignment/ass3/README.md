# Assignment 3 – CO3: Optimized Data Storage and Retrieval Using Tree-Based Structures

**Course:** CSA0307 - Data Structures  
**Student Name:** RS Vigneshwaran  
**Register Number:** 192521307  
**Department:** Information Technology  

---

## Content Overview

This directory contains the code implementations, execution output screenshots, and full documentation for Assignment 3.

### 1. Document
- `RS Vigneshwaran A3.docx`: Full assignment report document.

### 2. Questions, Source Codes & Screenshots

| Question | Topic / Data Structure | C Source Code | Output Screenshot | Description |
| :---: | :---: | :---: | :---: | :--- |
| **Q1** | **Binary Search Tree (BST)** | [`q1_bst.c`](./q1_bst.c) | [`A3 Q1.png`](./A3%20Q1.png) | Node creation, BST insertion, in-order traversal, searching, finding minimum, and node deletion with two children replacement. |
| **Q2** | **AVL Tree** | [`q2_avl.c`](./q2_avl.c) | [`A3 Q2.png`](./A3%20Q2.png) | Self-balancing binary search tree maintaining balance factor with Left-Left (LL), Right-Right (RR), Left-Right (LR), and Right-Left (RL) rotations. |
| **Q3** | **B-Tree** | [`q3_btree.c`](./q3_btree.c) | [`A3 Q3.png`](./A3%20Q3.png) | Multi-way search tree (order $T=3$) implementing key insertion, child splitting (`splitChild`), non-full insertion, search, and tree traversal. |
| **Q4** | **Red-Black Tree** | [`q4_redblack.c`](./q4_redblack.c) | [`A3 Q4.png`](./A3%20Q4.png) | Self-balancing BST using red/black node color invariants, tree rotations, and `fixInsert` for recoloring and balancing. |
| **Q5** | **Splay Tree** | [`q5_splay.c`](./q5_splay.c) | [`A3 Q5.png`](./A3%20Q5.png) | Self-adjusting BST using splay operations (zig, zig-zig, zig-zag) to bring accessed elements to the root. |
| **Q6** | **Trie (Prefix Tree)** | [`q6_trie.c`](./q6_trie.c) | [`A3 Q6.png`](./A3%20Q6.png) | Retrieval tree for strings and dictionary prefixes, supporting word insertion, exact word lookup, and prefix search. |

---

## How to Compile and Run

To compile and run any of the C programs using GCC:

```bash
# Example for Q1:
gcc -std=c11 -Wall -Wextra q1_bst.c -o q1_bst
./q1_bst
```
