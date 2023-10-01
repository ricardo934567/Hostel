//
// Created by Ricar on 20/09/2023.
//

#include "Arquivo.h"


int arquivo_b(FILE *_f,Sistema *_s,int _quantidade_id){




        fwrite(_s,sizeof (struct Sistema),_quantidade_id,_f);//qtd - 1 para não pegar a parte em branco do vetor dina.
        return 1;








    //fclose(_f);





}