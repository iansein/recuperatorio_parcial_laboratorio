#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Sucursal.h"
#include "Input.h"
#include "Trabajo.h"

/** \brief Listado de las sucursales existentes
 *
 *  \param eSucursal sucursal[]
 *  \param int tamSuc
 *  \return void
 *
 */

void MostrarSucursales(eSucursal sucursal[], int tamSuc)
{
	int i;

	for(i=0;i<tamSuc;i++)
	{
		printf("\nID : %d | SUCURSAL : %s\n\n", sucursal[i].idSucursal, sucursal[i].direccionSucursal);
	}
}

/** \brief Valida la id de la sucursal y verifica que no este fuera de los limites
 *
 *  \param eTrabajo trabajoMascota
 *  \param eSucursal sucursal[]
 *  \param int tamSuc
 *  \return void
 *
 */

int ValidarIDSucursal(eTrabajo trabajoMascota, eSucursal sucursal[], int tamSuc)
{
	int validacion;
	int i;
	validacion = 0;

	do
	{
		for(i=0;i<tamSuc;i++)
		{
			if(trabajoMascota.idSucursal == sucursal[i].idSucursal)
			{
				validacion = 1;
				break;
			}
			if(i+1 == tamSuc)
			{
				MostrarSucursales(sucursal, tamSuc);
				trabajoMascota.idSucursal = GetInt("\nError: Reingrese la id de la sucursal\n");
			}
		}


	}while(validacion==0);

	return trabajoMascota.idSucursal;
}

/** \brief Busca mediante ID una sucursal devolviendo su estrucutra
 *
 *  \param eSucursal sucursal[]
 *  \param eTrabajo trabajoMascota
 *  \param int tamSuc
 *  \return eSucursal sucursalAux
 *
 */
eSucursal ObtenerSucursalPorID(eSucursal sucursal[], eTrabajo trabajoMascota, int tamSuc)
{
	eSucursal sucursalAux;
	int i;

	for(i=0;i<tamSuc;i++)
	{
		if(trabajoMascota.idSucursal == sucursal[i].idSucursal)
		{
			sucursalAux = sucursal[i];
		}
	}

	return sucursalAux;
}
