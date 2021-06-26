/*
 * Controller.c
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */
#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBooks)
{
    int verificar;
    int retorno = -1;
    FILE* file = NULL;

    if(pArrayListBooks != NULL)
    {
        file = fopen(path, "r");

        if(file != NULL)
        {
        	verificar = parser_BookFromText(file, pArrayListBooks);
        	if(verificar == 0)
        	{
        		retorno = 0;
        	}

        }
    }

    fclose(file);
    return retorno;
}
int controller_ListBooks(LinkedList* pArrayListBooks)
{
    int retorno = -1;
    int i;
    int pantalla = 999;
    int respuesta;
    int respuesta2;
    int id;
    char titulo[MAX_NOMBRE];
    char autor[MAX_NOMBRE];
    float precio;
    char editorial[MAX_NOMBRE];
    eBook* pAuxMovie = eBook_new();

    if(pArrayListBooks != NULL)
    {
    	if(ll_len(pArrayListBooks)>0)
    	{
    		printf("|*******|**************************************************************|*****************|************|***********************|\n");
    		printf("|   ID  |                        TITULO                                |      AUTOR      |   PRECIO   |       EDITORIAL       |\n");
    		printf("|*******|**************************************************************|*****************|************|***********************|\n");
        do
        {
        for(i = 0 ; i < ll_len(pArrayListBooks); i++)
        {
        	pAuxMovie = (eBook*)ll_get(pArrayListBooks, i);

        	eBook_getId(pAuxMovie, &id);
        	eBook_getTitulo(pAuxMovie, titulo);
        	eBook_getAutor(pAuxMovie, autor);
        	eBook_getPrecio(pAuxMovie, &precio);
        	eBook_getEditorial(pAuxMovie, editorial);

            printf("| %5d | %60s | %15s | %10.2f |  %20s |\n", id,titulo,autor, precio,editorial);

            if(i == pantalla)
             {
        		do
        		{
        			respuesta = utn_getRespuesta ("\nPRESIONE [S] PARA MOSTRAR MAS EMPLEADOS: ","\nERROR", 3);
        			pantalla+=999;
        		}while(respuesta != 0);
              }
        	}
        	respuesta2 = utn_getRespuesta ("\nPRESIONE [S] PARA CONTINUAR: ","\nERROR", 3);

        }while(respuesta2 != 0);
        retorno = 0;

    	}
    }
    return retorno;
}
int controller_sort (LinkedList* pArrayListBooks)
{
	int retorno = -1;
	int orden = 0;

	 if(pArrayListBooks != NULL && ll_len(pArrayListBooks) > 0)
	 {
		 ll_sort(pArrayListBooks, eBook_compareByAutor, orden);
		 retorno = 0;
	 }
	 return retorno;
}
int controller_saveAsText(char* path , LinkedList* pArrayListMovies)
{
    FILE* file = NULL;
    int retorno = -1;
    int eBookQTY;
    int i;
    eBook* pAuxMovie;

    if(pArrayListMovies != NULL)
    {
        eBookQTY = ll_len(pArrayListMovies);

        file = fopen(path, "w");

        if(file != NULL
           && eBookQTY > 0 && eBookQTY <= 700
           && fprintf(file, "id,titulo,autor,precio,editorialId\n") != -1)
        {
            for(i = 0; i < eBookQTY; i++)
            {
            	pAuxMovie = (eBook*)ll_get(pArrayListMovies, i);
                if(fprintf(file, "%d,%s,%s,%.2f,%s\n",
                		pAuxMovie->id,
						pAuxMovie->titulo,
						pAuxMovie->autor,
						pAuxMovie->precio,
						pAuxMovie->editorial) == -1)
                {
                    break;
                }

            }
        }

        if(i > 0 && i == eBookQTY)
        {
        	//printf("\nMONTOS %.2f",pAuxeBook->monto);
        	retorno = 0;
        }
    }

    fclose(file);
    free(pAuxMovie);
    return retorno;
}
/*
int controller_getMontos (LinkedList* pArrayListMovies)
{
	int retorno = -1;
	eBook* pAuxMovie = eBook_new();
	int id;
	int dia;
	int cantidad;
	char horario[MAX_NOMBRE];
	char nombre[MAX_NOMBRE];
	int sala;
	float auxMonto;
	int i;

	if(pArrayListMovies != NULL)
	{
		for(i = 0; i < ll_len(pArrayListMovies);i++)
		{
			pAuxMovie = (eBook*)ll_get(pArrayListMovies, i);

			eBook_getDia(pAuxMovie, &dia);
			eBook_getCantidad(pAuxMovie, &cantidad);
			eBook_getId(pAuxMovie, &id);
			eBook_getNombre(pAuxMovie, nombre);
			eBook_getHora(pAuxMovie, horario);
        	eBook_getSala(pAuxMovie, &sala);
			eBook_getMontoGenrado (pAuxMovie, dia,cantidad, &auxMonto);
			eBook_setMonto(pAuxMovie, auxMonto);
			pAuxMovie = eBook_newParametrosInt(id,nombre,dia,horario,sala,cantidad,auxMonto);

		}
			if(pAuxMovie != NULL && ll_add(pArrayListMovies, (eBook*)pAuxMovie) == 0)
			{
				retorno = 0;
			}
	}

	return retorno;
}
int controller_saveAsText(char* path , LinkedList* pArrayListMovies)
{
    FILE* file = NULL;
    int retorno = -1;
    int eBookQTY;
    int i;
    eBook* pAuxMovie;

    if(pArrayListMovies != NULL)
    {
        eBookQTY = ll_len(pArrayListMovies);

        file = fopen(path, "w");

        if(file != NULL
           && eBookQTY > 0 && eBookQTY <= 700
           && fprintf(file, "id_venta,nombre_pelicula,dia,horario,sala,cantidad_entradas,monto\n") != -1)
        {
            for(i = 0; i < eBookQTY; i++)
            {
            	pAuxMovie = (eBook*)ll_get(pArrayListMovies, i);
                if(fprintf(file, "%d,%s,%d,%s,%d,%d,%.2f\n",
                		pAuxMovie->id_venta,
						pAuxMovie->nombre_pelicula,
						pAuxMovie->dia,
						pAuxMovie->horario,
						pAuxMovie->sala,
						pAuxMovie->cantidad_entradas,
						pAuxMovie->monto) == -1)
                {
                    break;
                }

            }
        }

        if(i > 0 && i == eBookQTY)
        {
        	//printf("\nMONTOS %.2f",pAuxeBook->monto);
        	retorno = 0;
        }
    }

    fclose(file);
    free(pAuxMovie);
    return retorno;
}

int controller_ListBySala(LinkedList* pArrayListMovies)
{
	int retorno = -1;
	eBook* pAuxMovie = eBook_new();
	int i;
	int id;
	char titulo[MAX_NOMBRE];
	char autor[MAX_NOMBRE];
	float precio;
	char editorial[MAX_NOMBRE];
	int flag = 1;
	if(pArrayListMovies != NULL && ll_isEmpty(pArrayListMovies)==0)
	{
		utn_getNumero(&auxSala, "\nINGRESE LA SALA A IMPRIMIR: ", "\nERROR", 1, 5, 3);
		printf("|*********|********|**************|**************************************************************|\n");
		printf("|   SALA  |CANTIDAD|    MONTO     |                      NOMBRE                                  |\n");
		printf("|*********|********|**************|**************************************************************|\n");
		ll_sort(pArrayListMovies,eBook_compareBynombre,1);
		for(i = 0; i < ll_len(pArrayListMovies); i++)
		{
			pAuxMovie = ll_get(pArrayListMovies, i);
			eBook_getSala(pAuxMovie, &sala);
			if(auxSala == sala)
			{
				eBook_getCantidad(pAuxMovie, &cantidad);
				eBook_getMonto(pAuxMovie, &monto);
				eBook_getNombre(pAuxMovie, nombre);
				if(flag ==1 || strcmp(auxNombre,nombre) !=0)
				{
					strcpy(auxNombre,nombre);
					retorno = 0;

				}
				printf("|  %5d  |  %5d |   %5.2f  |   %60s|\n",sala,cantidad,monto,nombre);
			}
		}
		retorno = 0;
	}
	return retorno;
}
*/
