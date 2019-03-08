#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){

    pid_t pid;
    int status;

    if((pid==fork()) == 0){

        //codigo processo-filho
        printf("PID %d \n",getpid());
        printf("PID PAI %d \n",getppid());
        _exit(0);
    }
    else {
        //codigo processo-pai
        printf("PID %d \n",getpid());
        printf("PID PAI %d \n",getppid());

        pid_t child = wait(&status);
        printf("Filho %d encerrou com codigo %d \n", child, WEXITSTATUS(status));
    }
}
