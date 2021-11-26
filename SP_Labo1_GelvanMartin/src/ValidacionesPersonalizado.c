/*
 ============================================================================
 Name        : ValidacionesPersonalizado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>
#include "ValidacionesPersonalizado.h"



int validacion_Numero(char cadena[]) {
	int i = 0;
	int esNumero = 0;

	while (i < strlen(cadena)) {
		esNumero = isdigit(cadena[i]);

		if (esNumero != 0) {
			i++;
		} else {
			break;
		}

	}

	return esNumero;
}

int validacion_AlfaNumerica(char cadena[]) {
	int i = 0;
	int esAlfaNumerico = 0;

	while (i < strlen(cadena) && esAlfaNumerico == 0) {
		esAlfaNumerico = isalnum(cadena[i]);

		if (esAlfaNumerico != 0) {
			i++;
		} else {
			break;
		}

	}

	return esAlfaNumerico;
}


int validacion_Cadena(char cadena[]) {
	int i = 0;
	int esString = 0;

	while (i < strlen(cadena)) {
		esString = isalpha(cadena[i]);

		if (esString != 0) {
			i++;
		} else {
			break;
		}

	}

	return esString;

}

int validacion_Espacio(char* cadena)
{
	int i;
	int tamanioCadena;
	int retorno=-1;

	tamanioCadena=strlen(cadena);

	for(i=0;i<tamanioCadena;i++)
	{
		if(cadena[i] == ' ' || cadena[i] == '\t' || cadena[i] == '\v' || cadena[i] == '\n')
		{
			retorno=0;
			break;
		}

	}
	return retorno;
}

int esNumeroSimbolo(char* cadena)
{
	int i;
	int tamanioCadena;
	int retorno=-1;


	if(cadena!=NULL)
	{
		tamanioCadena=strlen(cadena);

		for(i=0;i<tamanioCadena;i++)
		{
			if(isdigit(cadena[i])==0 && cadena[i]!='.' && cadena[0]!='+'
			&& cadena[0]!='-' && cadena[0]!='!' && cadena[0]!='¡' && cadena[0]!='@' && cadena[0]!='?' && cadena[0]!='¿')
			{
				retorno=0;
				break;
			}

		}

	}
	return retorno;
}
