/*
Patrick Toral
ptoral
*/

#include <errno.h>
#include "intVec.h"
#include <stdlib.h>

struct IntVecNode{
 	int * data;
 	int sz;
 	int capacity ;
} ;

typedef struct IntVecNode * IntVec;


IntVec intMakeEmptyVec(){
	//CREATING a IntVec and returning an empty one
	IntVec newVec = calloc(1, sizeof(IntVec));
    newVec->data = calloc(intInitCap, sizeof(int));
    newVec->sz = 0;
    newVec->capacity = intInitCap;

    return newVec;
}

// RETURNING A TOP SIZE 
int intTop(IntVec myVec){
    
	return myVec->data[myVec->sz - 1];

}

// RETURNING THE DATA AT i INDEX
int intData(IntVec myVec, int i){
	if( !(0<=i) || !(i < intSize(myVec)) ){
		
		exit(1);
	}
	return myVec->data[i];

}

//RETURNING SIZE OF THE myVec
int intSize(IntVec myVec){
	return myVec->sz;
}

// RETURNING THR CAPACITY
int intCapacity(IntVec myVec){
	return myVec->capacity;
}


void intVecPush(IntVec myVec, int newE){
    int newCap;
//CHECKING THE PRECONDITIONS FOR ARRAY DOUBLING
		if( myVec->sz == myVec->capacity ){
			int newCap = 2 * myVec->capacity;
			int *newData = realloc(myVec->data, newCap * sizeof(int));

			if(newData == NULL){



			} else if(newData != myVec->data){
				myVec->data = newData;


			}

			myVec->capacity = newCap;

		}
	// ADDING THE EDGE TO THE DATA ARRAY IN INTVECNODE
    myVec->data[myVec->sz] = newE;
      myVec->sz++;


}


void intVecPop(IntVec myVec){



}

