#include <unistd.h>
#include <stdio.h>
#include <string.h>

//testar ./a.out "teste arg1 arg2 arg3"
//teste é o ficheiro compilado de o exe3
//Falta meter a receber mais argumentos e usar execv

int main(int argc, char** argv){
    char* pch;
    char command[10][10];
    char executavel[10];
    int i=0;

    pch = strtok (argv[1]," ");
    
    while (pch != NULL && i<10){
        //printf ("%s\n",pch)
        if (i==0) strcpy(executavel,pch);
        else {strcpy(command[i-1],pch);}
        pch = strtok (NULL, " ");
        i++;
        
    }
    
    /*
    printf ("executavel %s\n",executavel);
    printf ("comando 1 %s\n", command[0]);
    printf ("comando 2 %s\n", command[1]);
    */
    
    execl(executavel,executavel, command[0],command[1],command[2],NULL);

    return 0;
}
