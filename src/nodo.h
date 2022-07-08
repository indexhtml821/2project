#ifndef NODO_H
#define NODO_H

#include "empleado.h"
#include <vector>

using namespace std;

class Nodo
{
protected:
    int id = 0;
    Empleado *empleado;
    Nodo *supervisor;
    vector<Nodo *> empleadosASupervisar;

public:
    ~Nodo();
    Nodo(int id, Empleado *empleado);

    void InsertarSupervisor(Nodo *supervisor);

    void InsertarSupervisar(Nodo *supervisado);
    Empleado *DevolverSupervisor();
    Empleado *DevolverSupervisar(int id);
    vector<Nodo *> DevolverSupervisados();
    Empleado *DevolverEmpleado();
};

#endif