#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Funciones.h"
#include "Input.h"
#include "Structs.h"
#include "Trabajo.h"
#include "Mascota.h"
#include "Servicio.h"
#include "Sucursal.h"

#define TAM 5
#define TAMS 3
#define TAMMASCOTAS 10
#define TAMSUC 4
int main()
{
	setbuf(stdout,NULL);
	int contadorTrabajos;
	int contadorMascotas;

    eTrabajo trabajoMascota [TAM];
    eServicio servicioMascota [TAMS] = {{20000, "Corte", 250}, {20001, "Desparasitado", 300}, {20002, "Castrado", 400}};
    eMascota mascota[TAMMASCOTAS] = {{15, "Juan", 5, "Bulldog", 1}, {16,"Roco", 3, "Pitbull", 1}, {17, "Dylan", 2, "Caniche", 1}, {18, "Gago", 4, "Cocker", 1}, {19, "Omero", 7,"Golden", 1}};
    eSucursal sucursal[TAMSUC] = {{100,"Caballito"}, {101,"Belgrano"},{102,"Boedo"},{103, "Puan"}};

    int opcion;
    int opcionMascota;
    int id;
    int bajaTrabajo;
    int bajaMascota;
    int* guardarId;


    InicializarDatos(trabajoMascota, TAM);
    InicializarDatosMascota(mascota, TAMMASCOTAS);
    contadorTrabajos = 0;
    contadorMascotas = 5;
    id = 0;
    guardarId = &id;

    do
    {
        opcion = MenuPrincipal();
        switch(opcion)
        {
            case 1:
            if(contadorMascotas > 0)
            {
            	CargarTrabajoMascota(trabajoMascota, TAM, TAMS, servicioMascota, mascota, TAMMASCOTAS, sucursal, TAMSUC, guardarId);
            	contadorTrabajos++;
            }
            else
            {
            	printf("\nPara dar de alta un trabajo debe ingresar una mascota (7-Submenu mascotas)\n");
            }

            break;

            case 2:
            if(contadorTrabajos > 0)
            {
            	bajaTrabajo = DarDeBajaTrabajo(trabajoMascota, TAM, servicioMascota, TAMS, mascota, TAMMASCOTAS, sucursal, TAMSUC);
                if(bajaTrabajo == 1)
                {
                	contadorTrabajos--;
                }
            }
            else
            {
                printf("\nPara dar de baja un trabajo necesita ingresar por lo menos uno.\n\n");
            }
            break;

            case 3:

            if(contadorTrabajos > 0)
            {
                ModificarTrabajo(trabajoMascota, TAM, TAMS, servicioMascota, mascota, TAMMASCOTAS, sucursal, TAMSUC);
            }
            else
            {
                printf("\nPara modificar un trabajo necesita ingresar por lo menos uno.\n\n");
            }
            break;

            case 4:
            if(contadorTrabajos > 0)
            {
                OrdenarListadoPorAnio(trabajoMascota, TAM, mascota, TAMMASCOTAS);
                MostrarTodosLosTrabajos(trabajoMascota, servicioMascota, TAMS, TAM, mascota, TAMMASCOTAS, sucursal, TAMSUC);
            }
            else
            {
                printf("\nPara mostrar el listado es necesario que ingrese por lo menos un trabajo\n\n");
            }
            break;

            case 5:
            MostrarListadoDeServicios(servicioMascota, TAMS);
            break;

            case 6:
            if(contadorTrabajos > 0)
            {
                MostrarPrecioTotal(servicioMascota, trabajoMascota, TAM, TAMS);
            }
            else
            {
                printf("\nPara obtener el precio total de los servicios es necesario que ingrese un trabajo\n\n");
            }
            break;

            case 7:

            do
            {
                opcionMascota = SubMenu();
                switch(opcionMascota)
                {
                    case 1:
                    CargarMascota(mascota, TAMMASCOTAS);
                    contadorMascotas++;
                    break;

                    case 2:
                    if(contadorMascotas > 0)
                    {
                    	bajaMascota = DarDeBajaMascota(mascota, TAMMASCOTAS, trabajoMascota, TAM);
                    	if(bajaMascota == 1)
                    	{
                    		contadorMascotas--;
                    	}
                    }
                    else
                    {
                    	printf("\nPara dar de baja a una mascota debe ingresar por lo menos una\n");
                    }
                    break;

                    case 3:
                    if(contadorMascotas > 0)
                    {
                    	ModificarMascota(mascota, TAMMASCOTAS);
                    }
                    else
                    {
                    	printf("\nPara modificar una mascota debe dar de alta una\n");
                    }
                    break;

                    case 4:
                    if(contadorMascotas > 0)
                    {
                    	MostrarMascotas(mascota, TAMMASCOTAS);
                    }
                    else
                    {
                    	printf("\nPara mostrar el listado de mascotas debe ingresar aunque sea una\n");
                    }
                    break;

                    case 5:
                    break;

                }

            }while(opcionMascota != 5);

            break;

            case 8:
            if(contadorTrabajos > 0)
            {
            	ListadoOrdenadoPorNombre(trabajoMascota, TAM, mascota, TAMMASCOTAS);
            	MostrarTodosLosTrabajos(trabajoMascota, servicioMascota, TAMS, TAM, mascota, TAMMASCOTAS, sucursal, TAMSUC);
            }
            else
            {
            	printf("\nPara mostrar el listado debe ingresar un trabajo\n");
            }
            break;

            case 9:
            if(contadorTrabajos > 0)
            {
            	ServiciosConMasTrabajos(trabajoMascota, TAM, servicioMascota, TAMS);
            }
            else
            {
            	printf("\nPara mostrar el listado debe ingresar un trabajo\n");
            }
            break;

            case 10:
            if(contadorTrabajos > 0)
            {
            	ListadoServiciosConSusNombres(trabajoMascota, TAM, servicioMascota, TAMS, mascota, TAMMASCOTAS);

            }
            else
            {
            	printf("\nPara mostrar el listado debe ingresar un trabajo\n");
            }
            break;

            case 11:
            if(contadorTrabajos > 0)
            {
            	PromedioDeEdadesPorServicio(trabajoMascota, TAM, mascota, TAMMASCOTAS, servicioMascota, TAMS);
            }
            else
            {
            	printf("\nPara mostrar el listado debe ingresar un trabajo\n");
            }
            break;

            case 12:
            if(contadorTrabajos > 0)
            {
            	GananciasTotalesSucursal(trabajoMascota, TAM, servicioMascota, TAMS, mascota, TAMMASCOTAS, sucursal, TAMSUC);
            }
            else
            {
            	printf("\nPara mostrar el listado debe ingresar un trabajo\n");
            }
            break;

            case 13:
            if(contadorTrabajos > 0)
            {
            	TurnosSucursales(trabajoMascota, TAM, servicioMascota, TAMS, mascota, TAMMASCOTAS, sucursal, TAMSUC);
            }
            else
            {
            	printf("\nPara mostrar el listado debe ingresar un trabajo\n");
            }
            break;

            case 14:

            break;

        }

    }while(opcion != 14);


    return 0;

}
