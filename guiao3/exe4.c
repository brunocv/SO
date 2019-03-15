#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){


    execv("teste", argv);
    
    return 0;
}
