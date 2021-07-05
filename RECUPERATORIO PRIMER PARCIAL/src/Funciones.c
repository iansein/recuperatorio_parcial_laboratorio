#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Funciones.h"
#include "Input.h"
#include "Trabajo.h"
#include "Mascota.h"
#include "Servicio.h"
#include "Sucursal.h"

/** \brief Muestra un trabajo
 *
 *  \param eTrabajo trabajoMascota
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return void
 *
 */

void MostrarUnTrabajo(eTrabajo trabajoMascota, eServicio servicioMascota[], int tamServicio, eMascota mascota[], int tamMascota, eSucursal sucursal[], int tamSuc)
{
    eServicio auxServicio;
    eMascota auxMascota;
    eSucursal auxSucursal;

    auxServicio = ObtenerServicioPorID(servicioMascota,trabajoMascota, tamServicio);
    auxMascota = ObtenerMascotaPorID(mascota, trabajoMascota, tamMascota);
    auxSucursal = ObtenerSucursalPorID(sucursal, trabajoMascota, tamSuc);

    printf("\nID TRABAJO : %d | NOMBRE : %s | EDAD : %d | RAZA : %s | SERVICIO : %s | PRECIO : %d | AÑO : %d | ID SUCURSAL : %d | SUCURSAL : %s \n", trabajoMascota.idTrabajo, auxMascota.nombreMascota, auxMascota.edad,
    																auxMascota.raza, auxServicio.descripcionServicio, auxServicio.precio,
																	trabajoMascota.fechaDelTrabajo.anio, auxSucursal.idSucursal, auxSucursal.direccionSucursal);

}

/** \brief Muestra un listado de todos los trabajos.
 *
 *  \param eTrabajo trabajoMascota
 *  \param int tam
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return void
 *
 */

void MostrarTodosLosTrabajos(eTrabajo trabajoMascota[], eServicio servicioMascota[], int tamServicio, int tam, eMascota mascota[], int tamMascota, eSucursal sucursal[], int tamSuc)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(trabajoMascota[i].isEmpty == 1)
        {
            MostrarUnTrabajo(trabajoMascota[i], servicioMascota, tamServicio, mascota, tamMascota, sucursal, tamSuc);
        }

    }
}

/** \brief Muestra un listado de los servicios con los nombres de las mascotas que lo utilizaron
 *
 *  \param eTrabajo trabajoMascota
 *  \param int tam
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return void
 *
 */

void ListadoServiciosConSusNombres(eTrabajo trabajoMascota[], int tam, eServicio servicioMascota[], int tamServicio, eMascota mascota[], int tamMascota)
{
	int i;
	int j;
	eMascota auxMascota;

	for(i=0;i<tamServicio;i++)
	{
		printf("\nSERVICIO : %s \n", servicioMascota[i].descripcionServicio);
		for(j=0;j<tam;j++)
		{
			if(trabajoMascota[j].idServicio == servicioMascota[i].idServicio && trabajoMascota[j].isEmpty == 1)
			{
				auxMascota = ObtenerMascotaPorID(mascota,trabajoMascota[j],tam);
				printf("%s\n", auxMascota.nombreMascota);
			}

		}
	}
}


/** \brief Muestra el listado de promedios de edad de las mascotas de cada servicio
 *
 *  \param eTrabajo trabajoMascota
 *  \param int tam
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \return void
 *
 */

void PromedioDeEdadesPorServicio(eTrabajo trabajoMascota[], int tam, eMascota mascota[], int tamMascota, eServicio servicioMascota[], int tamServicio)
{
	int i;
	int promedio[tamServicio];

	for(i=0;i<tamServicio;i++)
	{
		promedio[i] = ObtenerPromedioDeEdades(servicioMascota[i], trabajoMascota, tam, mascota, tamMascota);
	}

	for(i=0;i<tamServicio;i++)
	{
		printf("En %s el promedio de edad de las mascotas es : %d\n", servicioMascota[i].descripcionServicio, promedio[i]);
	}


}

/** \brief Obtiene el promedio de edad de mascotas por servicio
 *
 *  \param eServicio servicioMascota[]
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return int promedio
 *
 */

