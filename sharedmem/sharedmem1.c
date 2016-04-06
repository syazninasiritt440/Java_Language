#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHSIZE 100

int main(int argc, char *argv[])
{
  int id;
  key_t key;
  char *shm;
  char *s;

  key=123;

  id=shmget(key, SHSIZE, IPC_CREAT | 0666);
  if (id < 0 )
     {
     perror("shmget");
     exit(1);
    }

 shm = shmat(id, NULL, 0);
 if(shm == (char *) -1)
   {
   perror("shmat");
   exit(1);
   }

 memcpy(shm, "Hello Syazni",12);
 s=shm;
 s+=12;

 *s=0;

 while(*shm !='*')
   sleep(1);

  return 0;
}
