#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/wait.h> 
#include<unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>



int main(){
  srand(time(0));
  printf("Parent function %i\n", getpid());
  int pida;
  int pidb;
  int stat;
  int x=rand()%15+5;
  int y=rand()%15+5;
  if((pida=fork())==0){
    printf("Child a will now go to sleep for %i seconds, pid %i \n",x, getpid());
    sleep(x);
    printf("Child a has now finished sleeping for %i seconds, pid %i \n",x, getpid());
    return x;
  }
  else{
    if((pidb=fork())==0){
      printf("Child b will now go to sleep for %i seconds, pid %i \n",y, getpid());
      sleep(y);
      printf("Child b has now finished sleeping for %i seconds, pid %i \n",y, getpid());
      return y;
    }
    wait(&stat);
    if( WEXITSTATUS(stat)==x){
      printf("Child %i is victorious he slept for %i seconds, I am now a father of only one\n",pida, WEXITSTATUS(stat));
    }
    else{
      printf("Child %i is victorious he slept for %i seconds, I am now a father of only one\n", pidb,WEXITSTATUS(stat));

    }
    return 0;
  }
  
  return 0;
}
