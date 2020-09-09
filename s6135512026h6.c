#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
//Runner For Sequence
void *runner (void *param)
{
	int n = (int)atoi(param);
	int i,num[n];
	  //Defind num0 - num3
	  num[0] = 1;
	  num[1] = 1;
	  num[2] = 2;
	  num[3] = 2;
	  //Make number of num[i>3]
	  for(i=4; i<n; i++)
	  { //6135512026
	    
	      if( i % 3 == 0)  //if n is a multiple of 3
	      {
	       num[i] = num[i-1];
	      }
	
	      else  //otherwise
	      {
	       num[i] = (num[i-2] + num[i-2])-1;
	      }
	  }
	  //Loop Show output
	
	  printf("Hi: ");
	  for(i=0; i<n; i++)
	  {//6135512026
	    printf(" %d",num[i]);
	  }
	  printf("\n");
	
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	int i;
	//Create Thread 1
	pthread_t tid1;
	pthread_attr_t attr1;
	
	//Create Thread 2
	pthread_t tid2;
	pthread_attr_t attr2;
	
	//Check Err
	if(argc != 2)
	{
		fprintf(stderr, "usage: a.out <integer value>\n");
		return -1;
	}
	
	//Thread 1
	printf("Hi this is the main thread\n");
	pthread_attr_init(&attr1);
	pthread_create(&tid1,&attr1,runner,argv[1]);
	pthread_join(tid1,NULL);
	
	//Thread 2
	pthread_attr_init(&attr2);
	pthread_create(&tid2,&attr2,runner,argv[1]);
	pthread_join(tid2,NULL);
	printf("good bye^^ EiEi\n");
	
}



