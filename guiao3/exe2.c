#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    
    pid_t pid;
    int status;

    if((pid=fork())==0){
        printf("PID %d \n",getpid());
        printf("PID PAI %d \n",getppid());
        execl("/bin/ls","ls","-l",NULL);
    }
    pid_t a=wait(&status);
    if (WIFEXITED(status)) 
                printf("Filho %d encerrou com codigo %d \n", a, WEXITSTATUS(status));

    return 0;
}
