#include <user/user.h>
#include <kernel/param.h>

int main(int argc, char* argv[]){
    int i = 0;
    static char line[512];
    char* new_argv[MAXARG+2];

    if(argc > MAXARG){
        printf("too many arguments\n");
        exit(0);
    }

    for(int j = 0; j+1 < argc; j++)new_argv[j] = argv[j+1];
    new_argv[argc] = 0;

    while(read(0,&line[i],1) > 0){
        if(line[i] != '\n'){
            i++;
            if(i >= 512){
                printf("line too long\n");
                exit(0);
            }
        }else{
            if(fork() > 0){

                memset(line,0,512);
                i=0;
                wait(0);
            }else{
                
                line[i] = '\0';
                new_argv[argc-1] = line;
                exec(new_argv[0],new_argv);
                exit(0);
            }
        }
        
    }
    exit(0);
    return 0;
}
