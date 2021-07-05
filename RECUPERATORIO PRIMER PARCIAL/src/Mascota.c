#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Input.h"
#include "Structs.h"
#include "Mascota.h"
#include "Trabajo.h"

/** \brief Muestra un listado de las mascotas ya existentes
 *
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return void
 */
void MostrarMascotas(eMascota mascota[], int tamMascota)
{
    int i;

    for(i = 0; i<tamMascota;i++)
    {
        if(mascota[i].isEmpty == 1)
        {
            printf("\nID MASCOTA : %d | NOMBRE : %s | EDAD : %d | RAZA : %s\n", mascota[i].idMascota, mascota[i].nombreMascota, mascota[i].edad, mascota[i].raza);
        }
    }

}

/** \brief Inicializa algunas posiciones como "VACIAS@
 *
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return void
 */
void InicializarDatosMascota(eMascota mascota[], int tamMascota)
{
    int i;
    for(i=5; i<tamMascota ; i++)
    {
        mascota[i].isEmpty = 0;
    }
}

/** \brief Busca el indice donde la posicion este "VACIA"
 *
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return void
 */
int BuscarLibreMascota(eMascota mascota[], int tamMascota)
{
    int indice;
    int i;

    indice = -1;

    for(i=0;i<tamMascota;i++)
    {
        if(mascota[i].isEmpty == 0)
        {
            indice = i;
            break;
        }

    }

    return indice;
}

/** \brief Carga en una posicion "VACIA" una mascota
 *
 *  \param eMascota mascota[]
 *  \param int tam
 *  \return void
 */
void CargarMascota(eMascota mascota[], int tamMascota)
{
    int indice;
    indice = BuscarLibreMascota(mascota, tamMascota);

    if(indice == -1)
    {
    	printf("\nNo hay espacio disponible para agregar una mascota\n");
    }
    else
    {
        mascota[indice] = PedirDatosMascota(tamMascota, mascota);
        mascota[indice].isEmpty = 1;
    }

}


/** \brief Pide los datos de una mascota
 *
 *  \param int tamMascota
 *  \param eMascota mascotaExistente[]
 *  \return eMascota mascota
 */

eMascota PedirDatosMascota(int tamMascota, eMascota mascotaExistente[])
{
    eMascota mascota;
    int i;

    mascota.idMascota = 20;

    for(i = 0; i<tamMascota; i++)
    {
        if(mascotaExistente[i].isEmpty == 1 && mascota.idMascota == mascotaExistente[i].idMascota)
        {
            mascota.idMascota++;
        }
    }

    printf("\nID MASCOTA : %d\n\n", mascota.idMascota);

    GetString("Ingrese el nombre de la mascota\n", mascota.nombreMascota);
    mascota.edad = GetInt("Ingrese la edad de la mascota (1-20)\n");
    mascota.edad = ValidarUnRango("Ingrese la edad de la mascota (1-20)\n", 20, 1, mascota.edad);
    GetString("Ingrese la raza de la mascota\n", mascota.raza);


    return mascota;
}


/** \brief Busca el indice de una mascota para
 *
 *  \param eMascota mascota[]
 *  \param int tam
 *  \return void
 */

int BuscarIndiceMascota(eMascota mascota[], int tamMascota)
{
    int idIngresada;
    int indice;
    int i;

    indice = -1;
    MostrarMascotas(mascota, tamMascota);
    idIngresada = GetInt("Ingrese la ID del trabajo que busca\n");

    for(i=0;i<tamMascota;i++)
    {
        if(mascota[i].isEmpty == 1)
        {
            if(idIngresada == mascota[i].idMascota)
            {
                indice = i;
                break;
            }
        }

    }

    return indice;

}

/** \brief Da de baja a una mascota y deja una posicion "VACIA"
 *
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \param eTrabajo trabajoMascota[]
 *  \param int tam
 *  \return void
 */

int DarDeBajaMascota(eMascota mascota[], int tamMascota, eTrabajo trabajoMascota[], int tam)
{
    int indice;
    int i;
    int decision;

    decision = 2;

    indice = BuscarIndiceMascota(mascota, tamMascota);

    if(indice == -1)
    {
        printf("\nEl ID ingresado es incorrecto.\n");
    }
    else
    {
        decision = GetInt("\nConfirmar la baja de la mascota : Presione 1 para SI | Presione 2 para NO\n");
        decision = ValidarUnRango("Error : Presione 1 para SI | Presione 2 para NO\n", 2, 1,decision);

        if(decision == 1)
        {
            mascota[indice].isEmpty = 0;
            for(i=0;i<tam;i++)
            {
            	if(trabajoMascota[i].isEmpty == 1 && trabajoMascota[i].idMascota == mascota[indice].idMascota)
            	{
            		trabajoMascota[i].isEmpty = 0;
            	}
            }

            printf("\nUsted dio de baja la mascota\n\n");
        }
        else
        {
            printf("\nNo se dio de baja ninguna mascota\n");
        }
    }

    return decision;

}

/** \brief Modifica el nombre de una mascota
 *
 *  \param eMascota mascota[]
 *  \param int tamMascota
 *  \return void
 */
void ModificarMascota(eMascota mascota[], int tamMascota)
{
    int indice;
    int decision;

    indice = BuscarIndiceMascota(mascota, tamMascota);

    if(indice == -1)
    {
        printf("\nEl ID ingresado es incorrecto.\n");
    }
    else
    {
        decision = GetInt("\nEsta seguro que quiere modificar el nombre de la mascota? : Presione 1 para SI | Presione 2 para NO\n");
        decision = ValidarUnRango("Error : Presione 1 para SI | Presione 2 para NO\n", 2, 1,decision);

        if(decision == 1)
        {
        	GetString("Ingrese el nombre de la mascota\n", mascota[indice].nombreMascota);
            printf("\nUsted modifico el nombre de la mascota con exito!\n\n");
        }
        else
        {
            printf("\nNo se modifico ninguna mascota!\n\n");
        }
    }
}


/** \brief Obtiene una estructura de mascota mediante una busqueda de ID.
 *
 *  \param eMascota mascota[]
 *  \param eTrabajo trabajoMascota
 *  \param int tamMascota
 *  \return eMascota mascotaAux
 *
 */
eMascota ObtenerMascotaPorID(eMascota mascota[], eTrabajo trabajoMascota, int tamMascota)
{
	eMascota mascotaAux;
	int i;

	for(i=0;i<tamMascota;i++)
	{
		if(trabajoMascota.idMascota == mascota[i].idMascota)
		{
			mascotaAux = mascota[i];
		}
	}

	return mascotaAux;
}

/** \brief Valida que la ID de la mascota no este fuera de los limites.
 *
 *  \param eTrabajo trabajoMascota
 *  \param eServicio servicioMascota[]
 *  \param int tamMascota
 *  \return int trabajoMascota.idMascota
 *
 */

int ValidarIdMascota(eTrabajo trabajoMascota, eMascota mascota[], int tamMascota)
{
	int validacion;
	int i;
	validacion = 0;

	do
	{
		for(i=0;i<tamMascota;i++)
		{
			if(trabajoMascota.idMascota == mascota[i].idMascota && mascota[i].isEmpty == 1)
			{
				validacion = 1;
				break;
			}
			if(i+1 == tamMascota)
			{
				MostrarMascotas(mascota, tamMascota);
				trabajoMascota.idMascota = GetInt("\nReingrese el id de su mascota\n");
			}
		}

	}while(validacion == 0);

	return trabajoMascota.idMascota;
}

