#include "empleadoHoras.h"
#include <iomanip>

using namespace std;
EmpleadoHoras::EmpleadoHoras(int idEmpleado,
                             string nombre,
                             string apellido,
                             string email,
                             int tipoEmpleado,
                             int idSupervisor, int horasLaboradas,
                             float pagoPorHora)
{

    this->idEmpleado = idEmpleado;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->tipoEmpleado = tipoEmpleado;
    this->idSupervisor = idSupervisor;
    this->horasLaboradas = horasLaboradas;
    this->pagoPorHora = pagoPorHora;
}
void EmpleadoHoras::CalculoPago()
{

    pagoTotal = horasLaboradas * pagoPorHora;
}
string EmpleadoHoras::InfoEmpleadoParaArchivo()
{

    stringstream pagoTotalAPrecisar;
    pagoTotalAPrecisar << std::fixed << std::setprecision(1) << this->pagoTotal;

    string idEmpleado = (std::to_string(this->idEmpleado));
    string pagoTotal = pagoTotalAPrecisar.str();

    return idEmpleado + " " + this->nombre + " " + this->apellido + " " + pagoTotal;
}
string EmpleadoHoras::InfoCompletaEmpleados()
{

    stringstream pagoPorHoraAPrecisar;
    pagoPorHoraAPrecisar << std::fixed << std::setprecision(2) << this->pagoPorHora;
    stringstream pagoTotalAPrecisar;
    pagoTotalAPrecisar << std::fixed << std::setprecision(1) << this->pagoTotal;

    string idEmpleado = (std::to_string(this->idEmpleado));
    string tipoEmpleado = (std::to_string(this->tipoEmpleado));
    string idSupervisor = (std::to_string(this->idSupervisor));
    string horasLaboradas = (std::to_string(this->horasLaboradas));
    string pagoPorHora = pagoPorHoraAPrecisar.str();
    string pagoTotal = pagoTotalAPrecisar.str();

    return idEmpleado + " " + this->nombre + " " + this->apellido + " " + this->email + " " + tipoEmpleado + " " + idSupervisor + " " + horasLaboradas + " " + pagoPorHora + " " + pagoTotal;
}

float EmpleadoHoras::DevolverPagoTotal()
{
    return pagoTotal;
}