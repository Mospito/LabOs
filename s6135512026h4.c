#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 void Sequen (int n); //Prototype
 int main(int argc, char *argv[])
 {
 int num;
 num = (int)atoi(argv[1]);  //String to Integer // String ----> Int
 printf("Test : %d\n",num);
 pid_t pid;   //First child
 pid_t pid1;  //Second child

 pid = fork();  //make Process First child

 if(pid < 0 ) {    //Check Error
 fprintf(stderr,"Fork Failed");
 exit(-1);
 }
 //Child1 Process
else if(pid == 0 ) {

  printf("Child: My pid = %d:",getpid());
  Sequen(num); //Call Function

  }
//Child2 Process
 else {

   pid1 = fork();    //make Process Second child
   if(pid1 == 0)
   {
      printf("Child: My pid = %d:",getpid());
      Sequen(num); //Call Function

   }
   //Parent Process
 else
   {
      printf("Parent: My pid = %d, My Parent pid = %d\n",getpid(),getppid());

     wait(NULL); //wait Child
     printf("Good Bye.\n");
     exit(0);
    }
 }
 }
//Sequence Function
void Sequen (int n)
{
  int i,num[n];
  //Defind num0 - num3
  num[0] = 1;
  num[1] = 1;
  num[2] = 2;
  num[3] = 2;
  //Make number of num[i>3]
  for(i=4; i<n; i++)
  {
    if( i > 3)
    {
      if( i % 3 == 0)  //if n is a multiple of 3
      {
       num[i] = num[i-1];
      }

      else  //otherwise
      {
       num[i] = (num[i-2] + num[i-2])-1;
      }
    }
  }
  //Loop Show output

  for(i=0; i<n; i++)
  {
    printf(" %d",num[i]);
  }
  printf("\n");

}

