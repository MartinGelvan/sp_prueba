#include "Inputs.h"
#include "ValidacionesPersonalizado.h"

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;
	char auxEntero[200];


	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%s", auxEntero);

		numeroIngresado=atoi(auxEntero);

		while((esNumeroSimbolo(auxEntero)==0 && validacion_Espacio(mensaje)==0) || (numeroIngresado>max  || numeroIngresado<min))
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%s", auxEntero);
			numeroIngresado=atoi(auxEntero);

		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
	int retorno = -1;
	float numeroIngresado;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int retorno = -1;
	char buffer[256];
	int tam;
	int esUnaCadena=0;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		esUnaCadena=validacion_Cadena(buffer);



		while(tam > max || esUnaCadena==0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
			esUnaCadena=validacion_Cadena(buffer);
		}




		strcpy(cadena, buffer);
		retorno = 0;
	}

	return retorno;
}

int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}

int pedirConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

	return retorno;
}


