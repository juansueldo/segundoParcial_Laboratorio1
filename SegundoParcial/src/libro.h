/*
 * movie.h
 *
 *  Created on: 23 jun. 2021
 *      Author: Juan
 */

#ifndef LIBRO_H_
#define LIBRO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"

#define MAX_NOMBRE 70
#define DESCUENTO_1 0.20
#define DESCUENTO_2 0.10
#define PRECIO_1 300
#define PRECIO_2 200

typedef struct{
	int id;
	char titulo[MAX_NOMBRE];
	char autor[MAX_NOMBRE];
	float precio;
	int editorial;
}eLibro;

typedef struct{
	int editorial;
	char editorialDetalle[MAX_NOMBRE];
}eEditorial;

eLibro* eLibro_new();
eLibro* eLibro_newParametros(char* id,char* titulo,char* autor, char* precio, char* editorial);

int eLibro_setId(eLibro* this,int id);
int eLibro_getId(eLibro* this,int* id);

int eLibro_setTitulo(eLibro* this,char* titulo);
int eLibro_getTitulo(eLibro* this,char* titulo);


int eLibro_setAutor(eLibro* this,char* autor);
int eLibro_getAutor(eLibro* this,char* autor);


int eLibro_setPrecio(eLibro* this,float precio);
int eLibro_getPrecio(eLibro* this,float* precio);

int eLibro_setEditorial(eLibro* this,int editorial);
int eLibro_getEditorial(eLibro* this,int* editorial);

int eLibro_compareByAutor(void* pThis1, void* pThis2);

int eLibro_getEditorialId (eLibro* this,int editorialId,char* detalleEditorial);
int eLibro_setMonto(eLibro* this,float monto);
int eLibro_getMonto(eLibro* this,float* monto);
int eLibro_getMontoGenrado (eLibro* this, int dia,int cantidad, float* monto);
eLibro* eLibro_newParametrosInt(int id,char* nombre,int dia, char* horario, int sala, int cantidad, float monto);
void calcularMonto(void* this);
int eLibro_compareBynombre(void* pThis1, void* pThis2);
#endif /* LIBRO_H_ */
