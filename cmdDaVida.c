#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define True 0
#define Falso 1

void command(char *parametro){

}







int main(){
    char s[100];
	char entrada[20];
	char *comando, *parametro, *lixo;
	pid_t filho;
    int status;

    chdir("/media/brunnuh/");// comeca nessa pasta no meu caso
    printf ( "brunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));// mostra a pasta atual


    while(1){
        fgets(entrada,20,stdin);

        //tiraespa(entrada, comando, parametro, lixo);

        comando = strtok(entrada," ");
        parametro = strtok(NULL,"\n");
        lixo = strtok(NULL, " ");

        //printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));

        if(strcmp(comando,"cd") == True){
            if(strcmp(parametro,"..") == True){// nao esta entrando, comparacao esta errada
                chdir("..");
                printf ( "brunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));
            }else{
                chdir(parametro);
                printf ( "brunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));
            }
        }
        else if(strcmp(comando,"pwd\n") == True){
            printf ( "%s " , getcwd(s, 100));
            printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));
        }
        else{
            printf("Comando Invalido");
            printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));
        }


    }


    return 0;
    }





