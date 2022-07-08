#ifndef PROCESADOR_H
#define PROCESADOR_H

#include "empleado.h"
#include "planilla.h"
#include <map>
#include <iostream>
#include <string>

using namespace std;

class Procesador
{
protected:
  istream *streamPersonas;
  istream *streamNomina;
  istream *streamHoras;
  Planilla *empleados = new Planilla();
  map<int, float> salariosNomina;
  map<int, string> salariosHora;
  float total = 0;
  float impuestos=0;

public:
  Procesador(istream *streamPersonas, istream *streamNomina, istream *streamHoras);
  void anadirSalariosNomina();
  void anadirSalariosHoras();
  void anadirEmpleados();
  float obtenerNomina(int id);
  string obtenerHoras(int id);
  string obtenerEmpleado(int id);
  friend ostream &operator<<(ostream &o, const Procesador *procesador);
};

#endif