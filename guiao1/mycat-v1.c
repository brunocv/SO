#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv){

    int n;
    char c;

    while ((n=read(0,&c,1))>0){
        write(1,&c,n);
    }

    return 0;
}
