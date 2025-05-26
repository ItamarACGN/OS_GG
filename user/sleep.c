/*#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    write(1,"you must enter arguments!\n",strlen("you must enter arguments!\n"));
  } else {
    sleep(atoi(argv[1]));
  }
  exit(0);
}*/
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;

  for(i = 1; i < argc; i++){
    write(1, argv[i], strlen(argv[i]));
    if(i + 1 < argc){
      write(1, " ", 1);
    } else {
      write(1, "\n", 1);
    }
  }
  exit(0);
}

