#include <gtest/gtest.h>
#include "../src/planilla.h"
#include "../src/empleadoNomina.h"
#include "../src/empleadoHoras.h"
using namespace std;

namespace
{
    TEST(Tests_Planilla, Test_InsertarEmpleado)
    {
        /// AAA

        // Arrange - configurar el escenario
        Planilla *planilla = new Planilla();
        Empleado *empleado = new EmpleadoNomina(1, "juan", "carrillo", "juancarrillo@ucr", 1, 1, 4600);

        // Act - ejecute la operación`-

        planilla->InsertarEmpleado(empleado);
        string esperado = "1 juan carrillo juancarrillo@ucr 1 1 4600.00 0.000";
        string resultado = planilla->ObtenerEmpleado(1)->InfoCompletaEmpleados();

        //  delete planilla;
        // delete empleado;

        // Assert - valide los resultados

        EXPECT_EQ(esperado, resultado);
    }

    TEST(Tests_Planilla, Test_RecorrerArbol)
    {
        /// AAA

        // Arrange - configurar el escenario
        Planilla *planilla = new Planilla();
        Empleado *empleadoSupervisor = new EmpleadoNomina(1, "juan", "carrillo", "juancarrillo@ucr", 1, 1, 4600);

        Empleado *empleadoHoras = new EmpleadoHoras(2, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 55, 42.26);

        Empleado *empleadoNomina = new EmpleadoNomina(3, "juan", "carrillo", "juancarrillo@ucr", 1, 2, 4600);

        Empleado *empleadoNomina1 = new EmpleadoNomina(4, "juana", "carrillo", "juancarrillo@ucr", 1, 2, 4900);

        Empleado *empleadoHoras1 = new EmpleadoHoras(5, "Steven", "Tyler", "steven_tyler@biz.com", 1, 1, 50, 42.26);

        Empleado *empleadoNomina2 = new EmpleadoNomina(6, "maria", "carrillo", "mariacarrillo@ucr", 1, 5, 4900);

        // Act - ejecute la operación`-
        planilla->InsertarEmpleado(empleadoSupervisor);
        planilla->InsertarEmpleado(empleadoHoras);
        planilla->InsertarEmpleado(empleadoHoras1);
        planilla->InsertarEmpleado(empleadoNomina);
        planilla->InsertarEmpleado(empleadoNomina1);
        planilla->InsertarEmpleado(empleadoNomina2);
        Nodo *nodoSupervisor = planilla->ObtenerNodo(1);

        string esperado = "1 juan carrillo juancarrillo@ucr 1 1 4600.00 0.000\n2 Denis Tyler denis_tyler@biz.com 1 1 55 42.26 0.0\n3 juan carrillo juancarrillo@ucr 1 2 4600.00 0.000\n4 juana carrillo juancarrillo@ucr 1 2 4900.00 0.000\n5 Steven Tyler steven_tyler@biz.com 1 1 50 42.26 0.0\n6 maria carrillo mariacarrillo@ucr 1 5 4900.00 0.000\n";
        string resultado = planilla->RecorrerArbol(*nodoSupervisor);
        cout << resultado << endl;

        //  delete planilla;
        // delete empleado;

        // Assert - valide los resultados

        EXPECT_EQ(esperado, resultado);
    }

}