int ObtenerPromedioDeEdades(eServicio servicioMascota, eTrabajo trabajoMascota[], int tam, eMascota mascota[], int tamMascota)
{
	int contador;
	int acumulador;
	int promedio;
	int i;
	eMascota auxMascota;

	contador = 0;
	acumulador = 0;
	promedio = 0;


	for(i=0;i<tam;i++)
	{
		if(trabajoMascota[i].idServicio == servicioMascota.idServicio && trabajoMascota[i].isEmpty == 1)
		{
			auxMascota = ObtenerMascotaPorID(mascota, trabajoMascota[i], tamMascota);
			acumulador = acumulador + auxMascota.edad;
			contador++;
		}

	}

	if(contador > 0)
	{
		promedio = (acumulador / contador);
	}

	return promedio;
}

/** \brief Muestra el/los servicios que mas trabajos tuvieron
 *
 *  \param eTrabajo trabajoMascota
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \return void
 *
 */

void ServiciosConMasTrabajos(eTrabajo trabajoMascota[], int tam, eServicio servicioMascota[], int tamServicio)
{
	int contador[3] = {0,0,0};
	int i;

	int contadorMaximo;
	contadorMaximo = 0;


	for(i=0;i<tamServicio;i++)
	{
		contador[i] = ObtenerCantidadDeServicios(servicioMascota[i],trabajoMascota,tam);
	}

	for(i=0;i<tamServicio;i++)
	{
		if(contador[i] > contadorMaximo || i == 0)
		{
			contadorMaximo = contador[i];
		}
	}

	for(i=0;i<tamServicio;i++)
	{
		if(contador[i] == contadorMaximo)
		{
			 MostrarServicioMasUtilizado(servicioMascota[i]);
		}
	}
}

/** \brief Busca la existencia de un servicio para acumularlo.
 *
 *  \param eTrabajo trabajoMascota
 *  \param eServicio servicioMascota[]
 *  \param int tam
 *  \return int contador // contador > 0 (Se utilizo el servicio) / contador == 0 (No se utilizo el servicio)
 *
 */

int ObtenerCantidadDeServicios(eServicio servicioMascota, eTrabajo trabajoMascota[], int tam)
{
	int contador;
	int i;

	contador = 0;

	for(i=0;i<tam;i++)
	{
		if(trabajoMascota[i].idServicio == servicioMascota.idServicio && trabajoMascota[i].isEmpty == 1)
		{
			contador++;
		}
	}

	return contador;
}



/** \brief Ordena los nombres de manera descendente
 *
 *  \param eTrabajo trabajoUno
 *  \param eMascota mascota[]
 *  \param eTrabajo trabajoDos
 *  \param int tamMascota
 *  \return void
 *
 */
void OrdenarNombreSegundoCriterio(eTrabajo trabajoMascota[], eMascota mascota[], int tamMascota, int i)
{
	eTrabajo aux;
	eMascota mascotaUno;
	eMascota mascotaDos;

	mascotaUno = ObtenerMascotaPorID(mascota, trabajoMascota[i], tamMascota);
	mascotaDos = ObtenerMascotaPorID(mascota, trabajoMascota[i+1], tamMascota);

	if(strcmp(mascotaUno.nombreMascota, mascotaDos.nombreMascota) < 0)
	{
		aux = trabajoMascota[i];
		trabajoMascota[i] = trabajoMascota[i+1];
		trabajoMascota[i+1] = aux;
	}
}


/** \brief Ordena por año y si el año es igual ordena por nombre
 *
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return void
 *
 */
void OrdenarListadoPorAnio(eTrabajo trabajoMascota[], int tam,  eMascota mascota[], int tamMascota)
{
	int i;
	int j;
	eTrabajo auxiliar;

	for (i=0; i<tam - 1; i++)
	{
		for (j = i+1; j<tam; j++)
		{
			if (trabajoMascota[i].fechaDelTrabajo.anio > trabajoMascota[j].fechaDelTrabajo.anio)
			{
				auxiliar = trabajoMascota[i];
				trabajoMascota[i] = trabajoMascota[j];
				trabajoMascota[j] = auxiliar;
			}
			else
			{
			    if(trabajoMascota[i].fechaDelTrabajo.anio == trabajoMascota[j].fechaDelTrabajo.anio)
			    {
			    	OrdenarNombreSegundoCriterio(trabajoMascota, mascota, tamMascota, i);
			    }
			}

		}
	}
}



/** \brief Ordenamiento por nombre
 *
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return void
 *
 */

void ListadoOrdenadoPorNombre(eTrabajo trabajoMascota[], int tam, eMascota mascota[], int tamMascota)
{
	int i;
	int j;

	for (i=0; i<tam - 1; i++)
	{
		for (j = i+1; j<tam; j++)
		{

			 OrdenarNombreSegundoCriterio(trabajoMascota, mascota, tamMascota, i);

		}

	}
}


