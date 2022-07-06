#ifndef UNION_FIND_H
#define UNION_FIND_H

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program contains the definitions of union-find node pointer, a node in union-find forest, and union-find structure
*/

#include "llist.h"

typedef struct _NODEUF{
	NODE p;
	int tree_size;
}NODEUF;

typedef NODEUF* NODE_PTR;

typedef struct _UNION_FIND{
	NODE_PTR* arr;
	int sz;
	int cap;
}UNION_FIND;

UNION_FIND createUF(int);
UNION_FIND makeSetUF(UNION_FIND, int, int*);
NODE_PTR findUF(UNION_FIND, int);
void unionUF(UNION_FIND, int, int);
UNION_FIND deallocateUF(UNION_FIND);

#endif
