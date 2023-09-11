#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Control-And-View/Sistema.h"



int main() {

    int exit_menu_1 = 1; //sair do menu do usuario logado
    int exit_menu_0 = 1; //sair do menu do cadastro de usuario
    int chosen ;// escolhas do menu
    int log; // mensagens de erro ou sucesso
    int num_sistema_ids = 0 ;



    char nome_sistema[45], user_sistema[45], pass_sistema[45];


    Sistema *sistema_p = create_sistema();

    //add_sistema(sistema_p);
    //sistema_p = (Sistema *) malloc(2*sizeof(Sistema));
    //printf("Sistema tamanho %d\n", sizeof(sistema_p));

    while(exit_menu_0 != 0){
        setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada
        printf("\t \t -MENU-\n");
        printf("\t  1- Cadastrar\n");
        printf("\t  2- Logar\n");
        printf("\t  3- Excluir Usuário\n");
        printf("\t  4-Exit\n");
        scanf("%d", &chosen);

        switch (chosen) {
            case 1: // cadatrar usuário
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada
                printf("Digite o nome Funcionário\n");
                fgets(nome_sistema, sizeof(nome_sistema), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada


                printf("Digite o User \n");
                fgets(user_sistema, sizeof(user_sistema), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada


                printf("Digite a senha\n");
                fgets(pass_sistema, sizeof(pass_sistema), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada



                num_sistema_ids = add_sistema(num_sistema_ids,nome_sistema,user_sistema,pass_sistema,num_sistema_ids,sistema_p);
                break;
            case 2: //logar, isso entrá em outro menu já logado

                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada
                printf("Digite o User \n");
                fgets(user_sistema, sizeof(user_sistema), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada


                printf("Digite a senha\n");
                fgets(pass_sistema, sizeof(pass_sistema), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada
                // filtrar se tem cadastro ou não e verificar se está ativo ou não

                for (int i = 0; i <= num_sistema_ids; ++i) {
                    if(strcmp(sistema_p[i].USER, user_sistema)==0){

                        if(strcmp(sistema_p[i].PASS, pass_sistema)==0){
                            if(sistema_p[i].ACTIVATED == 1){
                                while(exit_menu_1 != 0){

                                    printf("\t \t -MENU-\n");
                                    printf("\t  9-Config\n");
                                    printf("\t  10-Exit\n");
                                    scanf("%d", &chosen);

                                    switch (chosen) {
                                        case 9: // escolha de config
                                            printf("\t \t -MENU-\n");
                                            printf("\t  1-TXT\n");
                                            printf("\t  2-BIN\n");
                                            scanf("%d", &chosen);
                                            switch (chosen) {
                                                case 1:
                                                    //chamar função de salvar em txt
                                                    break;
                                                case 2:
                                                    //chamar função de salvar em bin
                                                    break;
                                                default:
                                                    // por padrão salva em bin
                                                    break;
                                            }
                                            break;
                                        case 10:
                                            printf("Exit Success\n");
                                            exit_menu_1 = 0;
                                            break;

                                    }

                                }
                            }else{
                                printf("Usuário Excliodo\n");
                                break;
                            }


                        }else{
                            printf("Senha incorreta\n");
                            break;
                        }
                    }

                }







                break;

            case 3://Excluir
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada
                printf("Digite o User \n");
                fgets(user_sistema, sizeof(user_sistema), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada


                printf("Digite a senha\n");
                fgets(pass_sistema, sizeof(pass_sistema), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada

                log=delete_sistema(user_sistema,pass_sistema,num_sistema_ids,sistema_p);
                if(log== 1){
                    printf("Ecluido com sucesso");

                } else if(log == -1){
                    printf("Senha incorreta");
                }else if(log == -404){
                    printf("User não encontrado");
                }
                break;

            case 4://exit
                printf("Exit Success\n");
                exit_menu_0 = 0 ;
                break;

        }

    }

printf("----------------------------------nome_sistema (%s)---------------------------------------------------------",sistema_p[0].NAME);





    return 0;
}
