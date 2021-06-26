#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Controller.h"
#include "LinkedList.h"
#include "UTN.h"

Employee* employee_new()
{
	Employee* this=NULL;
	this=(Employee*)malloc(sizeof(Employee));

	if(this!=NULL)
	{
		this->id=0;
		this->horasTrabajadas=0;
		this->sueldo=0;
		strcpy(this->nombre, " ");
	}

	return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* auxEmpleado=employee_new();

	if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		strcpy(auxEmpleado->nombre, nombreStr);
		auxEmpleado->id=atoi(idStr);
		auxEmpleado->horasTrabajadas=atoi(horasTrabajadasStr);
		auxEmpleado->sueldo=atoi(sueldoStr);
	}

	return auxEmpleado;
}

void employee_delete(Employee* auxEmpleado)
{
	if(auxEmpleado!=NULL)
	{
		free(auxEmpleado);
	}
}

int employee_setId(Employee* this, int id)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->id=id;
		retorno=0;
	}

	return retorno;
}

int employee_getId(Employee* this, int* id)
{
	int retorno=-1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}

	return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int retorno=-1;

	if(this!=NULL)
	{
		strcpy(this->nombre, nombre);
		retorno=0;
	}

	return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int retorno=-1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;

	if(this!=NULL)
	{
		this->sueldo=sueldo;
		retorno=0;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno=-1;

	if(this!=NULL && sueldo!=NULL)
	{
		*sueldo=this->sueldo;
		retorno=0;
	}

	return retorno;
}

int employee_sortId(void* empleadoUno, void* empleadoDos)
{
	int retorno=-1;
	Employee* primerEmpleado=(Employee*)empleadoUno;
	Employee* segundoEmpleado=(Employee*)empleadoDos;

	if(empleadoUno!=NULL && empleadoDos!=NULL)
	{
		if(primerEmpleado->id > segundoEmpleado->id)
		{
			retorno=0;
		}
		else if(primerEmpleado->id < segundoEmpleado->id)
		{
			retorno=1;
		}
	}
	return retorno;
}

int employee_sortNombre(void* empleadoUno, void* empleadoDos)
{
	int retorno=-1;
	Employee* primerEmpleado=(Employee*)empleadoUno;
	Employee* segundoEmpleado=(Employee*)empleadoDos;

	if(empleadoUno!=NULL && empleadoDos!=NULL)
	{
		if(strcmp(primerEmpleado->nombre, segundoEmpleado->nombre)>0)
		{
			retorno=0;
		}
		else if(strcmp(primerEmpleado->nombre, segundoEmpleado->nombre)<0)
		{
			retorno=1;
		}
	}

	return retorno;
}

int employee_sortSueldo(void* empleadoUno, void* empleadoDos)
{
	int retorno=-1;
	Employee* primerEmpleado=(Employee*)empleadoUno;
	Employee* segundoEmpleado=(Employee*)empleadoDos;

	if(empleadoUno!=NULL && empleadoDos!=NULL)
	{
		if(primerEmpleado->sueldo > segundoEmpleado->sueldo)
		{
			retorno=0;
		}
		else if(primerEmpleado->sueldo < segundoEmpleado->sueldo)
		{
			retorno=1;
		}
	}

	return retorno;
}

int employee_sortHorasTrabajadas(void* empleadoUno, void* empleadoDos)
{
	int retorno=-1;
	Employee* primerEmpleado=(Employee*)empleadoUno;
	Employee* segundoEmpleado=(Employee*)empleadoDos;

	if(empleadoUno!=NULL && empleadoDos!=NULL)
	{
		if(primerEmpleado->horasTrabajadas > segundoEmpleado->horasTrabajadas)
		{
			retorno=0;
		}
		else if(primerEmpleado->horasTrabajadas > segundoEmpleado->horasTrabajadas)
		{
			retorno=1;
		}
	}

	return retorno;
}

int employee_buscarId(LinkedList* listaEmpleados, int idBuscado)
{
	int index;
	int i;
	Employee* auxiliarEId;

	if(listaEmpleados!=NULL)
	{
		for(i=0; i<ll_len(listaEmpleados); i++)
		{
			auxiliarEId=(Employee*)ll_get(listaEmpleados, i);
			if(auxiliarEId->id==idBuscado)
			{
				index=i;
				break;
			}
		}
	}

	return index;
}

int employee_imprimirEmpleado(Employee* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		printf("-> ID: %d | Nombre: %s | Horas trabajadas: %d | Sueldo: %d", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
		retorno=0;
	}


	return retorno;
}

int employee_idAutomatico(LinkedList* pArrayListEmployee, int* idAutomatico)
{
	int retorno=-1;
	int tamArray;
	Employee* auxiliarEmpleadoId;

	tamArray=ll_len(pArrayListEmployee);

	if(pArrayListEmployee!=NULL)
	{
		if(tamArray!=0)
		{
			auxiliarEmpleadoId=ll_get(pArrayListEmployee, tamArray-1);
			*idAutomatico=auxiliarEmpleadoId->id+1;
			retorno=0;
		}
	}

	return retorno;
}
