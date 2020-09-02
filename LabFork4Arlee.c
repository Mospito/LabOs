#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 void Sequen (int n); 
 int main(int argc, char *argv[])
 {
 int num,x,i;
 num = (int)atoi(argv[1]);  
 x = (2%5)+1; //3 Child
 printf("My X is %d",x); 
	
 pid_t pid;   

   printf("Parent: My pid = %d, My Parent pid = %d\n",getpid(),getppid());
   
   
   for(i=0; i<x; i++)
   {
   		pid = fork();
   	   if(pid == 0 ) 
		{
		  	 
		  	printf("Child: My pid = %d:",getpid());
		   Sequen(num);
		   	exit(0);
  		}
		else
	   {
	   	 wait(NULL); 

	   }
   }
  	printf("Good Bye.\n");


 }

void Sequen (int n)
{
  int i,num[n];
  
  num[0] = 1;
  num[1] = 1;
  num[2] = 2;
  num[3] = 2;
  
  for(i=4; i<n; i++)
  {
    if( i > 3)
    {
      if( i % 3 == 0)  
      {
       num[i] = num[i-1];
      }

      else  
      {
       num[i] = (num[i-2] + num[i-2])-1;
      }
    }
  }


  for(i=0; i<n; i++)
  {
    printf(" %d",num[i]);
  }
  printf("\n");

}

