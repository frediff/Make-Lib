#ifndef STACK_H
#define STACK_H

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program contains the definitions of stack data structure and the associated functions
*/

#include "llist.h"

typedef struct _STACK{
	LLIST l;
}STACK;

STACK createStack();
int isEmptyStack(STACK);
STACK push(STACK, int k);
STACK pop(STACK, int *k);
STACK deallocateStack(STACK);

#endif
