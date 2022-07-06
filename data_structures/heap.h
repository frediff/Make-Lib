#ifndef HEAP_H
#define HEAP_H

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program constains the definitions of heap data structure and associated functions
*/

typedef struct _HEAP{
	int* arr;
	int sz;
}HEAP;

HEAP createHeap();
int findMin(HEAP);
HEAP extractMin (HEAP);
HEAP insertHeap(HEAP, int);
int isFullHeap(HEAP);
int isEmptyHeap(HEAP);
HEAP deallocateHeap(HEAP);

#endif
