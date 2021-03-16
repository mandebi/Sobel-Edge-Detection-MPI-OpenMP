#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>

#define N 3000

int input_image [N][N];
int result_image [N][N];

struct timespec begin, end;
double time_spent;

/*   ttype: type to use for representing time */
typedef double ttype;
ttype tdiff(struct timespec a, struct timespec b)
/* Find the time difference. */
{
  ttype dt = (( b.tv_sec - a.tv_sec ) + ( b.tv_nsec - a.tv_nsec ) / 1E9);
  return dt;
}



struct timespec now()
/* Return the current time. */
{
  struct timespec t;
  clock_gettime(CLOCK_REALTIME, &t);
  return t;
}

void printArray(int A[N][N]){
	int i, j;
	
	for(i=0;i<N;i++){
      for(j=0;j<N;j++)
        printf(" %d", A[i][j]);
      printf("\n");	
	}		  
}


void load_image( ){
	
  FILE *fp;	
  int i,j, num;
  
  fp = fopen("input.txt", "r");
  
  if(fp == NULL) {
    printf("Error in opening file\n");
    exit(1);
  }
  
  i = 0;
  j = 0;  
  while( fscanf(fp, "%d", &input_image[i][j])!=EOF ) 	  
   {
      //printf(" input_image[%d][%d] = %d \n", i,j,input_image[i][j]);
	  j++;
	  if(j==N){
		  j = 0;
		  i++;
	  }
   }
   //printArray(input_image);	
  fclose(fp);	
}

void save_image( ){
	
  FILE *fp;	
  int i,j, num;
  
  fp = fopen("output.txt", "w");
  
  if(fp == NULL) {
    printf("Error in opening file\n");
    exit(1);
  }
  
  for(i=0;i<N;i++){
      for(j=0;j<N;j++)
		  if(j == 0)
		     fprintf(fp, "%d", result_image[i][j]); 
		  else
            fprintf(fp, " %d", result_image[i][j]);			  
    fprintf(fp, "\n");	
  }	  

  fclose(fp);	
}

void apply_sobel( ){
  int i,j;	
	
  for(i=0;i<N;i++)
   for(j=0;j<N;j++){
	 if(i == 0   || i == (N-1) || j==0 || j == (N-1)  )
        result_image[i][j] = 0; //we set all the edges to 0
     else
      	result_image[i][j] = abs( (input_image[i-1][j-1]-input_image[i+1][j-1]) + 2*(input_image[i-1][j]-input_image[i+1][j]) + (input_image[i-1][j+1]-input_image[i+1][j+1]) ) 
	                         +abs((input_image[i-1][j-1]-input_image[i-1][j+1]) + 2*(input_image[i][j-1]-input_image[i][j+1]) + (input_image[i+1][j-1]-input_image[i+1][j+1]) );	 
	   
   }	
   //printArray(result_image);		
}

int main()
{
  begin = now(); 	
	  load_image( );   
	  apply_sobel( );   
	  save_image( );   
  end = now(); 

  time_spent = tdiff(begin, end); 
      printf("\n  --> Total time: %.8f sec\n\n", time_spent);
       
  return 0;
}