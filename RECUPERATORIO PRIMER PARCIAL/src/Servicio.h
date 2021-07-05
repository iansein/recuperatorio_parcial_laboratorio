#ifndef SERVICIO_H_
#define SERVICIO_H_

void MostrarListadoServicioConId(eServicio[], int);

void MostrarListadoDeServicios(eServicio[], int);

int ElegirIdServicio(eServicio[], int);

void MostrarServicioMasUtilizado(eServicio);

eServicio ObtenerServicioPorID(eServicio[], eTrabajo, int);

#endif /* SERVICIO_H_ */
