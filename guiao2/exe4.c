#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){

    pid_t pid;
    int level=10;
    int status;

    for(int i=1; i<= level ; i++){

        if((pid=fork()) == 0){

            //codigo processo-filho
            printf("PID %d \n",getpid());
            printf("PID PAI %d \n",getppid());
            _exit(i);
        }
    }
    sleep(1); 
    for(int i=1; i<= level ;i++ ){
        //codigo processo-pai
        pid_t child = wait(&status);
        
        if(WIFEXITED(status)!=0){
            printf("Filho %d encerrou com codigo %d \n", child, WEXITSTATUS(status));
        }
    }
}