/** \brief Obtiene el precio total de los servicios
 *
 *  \param eServicio servicioMascota[]
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \param int tamServicio
 *  \return int acumuladorPrecio
 *
 */

int ObtenerPrecioTotal(eServicio servicioMascota[], eTrabajo trabajoMascota[], int tam, int tamServicio)
{
    int i;
    int j;
    int acumuladorPrecio;

    acumuladorPrecio = 0;

    for(i=0;i<tam;i++)
    {
        for(j=0;j<tamServicio;j++)
        {
            if(trabajoMascota[i].idServicio == servicioMascota[j].idServicio && trabajoMascota[i].isEmpty == 1)
            {
                acumuladorPrecio+=servicioMascota[j].precio;
            }
        }
    }

    return acumuladorPrecio;
}


/** \brief Muestra el precio total de los servicios
 *
 *  \param eServicio servicioMascota[]
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \return void
 *
 */

void MostrarPrecioTotal(eServicio servicioMascota[], eTrabajo trabajoMascota[], int tam, int tamServicio)
{
    int precioTotal;

    precioTotal = ObtenerPrecioTotal(servicioMascota, trabajoMascota, tam, tamServicio);

    printf("\nEl precio total de los servicios es : $%d\n\n", precioTotal);
}


/** \brief Muestra un listado de las sucursales con su respectivas ganancias y mascotas.
 *
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \param eSucursal sucursal[]
 *  \param int tamSuc
 *  \return void
 *
 */
void GananciasTotalesSucursal(eTrabajo trabajoMascota[], int tam, eServicio servicioMascota[], int tamServicio, eMascota mascota[], int tamMascota, eSucursal sucursal[], int tamSuc)
{
    int i;
    int j;
    int acumuladorPrecio;
    eServicio auxServicio;
    eMascota auxMascota;
    acumuladorPrecio = 0;

	for(i=0;i<tamSuc;i++)
	{
		acumuladorPrecio = 0;
		printf("--------------------------------\n");
		printf("\nSUCURSAL : %s \n\n", sucursal[i].direccionSucursal);
		printf("MASCOTAS : ");
		for(j=0;j<tam;j++)
		{
			if(trabajoMascota[j].idSucursal == sucursal[i].idSucursal && trabajoMascota[j].isEmpty == 1)
			{
				auxServicio = ObtenerServicioPorID(servicioMascota, trabajoMascota[j], tamServicio);
				auxMascota = ObtenerMascotaPorID(mascota, trabajoMascota[j], tamMascota);
				acumuladorPrecio+=auxServicio.precio;
				printf("%s, ", auxMascota.nombreMascota);
			}

		}
		printf("\nGANANCIAS FUTURAS : %d\n", acumuladorPrecio);
	}

	printf("--------------------------------\n");

}

/** \brief Muestra un listado de los turnos  con su respectivas sucursales, nombres y servicios.
 *
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \param eSucursal sucursal[]
 *  \param int tamSuc
 *  \return void
 *
 */

void TurnosSucursales(eTrabajo trabajoMascota[], int tam, eServicio servicioMascota[], int tamServicio, eMascota mascota[], int tamMascota, eSucursal sucursal[], int tamSuc)
{
    int i;
    int j;
    int contador;
    eServicio auxServicio;
    eMascota auxMascota;

    contador = 0;

	for(i=0;i<tamSuc;i++)
	{
		printf("--------------------------------\n");
		printf("\nSUCURSAL : %s \n\n", sucursal[i].direccionSucursal);
		for(j=0;j<tam;j++)
		{
			if(trabajoMascota[j].idSucursal == sucursal[i].idSucursal && trabajoMascota[j].isEmpty == 1)
			{
				auxServicio = ObtenerServicioPorID(servicioMascota, trabajoMascota[j], tamServicio);
				auxMascota = ObtenerMascotaPorID(mascota, trabajoMascota[j], tamMascota);
				contador++;
				printf("MASCOTA\n");
				printf("%s\n", auxMascota.nombreMascota);
				printf("SERVICIO : %s\n\n", auxServicio.descripcionServicio);
				printf("Turno : %d / %d / %d\n\n", trabajoMascota[j].fechaDelTrabajo.dia, trabajoMascota[j].fechaDelTrabajo.mes, trabajoMascota[j].fechaDelTrabajo.anio);
			}

		}

	}
	printf("--------------------------------\n");

	printf("TOTAL DE TURNOS ANOTADOS : %d\n", contador);
}













