#include <user/user.h>

const int MAX = 35;
int main(){
    int p_send[2];
    int p_wait[2];
    if(pipe(p_send) < 0){
        fprintf(2, "pipe failed\n");
        exit(1);
    }
    if(pipe(p_wait) < 0){
        fprintf(2, "pipe failed\n");
        exit(1);
    }
    int p = 3;
    for(; p <= MAX; p++){
        write(p_send[1], &p, sizeof(int));
    }
    p=2;
    while(p < MAX){
        
        int pid = fork();
        if(pid < 0){
            fprintf(2, "fork failed\n");
            exit(1);
        }
        if(pid > 0){
            printf("prime %d\n", p);
            int i;
            read(p_send[0], &i, sizeof(int));
            while(i<MAX){
                if(i % p != 0){
                    write(p_send[1], &i, sizeof(int));
                }
                read(p_send[0], &i, sizeof(int));
            }
            write(p_send[1], &i, sizeof(int));
            write(p_wait[1], &p, sizeof(int));
            wait(0); // wait for child to finish
            exit(0);
        }else{
            read(p_wait[0], &p, sizeof(int));
            read(p_send[0], &p, sizeof(int));
        }
    }
    close(p_send[0]);
    close(p_send[1]);
    close(p_wait[0]);
    close(p_wait[1]);

    exit(0);
    return 0;
}