#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv){

    int n=atoi(argv[1]);
    char *c=malloc(n);
    int z;
    
    while ((z=read(0,c,n))>0){
        write(1,c,z);
    }

    return 0;
}
