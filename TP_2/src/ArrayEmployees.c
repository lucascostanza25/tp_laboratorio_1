/*
 * ArrayEmployees.c
 *
 *  Created on: 8 may. 2021
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "ArrayEmployees.h"

#define T 1000
#define LIBRE 0
#define OCUPADO 1



eEmployee pedirDatosEmpleado()
{
	eEmployee miEmpleado;

	utn_getString(miEmpleado.nameEmployee, "Ingrese el primer nombre del empleado: ", "\nError!\n", 21, 5);

	utn_getString(miEmpleado.lastNameEmployee, "Ingrese el apellido del  empleado: ", "\nError!\n", 21, 5);

	utn_getFlotante(&miEmpleado.salaryEmployee, "Ingrese el salario del empleado (de 1 a 2000): ", "Error, salario incorrecto\n", 1, 2000, 4);

	utn_getNumero(&miEmpleado.sectorEmployee, "Ingrese el sector del empleado (de 1 al 5): ", "Error, sector incorrecto\n", 1, 5, 4);

	miEmpleado.isEmpty=OCUPADO;

	return miEmpleado;
}



void inicializarEmpleados(eEmployee *listaDeEmpleados, int tam)
{
	int i;

	for(i=0; i<tam; i++)
	{
		listaDeEmpleados[i].isEmpty=LIBRE;
	}
}

int buscarEmpleadosLibres(eEmployee *listaDeEmpleados, int  tam)
{
	int i;
	int index=-1;

	for(i=0; i<tam; i++)
	{
		if(listaDeEmpleados[i].isEmpty==LIBRE)
		{
			index=i;
			break;
		}
	}
	return index;
}

int cargarEmpleados(eEmployee *listaDeEmpleados, int tam, int *idAutomatico)
{
	int i;
	i=buscarEmpleadosLibres(listaDeEmpleados, tam);

	if(i!=-1)
	{
		listaDeEmpleados[i]=pedirDatosEmpleado();
		listaDeEmpleados[i].idEmployee=*idAutomatico+1;
		*idAutomatico=listaDeEmpleados[i].idEmployee;
	}
	return i;
}

void mostrarUnEmpleado(eEmployee unEmpleado)
{
	printf("%d %s %s %f %d\n",
			unEmpleado.idEmployee,
			unEmpleado.nameEmployee,
			unEmpleado.lastNameEmployee,
			unEmpleado.salaryEmployee,
			unEmpleado.sectorEmployee);
}

int mostrarListadoDeEmpleados(eEmployee *listaDeEmpleados, int tam)
{
	int i;
	int retorno=-1;

	for(i=0; i<tam; i++)
	{
		if(listaDeEmpleados[i].isEmpty==OCUPADO)
		{
			mostrarUnEmpleado(listaDeEmpleados[i]);
			retorno=0;
		}
	}

	return retorno;
}

int darDeBajaEmpleado(eEmployee *listaDeEmpleados, int tam)
{
	int idIngresado;
	int i;
	int eleccion;
	int retorno=-1;

	if(listaDeEmpleados->isEmpty==OCUPADO)
	{
		printf("Lista de empleados disponibles para dar de baja\n");
		mostrarListadoDeEmpleados(listaDeEmpleados, tam);
		utn_getNumero(&idIngresado, "Ingrese el ID del empleado a dar de baja: ", "Error, ID incorrecto\n", 1, 1000, 4);

		for(i=0; i<tam; i++)
		{
			if(idIngresado==listaDeEmpleados[i].idEmployee)
			{
				printf("Desea confirmar la baja de '%s', ID Nro: %d\n"
						"1.SI\n"
						"2.NO\n"
						"Seleccione una opcion: ", listaDeEmpleados[i].lastNameEmployee, idIngresado);
				scanf("%d", &eleccion);
				system("cls");

				if(eleccion==1)
				{
					listaDeEmpleados[i].isEmpty=LIBRE;
					retorno=0;
					break;
				}
				else
				{
					fflush(stdin);
					printf("Se cancelo la baja del empleado!\n");
					system("cls");
					break;
				}
			}
		}
	}
	else
	{
		printf("No hay empleados disponibles para dar de baja\n");
	}
	return retorno;
}

int modificarEmpleado(eEmployee *listaDeEmpleados, int tam)
{

	int idIngresado;
	int retorno=-1;
	int eleccion;
	int i;

	if(listaDeEmpleados->isEmpty==OCUPADO)
	{
		printf("Lista de empleados disponibles para modificar\n");
		mostrarListadoDeEmpleados(listaDeEmpleados, tam);
		utn_getNumero(&idIngresado, "Ingrese el ID del empleado a dar de baja: ", "Error, ID incorrecto\n", 1, 1000, 4);
		system("cls");
		for(i=0; i<tam; i++)
		{
			if(idIngresado==listaDeEmpleados[i].idEmployee)
			{
				printf("-- MODIFICAR EMPLEADO --\n"
						"1.Primer nombre\n"
						"2.Apellido\n"
						"3.Salario\n"
						"4.Sector\n"
						"0.Volver al menu principal\n"
						"Seleccione una opcion: ");
				scanf("%d", &eleccion);
				system("cls");
				if(eleccion!=0)
				{
					switch(eleccion)
					{
						case 1:
							utn_getString(listaDeEmpleados[i].nameEmployee, "Ingrese el primer nombre del  empleado: ", "Error!\n", 21, 5);
						break;

						case 2:
							utn_getString(listaDeEmpleados[i].lastNameEmployee, "Ingrese el apellido del  empleado: ", "Error!\n", 21, 5);
						break;

						case 3:
							utn_getFlotante(&listaDeEmpleados[i].salaryEmployee, "Ingrese el salario del empleado: ", "Error, salario incorrecto\n", 1, 2000, 4);
						break;

						case 4:
							utn_getNumero(&listaDeEmpleados[i].sectorEmployee, "Ingrese el sector del empleado del 1 al 5: ", "Error, sector incorrecto\n", 1, 5, 4);
						break;
					}
					retorno=0;
					system("cls");
				}
				else
				{
					fflush(stdin);
					printf("Se cancelo la modificacion del empleado!\n");
					system("cls");
					break;
				}
			}
		}
	}

	else
	{
		system("cls");
		printf("No hay empleados disponibles para dar de baja!\n");
	}

	return retorno;
}

int ordenarEmpleados(eEmployee *listaDeEmpleados, int tam)
{
	int i;
	int j;
	int retorno=-1;
	int eleccion;
	eEmployee auxEmpleado;
	eEmployee auxInt;

	if(listaDeEmpleados->isEmpty==OCUPADO)
	{
		printf("-- ORDENAR EMPLEDOS --\n"
				"1.Ordenar por apellido\n"
				"2.Ordenar por sector\n"
				"0.Volver al menu principal\n"
				"Seleccione una opcion: ");
		scanf("%d", &eleccion);
		if(eleccion!=0)
		{
			switch(eleccion)
			{
				case 1:
					system("cls");
					printf("Empleados ordenados por apellido\n");
					for(i=0; i<tam-1; i++)
						{
							for(j=i+1; j<tam; j++)
							{
								if(strcmp(listaDeEmpleados[i].lastNameEmployee, listaDeEmpleados[j].lastNameEmployee)>0)
								{
									auxEmpleado=listaDeEmpleados[i];
									listaDeEmpleados[i]=listaDeEmpleados[j];
									listaDeEmpleados[j]=auxEmpleado;
									break;
								}
							}
						}
				break;

				case 2:
					system("cls");
					printf("Empleados ordenados por sector\n");
					for(i=0; i<tam-1; i++)
					{
						for(j=i+1; j<tam; j++)
						{
							if(listaDeEmpleados[i].sectorEmployee > listaDeEmpleados[j].sectorEmployee)
							{
								auxInt=listaDeEmpleados[i];
								listaDeEmpleados[i]=listaDeEmpleados[j];
								listaDeEmpleados[j]=auxInt;
								break;
							}
						}
					}
				break;
			}
			retorno=0;
		}

	}
	else
	{
		printf("No hay empleados disponibles para ordenar!\n");
		retorno=1;
	}
	return retorno;
}

