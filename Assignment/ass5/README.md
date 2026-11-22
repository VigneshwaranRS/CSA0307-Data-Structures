# Assignment 5 – CO5: Modelling and Analysing Real-World Networks with Graphs

**Course:** CSA0307 - Data Structures  
**Student Name:** RS Vigneshwaran  
**Register Number:** 192521307  
**Department:** Information Technology  
**Case Study:** Chennai City Mobility and Delivery Network (50,000 junctions, 120,000 road segments)  

---

## Content Overview

This directory contains the complete source code implementations, execution output screenshots, and comprehensive documentation for Assignment 5 (CO5).

### 1. Document
- `RS Vigneshwaran A5.docx`: Comprehensive assignment report covering graph modeling, representation trade-offs, graph traversals, topological sorting, shortest-path algorithms (Dijkstra, Floyd-Warshall, A*), minimum spanning trees (Prim's algorithm), and production engineering decisions for large-scale urban mobility networks.

### 2. Tasks, Source Codes & Screenshots

| Task | Topic | C Source Code | Output Screenshot | Description |
| :---: | :---: | :---: | :---: | :--- |
| **Task A2** | **Graph Traversals (DFS)** | [`task_a2_dfs.c`](./task_a2_dfs.c) | [`A5 Q1.png`](./A5%20Q1.png) | Depth-First Search traversal on a 6-vertex adjacency matrix demonstrating recursive exploration and output prediction. |
| **Task A3** | **Topological Sorting (Kahn's)** | [`task_a3_kahn.c`](./task_a3_kahn.c) | [`A5 Q2.png`](./A5%20Q2.png) | Delivery hub setup workflow dependency scheduling using in-degree reduction and FIFO queue for cycle detection. |
| **Task A4** | **All-Pairs Shortest Path (Floyd)** | [`task_a4_floyd.c`](./task_a4_floyd.c) | [`A5 Q3.png`](./A5%20Q3.png) | Floyd-Warshall dynamic programming algorithm computing inter-hub distance matrix and path relaxation. |
| **Task A5** | **Minimum Spanning Tree (Prim's)** | [`task_a5_prim.c`](./task_a5_prim.c) | [`A5 Q4.png`](./A5%20Q4.png) | Greedy minimum spanning tree construction connecting villages with optic fibre cable at minimal total expenditure. |
| **Task B1** | **Metro Network BFS (CSR Format)** | [`task_b1_bfs_csr.c`](./task_b1_bfs_csr.c) | [`A5 Q5.png`](./A5%20Q5.png) | Breadth-First Search on Chennai Metro lines stored in Compressed Sparse Row (CSR) format finding fewest-stops path. |
| **Task B2** | **Shortest Paths (Dijkstra)** | [`task_b2_dijkstra.c`](./task_b2_dijkstra.c) | [`A5 Q6.png`](./A5%20Q6.png) | Single-source shortest path computation on weighted city road map with parent pointers and route reconstruction. |
| **Task B3** | **Heuristic Search (A* vs Dijkstra)** | [`task_b3_astar.c`](./task_b3_astar.c) | — | A* search on a 2D obstacle grid demonstrating 50% fewer node expansions than Dijkstra due to Euclidean heuristic. |
| **Task B4** | **Dynamic MST & Resilient Cabling** | [`task_b4_dynamic_mst.c`](./task_b4_dynamic_mst.c) | — | Dynamic recomputation of optic fibre MST upon primary link severance to preserve municipal network connectivity. |

---

## How to Compile and Run

To compile and execute any of the task demonstration programs using GCC:

```bash
# Example for Task A3 (Kahn's Topological Sort):
gcc -std=c11 -Wall -Wextra task_a3_kahn.c -o task_a3_kahn
./task_a3_kahn

# Example for Task B2 (Dijkstra Shortest Path):
gcc -std=c11 -Wall -Wextra task_b2_dijkstra.c -o task_b2_dijkstra
./task_b2_dijkstra
```
