#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "Structs.h"
#include "Mascota.h"


void InicializarDatos(eTrabajo[], int);

int BuscarLibre(eTrabajo[], int);

void CargarTrabajoMascota(eTrabajo[], int, int, eServicio[], eMascota[], int, eSucursal[], int, int*);

eTrabajo PedirDatosTrabajo(eServicio[], int, int, eTrabajo[], eMascota[], int, eSucursal[], int, int*);

void ValidarID(eTrabajo, eServicio[], int);

int BuscarIndice(eTrabajo[], int, eServicio[], int, eMascota[],int, eSucursal[], int);

int DarDeBajaTrabajo(eTrabajo[],int,eServicio[],int, eMascota[], int, eSucursal[], int);

void ModificarTrabajo(eTrabajo[], int, int, eServicio[], eMascota[], int, eSucursal[], int);

#endif /* FUNCIONES_H_ */


