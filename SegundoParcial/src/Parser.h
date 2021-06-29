/*
 * Parser.h
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "book.h"
/** \brief Parsea los datos los datos de los libros desde el archivo ingresado por el usuario
 *
 * @param path char* archivo que contiene los datos a parsear
 * @param pArrayListBook LinkedList* Array de tipo LinkedList.
 * @return int retorna 0 si los datos se fueron parseados, y -1 sino se parsearon
 *
 */
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListBook);

#endif /* PARSER_H_ */
