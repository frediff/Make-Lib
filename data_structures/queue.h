#ifndef QUEUE_H
#define QUEUE_H

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program contains the definitions of queue data structure and the associated functions
*/

#include "llist.h"

typedef struct _QUEUE{
	LLIST l;
}QUEUE;

QUEUE createQueue();
int isEmptyQueue(QUEUE);
QUEUE enqueue(QUEUE, int);
QUEUE dequeue(QUEUE, int*);
QUEUE deallocateQueue(QUEUE);

#endif
