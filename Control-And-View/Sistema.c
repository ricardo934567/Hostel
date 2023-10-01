//
// Created by Ricar on 11/09/2023.
//

#include <stdio.h>
#include "Sistema.h"


Sistema *create_sistema(int _tamanho) {
    Sistema *sistema = malloc(_tamanho*sizeof(Sistema));
    return sistema;
}

int add_sistema(int id,char name[], char user[], char password[],int qtd_users,Sistema *sistema){


int novo_tamanho = qtd_users +1;

    sistema = (Sistema *)realloc(sistema, novo_tamanho * sizeof(Sistema));
    if(sistema == NULL){
        printf("ERRO REALLOC");
        return -1;
    }




    sistema[id].ID = qtd_users +1;
    strcpy(sistema[id].NAME,name);
    strcpy(sistema[id].USER,user);
    strcpy(sistema[id].PASS,password);
    sistema[id].ACTIVATED = 1;
    sistema[id].PERMISSION = 0;


    return novo_tamanho;


}

int delete_sistema(char user[45], char password[45],int qtd_users,Sistema *sistema){
    for(int i=0;i<qtd_users;i++){
        if(strcmp(user,sistema[i].USER) ==0 ){  // 0 = strings iguais
            if(strcmp(password,sistema[i].PASS)== 0){
                sistema[i].ACTIVATED = 0;// 0 = excluido

                return 1;

            } else{

                return -1;
            }
            break;
        } else if(strcmp(user,sistema[i].USER) ==1 && i == qtd_users){

            return -404;
        }
    }

}