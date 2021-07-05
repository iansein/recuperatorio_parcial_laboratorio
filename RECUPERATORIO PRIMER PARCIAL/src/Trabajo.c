#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Trabajo.h"
#include "Input.h"
#include "Structs.h"
#include "Servicio.h"
#include "Funciones.h"
#include "Mascota.h"
#include "Sucursal.h"

/** \brief Inicializa todas las posiciones para que esten "VACIAS"
 *
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \return void
 */
void InicializarDatos(eTrabajo trabajoMascota[], int tam)
{
    int i;
    for(i=0; i<tam ; i++)
    {
        trabajoMascota[i].isEmpty = 0;
    }
}

/** \brief Busca la posicion libre dentro del array de trabajos
 *
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \return int indice
 */
int BuscarLibre(eTrabajo trabajoMascota[], int tam)
{
    int indice;
    int i;

    indice = -1;

    for(i=0;i<tam;i++)
    {
        if(trabajoMascota[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

/** \brief Carga en una posicion "VACIA" un trabajo
 *
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \param int tamServicio
 *  \param eServicio servicioMascota[]
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \param eSucursal sucursal[]
 *  \param int tamSuc
 *  \return void
 */

void CargarTrabajoMascota(eTrabajo trabajoMascota[], int tam, int tamServicio, eServicio servicioMascota[], eMascota mascota[], int tamMascota, eSucursal sucursal[], int tamSuc, int* guardarId)
{
    int indice;
    indice = BuscarLibre(trabajoMascota, tam);

    if(indice == -1)
    {
        printf("\nNo hay espacio disponible\n");
    }
    else
    {
        trabajoMascota[indice] = PedirDatosTrabajo(servicioMascota, tamServicio, tam, trabajoMascota, mascota, tamMascota, sucursal, tamSuc, guardarId);
        trabajoMascota[indice].isEmpty = 1;
    }

}

/** \brief Pide los datos del trabajo solicitado
 *
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \param int tam
 *  \param eTrabajo trabajoMascotaExistente[]
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \param eSucursal sucursal[]
 *  \param int tamSuc
 *  \return eTrabajo trabajoMascota
 */

eTrabajo PedirDatosTrabajo(eServicio servicioMascota[], int tamServicio, int tam, eTrabajo trabajoMascotaExistente[], eMascota mascota[], int tamMascota, eSucursal sucursal[], int tamSuc, int* guardarId)
{
    eTrabajo trabajoMascota;

    *guardarId = *guardarId + 1;
    trabajoMascota.idTrabajo = *guardarId;


    printf("\nID Trabajo : %d\n\n", trabajoMascota.idTrabajo);

    MostrarMascotas(mascota, tamMascota);
    trabajoMascota.idMascota = GetInt("\nIngrese el id de la mascota\n");
    trabajoMascota.idMascota = ValidarIdMascota(trabajoMascota, mascota, tamMascota);

    MostrarSucursales(sucursal, tamSuc);
    trabajoMascota.idSucursal = GetInt("\nIngrese el id de la sucursal\n");
    trabajoMascota.idSucursal = ValidarIDSucursal(trabajoMascota, sucursal, tamSuc);

    trabajoMascota.idServicio = ElegirIdServicio(servicioMascota, tamServicio);

    trabajoMascota.fechaDelTrabajo.dia = GetInt("\nIngrese el dia del trabajo solicitado [ 1-31 ]\n");
    trabajoMascota.fechaDelTrabajo.dia = ValidarUnRango("Error : Reingrese el dia del trabajo solicitado [ 1-31 ]\n", 31, 1, trabajoMascota.fechaDelTrabajo.dia);

    trabajoMascota.fechaDelTrabajo.mes = GetInt("\nIngrese el mes del trabajo solicitado [ 1-12 ]\n");
    trabajoMascota.fechaDelTrabajo.mes = ValidarUnRango("Error : Reingrese el mes del trabajo solicitado [ 1-12 ]\n", 12, 1, trabajoMascota.fechaDelTrabajo.mes);

    trabajoMascota.fechaDelTrabajo.anio = GetInt("\nIngrese el año del trabajo solicitado [ 2021 - 2022]\n");
    trabajoMascota.fechaDelTrabajo.anio = ValidarUnRango("Error : Reingrese el año del trabajo solicitado [ 2021-2022 ]\n", 2022, 2021, trabajoMascota.fechaDelTrabajo.anio);

    return trabajoMascota;
}


/** \brief Busca el indice de un trabajo en especifico
 *
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \param eServicio servicioMascota[]
 *  \param int tamServicio
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \param eSucursal sucursal[]
 *  \param int tamSuc
 *  \return int indice
 */

int BuscarIndice(eTrabajo trabajoMascota[], int tam, eServicio servicioMascota[], int tamServicio, eMascota mascota[], int tamMascota, eSucursal sucursal[], int tamSuc)
{
    int idIngresada;
    int indice;
    int i;

    indice = -1;
    MostrarTodosLosTrabajos(trabajoMascota, servicioMascota, tamServicio, tam, mascota, tamMascota, sucursal, tamSuc);
    idIngresada = GetInt("\nIngrese la ID del trabajo que busca\n");

    for(i=0;i<tam;i++)
    {
        if(idIngresada == trabajoMascota[i].idTrabajo)
        {
            indice = i;
            break;
        }
    }

    return indice;

}

/** \brief Da la baja a un trabajo y vuelve a haber una posicion "VACIA"
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
 */
int DarDeBajaTrabajo(eTrabajo trabajoMascota[], int tam, eServicio servicioMascota[], int tamServicio, eMascota mascota[], int tamMascota, eSucursal sucursal[],int tamSuc)
{
    int indice;
    int decision;

    indice = BuscarIndice(trabajoMascota, tam, servicioMascota, tamServicio, mascota, tamMascota, sucursal, tamSuc);
    if(indice == -1)
    {
        printf("\nEl ID ingresado es incorrecto!\n");
    }
    else
    {
        decision = GetInt("\nConfirmar la baja del trabajo : Presione 1 para SI | Presione 2 para NO\n");
        decision = ValidarUnRango("Error : Presione 1 para SI | Presione 2 para NO\n", 2, 1,decision);

        if(decision == 1)
        {
            trabajoMascota[indice].isEmpty = 0;
            printf("\nUsted dio de baja el trabajo\n\n");
        }
        else
        {
            printf("\nNo se dio de baja ningun trabajo.\n");
        }
    }

    return decision;

}

/** \brief Modifica el servicio de un trabajo
 *
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \param int tamServicio
 *  \param eServicio servicioMascota[]
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \param eSucursal sucursal[]
 *  \param int tamSuc
 *  \return void
 */
void ModificarTrabajo(eTrabajo trabajoMascota[], int tam, int tamServicio, eServicio servicioMascota[], eMascota mascota[], int tamMascota, eSucursal sucursal[], int tamSuc)
{

    int indice;
    int decision;

    indice = BuscarIndice(trabajoMascota, tam, servicioMascota, tamServicio, mascota, tamMascota, sucursal, tamSuc);
    if(indice == -1)
    {
    	printf("\nEl ID ingresado es incorrecto!\n");
    }
    else
    {
        decision = GetInt("\nConfirmar la modificacion del trabajo : Presione 1 para SI | Presione 2 para NO\n");
        decision = ValidarUnRango("Error : Presione 1 para SI | Presione 2 para NO\n", 2, 1,decision);

        if(decision == 1)
        {
        	trabajoMascota[indice].idServicio = ElegirIdServicio(servicioMascota, tamServicio);
            printf("\nUsted ha modificado el trabajo correctamente\n");
        }
        else
        {
            printf("\nNo se modifico a ningun trabajo.\n");
        }

    }


}











