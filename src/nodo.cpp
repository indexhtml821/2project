#include "nodo.h"

Nodo::~Nodo()
{
    delete empleado;
}

Nodo::Nodo(int id, Empleado *empleado)
{

    this->id = id;
    this->empleado = empleado;
}

void Nodo ::InsertarSupervisor(Nodo *supervisor)
{

    this->supervisor = supervisor;
}

void Nodo ::InsertarSupervisar(Nodo *supervisar)
{

    this->empleadosASupervisar.push_back(supervisar);
}

Empleado *Nodo::DevolverSupervisor()
{
    Empleado *empleadoSolicitado = this->supervisor->DevolverEmpleado();
    return empleadoSolicitado;
}
Empleado *Nodo ::DevolverSupervisar(int id)
{

    Empleado *empleadoADevolver;
    for (Nodo *empleado : this->empleadosASupervisar)
    {
        if (empleado->DevolverEmpleado()->ObtenerIdEmpleado() == id)
        {
            empleadoADevolver = empleado->DevolverEmpleado();
        }
    }
    return empleadoADevolver;
}

vector<Nodo *> Nodo::DevolverSupervisados()
{

    return this->empleadosASupervisar;
}
Empleado *Nodo::DevolverEmpleado()
{

    Empleado *empleadoSolicitado = this->empleado;
    return empleadoSolicitado;
}
