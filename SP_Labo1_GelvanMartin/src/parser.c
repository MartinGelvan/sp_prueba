#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perros.h"
#include "parser.h"
#include "Controller.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_PerroFromText(FILE* pFile , LinkedList* pArrayListPerros)
{
	char auxId[120];
	char auxNombre[120];
	char auxRaza[120];
	char auxEdad[120];
	int exito=0;

	if(pFile!=NULL && pArrayListPerros!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxRaza,auxEdad);

		while(!feof(pFile))
		{
			Perro* pPerro;
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxRaza,auxEdad);
			pPerro= perro_newParametros(auxId, auxNombre, auxRaza, auxEdad);
			ll_add(pArrayListPerros, pPerro);
			if(feof(pFile))
			{
				break;
			}

		}


		if(feof(pFile))
		{
			exito=1;
		}

	}

    return exito;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_PerroFromBinary(FILE* pFile , LinkedList* pArrayListPerros)
{
	//char auxId[40];
	//char auxNombre[40];
	//char auxHoras[40];
	//char auxSueldo[40];
	int exito=0;

	if(pFile!=NULL && pArrayListPerros!=NULL)
	{

		while(!feof(pFile))
		{
			Perro* pPerro= perro_new();
			fread(pPerro,sizeof(Perro), 1,pFile);
			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListPerros, pPerro);


		}

		exito=1;
	}
    return exito;
}
