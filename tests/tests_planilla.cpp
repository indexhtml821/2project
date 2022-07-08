#include <gtest/gtest.h>
#include "../src/planilla.h"
#include "../src/empleadoNomina.h"
using namespace std;

namespace
{
    TEST(Tests_Planilla, Test_Planilla_Insertar_Empleado)
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
    

}