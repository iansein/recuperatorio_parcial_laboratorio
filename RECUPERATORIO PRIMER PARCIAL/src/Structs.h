#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int idTrabajo;
    int idMascota;
    int idServicio;
    int idSucursal;
    int isEmpty;
    eFecha fechaDelTrabajo;

}eTrabajo;

typedef struct
{
    int idMascota;
    char nombreMascota[25];
    int edad;
    char raza[25];
    int isEmpty;

}eMascota;

typedef struct
{
    int idServicio;
    char descripcionServicio[25];
    int precio;
}eServicio;


typedef struct
{
	int idSucursal;
	char direccionSucursal[25];
}eSucursal;

#endif /* STRUCTS_H_ */
