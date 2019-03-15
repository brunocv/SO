#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char** argv){

    pid_t pid;
    int status;

    for(int i=0; i< argc-1 ; i++){

        if((pid=fork()) == 0){

            //codigo processo-filho
            printf("PID %d \n",getpid());
            printf("PID PAI %d \n",getppid());
            execl(argv[i+1],"teste","ls","pwd","ps",NULL);
        }
    }

    sleep(1); 
    for(int i=0; i< argc -1 ;i++ ){
        //codigo processo-pai
        pid_t child = wait(&status);
        
        if(WIFEXITED(status)!=0){
            printf("Filho %d encerrou com codigo %d \n", child, WEXITSTATUS(status));
        }
    }
}
