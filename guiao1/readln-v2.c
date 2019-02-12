#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

ssize_t readln(int fildes, void *buf, size_t nbyte){
    int i;
    for(i = 0; (read(fildes,(char*) buf +i, 1)>0) && (*((char *)buf+i) !='\n');i++);
    return i;
}

int main(int argc, char** argv){
    
    char c[256];
    int z;
    int i=0;
    
    z=readln(0,c,1);

    while(i<z){
        write(1,(c+i),1);
        i++;
    }
    printf("\n");

    return 0;
}
