#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    
    int n;
    char c;
    
    while((n=read(0,&c,1))>0){
        if (c==EOF || c=='\n') break;
        write(1,&c,n);
    }
    printf("\n");

    return 0;
}
