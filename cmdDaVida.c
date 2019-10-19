#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define COLOR_1  "\e[0;33m"
#define COLOR_2 "\e[0;36m"
#define COLOR_RESET "\x1b[0m"

#define True 0
#define False 1

void command(char *parametro){

}


void pAtual(char pastaAtual[]){

    printf(COLOR_1);
    printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(pastaAtual, 100));
    printf(COLOR_RESET);
}

void mais(char *parametro){
  char more[] = "more ";
  strcat(more,parametro);
  system(more);

}


int main(){
  char pastaAtual[100];
	char entrada[20];
	char *parametro[2], *subparametro[1];
  char more[] = "more ";
	pid_t filho;
  int status;
  char *cmd = "ls";
  char *usuario;
  int flag = False;
  usuario = getenv("USER");
  system("clear");// limpando a tela
  int pipe_b[2];
  char buffer[20];
  int sl = pipe(pipe_b);

  if(sl < 0){
    printf("Erro na criacao do pipe\n" );
    return -1;
  }



    chdir("/home/bruno/Documentos/Trabalhos_Ufma-master");// comeca nessa pasta no meu caso
    printf(COLOR_1);
    printf ("%s@%s-PC:~%s$ ", usuario,usuario, getcwd(pastaAtual, 100) );// mostra a pasta atual
    printf(COLOR_RESET);

    while(1){
        fgets(entrada,20,stdin);

        parametro[0] = strtok(entrada, " "); // recebe sempre espaco em branco ou a primeira palavra
        parametro[1] = strtok(NULL,"\n");// \n recebe sempre a segunda palavra ou NULL

        if(parametro[1] != NULL && strcmp(parametro[1],"|") == True){
            flag = True;
            subparametro[0] = strtok(parametro[1],"| ");
            parametro[1] = strtok(NULL,"/n");
            //printf(" sb %s\npa %s\n",subparametro[0], parametro[1] );
        }else{
          subparametro[0] = NULL;
        }

                if(strcmp(parametro[0],"cd") == True){// erro se digitar somente

                    chdir(parametro[1]); // implementar condicao de erro para pastas que nao existem
                    pAtual(pastaAtual);
                }
                else if(strcmp(parametro[0],"pwd\n") == True){
                    printf ( "%s " , getcwd(pastaAtual, 100));
                    pAtual(pastaAtual);
                }
                else if((strcmp(parametro[0], "ls") == True) || (strcmp(parametro[0], "ls\n") == True)){

                    filho = fork();

                    if(filho == 0){
                        //printf("filho" );
                        system("ls");

                        close(pipe_b[0]) ;
                        //printf("subparametro:%s\n", subparametro[0]);
                        write(pipe_b[1],parametro[1],strlen(parametro[1])+1);


                    }else{

                            close(pipe_b[1]) ;
                            read(pipe_b[0], buffer, sizeof(buffer));
                            //printf("%s",buffer);
                            if(strcmp(buffer,"more")){
                              //char more[] = "more ";
                              strcat(more,buffer);
                              system(more);
                              pAtual(pastaAtual);
                            }

                        }


                }
                else if((strcmp(parametro[0],"more") == True)){
                    mais(parametro[1]);
                    pAtual(pastaAtual);
                }else if((strcmp(parametro[0],"grep"))){

                }
                else{
                    printf("Comando Invalido");
                    pAtual(pastaAtual);
                }
            }




    return 0;
    }
