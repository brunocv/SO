#include <unistd.h>
#include <stdio.h>

int main(){


    execl("/bin/ls","ls","-l",NULL);
    
    return 0;
}
