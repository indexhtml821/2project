#ifndef EMPLEADONOMINA_h
#define EMPLEADONOMINA_h

#include "empleado.h"

using namespace std;

class EmpleadoNomina : public Empleado
{
protected:
    float salarioFinal;
    float salarioBruto;

public:
    EmpleadoNomina(int idEmpleado,
                   string nombre,
                   string apellido,
                   string email,
                   int tipoEmpleado,
                   int idSupervisor,
                   float salario);

    void CalculoPago();
    string InfoEmpleadoParaArchivo();
    string InfoCompletaEmpleados();
    float DevolverSalario();
};

#endif