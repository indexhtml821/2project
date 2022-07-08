#include "planilla.h"
#include <iostream>
Planilla::~Planilla()
{
    int cantidadIndices = indicePlanilla.size();

    supervisor->~Nodo();
    for (int i = 1; i < cantidadIndices; i++)
    {
        indicePlanilla.erase(i);
    }
}

void Planilla::InsertarEmpleado(Empleado *empleadoAInsertar)
{
    Empleado *empleado = empleadoAInsertar;
    int id = empleadoAInsertar->ObtenerIdEmpleado();
    int idSupervisor = empleado->ObtenerIdSupervisor();
    Nodo *nodoEmpleado = new Nodo(id, empleado);

    if (id == 1)
    {

        supervisor = new Nodo(id, empleado);
        this->supervisor->InsertarSupervisar(nodoEmpleado);
        this->indicePlanilla.insert(std::pair<int, Nodo *>(id, nodoEmpleado));
        return;
    }
    Nodo *nodoSupervisor = this->indicePlanilla.at(idSupervisor);
    nodoSupervisor->InsertarSupervisar(nodoEmpleado);
    nodoEmpleado->InsertarSupervisor(nodoSupervisor);

    this->indicePlanilla.insert(std::pair<int, Nodo *>(id, nodoEmpleado));
}

Empleado *Planilla::ObtenerEmpleado(int id)
{

    Empleado *empleadoSolicitado = indicePlanilla.at(id)->DevolverEmpleado();
    return empleadoSolicitado;
}

int Planilla::DevolverIndicePlanilla()
{

    return this->indicePlanilla.size();
}

string Planilla ::RecorrerArbol(Nodo aBuscar)
{
    string info = "";
    info += aBuscar.DevolverEmpleado()->InfoCompletaEmpleados() + "\n";

    for (Nodo *empleado : aBuscar.DevolverSupervisados())
    {

        info += RecorrerArbol(*empleado);
    }

    return info;
}

Nodo *Planilla::ObtenerNodo(int id)
{

    return this->indicePlanilla.at(id);
}