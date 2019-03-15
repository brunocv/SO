#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char** argv){
    
    for(int i=0; i<argc-1; i++) printf("Comando: %s\n", argv[i+1]);

    return 0;
}
