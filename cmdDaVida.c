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
	char *param[2];
	pid_t filho;
    int status;

    chdir("/media/brunnuh/");// comeca nessa pasta no meu caso
    printf ( "brunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));// mostra a pasta atual
    //fgets(entrada,20,stdin);
    //fgets(entrada,20,stdin);
    /*param[0] = strtok(entrada, " ");
    param[1] = strtok(NULL,"\n");
        //param[2] = NULL;
        printf("parametro:%s", param[0]);
        printf("\nparametro:%s", param[1]);
        printf("\nsad");*/
    while(1){
        fgets(entrada,20,stdin);


        param[0] = strtok(entrada, " "); // recebe sempre espaco em branco ou a primeira palavra
        param[1] = strtok(NULL,"\n");// recebe sempre a segunda palavra ou NULL
        param[2] = NULL;// smp NULL;
        printf("\n0-parametro%s", param[0]);
        printf("\n1-parametro%s", param[1]);
        printf("\n2-parametro%s", param[2]);
        //comando = strtok(entrada," ");
        //parametro = strtok(NULL,"\n");
        //lixo = strtok(NULL, " ");

        //printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));



        if(strcmp(comando,"cd") == True){// erro se digitar somente cd
            if(strcmp(parametro,"..") == True){
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
        else if(strcmp(comando, "ls\n") == True){
            printf("das");
            execvp(comando, parametro);
        }

        else{
            printf("Comando Invalido");
            printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));
        }


    }


    return 0;
    }





