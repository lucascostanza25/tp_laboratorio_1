/*
Trabajo practico Nro 2: Nomina de empleados

Costanza, Lucas
Division 1B
*/

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define T 1000

int main(void) {
	setbuf(stdout, NULL);
	eEmployee listaDeEmpleados[T];
	inicializarEmpleados(listaDeEmpleados, T);
	int idEmpleado=0;
	int menu;
	int res;

	do
	{
		printf("-- NOMINA DE EMPLADOS --\n"
				"(TP Nro 2 - Lucas Costanza)\n"
				"\n1.Dar de alta empleados\n"
				"2.Modificar empleados\n"
				"3.Dar de baja empleados\n"
				"4.Ordenar empleados\n"
				"5.Listado de empleados\n"
				"\nIngrese  una opcion: ");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1:
				system("cls");
				res=cargarEmpleados(listaDeEmpleados, T, &idEmpleado);
				if(res!=-1)
				{
					printf("\nEmpleado agregado con exito!\n");
				}
				else
				{
					printf("\nNo hay mas espacio para agregar empleados!\n");
				}
				system("pause");
			break;

			case 2:
				system("cls");
				if(modificarEmpleado(listaDeEmpleados, T)!=-1)
				{
					printf("Empleado modificado con exito!\n");
				}
				else
				{
					printf("Se cancelo la modificacion del empleado!\n");
				}
				system("pause");
			break;

			case 3:
				system("cls");
				if(darDeBajaEmpleado(listaDeEmpleados, T)!=-1)
				{
					printf("Empleado dado de baja con exito!\n");
				}
				else
				{
					printf("Se cancelo la baja del empleado!\n");
				}
				system("pause");
			break;

			case 4:
				system("cls");
				if(ordenarEmpleados(listaDeEmpleados, T)!=-1)
				{
					mostrarListadoDeEmpleados(listaDeEmpleados, T);
				}
				else
				{
					printf("Se cancelo el ordenamiento de los empleados!\n");
				}
				system("pause");
			break;

			case 5:
				system("cls");
				if(mostrarListadoDeEmpleados(listaDeEmpleados, T)!=-1)
				{
					printf("\nListado de empleados!\n");
				}
				else
				{
					printf("No hay empleados disponibles para mostrar!\n");
				}
				system("pause");
			break;
		}
		system("cls");
	}while(menu!=0);

	return EXIT_SUCCESS;
}
