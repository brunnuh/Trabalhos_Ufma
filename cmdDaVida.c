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
#define Falso 1

void command(char *parametro){

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
  usuario = getenv("USER");
  system("clear");// limpando a tela
  int pipe_b[2];
  if(pipe(pipe_b) < 0){
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
        parametro[1] = strtok(NULL,"\n");// recebe sempre a segunda palavra ou NULL
        if(strcmp(parametro[1],"|")){
          subparametro[0] = strtok(parametro[1],"| ");
          parametro[1] = strtok(NULL,"/n");
          printf(" sb %s\npa %s\n",subparametro[0], parametro[1] );
        }

                if(strcmp(parametro[0],"cd") == True){// erro se digitar somente
                    chdir(parametro[1]); // implementar condicao de erro para pastas que nao existem
                    printf(COLOR_1);
                    printf ( "brunnuh@brunnuh-linux:~%s$ " , getcwd(pastaAtual, 100));
                    printf(COLOR_RESET);
                }
                else if(strcmp(parametro[0],"pwd\n") == True){
                    printf ( "%s " , getcwd(pastaAtual, 100));
                    printf(COLOR_1);
                    printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(pastaAtual, 100));
                    printf(COLOR_RESET);
                }
                else if((strcmp(parametro[0], "ls\n") == True)){
                    system("ls");
                    printf(COLOR_1);
                    printf ( "brunnuh@brunnuh-linux:~%s$ " , getcwd(pastaAtual, 100));
                    printf(COLOR_RESET);
                }
                else if((strcmp(parametro[0],"more") == True)){
                    strcat(more,parametro[1]);
                    system(more);
                    printf("Comando Invalido");
                    printf(COLOR_1);
                    printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(pastaAtual, 100));
                    printf(COLOR_RESET);
                }else if((strcmp(parametro[0],"grep"))){

                }
                else{
                    printf("Comando Invalido");
                    printf(COLOR_1);
                    printf ( "\nbrunnuh@brunnuh-linux:~%s$ " , getcwd(pastaAtual, 100));
                    printf(COLOR_RESET);
                }
            }




    return 0;
    }
