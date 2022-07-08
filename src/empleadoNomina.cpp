#include "empleadoNomina.h"
#include <iomanip>
#include <sstream>

using namespace std;

EmpleadoNomina::EmpleadoNomina(int idEmpleado,
                               string nombre,
                               string apellido,
                               string email,
                               int tipoEmpleado,
                               int idSupervisor,
                               float salario)
{

    this->idEmpleado = idEmpleado;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->tipoEmpleado = tipoEmpleado;
    this->idSupervisor = idSupervisor;
    this->salarioBruto = salario;
}

void EmpleadoNomina::CalculoPago()
{
    float impuesto = 0.07;
    salario = this->salarioBruto - (this->salarioBruto * impuesto);
}

string EmpleadoNomina::InfoEmpleadoParaArchivo()
{

    stringstream salarioBrutoAPrecisar;
    salarioBrutoAPrecisar << std::fixed << std::setprecision(2) << this->salarioBruto;
    stringstream salarioFinalAPrecisar;
    salarioFinalAPrecisar << std::fixed << std::setprecision(3) << this->salario;

    string idEmpleado = (std::to_string(this->idEmpleado));
    string salario = salarioFinalAPrecisar.str();

    return idEmpleado + " " + this->nombre + " " + this->apellido + " " + salario;
}

string EmpleadoNomina::InfoCompletaEmpleados()
{

    stringstream salarioBrutoAPrecisar;
    salarioBrutoAPrecisar << std::fixed << std::setprecision(2) << this->salarioBruto;
    stringstream salarioFinalAPrecisar;
    salarioFinalAPrecisar << std::fixed << std::setprecision(3) << this->salarioFinal;

    string idEmpleado = (std::to_string(this->idEmpleado));
    string tipoEmpleado = (std::to_string(this->tipoEmpleado));
    string idSupervisor = (std::to_string(this->idSupervisor));
    string salarioBruto = salarioBrutoAPrecisar.str();
    string salarioFinal = salarioFinalAPrecisar.str();

    return idEmpleado + " " + this->nombre + " " + this->apellido + " " + this->email + " " + tipoEmpleado + " " + idSupervisor + " " + salarioBruto + " " + salarioFinal;
}
float EmpleadoNomina::DevolverSalario()
{
    return this->salario;
}
