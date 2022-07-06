#include<graph.h>
#include<stdio.h>

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program prompts a user to enter a file name that stores a graph, reads that graph, and performs DFS, BFS and MST calculation on it.
*/

int main(){
	char buffer[256];
	printf("ENTER PATH OF FILE CONTAINING THE GRAPH : ");
	scanf("%s",buffer);
	GRAPH g = readGraph(buffer);
	DFS(g);
	BFS(g);
	MST(g);
	g = deallocateGraph(g);
	return 0;
}
