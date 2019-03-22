#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

//int dup(int fd)
//int dup2(int fd1, int fd2);

int main(){

    int std_i = open ("entrada.txt", O_RDONLY);
    int std_o = open ("saida.txt", O_CREAT | O_WRONLY, 0666);
    int std_e = open ("erros.txt", O_CREAT | O_WRONLY, 0666);
    int res=0;
    char buffer;
    
    res = dup2(std_i,0);
    res = dup2(std_o,1);
    res = dup2(std_e,2);

    close(std_i);
    close(std_o);
    close(std_e);
    
    if(!fork()){
        execl("/bin/ls","ls",NULL);
        _exit(0);
    }
    else{
        int status;
        wait(&status);
        while(read(0,&buffer,1)!=0) write(1,&buffer,1);
    }
    return 0;

}
