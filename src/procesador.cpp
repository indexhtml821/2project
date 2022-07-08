#include "procesador.h"
#include "empleadoHoras.h"
#include "empleadoNomina.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

Procesador::Procesador(istream *streamPersonas, istream *streamNomina, istream *streamHoras)
{

    this->streamPersonas = streamPersonas;
    this->streamNomina = streamNomina;
    this->streamHoras = streamHoras;
}

void Procesador::AnadirSalariosNomina()
{
    string infoNomina{};
    int idEmpleado = 0;
    float salario = 0;
    while (std::getline(*(this->streamNomina), infoNomina))
    {
        std::istringstream stream(infoNomina);
        stream >> idEmpleado >> salario;
        this->total += salario;
        this->impuestos += salario * 0.07;
        salariosNomina.insert(std::pair<int, float>(idEmpleado, salario));
    }
}
void Procesador::AnadirSalariosHoras()
{
    string infoHoras{};
    int idEmpleado = 0;
    string precioPorHora = "";
    string horas_a_calcular = "";

    while (std::getline(*(this->streamHoras), infoHoras))
    {
        std::istringstream stream(infoHoras);
        stream >> idEmpleado >> precioPorHora >> horas_a_calcular;
        this->total += stof(precioPorHora) * stoi(horas_a_calcular);
        string infoHorasCacular = precioPorHora + " " + horas_a_calcular;
        salariosHora.insert(std::pair<int, string>(idEmpleado, infoHorasCacular));
    }
}

void Procesador::AnadirEmpleados()
{

    AnadirSalariosHoras();
    AnadirSalariosNomina();
    string infoPersona{};

    while (std::getline(*(this->streamPersonas), infoPersona))
    {
        int idEmpleado = 0;
        string nombre = "";
        string apellido = "";
        string email = "";
        int tipoEmpleado = 0;
        int idSupervisor = 0;
        std::istringstream stream(infoPersona);
        stream >> idEmpleado >> nombre >> apellido >> email >> tipoEmpleado >> idSupervisor;

        if (tipoEmpleado == 1)
        {
            float salario = salariosNomina.at(idEmpleado);
            Empleado *empleadoNuevo = new EmpleadoNomina(idEmpleado,
                                                         nombre,
                                                         apellido,
                                                         email,
                                                         tipoEmpleado,
                                                         idSupervisor,
                                                         salario);
            empleadoNuevo->CalculoPago();
            empleados->InsertarEmpleado(empleadoNuevo);

            // delete empleado nuevo
        }
        else if (tipoEmpleado == 2)
        {
            int horasLaboradas = 0;
            float pagoPorHora = 0;
            string salario = salariosHora.at(idEmpleado);

            std::istringstream stream(salario);
            stream >> pagoPorHora >> horasLaboradas;

            Empleado *empleadoNuevo = new EmpleadoHoras(idEmpleado,
                                                        nombre,
                                                        apellido,
                                                        email,
                                                        tipoEmpleado,
                                                        idSupervisor,
                                                        horasLaboradas,
                                                        pagoPorHora);
            empleadoNuevo->CalculoPago();
            empleados->InsertarEmpleado(empleadoNuevo);
        }
    }
}

float Procesador::ObtenerNomina(int id)
{
    return salariosNomina.at(id);
}

string Procesador::ObtenerHoras(int id)
{
    return salariosHora.at(id);
}

string Procesador::ObtenerEmpleado(int id)
{

    Empleado *empleadoSolicitado = empleados->ObtenerEmpleado(id);

    string infoSolicitada = empleadoSolicitado->InfoEmpleadoParaArchivo();

    return infoSolicitada;
}
float Procesador::ObtenerTotal()
{
    return this->total;
}
float Procesador::Obtenerimpuestos()
{

    return this->impuestos;
}
std::ostream &operator<<(ostream &o, const Procesador *procesador)
{

    int contador = procesador->empleados->DevolverIndicePlanilla();

    for (int i = 1; i < contador + 1; i++)
    {
        Empleado *empleado = procesador->empleados->ObtenerEmpleado(i);
        Empleado *supervisor = procesador->empleados->ObtenerEmpleado(empleado->ObtenerIdSupervisor());

        o << empleado->InfoEmpleadoParaArchivo() << " Supervisor: " << supervisor->ObtenerNombre() << endl;
    }

    o << "Total: " << procesador->total << "  -  Impuestos:  " << procesador->impuestos;

    return o;
}