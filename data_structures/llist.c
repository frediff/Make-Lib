#include <stdlib.h>
#include "llist.h"

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program implements the functions associated with a singly linked list
*/

LLIST createList(){
	LLIST newLIST = {NULL,NULL};
	return newLIST;
};

int searchList(LLIST H, int k){
	if(H.front == NULL) return 0;
	else{
		NODE* iterator = H.front;
		while(1){
			if(iterator->val == k) return 1;
			else {
				if(iterator == H.end) break;
				else iterator = iterator->next;
			}
		}
		return 0;
	}
};

LLIST insertAtFront(LLIST H, int k) {
	if(H.front == NULL){
		H.front = (NODE*) malloc(sizeof(NODE));
		H.front->val = k;
		H.front->next = NULL;
		H.end = H.front;
	}
	else{
		NODE* temp = (NODE*) malloc(sizeof(NODE));
		temp->val = k;
		temp->next = H.front;
		H.front = temp;
	}
	return H;
};

LLIST insertAtEnd(LLIST H, int k){
	if(H.end == NULL){
		H.end = (NODE*) malloc(sizeof(NODE));
		H.end->val = k;
		H.end->next = NULL;
		H.front = H.end;
	}
	else{
		NODE* temp = (NODE*) malloc(sizeof(NODE));
		temp->val = k;
		temp->next = NULL;
		H.end->next = temp;
		H.end = temp;
	}
	return H;
};

LLIST deleteFromFront(LLIST H, int* k){
	if(H.front == NULL){
		return H;
	}
	else{
		NODE* temp = H.front;
		*k = temp->val;
		if(H.front == H.end){
			H.front = NULL;
			H.end = NULL;
		}
		else H.front = temp->next;
		free(temp);
		return H;
	}
};

LLIST deleteFromEnd(LLIST H, int* k){
	if(H.end == NULL){
		return H;
	}
	else{
		NODE* second_last = NULL;
		NODE* iterator = H.front;
		while(iterator != H.end) {
			second_last = iterator;
			iterator = iterator->next;
		}
		*k = iterator->val;
		free(iterator);
		if(second_last == NULL) {
			H.front = NULL;
			H.end = NULL;
			return H;
		}
		else{
			second_last->next = NULL;
			H.end = second_last;
			return H;
		}
	}
};

LLIST deleteList(LLIST H, int k){
	if(H.front == NULL) return H;
	else{
		NODE* iterator = H.front;
		NODE* previous = NULL;
		while(1){
			if(iterator->val == k){
				if(previous == NULL){
					free(iterator);
					H.front = NULL;
					H.end = NULL;
					return H;
				}
				else{
					previous->next = iterator->next;
					free(iterator);
					return H;
				}
			}
			else {
				if(iterator == H.end) break;
				else{
					previous = iterator;
					iterator = iterator->next;
				}
			}
		}
		return H;
	}
};

LLIST deallocateList(LLIST H){
	if(H.front == NULL){
		H.front = NULL;
		H.end = NULL;
		return H;
	}
	NODE* iterator = H.front;
	NODE* temp = iterator;
	while(iterator!=NULL){
		temp = iterator;
		iterator = iterator->next;
		free(temp);
	}
	H.front = NULL;
	H.end = NULL;
	return H;
};
