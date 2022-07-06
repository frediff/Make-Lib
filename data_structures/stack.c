#include <stddef.h>
#include "stack.h"

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program implements the standard stack operations
*/

STACK createStack(){
	STACK S;
	S.l = createList();
	return S;
};

int isEmptyStack(STACK S){
	if(S.l.front == NULL) return 1;
	else return 0;
};

STACK push(STACK S, int k){
	S.l = insertAtFront(S.l, k);
	return S;
};

STACK pop(STACK S, int *k){
	S.l = deleteFromFront(S.l, k);
	return S;
};

STACK deallocateStack(STACK S){
	S.l = deallocateList(S.l);
	return S;
};