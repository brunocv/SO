#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv){
    int i=0;
    char c='a';
    
    int file = open(argv[1], O_CREAT | O_TRUNC |O_RDONLY |O_WRONLY , S_IRUSR | S_IRGRP | S_IROTH);

    while (i<100000){
        write(file,&c,1);
        i++;
    }
    
    close(file);

    return 0;
}

