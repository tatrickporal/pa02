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

//Edge structs to and from with a weight
typedef struct{
     int from;
     int to;
     double weight;
} Edge;

/*
This function is called after the first line has been processed
It will return an edge where the to and from int's defined in the struct 
are used in the parameters for intVedPush 
*/
Edge parseEdge(char * line, int lineSize, int linenumber,IntVec *adjlist, int n, int flag){
    int digit;
    Edge newEdge;
    int from;
    int to;
    double weight;
    char garbage;
    


    int items = sscanf(line, "%d %d %lf %c", &from, &to, &weight, &garbage);
     newEdge.from = from;
     newEdge.to = to;
     newEdge.weight = weight;
     //if Items are only equal to two overwrite the ones given above
    if(digit == 2){
     newEdge.from = from;
     newEdge.to = to;
     newEdge.weight = 0.0;       
    }

    //error checking of more than 3 elements
    if( (items <= 1) || (items > 3) ){

      fprintf(stderr,"--------- \n");
     fprintf(stderr, "BAD LINE: %d  \n",linenumber ); 
     fprintf(stderr,"--------- \n");
     exit(EXIT_FAILURE);
  } 

  //NExt two if statements check if the inputted number is greater than n
  if(from > n ){
fprintf(stderr,"--------- \n");
    fprintf(stderr,"BAD LINE: %d  \n", linenumber);
   fprintf(stderr,"%d is > %d\n", from, n); 
   fprintf(stderr,"BAD LINE: %d  \n", linenumber);
   fprintf(stderr,"--------- \n");
      exit(EXIT_FAILURE);


  }

   //Pushing the edges to the adjlist 
   intVecPush(adjlist[newEdge.from], newEdge.to);
   //If the -U is called
   if(flag == 1){
   intVecPush(adjlist[newEdge.to], newEdge.from);
   }


     return newEdge;
}





int main(int argc, char *argv[])
{
  int flag = 0;
  char *file = argv[1];
   FILE* fp = fopen( "out_file.txt", "w" );


	//The amount of Command line args must be 2 (1:Program name, 2:Input file)
	if((argc != 2) && (argc != 3)){
		fprintf(stderr,"--------- \n");
     fprintf(stderr, "%s\n","NEED AT LEAST TWO COMMAND LINE ARGUMENTS AND AT MOST 3" );
     fprintf(stderr,"--------- \n"); 
     exit(EXIT_FAILURE);

	}
	//Open the file that is defined by the second command line argument

//Checking for the flag and setting input file to the third argument if it is true
     if(strncmp(argv[1],"-U",3 ) == 0){
       printf("FLAG\n");
       flag = 1;
       file = argv[2];
     }


  FILE *input = fopen(file,"r");
	
	if(input == 0){
      //File could not be found
  fprintf(stderr,"--------- \n");
      fprintf(stderr, "%s '%s' %s\n", "File:", argv[1], "not found" ); 
      fprintf(stderr,"--------- \n");
      exit(EXIT_FAILURE);

      
	} else {
		//File found
    if(flag == 0){


	  printf("%s '%s' %s\n", "Opened", argv[1], "for input :)");
   } else {
    printf("%s '%s' %s\n", "Opened", argv[2], "for input :)");
   }
	}


   char line[1000];
   char first[1000];
   int digit = 0;
   int linenum = 1;
   int n = 0;
   int m = 0;
  

   fgets(first, sizeof(first), input);
   char garbage;
   int check = sscanf(first, "%d %c", &n, &garbage);


   //Checking if the first item has a digit in it 
   if(check != 1){
   fprintf(stderr,"--------- \n");
     fprintf(stderr, "TOO MANY NUMBERS ON LINE: 1 => %s \n", first  );
     fprintf(stderr,"--------- \n");
    exit(EXIT_FAILURE);
   }




//MAKING THE ADJECENCY LIST TO CONNECT TO EDGES WITH LENGTH n
   IntVec *adjlist = calloc(n+1, sizeof(IntVec));;
   for(int i = 0; i<=n; i++){
  
     adjlist[i] = intMakeEmptyVec();

   }

  //STARTING AT THE SECOND LINE
    while (fgets(line, sizeof(line), input)) { 
   linenum++;
        if(linenum > 1){

         //INCREASE THE CONNECTION EDGES m AND caling the functions 
         Edge this = parseEdge(line, strlen(line), linenum, adjlist, n, flag);
         if(flag == 0){
          m++;
         } else {

          //if undirected graph
          m+=2;
         }
         
       }
    
    
    digit = 0;
   } 
  if(n>20){
  fprintf(fp,"\n");
  fprintf(fp,"Graph of input:\n");
  fprintf(fp,"\n");
  }
  printf("\n");
  printf("Graph of input:\n");
  printf("\n");
  //printing original 
printAdjVerts(adjlist,  n,  m, fp);



printf("\n");



//making original adjmatrix
int **adjmatrix= makeAdjMatrix(adjlist,  n);

if(n<=20){
printf("Matrix of input:\n");
printf("\n");
//printing the oringinal adjmatrix
printAdjMatrix(adjmatrix, n);
printf("\n");
} else {
  printf("Too many numbers to make a matrix\n");
}




printf("\n");

  

//creating the transpose graph out of the original
IntVec *transpose = transposeGraph(adjlist,n);
//Making the matrix off the transposed matrix
int **transposematrix = (int)makeAdjMatrix(transpose,n);
  if(n>20){
  fprintf(fp,"\n");
  fprintf(fp,"Transpose graph of input: \n");
  fprintf(fp,"\n");
  }
printf("\n");
printf("Transpose graph of input: \n");
printf("\n");
// printing the transpose graph
printAdjVerts(transpose, n, m, fp);


if(n<=20){
printf("Transposed Matrix of Input:\n");
printf("\n");
//printinf the tranposed matrix 
printAdjMatrix(transposematrix, n);

printf("\n");
}




IntVec *twiceTranspose = transposeGraph(transpose,n);
// creating the twice transposed matrix
int **twiceTransposematrix = (int)makeAdjMatrix(twiceTranspose,n);
  if(n>20){
  fprintf(fp,"\n");
  fprintf(fp,"Twice-Transposed Graph: \n");
  fprintf(fp,"\n");
  }
printf("\n");
printf("Twice-Transposed Graph: \n");
printf("\n");
//printing the twice transposed graph (ORIGINAL)
printAdjVerts(twiceTranspose, n, m, fp);


if(n<=20){
printf("Twice-Transposed Matrix:\n");
printf("\n");
//printing the twice transposed matrix (ORIGINAL)
printAdjMatrix(twiceTransposematrix, n);
printf("\n");
}

}








