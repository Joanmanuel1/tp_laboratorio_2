#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "utn.h"

static int buscarLugarLibre(eEmpleado* array,int tam);
static int proximoId();

/**
*   \brief Inicializa el array de empleados.
*   \param Recibe un puntero de array de empleados.
*   \param Recibe el tamaño.
*   \return Retorna codigo de retorno.
*/

int empleado_init(eEmpleado* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            array[i].isEmpty = 0;
        }
    }
    return retorno;
}

/**
*   \brief Busca un lugar libre en el array de empleados.
*   \param Recibe un puntero de array de empleados.
*   \param Recibe el tamaño.
*   \return Retorna codigo de retorno.
*/


static int buscarLugarLibre(eEmpleado* array,int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0; i<tam; i++)
        {
            if(array[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
*   \brief Da de alta a un empleado en el array de empleados.
*   \param Recibe un puntero de array de empleados.
*   \param Recibe el tamaño.
*   \return Retorna codigo de retorno.
*/


int empleado_alta(eEmpleado* array,int tam)
{
    int retorno = -1;
    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int isEmpty;
    int id;
    int indice = buscarLugarLibre(array,tam);

    system("cls");
    printf(" Alta de empleado \n\n");

    if(tam > 0 && array != NULL)
    {
        retorno = -2;

        if(indice >= 0)
        {
            id = proximoId();
            retorno = -3;
            if(!getValidString(" Name        :"," Dato ingresado erroneo\n"," Overflow", name,50,2))
            {
                if(!getValidString(" Last name   :"," Dato ingresado erroneo\n","Overflow", lastName,50,2))
                {
                    if(!getValidFloat( " Salary      :"," Dato ingresado erroneo\n",&salary,0,200000,2))
                    {
                        if(!getValidInt(   " Sector      :"," Dato ingresado erroneo\n",&sector,0,999,2))
                        {
                            retorno = 0;

                            strcpy(array[indice].name,name);
                            strcpy(array[indice].lastName,lastName);
                            array[indice].sector=sector;
                            array[indice].salary=salary;

                            array[indice].id = id;
                            array[indice].isEmpty = 1;

                        }
                    }
                }
            }
        }
    }
    return retorno;
}

/**
*   \brief Modifica un empleado en el array de empleados.
*   \param Recibe un puntero de array de empleados.
*   \param Recibe el tamaño.
*   \param Recibe el ID del empleado.
*   \return Retorna codigo de retorno.
*/


int empleado_modificacion(eEmpleado* array,int tam, int id)
{
    int retorno = -1;
    char name[50];
    char lastName[50];
    float salary;
    int sector;
    int isEmpty;
    int indice = empleado_buscarPorId(array,tam,id);

    system("cls");
    printf(" Modificacion de un empleado \n\n");

    if(indice >= 0)
    {
        retorno = -2;

        if(!getValidString(" Name        :"," Dato ingresado erroneo\n","Overflow", name,50,2))
        {
            if(!getValidString(" Last name   :"," Dato ingresado erroneo\n","Overflow", lastName,50,2))
            {
                if(!getValidFloat( " Salary      :"," Dato ingresado erroneo\n",&salary,0,200000,2))
                {
                    if(!getValidInt(   " Sector      :"," Dato ingresado erroneo\n",&sector,0,999,2))
                    {
                        retorno = 0;

                        strcpy(array[indice].name,name);
                        strcpy(array[indice].lastName,lastName);
                        array[indice].sector=sector;
                        array[indice].salary=salary;
                    }
                }
            }
        }
        return retorno;
    }
}

/**
*   \brief Realiza la baja a un empleado en el array de empleados.
*   \param Recibe un puntero de array de empleados.
*   \param Recibe el tamaño.
*   \param Recibe el ID del empleado.
*   \return Retorna codigo de retorno.
*/


int empleado_baja(eEmpleado* array,int tam, int id)
{

    int retorno = -1;
    int indice;
    indice = empleado_buscarPorId(array,tam,id);

    system("cls");
    printf(" Baja de empleado \n\n");

    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = 0;
    }
    return retorno;
}

/**
*   \brief Muestra un listado de empleados.
*   \param Recibe un puntero de array de empleados.
*   \param Recibe el tamaño.
*   \return Retorna codigo de retorno.
*/


int empleado_mostrar(eEmpleado* array,int tam)
{
    int retorno = -1;
    int i;

    system("cls");
    printf(" Lista de empleados \n");
    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            if(array[i].isEmpty == 1)
            {
                printf("\n Apellido y Nombre: %s %s - Sector: %d ",array[i].lastName,array[i].name, array[i].sector);
            }
        }
    }
    return retorno;

}

