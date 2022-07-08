#ifndef EMPLEADOHORAS_h
#define EMPLEADOHORAS_h

#include "empleado.h"

class EmpleadoHoras : public Empleado
{

protected:
    int horasLaboradas = 0;
    float pagoPorHora = 0;
    float pagoTotal = 0;

public:
    EmpleadoHoras(int idEmpleado,
                  string nombre,
                  string apellido,
                  string email,
                  int tipoEmpleado,
                  int idSupervisor, int horasLaboradas,
                  float pagoPorHora);

    void CalculoPago();
    string InfoEmpleadoParaArchivo();
    string InfoCompletaEmpleados();
    float DevolverPagoTotal();
};

#endif