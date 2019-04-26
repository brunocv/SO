#include<unistd.h>
#include <sys/wait.h>
#include <stdio.h>


//int pipe(pd[2]);RETURNS: 0 on success -1 on error

int main (int agc,char** argv){

    int p[2];
    char line[] = "linha1\n";
    char buffer[20];
    int res;
    int status;

    if(pipe(p) == -1){
        perror("pipe error");
        return -1;
    }
    
    switch(fork()){
        case -1:
                perror("fork");
                return -1;
        case 0:
                //filho
                //fechar descritor de escrita no filho porque não o vai usar

                close(p[1]);
                // aqui o res é importante para saber quanto lemos realmente..
                res = read(p[0], &buffer,sizeof(buffer));
                printf("Filho:  %s,,,,,, O CARLOS É UM PANELEIRO from pipe \n", buffer);
                close(p[0]);
                _exit(0);
        default:
                //pai
                //fechar de descritor de leitura no pai
                close(p[0]);
                write(p[1], &line, sizeof(line));
                close(p[1]);
                wait(&status);
    }
    return 0;
}
