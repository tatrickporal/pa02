/*
Patrick Toral
ptoral
*/

#ifndef C101IntVec
#define C101IntVec



typedef struct IntVecNode * IntVec;


/*
* PRINTING THE INPUTTED adjmatrix
* precondition: adjlist has to be created, n > 0, m > 0
*/

void printAdjVerts(IntVec *adjlist, int n, int m, FILE* fp);

/*
* PRINTING THE INPUTTED adjmatrix
* precondition: adjmatrix has to be created, n > 0
*/

void printAdjMatrix(int **adjmatrix, int n);

/*
* MAKING AN adjmatrix OUT OF THE INPUTTED adjlist
* precondition: adjlist has to be created, n > 0
* postcondition: adjmatrix is created 
*/

int** makeAdjMatrix(IntVec *adjlist, int n);

/*
* MAKING A TRANSPOSED VERSION OF THE origGrahp
* preconditions: origGraph has to be created, n > 0
* postcondition: the transposed version of origGraph is created 
*/

IntVec* transposeGraph(IntVec *origGraph, int n);

#endif