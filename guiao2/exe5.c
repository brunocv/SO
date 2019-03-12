#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void criaFilho(int i){
    
    int status;
    pid_t pid;
    
    if (i>=10) return;
    else {
         
        if( (pid=fork()) == 0){
            
            //codigo processo-filho
            printf("PID %d \n",getpid());
            printf("PID PAI %d \n",getppid());
            criaFilho(i+1);
        }
        else {
            wait(&status);
        }
    }
    _exit(i);
}


int main(){

    pid_t pid;
    int level=10;
    int status;

    
    if( (pid=fork()) == 0){
            
        //codigo processo-filho
        printf("PID %d \n",getpid());
        printf("PID PAI %d \n",getppid());
        criaFilho(1);
    }
    
    

    sleep(1); 
    
    //codigo processo-pai
    pid_t child = wait(&status);
        
    if(WIFEXITED(status)!=0)
        printf("Filho %d encerrou com codigo %d \n", child, WEXITSTATUS(status));

}
