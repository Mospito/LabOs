#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void Sequen (int n); 
 int main(int argc, char *argv[])
 {
 // One Child
 int temp = 10,num;
  num = (int)atoi(argv[1]); 
 pid_t pid;
 /* fork a child process */
 pid = fork(); // return 0 to the child process
 // whereas the nonzero process id of
 // the child is returned to the parent

 if(pid < 0) { /* error occurred */
 fprintf(stderr,"Fork Failed");
 exit(-1);
 }
 else if(pid == 0) { /* child process */

	printf("Child: My pid = %d:",getpid());
	Sequen(num);

 }
 else { /* parent process*/
 printf("Parent: My pid = %d, My Parent pid = %d\n",getpid(),getppid());
 /* parent will wait for the child to complete */
 wait(NULL);
 printf("Good Bye.\n");
 exit(0);
 }
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

