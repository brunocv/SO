#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){

    pid_t pid;

    if((pid==fork()) == 0){

        //codigo processo-filho
        printf("PID %d \n",getpid());
        printf("PID PAI %d \n",getppid());
        _exit(0);
    }
}
