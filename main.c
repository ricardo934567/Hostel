#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Control-And-View/Sistema.h"
#include "Model/Arquivo.h"

void remover_linha(char *str){
    size_t tamanho = strlen(str);
    if(tamanho > 0 && str[tamanho - 1] =='\n'){
        str[tamanho - 1]= '\0';
    }
}
const char *sistema_arquivo_bin = "Sistema.bin";
//const char *sistema_arquivo_txt = "Sistema.txt";

int sistema_recuperar_id(const char *_sistema_arquivo){
    FILE *file1 = fopen(_sistema_arquivo, "rb");
    int cont=0;
    if(file1 ==NULL){
        printf("ERRO AO ABRIR O ARQ");
        return -1;
    }
    Sistema sistema_temp;
    while(fread(&sistema_temp, sizeof (Sistema),1,file1) == 1){
        cont++;
    }
    fclose(file1);
    return cont;
}

int sistema_recuperar_dados(const char *_sistema_arquivo,Sistema *_sistema_recuperar,int n){
    _sistema_recuperar = realloc(_sistema_arquivo,n*(sizeof(Sistema) ));
    FILE *file = fopen(_sistema_arquivo, "rb");

    if(file ==NULL){
        printf("ERRO AO ABRIR O ARQ");
        return -1;
    }

    fread(_sistema_recuperar, sizeof (Sistema),n,file) ;



    fclose(file);
    return 1;
}

int ler_arquivo_binario(const char *nome_arquivo, int tamanho,Sistema *_sistema_p) {
    FILE *arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }







    fread(_sistema_p, sizeof(Sistema), tamanho, arquivo); // Lê os dados do arquivo para o vetor

    fclose(arquivo);
    return 1;
}

int main() {

    int exit_menu_1 = 1; //sair do menu do usuario logado
    int exit_menu_0 = 1; //sair do menu do cadastro de usuario
    int chosen ;// escolhas do menu
    int log; // mensagens de erro ou sucesso
    int sistema_num_ids = sistema_recuperar_id(sistema_arquivo_bin);
    // Limpar a tela usando o comando "cls" no Windows
    system("cls");

    printf("cont id %d \n",sistema_num_ids);






    char sistema_nome[45], sistema_user[45], sistema_pass[45];


    Sistema *sistema_p = create_sistema(sistema_num_ids);

    if(sistema_num_ids>0){
       //sistema_recuperar_dados(sistema_arquivo_bin,sistema_p,sistema_num_ids);


        ler_arquivo_binario(sistema_arquivo_bin,sistema_num_ids,sistema_p);
        printf("Dados recuperardos\n\t");

        for (int i = 0; i < sistema_num_ids; i++) {
            printf("Sistema %d:\n", i + 1);
            printf("ID: %d\n", sistema_p[i].ID);
            printf("Nome: %s\n", sistema_p[i].NAME);
            printf("Usuário: %s\n", sistema_p[i].USER);
            printf("Senha: %s\n", sistema_p[i].PASS);
            printf("Permissão: %d\n", sistema_p[i].PERMISSION);
            printf("Ativado: %d\n", sistema_p[i].ACTIVATED);
            printf("\n");
        }

    }



    //FILE *arquivo;

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
        setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada


        // FILE *file_t = fopen(sistema_arquivo_txt, "a+");

        switch (chosen) {
            case 1: // cadatrar usuário
                printf("Digite o nome Funcionário\n");
                fgets(sistema_nome, sizeof(sistema_nome), stdin);
                remover_linha(sistema_nome);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada


                printf("Digite o User \n");
                fgets(sistema_user, sizeof(sistema_user), stdin);
                remover_linha(sistema_user);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada


                printf("Digite a senha\n");
                fgets(sistema_pass, sizeof(sistema_pass), stdin);
                remover_linha(sistema_pass);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada




                sistema_num_ids = add_sistema(sistema_num_ids, sistema_nome, sistema_user, sistema_pass, sistema_num_ids, sistema_p);
                FILE *file_b = fopen(sistema_arquivo_bin, "wb");
                arquivo_b(file_b, sistema_p, sistema_num_ids );
                fclose(file_b);
               /* arquivo = fopen("Sistema.bin","ab");
                if (arquivo == NULL) {
                    perror("Erro ao abrir o arquivo");
                    return 1;
                }

                fwrite(sistema_p,sizeof(Sistema),sistema_num_ids,arquivo);

                fclose(arquivo);*/




               /*
               FILE *arquivo;

                arquivo = fopen("teste.bin","wb");
                if (arquivo == NULL) {
                    perror("Erro ao abrir o arquivo");
                    return -1;
                }

                fwrite(sistema_p,sizeof (struct Sistema),sistema_num_ids,arquivo);
                */




                break;
            case 2: //logar, isso entrá em outro menu já logado

                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada
                printf("Digite o User \n");
                fgets(sistema_user, sizeof(sistema_user), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada


                printf("Digite a senha\n");
                fgets(sistema_pass, sizeof(sistema_pass), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada
                // filtrar se tem cadastro ou não e verificar se está ativo ou não

                for (int i = 0; i < sistema_num_ids; ++i) {
                    if(strcmp(sistema_p[i].USER, sistema_user)==0){

                        if(strcmp(sistema_p[i].PASS, sistema_pass) == 0){
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
                fgets(sistema_user, sizeof(sistema_user), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada


                printf("Digite a senha\n");
                fgets(sistema_pass, sizeof(sistema_pass), stdin);
                setbuf(stdin, NULL);// limpando buffer para não pegar  resto de uma entrada passada

                log=delete_sistema(sistema_user, sistema_pass, sistema_num_ids, sistema_p);
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

               // fclose(file_b);
                break;



        }

    }

//printf("----------------------------------sistema_nome (%s)---------------------------------------------------------",sistema_p[0].NAME);
    Sistema vetor[3];

    // Abra o arquivo binário no modo de leitura
    FILE *arquivo_a = fopen(sistema_arquivo_bin, "rb");
    if (arquivo_a == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Leia os dados do arquivo para o vetor de structs
    fread(vetor, sizeof(struct Sistema), 3, arquivo_a );

    // Feche o arquivo após a leitura
    fclose(arquivo_a );

    // Agora, o vetor contém os dados recuperados do arquivo
    // Faça o que for necessário com os dados

    // Exemplo: Imprima os valores das structs
    for (int i = 0; i < 3; i++) {
        printf("Sistema %d:\n", i + 1);
        printf("ID: %d\n", vetor[i].ID);
        printf("Nome: %s\n", vetor[i].NAME);
        printf("Usuário: %s\n", vetor[i].USER);
        printf("Senha: %s\n", vetor[i].PASS);
        printf("Permissão: %d\n", vetor[i].PERMISSION);
        printf("Ativado: %d\n", vetor[i].ACTIVATED);
        printf("\n");
    }








    return 0;
}
