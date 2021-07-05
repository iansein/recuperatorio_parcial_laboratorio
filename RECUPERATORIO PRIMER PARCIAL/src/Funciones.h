#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Structs.h"

#ifndef FUNCIONES_H_
#define FUNCIONES_H_


int ObtenerPrecioTotal(eServicio[], eTrabajo[], int, int);

void MostrarPrecioTotal(eServicio[], eTrabajo[], int, int);

void OrdenarListadoPorAnio(eTrabajo[], int, eMascota[], int);

void ListadoOrdenadoPorNombre(eTrabajo[], int, eMascota[], int);

void MostrarUnTrabajo(eTrabajo, eServicio[], int, eMascota[], int, eSucursal[], int);

void MostrarTodosLosTrabajos(eTrabajo[], eServicio[], int, int, eMascota[], int, eSucursal[], int);

void ListadoServiciosConSusNombres(eTrabajo[], int, eServicio[], int, eMascota[], int);

void PromedioDeEdadesPorServicio(eTrabajo[], int, eMascota [], int, eServicio[], int);

void ServiciosConMasTrabajos(eTrabajo[], int, eServicio[], int);

int ObtenerCantidadDeServicios(eServicio, eTrabajo[], int);

void OrdenarNombreSegundoCriterio(eTrabajo[], eMascota[], int, int);

int ObtenerPromedioDeEdades(eServicio, eTrabajo[], int, eMascota[], int);

void GananciasTotalesSucursal(eTrabajo[], int, eServicio[], int, eMascota[], int, eSucursal[], int);

void TurnosSucursales(eTrabajo[], int, eServicio[], int, eMascota[], int, eSucursal[], int);

void OrdenarId(eTrabajo[], int,  eMascota[], int);

#endif /* FUNCIONES_H_ */
