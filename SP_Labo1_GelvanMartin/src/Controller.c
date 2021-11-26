#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Perros.h"
#include "Inputs.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPerros)
{
	FILE* pFile;
	int exito=0;

	if(path!=NULL && pArrayListPerros!=NULL) // verifico que path y pArrayListPerros sean distinto de NULL
	{
		pFile=fopen(path,"r"); //abro archivo en modo lectura de texto

		if(pFile!=NULL) // verifico que pFile sea distinto de NULL
		{
			parser_PerroFromText(pFile ,pArrayListPerros); // llamo al parser
			exito=1;
		}
		fclose(pFile); //cierro el archivo
	}

	return exito;
    //return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int exito=0;

	if(path!=NULL && pArrayListEmployee!=NULL) // verifico que path y pArrayListPerros sean distinto de NULL
	{
		pFile=fopen(path,"rb"); // abro el archivo y leo en forma binaria

		if(pFile!=NULL) //verifico que pFile sea distinto de NULL
		{
			parser_PerroFromBinary(pFile ,pArrayListEmployee); //llamo al parser del binario
			exito=1;
		}
		fclose(pFile); //cierro el archivo
	}

	return exito;
   // return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListPerros(LinkedList* pArrayListPerros)
{
	int i;
	int tam;
	int auxId;
	int auxEdad;
	char auxNombre[120];
	char auxRaza[120];
	Perro* auxPerro;
	int exito=0;

	printf("%-10s %-10s %-10s %-10s\n","ID","NOMBRE","RAZA","EDAD");

	if(pArrayListPerros!=NULL) //Verifico que pArrayListPerros sea distinto de NULL
	{
		tam=ll_len(pArrayListPerros); //guardo el tamaño del array en una variable

		for(i=0;i<tam;i++)
		{
			auxPerro=(Perro*)ll_get(pArrayListPerros, i); //Guardo los perros en auxPerro
			perro_getId(auxPerro, &auxId); //traigo el id del perro
			perro_getNombre(auxPerro, auxNombre); //traigo el nombre del perro
			perro_getRaza(auxPerro, auxRaza); //traigo la raza del perro
			perro_getEdad(auxPerro, &auxEdad); //traigo la edad del perro
			printf("%-10d %-10s %-10s %-10d\n",auxId,auxNombre,auxRaza,auxEdad); //Imprimo los perros


		}

		exito=1;
	}

    return exito;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortPerro(LinkedList* pArrayListPerros)
{
	int opcion;
	int exito=0;

	if(pArrayListPerros!=NULL)
	{
		pedirEntero(&opcion, "¿Como le gustaria ordenar?\n"
				"1.Por ID ascendente\n"
				"2.Por ID descendente\n"
				"3.Por Nombre A->Z\n"
				"4.Por Nombre Z->A\n"
				"5.Por Raza ascendente\n"
				"6.Por Raza descendente\n"
				"7.Por Edad ascendente\n"
				"8.Por Edad descendente\n\n"
				"Elija una opcion: ",
				"Error, reingrese la opcion\n"
				"1.Por ID ascendente\n"
				"2.Por ID descendente\n"
				"3.Por Nombre A->Z\n"
				"4.Por Nombre Z->A\n"
				"5.Por Raza ascendente\n"
				"6.Por Raza descendente\n"
				"7.Por Edad ascendente\n"
				"8.Por Edad descendente\n\n"
				"Elija una opcion: ", 1, 8);

		switch(opcion)
		{
			case 1:
				ll_sort(pArrayListPerros, perro_CompareById, 1); // hago el sort del id
				controller_ListPerros(pArrayListPerros);
			break;
			case 2:
				ll_sort(pArrayListPerros, perro_CompareById, 0);
				controller_ListPerros(pArrayListPerros);
			break;
			case 3:
				ll_sort(pArrayListPerros, perro_CompareByName, 1);// hago el sort del nombre
				controller_ListPerros(pArrayListPerros);
			break;
			case 4:
				ll_sort(pArrayListPerros, perro_CompareByName, 0);
				controller_ListPerros(pArrayListPerros);
			break;
			case 5:
				ll_sort(pArrayListPerros, perro_CompareByRaza, 1);// hago el sort de la raza
				controller_ListPerros(pArrayListPerros);
			break;
			case 6:
				ll_sort(pArrayListPerros, perro_CompareByRaza, 0);
				controller_ListPerros(pArrayListPerros);
			break;
			case 7:
				ll_sort(pArrayListPerros, perro_CompareByEdad, 1);// hago el sort de la edad
				controller_ListPerros(pArrayListPerros);
			break;
			case 8:
				ll_sort(pArrayListPerros, perro_CompareByEdad, 0);
				controller_ListPerros(pArrayListPerros);
			break;
		}

		exito=1;
	}
    return exito;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPerros)
{
	FILE* pFile;
	int tam;
	int i;
	Perro* perro;
	int auxId;
	char auxNombre[120];
	char auxRaza[120];
	int auxEdad;
	int exito=0;

	if(path!=NULL && pArrayListPerros!=NULL) //Verifico que el path y el pArrayListPerros sean distinto de NULL
	{

		pFile=fopen(path,"w"); // abro el archivo para escribir en forma de texto

		if(pFile!=NULL) //Verifico que el pFile sea distinto de NULL
		{
			tam= ll_len(pArrayListPerros); //guardo el tamaño del array en una variable
			fprintf(pFile,"Id,Nombre,Raza,Edad\n"); //hago un fprintf para almacenar en el archivo

			for(i=0;i<tam;i++)
			{
				perro=ll_get(pArrayListPerros, i); //guardo los perros en una variable
				perro_getId(perro,&auxId); //me traigo el id
				perro_getNombre(perro,auxNombre); // me traigo el nombre
				perro_getRaza(perro,auxRaza); //me traigo la raza
				perro_getEdad(perro,&auxEdad); //me traigo la edad
				fprintf(pFile,"%d,%s,%s,%d\n", auxId,auxNombre, auxRaza,auxEdad);//hago un fprintf para almacenar en el archivo
			}
			fclose(pFile); //cierro el archivo
			exito=1;
		}

	}
	return exito;
    //return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPerros)
{
	FILE* pFile;
	Perro* auxPerro;
	int tam;
	int i;
	int exito=0;

	if(path!=NULL && pArrayListPerros!=NULL) //Verifico que el path y el pArrayListPerros sean distintos de NULL
	{
		pFile=fopen(path, "wb"); //abro el archivo y lo escribo en forma binaria

		if(pFile!=NULL) //Verifico que el pFile sea distintos de NULL
		{
			tam=ll_len(pArrayListPerros); //guardo el tamaño del array en una variable

			for(i=0;i<tam;i++)
			{
				auxPerro=(Perro*)ll_get(pArrayListPerros, i); //guardo los perros en auxPerro
				fwrite(auxPerro,sizeof(Perro),1,pFile); //escribo en forma binaria
			}

			fclose(pFile);
			exito=1;
		}
	}

	return exito;
	//return 1;
}

