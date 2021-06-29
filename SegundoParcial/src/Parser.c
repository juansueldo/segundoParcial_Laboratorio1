/*
 * Parser.c
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */
#include "Parser.h"
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook)
{
    int cantidad;
    int retorno = -1;
    char buffer[5][200];
    eBook* pAuxBook = NULL;

    if(pFile != NULL && pArrayListBook != NULL)
    {
    	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);
    	do
        {
        	cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

        	if(cantidad < 5)
            {
        		printf("\nFIN");
        		break;
            }
        	else
        	{
        		if(strcmp(buffer[4],"Planeta")==0)
        		{
        			//buffer[4] = 1;
        			strcpy(buffer[4], "1");
        		}
        		if(strcmp(buffer[4],"SIGLO XXI EDITORES")==0)
    			{
        			//buffer[4] = 2;
        			strcpy(buffer[4], "2");
    			}
    			if(strcmp(buffer[4],"Pearson")==0)
    			{
    				//buffer[4] =3;
    				strcpy(buffer[4], "3");
    			}
    			if(strcmp(buffer[4],"Minotauro")==0)
    			{
    				//buffer[4]= 4;
    				strcpy(buffer[4], "4");
    			}
    			if(strcmp(buffer[4],"SALAMANDRA")==0)
    			{
    				//buffer[4] = 5;
    				strcpy(buffer[4], "5");
    			}
    			if(strcmp(buffer[4],"PENGUIN BOOKS")==0)
    			{
    				//buffer[4] = 6;
    				strcpy(buffer[4], "6");
    			}
        		pAuxBook = eBook_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

                if(pAuxBook != NULL && ll_add(pArrayListBook, (eBook*)pAuxBook) == 0)
                {
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

