#include "user/user.h"

char byte,byte2 = (char)69;
int main(){
    int p[2],p2[2];
    if(pipe(p) < 0){
        fprintf(2, "pipe failed\n");
        exit(1);
    }
    if(pipe(p2) < 0){
        fprintf(2, "pipe failed\n");
        exit(1);
    }
    int pid = fork();
    if(pid < 0){
        fprintf(2, "fork failed\n");
        exit(1);
    }
    if(pid > 0){
        write(p[1], &byte, 1);
        read(p2[0], &byte2, 1);
        printf("%d recieved pong\n", pid);
        if(byte2 == byte){
            printf("ping-pong successful\n");
        } else {
            printf("ping-pong failed\n");
        }
        close(p[0]);
        close(p[1]);
        close(p2[0]);
        close(p2[1]);
        exit(0);
    }else{
        read(p[0], &byte, 1);
        printf("%d recieved ping\n",getpid());
        write(p2[1], &byte2, 1);
        exit(0);
    }
}