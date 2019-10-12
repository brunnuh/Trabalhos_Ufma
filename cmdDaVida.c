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
	//char *comando, *parametro, *lixo;
	char *parametro[2];
	pid_t filho;
    int status;
    char *cmd = "ls";
    /*char *argv[3];
    argv[0] = "ls";
    argv[1] = "-l";
    argv[2] = NULL;

    execvp(cmd, argv); //This will run "ls -la" as if it were a command
*/

    //parametro[2] = NULL;
    //printf("%i", parametro[2] == NULL);
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


        parametro[0] = strtok(entrada, " "); // recebe sempre espaco em branco ou a primeira palavra
        parametro[1] = strtok(NULL,"\n");// recebe sempre a segunda palavra ou NULL
        //param[2] = NULL;// smp NULL;
        //printf("\n0-parametro%s", parametro[0]);
        //printf("\n1-parametro%s", parametro[1]);
        //printf("\n2-parametro%s", param[2]);
        //comando = strtok(entrada," ");
        //parametro = strtok(NULL,"\n");
        //lixo = strtok(NULL, " ");

        //printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));


        filho = fork();
            if(filho == True){
                if(strcmp(parametro[0],"cd") == True){// erro se digitar somente
                    chdir(parametro[1]); // implementar condicao de erro para pastas que nao existem
                    printf ( "brunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));
                }
                else if(strcmp(parametro[0],"pwd\n") == True){
                    printf ( "%s " , getcwd(s, 100));
                    printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));

                }
                else if((strcmp(parametro[0], "ls\n") == True) && (parametro[1] ==  NULL)){
                    //printf("\n0-parametro%s", parametro[0]);
                    //printf("\n1-parametro%s", parametro[1]);
                    //printf("%i",execvp(arquivo,parametro[0]));
                    system("ls");
                    printf ( "brunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));
                }
                else{
                    printf("Comando Invalido");
                    printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(s, 100));
                }
            }
            else{

                while (1);{// esperar filho terminar
                    if(wait(&status) != filho){
                        break;
                    }
                }

            }
    }


    return 0;
    }





