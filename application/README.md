# Application of the Library

A program [`main.c`](main.c) is coded with a `main` function that reads a file name from the user, which stores a weighted undirected graph. The program then calls `readGraph` to prepare a graph `G`. Finally, the program calls `DFS`, `BFS`, and `MST` on `G`. 

The [`makefile`](makefile) is written to create an executable file called [`graph.out`](graph.out) from the [`main.c`](main.c) file.

A sample graph is written in the text file [`sample_graph.txt`](sample_graph.txt)
