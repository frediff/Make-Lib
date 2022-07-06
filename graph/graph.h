#ifndef __GRAPHS_
#define __GRAPHS_

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program contains the definitions of graph data structure and the associated operations : BFS, DFS, MST-calculation
*/

typedef struct _GRAPH{
	int** adj_mat;
	int n;
	int m;
}GRAPH;

GRAPH readGraph(char*);
void DFS(GRAPH);
void BFS(GRAPH);
void MST(GRAPH);
GRAPH deallocateGraph(GRAPH);

#endif
