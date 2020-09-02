#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

 int main(int argc, char *argv[])
 {
 int temp = 10;
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
 // sleep(5);
 printf("Child: My pid = %d: \n",getpid());
 sleep(2);
 }
 else { /* parent process*/
 sleep(5);
 printf("Process: My pid = %d, My Parent pid = %d\n",getpid(),getppid);
 /* parent will wait for the child to complete */
 wait(NULL);
 printf("Good Bye.\n");
 exit(0);
 }
 }
