#ifndef MASCOTA_H_
#define MASCOTA_H_


void MostrarMascotas(eMascota[], int);

void InicializarDatosMascota(eMascota[], int);

int BuscarLibreMascota(eMascota[], int);

void CargarMascota(eMascota[], int);

eMascota PedirDatosMascota(int, eMascota[]);

int BuscarIndiceMascota(eMascota[], int);

int DarDeBajaMascota(eMascota[], int, eTrabajo[], int);

void ModificarMascota(eMascota[], int);

eMascota ObtenerMascotaPorID(eMascota[], eTrabajo, int);

int ValidarIdMascota(eTrabajo, eMascota[], int);

#endif /* MASCOTA_H_ */
