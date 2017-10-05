/*
Patrick Toral
ptoral
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>

#include "loadGraph.h"
#include "intVec.h"




void printAdjVerts(IntVec *adjlist, int n, int m, FILE* fp){

 
	  // PRINTING OF OUTPUT


      if(n>20){
      fprintf(fp,"n = %d\n", n );
      fprintf(fp,"m = %d\n", m);

      for(int i = 1; i <= n;i++){
     
      fprintf(fp,"%3d ", i );
      if(intSize(adjlist[i]) == 0){
        fprintf(fp,"          []\n" );
      } else {
      
      fprintf(fp,"          [");
      
          for(int j = 0; j < intSize(adjlist[i]); j++ ){
        
            if((j + 1) != intSize(adjlist[i]) ){
              fprintf(fp," %d, ", intData(adjlist[i],j));
            
            
          }   else {
            fprintf(fp," %d ]\n",intData(adjlist[i],j) );
          
          }
        }
      }      
    }
    //ENDING OF PRINTING OF OUTPUT

    fprintf(fp,"\n");
      } 

      printf("n = %d\n", n );
      printf("m = %d\n", m);

      for(int i = 1; i <= n;i++){
     
      printf("%3d ", i );
      if(intSize(adjlist[i]) == 0){
        printf("          []\n" );
      } else {
      
      printf("          [");
      
          for(int j = 0; j < intSize(adjlist[i]); j++ ){
        
            if((j + 1) != intSize(adjlist[i]) ){
              printf(" %d, ", intData(adjlist[i],j));
            
            
          }   else {
            printf(" %d ]\n",intData(adjlist[i],j) );
          
          }
        }
      }      
    }
    //ENDING OF PRINTING OF OUTPUT

    printf("\n");
  }



/* NOT INCLUDED IN .h BECAUSE IT ONLY IS CALLED IN loadgraph.c
* MAKING AN EMPTY MATRIX WITH (N+1)x(N+1) SIZE
*/

int** makeEmptyAdjMatrix(int n){
     int **adjmatrix = calloc(n + 1, sizeof(int*));
   for(int i = 0; i <= n; i++){

    adjmatrix[i] = calloc(n + 1,sizeof(int*));


   }
    return adjmatrix;
}

/*
* FINDING WHERE THERE IS DATA AT THE ITERATED adjlist IS NOT EMPTY
* THEN GOING THROUGH THAT adjlit's data AND INSERTED THAT INTO THE MATRIX 
  */


int** makeAdjMatrix(IntVec *adjlist, int n){
	int **adjmatrix = makeEmptyAdjMatrix(n);
	 int t = 1;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j<= n; j++){ 	
        //CHECKING FOR adjlist SIZE
     		 if(intSize(adjlist[t]) != 0){
            //INSERTING INTO MATRIX
       		 	for(int k = 0; k < intSize(adjlist[t]); k++){
    		 		adjmatrix[i][intData(adjlist[t], k)] = 1;
    		 	}
    		 }         
    	}
    	t++;
    }
printf("\n");
 return adjmatrix;
}

/*
* PRINTING THE ADJMATRIX BY PRINTING OUT THE INDEXES WITH A DOUBLE FOR LOOP
* FORMATTING IS ALSO IMPORTANT AND SOMETHING I HAVE IMPLEMENTED
*/

void printAdjMatrix(int **adjmatrix, int n){    
printf("      ");	
        for(int p = 1; p <= n; p++){
         printf("%d ", p);
        }
        printf("\n");
        printf("      ");	
        for(int p = 1; p <= n; p++){
         printf("- -");
        } 
           printf("\n");
         for (int i = 1; i <= n; i++)
         {    	
         	printf("%3d : ", i );
         	for (int j = 1; j <= n; j++)
         	{



                       

            if(j<=9){
           //DOUBLE DIGIT CHECK FOR FORMATTING
         		printf("%d ", adjmatrix[i][j]);
           } else{
            printf(" %d ", adjmatrix[i][j]);
           }





         	}
         	printf("\n");
         }

}

/*
* CREATES THE GRAPH TO BE RETURNED THAT IS THE TRANSPOSE OF THE GRAPH PASSED
* LOOKS AT THE ITERATION OF THE adjlist SUCH THAT IT IS NOT EMPTY
* IT THEN INSERTS THE REVERSED LOGIC OF THE ORIGINAL GRAPH 
* SUCH THAT THE DATA THE ORIGINAL GRAPH IS EDGED TO IS REVERSED
* AND INSERTED AT THE INDEX OF THE TRANSPOSED GRAPH
*/


IntVec* transposeGraph( IntVec *origGraph, int n){
//Creating the transposed graph that is to be returned
IntVec *transpose = calloc(n+1, sizeof(IntVec));
  for(int i = 0; i<=n; i++){ 
     transpose[i] = intMakeEmptyVec();
   }
   

	for(int i = 0; i <= n; i++){

		if(intSize(origGraph[i]) != 0){
    //SIZE CHECK
			for(int j = 0; j < intSize(origGraph[i]); j++ ){
       //PUSHING ONTO THE NEW TRANSPOSED GRAPH 
				intVecPush(transpose[intData(origGraph[i], j)], i);

			}

		}
	}
return transpose;
}









