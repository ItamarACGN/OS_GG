#include "user/user.h"


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
        char byte = (char)69;
        write(p[1], &byte, 1);
        char byte_received;
        read(p2[0], &byte_received, 1);
        printf("%d: received pong\n",getpid());
        //printf("byte received: %d \n" , byte_received);
        close(p[0]);
        close(p[1]);
        close(p2[0]);
        close(p2[1]);
        exit(0);
    }else{
        char byte_recieved;
        char byte = (char)69;
        read(p[0], &byte_recieved, 1);
        printf("%d: received ping\n",getpid());
        write(p2[1], &byte, 1);
        //printf("byte recieved: %d \n" , byte_recieved);
        exit(0);
    }
}