#include <stddef.h>
#include "queue.h"

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program implements the standard queue operations
*/

QUEUE createQueue(){
	QUEUE Q;
	Q.l = createList();
	return Q;
};

int isEmptyQueue(QUEUE Q){
	if(Q.l.front == NULL) return 1;
	else return 0;
};

QUEUE enqueue(QUEUE Q, int k){
	Q.l = insertAtEnd(Q.l, k);
	return Q;
};

QUEUE dequeue(QUEUE Q, int* k){
	Q.l = deleteFromFront(Q.l, k);
	return Q;
};

QUEUE deallocateQueue(QUEUE Q){
	Q.l = deallocateList(Q.l);
	return Q;
};