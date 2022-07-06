#include <stdlib.h>
#include "union_find.h"

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program implements the standard union find operations
*/

UNION_FIND createUF(int n){
	UNION_FIND F;
	F.arr = (NODE_PTR*) calloc(n, sizeof(NODE_PTR));
	F.sz = 0;
	F.cap = n;
	return F;
};

UNION_FIND makeSetUF(UNION_FIND F, int x, int* i){
	if(F.sz == F.cap) return F;
	F.arr[F.sz] = (NODE_PTR) malloc(sizeof(NODEUF));
	F.arr[F.sz]->p.val =  x;
	F.arr[F.sz]->p.next = NULL;
	F.arr[F.sz]->tree_size = 1;
	*i = F.sz;
	++F.sz;
	return F;
};

NODE_PTR findUF(UNION_FIND F, int i){
	if(F.arr[i] == NULL) return NULL;
	else{
		NODE_PTR ID = F.arr[i];
		while(ID->p.next != NULL){
			ID = (NODE_PTR) (ID->p.next);
		}
		return ID;
	}
};

void unionUF(UNION_FIND F, int i, int j){
	if(F.arr[i] == NULL || F.arr[j] == NULL) return;

	NODE_PTR ID1 = findUF(F,i);
	NODE_PTR ID2 = findUF(F,j);

	if (ID1 == ID2) {
		return;
	}

	if(ID1->tree_size < ID2->tree_size){
		ID1->p.next = (NODE*) ID2;
		ID2->tree_size = ID1->tree_size + ID2->tree_size;
	}
	else{
		ID2->p.next = (NODE*) ID1;
		ID1->tree_size = ID2->tree_size + ID1->tree_size;
	}
};

UNION_FIND deallocateUF(UNION_FIND F){
	if(F.arr == NULL){
		F.arr = NULL;
		F.sz = 0;
		F.cap = 0;
		return F;
	}
	for(int iterator = 0; iterator<F.cap; ++iterator){
		if(F.arr[iterator] != NULL){
			free(F.arr[iterator]);
			F.arr[iterator] = NULL;
		}
	}
	free(F.arr);
	F.sz = 0;
	F.cap = 0;
	F.arr = NULL;
	return F;
};
