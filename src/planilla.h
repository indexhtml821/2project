#ifndef PLANILLA_H
#define PLANILLA_H

#include "nodo.h"
#include "empleado.h"
#include <map>

using namespace std;

class Planilla
{
  // protected:
  Nodo *supervisor;
  map<int, Nodo *> indicePlanilla;

public:
  ~Planilla();
  void InsertarEmpleado(Empleado *empleadoAInsertar);
  Empleado *ObtenerEmpleado(int id);
  int DevolverIndicePlanilla();
  string RecorrerArbol(Nodo aBuscar);
  Nodo *ObtenerNodo(int id);
};

#endif