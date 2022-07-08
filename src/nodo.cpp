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

    this->empleadosASupervisar.insert(std::pair<int, Nodo *>(supervisar->DevolverEmpleado()->ObtenerIdEmpleado(), supervisar));
}

Empleado *Nodo::DevolverSupervisor()
{
    Empleado *empleadoSolicitado = this->supervisor->DevolverEmpleado();
    return empleadoSolicitado;
}
Empleado *Nodo ::DevolverSupervisar(int id)
{
    Empleado *empleadoSolicitado = this->empleadosASupervisar.at(id)->DevolverEmpleado();
    return empleadoSolicitado;
}
Empleado *Nodo::DevolverEmpleado()
{

    Empleado *empleadoSolicitado = this->empleado;
    return empleadoSolicitado;
}

string Nodo::DevolverInfoNodo()
{
    string info = "";
    auto iter = this->empleadosASupervisar.begin();
    if (this->empleadosASupervisar.empty())
    {
        return this->empleado->InfoCompletaEmpleados() + "/n";
    }
    else
    {

        while (iter != this->empleadosASupervisar.end())
        {

            info += iter->second->DevolverInfoNodo();
            iter++;
        }
        return info += this->empleado->InfoCompletaEmpleados();
    }
}