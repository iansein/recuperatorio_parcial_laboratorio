#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Trabajo.h"
#include "Structs.h"
#include "Servicio.h"
#include "Input.h"

/** \brief Muestra un listado de los servicios existentes
 *
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \return void
 */
void MostrarListadoDeServicios(eServicio servicioMascota[], int tamServicio)
{
    int i;
    for(i=0;i<tamServicio;i++)
    {
        printf("\nSERVICIO : %s | PRECIO : %d\n", servicioMascota[i].descripcionServicio, servicioMascota[i].precio);

    }
}

/** \brief Muestra un listado de los servicios con sus respectivos ID's
 *
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \return void
 */
void MostrarListadoServicioConId(eServicio servicioMascota[], int tamServicio)
{
    int i;

    for(i=0;i<tamServicio;i++)
    {
        printf("\nID : %d | SERVICIO : %s | PRECIO : %d\n\n", servicioMascota[i].idServicio, servicioMascota[i].descripcionServicio, servicioMascota[i].precio);

    }

}


/** \brief Permite al usuario elegir exclusivamente entre 3 opciones de servicio
 *
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \return int idServicio
 */

int ElegirIdServicio(eServicio servicioMascota[], int tamServicio)
{
    int idServicio;

    MostrarListadoServicioConId(servicioMascota, tamServicio);
    idServicio = GetInt("\nIngrese la ID del servicio\n");

    while(idServicio != 20000 && idServicio != 20001 && idServicio != 20002)
    {
        MostrarListadoServicioConId(servicioMascota, tamServicio);
        idServicio = GetInt("\nError : Reingrese la ID del servicio\n");
    }

    return idServicio;
}

/** \brief Muestra un listado de el/los servicios mas utilizados en un trabajo
 *
 *  \param eServicio servicioMascota[]
 *  \return void
 */

void MostrarServicioMasUtilizado(eServicio servicioMascota)
{
	printf("\nEl servicio con mas trabajos realizados fue : %s\n", servicioMascota.descripcionServicio);
}

/** \brief Obtiene una estructura de servicio por ID
 *
 *  \param eServicio servicioMascota[]
 *  \param eTrabajo trabajoMascota
 *  \param int tamServicio
 *  \return eServicio auxServicio
 *
 */
eServicio ObtenerServicioPorID(eServicio servicioMascota[], eTrabajo trabajoMascota, int tamServicio)
{
	eServicio auxServicio;

	int i;

	for(i=0;i<tamServicio;i++)
	{
		if(trabajoMascota.idServicio == servicioMascota[i].idServicio)
		{
			auxServicio = servicioMascota[i];
		}
	}

	return auxServicio;
}

