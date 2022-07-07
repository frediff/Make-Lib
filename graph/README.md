# Graph Library

#### This directory contains implementation of some basic graph functions and the make-file to build and install a static library out of it.

We implement a data type `GRAPH` to represent weighted, undirected graphs with positive integer weights. The `GRAPH` data type can represent graphs with a maximum of `100` nodes, using adjacency matrix to store the graph. For an edge existing in the graph, the corresponding entry in the matrix stores the weight of the edge. If for an entry `(i, j)`
no corresponding edge exists in the graph, the entry stores 0. The `GRAPH` data type supports the following functions:
- `GRAPH readGraph(char *FName)`: Reads the nodes and edges of a graph from a file with name `FName` (assuming that the file always exists). The format of the file is specified later. The new graph is returned.
- `void DFS(GRAPH G)`: Does a `DFS` traversal of the graph `G` using the `STACK` data type (in the dynamic library), and prints out the nodes in the `DFS` traversal order.
- `void BFS(GRAPH G)`: Does a `BFS` traversal of the graph `G` using the `QUEUE` data type (in the dynamic library), and prints out the nodes in the `BFS` traversal order.
- `void MST(GRAPH G)`: Computes the minimum spanning tree of the graph `G` using Kruskal’s algorithm. The function prints out the edges added to the tree (the two endpoints and the weight), each edge in a single line, followed by the weight of the `MST` in the last line. The function uses the `UNION_FIND` data structure of the dynamic library.

***The functions are implemented in the C file [`graph.c`](graph.c) with an appropriate [`graph.h`](graph.h) file added.***

The format in which a graph will be stored in the file is given below:
- The first line will contain the number of nodes `n`. The nodes are identified by the numbers `0` to `n – 1`.
- The second line will store the number of edges `m`.
- After that, there will be `m` lines, each specifying one edge. Each edge will be specified in a single line with the format `u v w`, representing an edge between nodes `u` and `v` with weight `w`. Assume that the same edge is not present multiple times in the file.

***The installation dependencies are present in [`makefile.graph`](makefile.graph).***

***Always make sure that the `makefile` is run with root permission.***
