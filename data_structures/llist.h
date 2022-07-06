#ifndef LLIST_H
#define LLIST_H

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program contains the definitions of a node in linked list and the associated functions
*/

typedef struct _NODE{
	int val;
	struct _NODE* next;
}NODE;

typedef struct _LLIST{
	NODE* front;
	NODE* end;
}LLIST;

LLIST createList();
int searchList(LLIST, int);
LLIST insertAtFront(LLIST, int);
LLIST insertAtEnd(LLIST, int);
LLIST deleteFromFront(LLIST, int*);
LLIST deleteFromEnd(LLIST, int*);
LLIST deleteList(LLIST, int);
LLIST deallocateList(LLIST);

#endif
