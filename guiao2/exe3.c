#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){

    pid_t pid;
    int status;
    int level=10;

    for(int i=1; i<= level ; i++){

        if((pid==fork()) == 0){

            //codigo processo-filho
            printf("PID %d \n",getpid());
            printf("PID PAI %d \n",getppid());
            _exit(i);
        }
        else {
            //codigo processo-pai
            pid_t child = wait(&status);
            printf("Filho %d encerrou com codigo %d \n", child, WEXITSTATUS(status));
        }
    }
}
