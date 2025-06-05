
#include "user/user.h"

int main(int argc, char *argv[])
{
  if(argc <= 1){
    printf("you must enter arguments!\n");
  } else {
    sleep(atoi(argv[1]));
  }
  exit(0);
}


