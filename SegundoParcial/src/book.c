#include "book.h"
//static int isValidNombre(char* cadena,int longitud);

eBook* eBook_new()
{
    eBook* pAuxBook;

    pAuxBook = (eBook*)malloc(sizeof(eBook));

    return pAuxBook;
}
void eBook_delete(eBook *this)
{

    if(this != NULL)
    {
        free(this);
    }
}
eBook* eBook_newParametros(char* id,char* titulo,char* autor, char* precio, char* editorial)
{
    eBook* this = eBook_new();
    void *retorno = NULL;
    if(this != NULL && id != NULL && titulo != NULL && autor != NULL && precio != NULL && editorial != NULL)
    {
    	if(!eBook_setId(this, atoi(id)) &&
    	!eBook_setTitulo(this, titulo) &&
    	!eBook_setAutor(this, autor) &&
		!eBook_setPrecio(this,atof(precio)) &&
    	!eBook_setEditorial(this, atoi(editorial)))
    	{
    		retorno = this;
    	}
    	else
    	{
    		eBook_delete(this);
    		retorno = this;
    	}

    }
    return retorno;
}
int eBook_setId(eBook* this,int id)
{
	int retorno = -1;
	if(this != NULL && id >= 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int eBook_getId(eBook* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;

	}
	return retorno;
}
int eBook_setTitulo(eBook* this,char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo != NULL)
    {
    	strcpy(this->titulo, titulo);
    	retorno = 0;
    }

    return retorno;
}
int eBook_getTitulo(eBook* this,char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo !=NULL)
    {

        strcpy(titulo, this->titulo);
        retorno = 0;
    }

    return retorno;
}
int eBook_setAutor(eBook* this,char* autor)
{
    int retorno = -1;

    if(this != NULL && autor != NULL)
    {
    	strcpy(this->autor, autor);
    	retorno = 0;
    }

    return retorno;
}
int eBook_getAutor(eBook* this,char* autor)
{
    int retorno = -1;

    if(this != NULL && autor !=NULL)
    {
        strcpy(autor, this->autor);
        retorno = 0;
    }

    return retorno;
}
int eBook_setPrecio(eBook* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio >= 0)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}
int eBook_getPrecio(eBook* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}
int eBook_setEditorial(eBook* this,int editorial)
{
    int retorno = -1;

    if(this != NULL && editorial != 0)
    {
    	this->editorial= editorial;
        retorno = 0;
    }

    return retorno;
}
int eBook_getEditorial(eBook* this,int* editorial)
{
    int retorno = -1;

    if(this != NULL && editorial != 0)
    {
        *editorial = this->editorial;
        retorno = 0;
    }

    return retorno;
}
int eBook_compareByAutor(void* pThis1, void* pThis2)
{
    int comparar;
    eBook* pAuxBook1 = (eBook*)pThis1;
    eBook* pAuxBook2 = (eBook*)pThis2;

    if(pAuxBook1 != NULL && pAuxBook2 != NULL)
    {
        comparar = strcmp(pAuxBook1->autor, pAuxBook2->autor);
    }

    return comparar;
}
int eBook_getEditorialId (eEditorial* arrayEditorial,int editorialId,char* detalleEditorial)
{
	int retorno = -1;
	if(arrayEditorial != NULL && detalleEditorial != NULL)
	{
		if(arrayEditorial->editorial == editorialId)
		{
			switch(editorialId)
			{
			case 1:
				strcpy(detalleEditorial,"Planeta");
				break;
			case 2:
				strcpy(detalleEditorial,"SIGLO XXI EDITORES");
				break;
			case 3:
				strcpy(detalleEditorial,"Pearson");
				break;
			case 4:
				strcpy(detalleEditorial,"Minotauro");
				break;
			case 5:
				strcpy(detalleEditorial,"Salamandra");
				break;
			case 6:
				strcpy(detalleEditorial,"Penguin books");
				break;
			}
			retorno = 0;
		}
	}

	return retorno;
}
void calcularMonto(void* this)
{
	int editorial;
	float precio;
	float precioDescuento;
	if(this != NULL)
	{
		eBook_getEditorial(this, &editorial);
		eBook_getPrecio(this, &precio);

		if(editorial == 1 && precio >= 300)
		{
			precioDescuento = precio - (precio * 0.20);
			eBook_setPrecio(this, precioDescuento);
		}
		if(editorial == 2 && precio <= 200)
		{
			precioDescuento = precio - (precio * 0.10);
			eBook_setPrecio(this, precioDescuento);

		}
	}
}/*
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
*/
