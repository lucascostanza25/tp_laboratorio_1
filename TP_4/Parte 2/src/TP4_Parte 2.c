#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN.h"

int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int flagFileTexto=0;
    int flagFileBin=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        utn_getNumero(&option, "-- TP Nro 3 --\n"
		"1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
		"2.Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n"
		"3.Alta de empleado\n"
		"4.Modificar datos de empleado\n"
		"5.Baja de empleado\n"
		"6.Listar empleados\n"
		"7.Ordenar empleados\n"
		"8.Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
		"9.Guardar los datos de los empleados en el archivo data.bin (modo binario)\n"
		"10.Salir\n"
		"\nSeleccione una opcion: ", "Error, numero incorrecto", 1, 10, 2);
        system("cls");
        switch(option)
        {
            case 1:
                if(!controller_loadFromText("../data.csv", listaEmpleados))
                {
                	printf("Archivo cargado con exito!\n");
                	flagFileTexto=1;
                }
                else
                {
                	printf("No se pudo leer el archivo!\n");
                }
                system("pause");
            break;

            case 2:
            	if(!controller_loadFromBinary("../data.bin", listaEmpleados))
            	{
            		printf("Archivo cargado con exito!\n");
            		flagFileBin=1;
            	}
            	else
				{
					printf("No se pudo leer el archivo!\n");
				}
            	system("pause");
            break;

            case 3:
            	if(flagFileTexto==1 || flagFileBin==1)
            	{
					if(controller_addEmployee(listaEmpleados)!=-1)
					{
						printf("Empleado dado de alta exitosamente!\n");
					}
            	}
            	else
            	{
            		printf("Primero cargue el archivo .cvs o .bin!\n");
            	}
            	system("pause");
            break;

            case 4:
            	if(flagFileTexto==1 || flagFileBin==1)
            	{
            		controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Primero cargue el archivo .cvs o .bin!\n");
            	}
            	system("pause");
            break;

            case 5:
            	if(flagFileTexto==1 || flagFileBin==1)
            	{
            		if(controller_removeEmployee(listaEmpleados)!=-1)
            		{
            			printf("Empleado dado de baja exitosamente!\n");
            		}
            	}
            	else
            	{
            		printf("Primero cargue el archivo .cvs o .bin!\n");
            	}
            	system("pause");
            break;

            case 6:
            	if(controller_ListEmployee(listaEmpleados)!=-1)
            	{
            		printf("Lista de empleados dados de alta!\n");
            	}
            	system("pause");
            break;

            case 7:
            	if(flagFileTexto==1 || flagFileBin==1)
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("Primero cargue el archivo .cvs o .bin!\n");
            	}
            	system("pause");
            break;

            case 8:
            	if(controller_saveAsText("../data.csv", listaEmpleados)!=-1)
            	{
            		printf("Cambios guardados exitosamente!\n");
            	}
            	system("pause");
            break;

            case 9:
            	if(controller_saveAsBinary("../data.bin", listaEmpleados)!=-1)
            	{
            		printf("Cambios guardados exitosamente!\n");
            	}
            	system("pause");
            break;

            case 10:
            	utn_getNumero(&option, "Desea salir del programa?\nATENCION! Todos los progresos no guardados se perderan!\n\n1.Si\n2.No\n\nSeleccione una opcion: ", "Error, numero incorrecto", 1, 2, 0);
            	if(option==1)
            	{
            		option=10;
            	}
            break;
        }
        system("cls");
    }while(option != 10);
    return 0;
}

