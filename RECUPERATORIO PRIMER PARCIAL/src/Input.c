#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Input.h"

/** \brief Devuelve un numero entero
 *
 *  \param char mensaje[]
 *  \return int numeroIngresado
 *
 */

int GetInt(char mensaje[])
{
    int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}

/** \brief Asigna valor al string
 *
 *  \param char* mensaje
 *  \param char* string
 *  \return void
 *
 */
void GetString(char *mensaje, char *string)
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", string);
}

/** \brief Valida un rango entre 2 numeros
 *
 *  \param char mensaje[]
 *  \param int numeroMaximoPosible
 *  \param int numeroMinimoPosible
 *  \param int numeroIngresado
 *  \return int numeroIngresado
 *
 */

int ValidarUnRango(char mensaje[], int numeroMaximoPosible, int numeroMinimoPosible, int numeroIngresado)
{
    while(numeroIngresado > numeroMaximoPosible || numeroIngresado < numeroMinimoPosible)
    {
        numeroIngresado = GetInt(mensaje);
    }

    return numeroIngresado;
}

/** \brief Menu principal de opciones
 *
 *  \param void
 *  \return int opcion
 */

int MenuPrincipal(void)
{
    int opcion;

    printf("\n\nVETERINARIA SEIN\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificacion\n");
    printf("4- Listado trabajos\n");
    printf("5- Listado servicios\n");
    printf("6- Precio total por servicios\n");
    printf("7- Submenu para las mascotas\n");
    printf("8- Listado de todos los trabajos ordenados por nombre de mascota\n");
    printf("9- El o los servicios con mas trabajos realizados\n");
    printf("10- Listado de servicios con el nombre de las mascotas que se lo realizaron\n");
    printf("11- Promedio de edades de las mascotas que realizaron un servicio elegido por el usuario\n");
    printf("12- Listado de ganancias futuras y mascotas por cada sucursal\n");
    printf("13- Listado de turnos con sus respectivas sucursales, nombres, servicios y la totalidad de turnos en general\n");
    printf("14- Salir\n");
    printf("-------------------------\n");
    opcion = GetInt("Ingrese una opcion\n");

    return opcion;
}

/** \brief Submenu de opciones
 *
 *  \param void
 *  \return int opcion
 */
int SubMenu(void)
{
    int opcion;

    printf("---------- MASCOTAS ----------\n");
    printf("1- ALTA\n");
    printf("2- BAJA\n");
    printf("3- MODIFICACION\n");
    printf("4- LISTADO DE MASCOTAS\n");
    printf("5- SALIR\n");
    printf("------------------------------\n");
    opcion = GetInt("Ingrese una opcion\n");

    return opcion;
}


