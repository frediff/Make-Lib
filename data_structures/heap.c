#include <stdlib.h>
#include <limits.h>
#include "heap.h"

/*
Code written by SUBHAM GHOSH
ROLL NO. : 20CS10065
2ND YEAR UG, CSE DEPT. IIT KGP
*/

/*
This program implements the standard heap operations
*/

HEAP createHeap(){
	HEAP H = {NULL,0};
	H.arr = (int*) malloc(sizeof(int)*100);
	return H;
};

int findMin(HEAP H){
	if(H.sz == 0) return INT_MIN;
	else return H.arr[0];
};

HEAP extractMin (HEAP H){
	if(H.sz == 0) return H;
	int temp = H.arr[H.sz];
	H.arr[H.sz] = H.arr[0];
	H.arr[0] = temp;
	--H.sz;
	int idx = 0;
	while((2*idx+1) < H.sz){
		if(H.arr[idx] > H.arr[2*idx+1]){
			if(((2*idx+2) < H.sz) && (H.arr[2*idx+2] < H.arr[2*idx+1])){
				temp = H.arr[idx];
				H.arr[idx] = H.arr[2*idx+2];
				H.arr[2*idx+2] = temp;
				idx = 2*idx+2;
			}
			else{
				temp = H.arr[idx];
				H.arr[idx] = H.arr[2*idx+1];
				H.arr[2*idx+1] = temp;
				idx = 2*idx+1;
			}
		}
		else if(((2*idx+2) < H.sz) && (H.arr[2*idx+2] < H.arr[idx])){
			temp = H.arr[idx];
			H.arr[idx] = H.arr[2*idx+2];
			H.arr[2*idx+2] = temp;
			idx = 2*idx+2;
		}
		else return H;
	}
	return H;
};

HEAP insertHeap(HEAP H, int k){
	if(H.sz == 100) return H;
	H.arr[H.sz] = k;
	int temp;
	int idx = H.sz;
	++H.sz;
	while(idx){
		if(H.arr[idx] < H.arr[(idx-1)/2]){
			temp = H.arr[idx];
			H.arr[idx] = H.arr[(idx-1)/2];
			H.arr[(idx-1)/2] = temp;
			idx = (idx-1)/2;
		}
		else{
			return H;
		}
	}
	return H;
};

int isFullHeap(HEAP H){
	if(H.sz == 100) return 1;
	else return 0;
};

int isEmptyHeap(HEAP H){
	if(H.sz == 0) return 1;
	else return 0;
};

HEAP deallocateHeap(HEAP H){
	if(H.arr == NULL){
		H.arr = NULL;
		H.sz = 100;
		return H;
	}
	free(H.arr);
	H.arr = NULL;
	H.sz = 100;
	return H;
};
