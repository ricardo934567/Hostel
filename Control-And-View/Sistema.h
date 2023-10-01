//
// Created by Ricar on 11/09/2023.
//

#include <stdlib.h>
#include <string.h>
#ifndef HOSTEL_SISTEMA_H
#define HOSTEL_SISTEMA_H
typedef struct Sistema{
    int ID; //identificador
    char NAME[45];
    char USER[45];
    char PASS[45];
    int PERMISSION;//permissões 1-total 2-parcial 3-somente busca
    int ACTIVATED;// 0-Excluido 1-Ativo

}Sistema;

Sistema *create_sistema(int _tamanho);//criar sistema
int add_sistema(int id,char name[45], char user[45], char password[45],int qtd_users,Sistema *sistema);
int delete_sistema(char user[45], char password[45],int qtd_users,Sistema *sistema);

#endif //HOSTEL_SISTEMA_H
