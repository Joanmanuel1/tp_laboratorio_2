#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"
#include "empleado.h"
#define MAX_EMPLEADOS 1000

/**
*   Una empresa requiere un sistema para administrar su n�mina de empleados. Se sabe que
*   dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
*   Datos:

*   El sistema deber� tener el siguiente men� de opciones:
*   1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
*   de Id. El resto de los campos se le pedir� al empleado.
*   2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
*   o Salario o Sector
*   3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
*   4. INFORMAR:
*   1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
*   2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
*   NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
*   Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
*   carga de alg�n empleado.
*   Para la realizaci�n de este programa, se utilizar� una biblioteca llamada �empleado� que
*   facilitar� el manejo de la lista de empleados y su modificaci�n. En la secci�n siguiente se
*   detallan las funciones que esta biblioteca debe tener.
*/

int main()
{
    eEmpleado arrayEmpleados[MAX_EMPLEADOS];
    int menu;
    int auxiliarId;
    int ret;

    empleado_init(arrayEmpleados,MAX_EMPLEADOS);

    do
    {

        system("cls");
        printf("1. Alta de empleado \n");
        printf("2. Baja de empleado \n");
        printf("3. Modificar empleado \n");
        printf("4. Informe \n");
        printf("5. Salir \n");

        getValidInt("\nIngrese opcion :","Dato ingresado erroneo\n",&menu,1,5,1);
        switch (menu)
        {
        case 1:
            ret=empleado_alta(arrayEmpleados,MAX_EMPLEADOS);
            if(ret!=0)
            {
                printf("No se pudo dar de alta el empleado \n");
            }

            break;
        case 2:
            getValidInt("ID?","\nnumero invalido\n",&auxiliarId,0,2000,2);
            ret=empleado_baja(arrayEmpleados,MAX_EMPLEADOS, auxiliarId);
            if(ret!=0)
            {
                printf("No existe el id \n");
            }

            break;
        case 3:
            getValidInt("ID?","\nNumero invalido\n",&auxiliarId,0,100,2);
            ret=empleado_modificacion(arrayEmpleados,MAX_EMPLEADOS, auxiliarId);
            if(ret!=0)
            {
                printf("No existe el id \n");
            }

            break;
        case 4:
            empleado_ordenar(arrayEmpleados,MAX_EMPLEADOS,0);
            empleado_mostrar(arrayEmpleados,MAX_EMPLEADOS);
            empleado_informe(arrayEmpleados, MAX_EMPLEADOS);
            break;
        }

        system("pause");
    }
    while(menu != 5);

    return 0;
}
