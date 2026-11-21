# Assignment 4 – CO4: Designing Fast Storage and Ordering of Data

**Course:** CSA0307 - Data Structures  
**Student Name:** RS Vigneshwaran  
**Register Number:** 192521307  
**Department:** Information Technology  

---

## Content Overview

This directory contains the source codes, execution output screenshots, and comprehensive documentation for Assignment 4 (CO4).

### 1. Document
- `RS Vigneshwaran A4.docx`: Comprehensive assignment report covering hash function diagnosis, collision resolution strategies, priority queue heaps, sorting forensics, parallel sorting, and the food delivery platform design challenge.

### 2. Tasks, Source Codes & Screenshots

| Task | Topic | C Source Code | Output Screenshot | Description |
| :---: | :---: | :---: | :---: | :--- |
| **Task 1** | **Hash Function Design Review** | [`task1_hash_function.c`](./task1_hash_function.c) | [`A4 Q1.png`](./A4%20Q1.png) | Diagnosing poor first-two-character hash function and implementing repaired 32-bit FNV-1a and Polynomial rolling hash functions. |
| **Task 2** | **Collision-Resolution Strategies** | [`task2_separate_chaining.c`](./task2_separate_chaining.c) | [`A4 Q2.png`](./A4%20Q2.png) | Separate chaining table with `put` and `get` operations, probe tracking, and linear probing cluster simulation. |
| **Task 3** | **Heaps & Priority Queues** | [`task3_max_heap.c`](./task3_max_heap.c) | [`A4 Q3.png`](./A4%20Q3.png) | Min-heap bottom-up $O(n)$ build-heap verification and emergency triage binary max-heap priority queue. |
| **Task 4** | **Sorting Forensics** | [`task4_quicksort_partition.c`](./task4_quicksort_partition.c) | [`A4 Q4.png`](./A4%20Q4.png) | Quicksort worst-case $O(n^2)$ analysis on sorted input and Lomuto partition tracing loop swaps and pivot placement. |
| **Task 5** | **Sorting Algorithms & Parallel Sorting** | [`task5_stable_merge_sort.c`](./task5_stable_merge_sort.c) | [`A4 Q5.png`](./A4%20Q5.png) | Stable merge sort implementation on order amounts preserving arrival order, with comparison counting and OpenMP parallel analysis. |
| **Task 6** | **Design Challenge** | [`task6_order_system.c`](./task6_order_system.c) | [`A4 Q6.png`](./A4%20Q6.png) | High-throughput food delivery platform engine integrating hash table ID lookup, lateness max-heap, and $O(\log n)$ cancellation. |

---

## How to Compile and Run

To compile and execute any of the task demonstration programs using GCC:

```bash
# Example for Task 1:
gcc -std=c11 -Wall -Wextra task1_hash_function.c -o task1_hash_function
./task1_hash_function

# Example for Task 6:
gcc -std=c11 -Wall -Wextra task6_order_system.c -o task6_order_system
./task6_order_system
```