/**
*   \brief Ordena el array de empleados por nombre.
*   \param Recibe un puntero de array de empleados.
*   \param Recibe el tamaño.
*   \param Recibe el orden.
*   \return Retorna codigo de retorno.
*/


int empleado_ordenar(eEmpleado* array,int tam, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;

    eEmpleado auxiliar;

    if(tam > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0; i<tam-1; i++)
            {
                if(array[i].isEmpty == 1 && array[i+1].isEmpty == 1 )
                {
                    if((strcmp(array[i].lastName,array[i+1].lastName) > 0 && !orden) || (strcmp(array[i].lastName,array[i+1].lastName) < 0 && orden)) //<------------
                    {
                        auxiliar = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliar;
                        flagSwap = 1;
                    }
                    if(!strcmp(array[i].lastName,array[i+1].lastName))
                    {
                        if(array[i].sector > array[i+1].sector && !orden || array[i].sector < array[i+1].sector && orden) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                        }
                    }
                }
            }
        }
        while(flagSwap);
    }

    return retorno;
}

/**
*   \brief Busca un empleado por ID en el array de empleados.
*   \param Recibe un puntero de array de empleados.
*   \param Recibe el tamaño.
*   \param Recibe el ID del empleado.
*   \return Retorna codigo de retorno.
*/


int empleado_buscarPorId(eEmpleado* array,int tam, int id)
{
    int retorno = -1;
    int i;
    if(array > 0 && array != NULL)
    {
        retorno = -2;

        for(i=0; i<tam; i++)
        {

            if(array[i].isEmpty == 1 && array[i].id == id)
            {
                printf("1. Alta de empleado \n");
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
*   \brief Busca el proximo ID libre.
*   \return Retorna el ultimo ID.
*/


static int proximoId()
{
    static int ultimoId = 0;
    ultimoId++;
    return ultimoId;
}

/**
*   \brief Muestra el informe de la cantidad de empleados,
           el salario promedio y los empleados con salario superior al promedio.
*   \param Recibe un puntero de array de empleados.
*   \param Recibe el tamaño.
*   \return Retorna codigo de retorno.
*/


int empleado_informe(eEmpleado* array, int tam)
{
    int contadorEmpleados=0;
    float acumuladorSalario=0;
    int i;
    float promedio = 0;
    int retorno = -1;
    int salarioSuperiorAlPromedio=0;
    int flag = 0;


    printf("\n \n Informe: \n");

    if(tam > 0 && array != NULL)
    {

        for(i=0; i<tam; i++)
        {
            if(array[i].isEmpty == 1)
            {
                acumuladorSalario = acumuladorSalario + array[i].salary;
                contadorEmpleados++;
                flag = 1;
                retorno = 0;
            }
        }
        if(flag == 1)
        {
            promedio= acumuladorSalario/contadorEmpleados;
        }
        for(i=0; i<tam; i++)
        {
            if(array[i].isEmpty == 1)
            {
                if(array[i].salary > promedio)
                {
                    salarioSuperiorAlPromedio++;
                }
            }
        }
        printf("\n Cantidad de empleados: %d \n Total salario: %.2f \n Salario promedio: %.2f \n Empleados con salario mayor al promedio: %d \n",contadorEmpleados, acumuladorSalario,promedio,salarioSuperiorAlPromedio);
    }
    return retorno;
}
