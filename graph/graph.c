#include"graph.h"
#include<stdlib.h>
#include<stdio.h>
#include<subham_ds.h>

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program implements the functions associated with the graph data structure
*/

GRAPH readGraph(char* Fname){
	FILE* f = fopen(Fname, "r");
	int i=0;

	GRAPH G = {NULL,0,0};
	fscanf(f,"%d",&G.n);
	G.adj_mat = (int**) malloc(sizeof(int*)*G.n);
	for(i=0;i<G.n;++i){
		G.adj_mat[i] = (int*) calloc(G.n,sizeof(int));
	}
	
	fscanf(f,"%d",&G.m);
	
	int u,v,w;
	for(i=0;i<G.m;++i){
		fscanf(f,"%d%d%d",&u,&v,&w);
		G.adj_mat[u][v] = w;
		G.adj_mat[v][u] = w;
	}

	fclose(f);
	return G;
};

void DFS(GRAPH G){
	if(G.adj_mat == NULL){
		printf("\nDFS CANNOT BE DONE. GRAPH IS EMPTY\n");
		return;
	}
	printf("\nDFS TRAVERSAL ORDER : ");
	char* visit_flag = (char*) calloc(G.n,sizeof(char));
	STACK dfs = createStack();
	int i=0,j=0,top;
	char is_pop = 1;
	int buffer;
	for(i=0;i<G.n;++i){

		if(!visit_flag[i]){

			dfs = push(dfs,i);
			visit_flag[i] = 1;
			printf("%d ",i);
			
			while(!isEmptyStack(dfs)){

				top = dfs.l.front->val;
				is_pop = 1;

				for(j=0;j<G.n;++j){
					if(!visit_flag[j] && G.adj_mat[top][j]){
						dfs = push(dfs,j);
						printf("%d ",j);
						visit_flag[j] = 1;
						is_pop = 0;
						break;
					}					
				}

				if(is_pop){
					dfs = pop(dfs,&buffer);
				}
			}
		}		
	}
	free(visit_flag);
	visit_flag = NULL;
	dfs = deallocateStack(dfs);
	printf("\n");
};

void BFS(GRAPH G){
	if(G.adj_mat == NULL){
		printf("\nBFS CANNOT BE DONE. GRAPH IS EMPTY\n");
		return;
	}
	printf("\nBFS TRAVERSAL ORDER : ");
	char* visit_flag = (char*) calloc(G.n,sizeof(char));
	QUEUE bfs = createQueue();

	int i=0,j=0,buffer;

	for(i=0;i<G.n;++i){

		if(!visit_flag[i]){

			bfs = enqueue(bfs,i);
			visit_flag[i] = 1;
			
			while(!isEmptyQueue(bfs)){
				bfs = dequeue(bfs,&buffer);
				printf("%d ",buffer);

				for(j=0;j<G.n;++j){
					if(!visit_flag[j] && G.adj_mat[buffer][j]){
						bfs = enqueue(bfs,j);
						visit_flag[j] = 1;
					}					
				}
			}
		}		
	}
	free(visit_flag);
	visit_flag = NULL;
	bfs = deallocateQueue(bfs);
	printf("\n");
};

void sortEdges(int** edge,int n){
	if(n<=1) return;
	int i;
	int j;
	int k;

	int** l = (int**) malloc((n/2)*sizeof(int*));
	for(i=0;i<(n/2);++i){
		l[i] = edge[i];
	}
	sortEdges(l,n/2);

	int** r = (int**) malloc((n-n/2)*sizeof(int*));
	for(i=0;i<(n-n/2);++i){
		r[i] = edge[i+n/2];
	}
	sortEdges(r,n-n/2);

	i=0;
	j=0;
	k=0;
	while((i<(n/2)) && (j<(n-n/2))){
		if(l[i][2]<r[j][2]){
			edge[k++] = l[i++];
		}
		else{
			edge[k++] = r[j++];
		}
	}
	while(i<(n/2)){
		edge[k++] = l[i++];
	}
	while(j<(n-n/2)){
		edge[k++] = r[j++];
	}

	free(l);
	l = NULL;
	free(r);
	r = NULL;
}

void MST(GRAPH G){
	if(G.adj_mat == NULL){
		printf("\nMST CANNOT BE CALCULATED. GRAPH IS EMPTY\n");
		return;
	}
	printf("\nMST : ");
	int** edge = (int**) calloc(G.m,sizeof(int*));

	int i=0,j=0;
	for(i=0;i<G.m;++i){
		edge[i] = (int*) malloc(3*sizeof(int));
	}

	int k = 0;
	for(i=0;i<G.n;++i){
		for(j=(i+1);j<G.n;++j){
			if(G.adj_mat[i][j]){
				edge[k][0] = i;
				edge[k][1] = j;
				edge[k][2] = G.adj_mat[i][j];
				++k;
			}
		}
	}

	sortEdges(edge,k);
	int buffer;
	UNION_FIND uf = createUF(G.n);
	for(i=0;i<G.n;++i){
		uf = makeSetUF(uf,i,&buffer);
	}


	NODE_PTR u = NULL,v = NULL;
	int weight = 0;
	int count = 0;
	for(int iter=0;iter<k;++iter){
		i = edge[iter][0];
		j = edge[iter][1];
		u = findUF(uf,i);
		v = findUF(uf,j);
		if(u==v){
			continue;
		}
		else{
			unionUF(uf,i,j);
			weight += edge[iter][2];
			++count;
			printf("\n%d %d %d",i,j,edge[iter][2]);
		}
	}
	printf("\nWEIGHT OF THE MST : %d\n",weight);
	if(count!=G.n-1){
		printf("\nTHE GIVEN GRAPH HAPPENS TO BE DISCONNECTED. THE LIST OF EDGES SO OBTAINED THUS FORM A FOREST OF MSTs CORRESPONDING TO EACH CONNECTED COMPONENT OF THE GRAPH AND THE WEIGHT SO OBTAINED IS THE SUM OF ALL SUCH MSTs\n");
	}
	uf = deallocateUF(uf);
	for(i=0;i<G.m;++i){
		free(edge[i]);
		edge[i] = NULL;
	}
	free(edge);
	edge = NULL;
}

GRAPH deallocateGraph(GRAPH G){
	int i=0;
	if(G.adj_mat == NULL){
		G.adj_mat = NULL;
		G.n = 0;
		G.m = 0;
		return G;
	}
	for(i=0;i<G.n;++i) {
		free(G.adj_mat[i]);
		G.adj_mat[i] = NULL;
	}
	free(G.adj_mat);
	G.adj_mat = NULL;
	G.n = 0;
	G.m = 0;
	return G;
};
