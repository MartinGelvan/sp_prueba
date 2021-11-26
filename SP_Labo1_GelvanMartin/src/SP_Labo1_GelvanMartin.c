/*
 ============================================================================
 Name        : SP_Labo1_GelvanMartin.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Perros.h"
#include "Inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 10;
    int exito;
    int banderaTexto=0;
    int banderaBinario=0;
    LinkedList* listaPerrosFiltradoEdad;
    LinkedList* listaPerrosFiltradoRaza;
    int tamUno;
    int tamDOs;

    LinkedList* listaPerros = ll_newLinkedList();
    do{
    	pedirEntero(&option, "1.Cargar los datos de los perros desde el archivo perros.csv (modo texto)\n"
    			 "2. Cargar los datos de los perros desde el archivo perros.csv (modo binario)\n"
    			"3. \n"
    		     "4.\n"
    		     "5. Listar Perros de mas de 10 años\n"
    		     "6. Listar perros\n"
    		     "7. Ordenar perros\n"
    		     "8. Guardar los datos de los perros en el archivo perros.csv (modo texto)\n"
    		     "9. Guardar los datos de los perros en el archivo perros.csv (modo binario)\n"
    		    "10. Salir\n"
    		    "Elija la opcion: ", "Error, esa opcion no existe, reingrese la opcion.\n"
    		    "1. Cargar los datos de los perros desde el archivo perros.csv (modo texto)\n"
				 "2. Cargar los datos de los perros desde el archivo perros.csv (modo binario)\n"
				 "3. \n"
				 "4. \n"
				 "5. Listar Perros de mas de 10 años\n"
				 "6. Listar perros\n"
				 "7. Ordenar perros\n"
				 "8. Guardar los datos de los perros en el archivo perros.csv (modo texto)\n"
				" 9. Guardar los datos de los perros en el archivo perros.csv (modo binario)\n"
				"10. Salir\n"
				"Elija la opcion: ", 1, 10);

        switch(option)
        {
            case 1:
                exito=controller_loadFromText("src\\perros.csv",listaPerros);
                if(exito==1)
                {
                	printf("\nSe cargo en forma de texto con exito!\n\n");
                	banderaTexto=1;
                }else
                {
                	printf("\nNo se logro cargar en forma de texto\n");
                }


                system("pause");
                break;
            case 2:
            	exito=controller_loadFromBinary("src\\dataBinarioPerros.csv" , listaPerros);
            	if(exito==1)
				{
					printf("\nSe cargo en forma binaria con exito!\n\n");
					banderaBinario=1;
				}else
				{
					printf("\nNo se logro cargar en forma binaria\n");
				}
            	system("pause");
			break;

			case 3:
				listaPerrosFiltradoRaza=ll_filtro(listaPerros,filtroRazaGolden);

				tamUno=ll_len(listaPerros);
				tamDOs=ll_len(listaPerrosFiltradoRaza);

				printf("\nTam 1: %d\n", tamUno);
				printf("\nTam 2: %d\n", tamDOs);
				if(listaPerrosFiltradoRaza!=NULL)
				{
					if((controller_saveAsText("perrosFiltradosPorRazaFemale.csv", listaPerrosFiltradoRaza))==1)
					{
						printf("\nLista creada y guardada como perrosFiltradosPorRazaFemale.csv \n");
					}

					controller_ListPerros(listaPerrosFiltradoRaza);
				}


				system("pause");
			break;

			case 4:


			break;

			case 5:

				listaPerrosFiltradoEdad=ll_filtro(listaPerros, filtroEdad);
				controller_ListPerros(listaPerrosFiltradoEdad);
				system("pause");

			break;

			case 6:
				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_ListPerros(listaPerros);
					if(exito==1)
					{
						printf("\nSe mostro la lista con exito!\n\n");
						banderaBinario=1;
					}else
					{
						printf("\nNo se logro mostrar la lista\n");
					}
				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}
				system("pause");
			break;

			case 7:
				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_sortPerro(listaPerros);
					if(exito==1)
					{
						printf("\nSe ordeno con exito!\n\n");
						banderaBinario=1;
					}else
					{
						printf("\nNo se logro ordenar\n");
					}
				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}
				system("pause");
			break;

			case 8:
				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_saveAsText("src\\perros.csv" , listaPerros);
					if(exito==1)
					{
						printf("\nSe guardo en forma de texto con exito!\n\n");
					}else
					{
						printf("\nNo se logro guardar en forma de texto\n");
					}

				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}

				system("pause");
			break;

			case 9:

				if(banderaTexto==1 || banderaBinario==1)
				{
					exito=controller_saveAsBinary("src\\dataBinarioPerros.csv" ,listaPerros );
					if(exito==1)
					{
						printf("\nSe guardo en forma binaria con exito!\n\n");
					}else
					{
						printf("\nNo se logro guardar en forma binaria\n");
					}

				}else
				{
					printf("\nIngrese la opcion 1 primero o la 2\n");
				}
				system("pause");
			break;

			case 10:
					printf("\nFinalizado\n");

			break;
        }
    }while(option != 10);
    return 0;
}

