#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN.h"
#define T_ID 2000


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pArchivo=fopen(path, "r");

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(pArchivo!=NULL)
		{
			parser_EmployeeFromText(pArchivo, pArrayListEmployee);
			retorno=0;
			fclose(pArchivo);
		}
	}

    return retorno;
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
	int retorno=-1;
	FILE* pArchivo=fopen(path, "rb");

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if(pArchivo!=NULL)
		{
			parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
			fclose(pArchivo);
			retorno=0;
		}
	}

	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int auxIdE, auxSueldoE, auxHsE;
	char nombreEmpleado[50];
	Employee* nuevoEmpleado;


	if(pArrayListEmployee!=NULL)
	{
		nuevoEmpleado=employee_new();
		utn_getNumero(&auxIdE, "Ingrese el ID del empleado: ", "Error", 1, 10000, 4);
		utn_getString(nombreEmpleado, "Ingrese el nombre del empleado: ", "Error, se excedio la longitud!\n", 50, 2);
		utn_getNumero(&auxSueldoE, "Ingrese el sueldo del empleado (de $1 a $10000): ", "Error, sueldo fuera de rango!\n", 1, 10000, 4);
		utn_getNumero(&auxHsE, "Ingrese las horas trabajadas del empleado: ", "Error, horas fuera de rango!\n", 0, 10000, 4);

		employee_setId(nuevoEmpleado, auxIdE);
		employee_setNombre(nuevoEmpleado, nombreEmpleado);
		employee_setSueldo(nuevoEmpleado, auxSueldoE);
		employee_setHorasTrabajadas(nuevoEmpleado, auxHsE);

		ll_add(pArrayListEmployee, nuevoEmpleado);

		retorno=0;
	}


    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int menuModificacion;
	int indexId;
	int idIngresado;
	int nuevoSueldo;
	int nuevoHoras;
	char nuevoNombre[50];
	Employee* empleadoEditado;

	if(pArrayListEmployee!=NULL)
	{
		printf("-- EDITAR --\n"
				"Lista de empleados disponibles para editar\n");
		controller_ListEmployee(pArrayListEmployee);
		utn_getNumero(&idIngresado, "Ingrese el ID del empleado a editar: ", "Error", 1, T_ID, 4);
		system("cls");
		indexId=employee_buscarId(pArrayListEmployee, idIngresado);
		if(indexId!=-1)
		{
			empleadoEditado=(Employee*)ll_get(pArrayListEmployee, idIngresado);
			printf("Empleado seleccionado\n");
			employee_imprimirEmpleado((Employee*)ll_get(pArrayListEmployee, idIngresado));
			printf("\nSeleccione que desea editar\n"
					"1.Nombre\n"
					"2.Horas\n"
					"3.Sueldo\n");
			utn_getNumero(&menuModificacion, "Seleccione una opcion: ", "Error, opcion invalida\n", 1, 3, 4);
			system("cls");
			switch(menuModificacion)
			{
				case 1:
					utn_getString(nuevoNombre, "Ingrese el nuevo nombre: ", "Error, limite excedido", 50, 4);
					employee_setNombre(empleadoEditado, nuevoNombre);
					retorno=0;
				break;

				case 2:
					utn_getNumero(&nuevoHoras, "Ingrese las horas trabajadas: ", "Error! Fuera de rango\n", 1, 10000, 4);
					employee_setHorasTrabajadas(empleadoEditado, nuevoHoras);
					retorno=0;
				break;

				case 3:
					utn_getNumero(&nuevoSueldo, "Ingrese el sueldo: ", "Error! fuera de rango\n", 1, 10000, 4);
					employee_setSueldo(empleadoEditado, nuevoSueldo);
					retorno=0;
				break;
			}
		}
		else
		{
			printf("No se encontro a ningun empleado con ese ID!\n");
		}

	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int idIngresado;
	int indexId;
	int opcionBorrado;

	if(pArrayListEmployee!=NULL)
	{
		printf("-- DAR DE BAJA --\nEmpleados disponibles para dar de baja\n");
		controller_ListEmployee(pArrayListEmployee);
		utn_getNumero(&idIngresado, "Ingrese el id del empleado a dar de baja: ", "Erro! fuera de rango\n", 1, T_ID, 4);
		indexId=employee_buscarId(pArrayListEmployee, idIngresado);
		system("cls");
		if(indexId!=-1)
		{
			printf("Empleado seleccionado para dar de baja\n");
			employee_imprimirEmpleado((Employee*)ll_get(pArrayListEmployee, idIngresado));
			utn_getNumero(&opcionBorrado, "\n1.Si\n2.No\nSeleccione una opcion: ", "Error! Fuera de rango\n", 1, 2, 4);
			if(opcionBorrado==1)
			{
				if(!ll_remove(pArrayListEmployee, indexId))
				{
					retorno=0;
				}
			}
		}
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	int auxId;
	int auxSueldo;
	int auxHoras;
	char auxNombre[50];
	Employee* auxEmpleado;

	if(pArrayListEmployee!=NULL)
	{
		printf("ID  | NOMBRE            | SUELDO    | HORAS\n");

		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			auxEmpleado=ll_get(pArrayListEmployee, i);
			employee_getHorasTrabajadas(auxEmpleado, &auxHoras);
			employee_getId(auxEmpleado, &auxId);
			employee_getSueldo(auxEmpleado, &auxSueldo);
			employee_getNombre(auxEmpleado, auxNombre);
			printf("%d %8s %18d %10d\n", auxId, auxNombre, auxSueldo, auxHoras);
		}
		retorno=0;
	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int menuOrdenamiento;

	if(pArrayListEmployee!=NULL)
	{
		utn_getNumero(&menuOrdenamiento, "-- ODENAR --\n"
				"1.ID ascendente\n"
				"2.ID descendiente\n"
				"3.Nombre ascendente\n"
				"4.Nombre descendente\n"
				"5.Sueldo ascendente\n"
				"6.Sueldo descendente\n"
				"7.Horas ascendente\n"
				"8.Horas descendente\n"
				"Seleccione una opcion: ", "Error, opcion incorrecta\n", 1, 8, 4);
		switch(menuOrdenamiento)
		{
			case 1:
				ll_sort(pArrayListEmployee, employee_sortId, 0);
			break;

			case 2:
				ll_sort(pArrayListEmployee, employee_sortId, 1);
			break;

			case 3:
				ll_sort(pArrayListEmployee, employee_sortNombre, 0);
			break;

			case 4:
				ll_sort(pArrayListEmployee, employee_sortNombre, 1);
			break;

			case 5:
				ll_sort(pArrayListEmployee, employee_sortSueldo, 0);
			break;

			case 6:
				ll_sort(pArrayListEmployee, employee_sortSueldo, 1);
			break;

			case 7:
				ll_sort(pArrayListEmployee, employee_sortHorasTrabajadas, 0);
			break;

			case 8:
				ll_sort(pArrayListEmployee, employee_sortHorasTrabajadas, 1);
			break;
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int i;
	FILE* pArchivo;
	Employee* empleadoGuardado;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		pArchivo=fopen(path, "w");
		if(pArchivo!=NULL)
		{
			fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
			for(i=0; i<ll_len(pArrayListEmployee); i++)
			{
				empleadoGuardado=(Employee*)ll_get(pArrayListEmployee, i);
				fprintf(pArchivo, "%d,%s,%d,%d\n", empleadoGuardado->id, empleadoGuardado->nombre, empleadoGuardado->horasTrabajadas, empleadoGuardado->sueldo);
				retorno=0;
			}
			fclose(pArchivo);
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	FILE* pArchivo;
	Employee* empleadoBinario;
	int i;

	if(pArrayListEmployee!=NULL && path!=NULL)
	{
		pArchivo=fopen(path, "wb");

		if(pArchivo!=NULL)
		{
			for(i=0; i<ll_len(pArrayListEmployee); i++)
			{
				fwrite(empleadoBinario, sizeof(Employee), 1, pArchivo);
			}
		}
	}

	return retorno;
}


