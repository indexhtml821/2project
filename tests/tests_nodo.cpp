#include <gtest/gtest.h>
#include "../src/nodo.h"
#include "../src/empleadoHoras.h"
#include "../src/empleadoNomina.h"

namespace
{
  TEST(Tests_Nodo, Test_CrearNodo)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoHoras *empleadoHoras = new EmpleadoHoras(1, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 55, 42.26);

    Nodo *nodo = new Nodo(empleadoHoras->ObtenerIdEmpleado(), empleadoHoras);

    // Act - ejecute la operación`-
    Empleado *empleadoResultado = nodo->DevolverEmpleado();

    string esperada = empleadoResultado->InfoCompletaEmpleados();
    string actual = empleadoHoras->InfoCompletaEmpleados();

    delete nodo;

    // Assert - valide los resultados
    EXPECT_EQ(esperada, actual);
  }

  TEST(Tests_Nodo, Test_InsertarSupervisorySupervisado)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoHoras *empleadoHoras = new EmpleadoHoras(2, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 55, 42.26);
    Nodo *nodo = new Nodo(empleadoHoras->ObtenerIdEmpleado(), empleadoHoras);

    Empleado *empleadoNomina = new EmpleadoNomina(3, "juan", "carrillo", "juancarrillo@ucr", 1, 1, 4600);
    Nodo *nodo1 = new Nodo(empleadoNomina->ObtenerIdEmpleado(), empleadoNomina);

    EmpleadoHoras *empleadoHoraSupervisor = new EmpleadoHoras(1, "Steven", "Tyler", "steven_tyler@biz.com", 1, 1, 50, 42.26);
    Nodo *nodoSupervisor = new Nodo(empleadoHoraSupervisor->ObtenerIdEmpleado(), empleadoHoraSupervisor);

    nodo->InsertarSupervisor(nodoSupervisor);

    nodoSupervisor->InsertarSupervisar(nodo);
    nodoSupervisor->InsertarSupervisar(nodo1);

    // Act - ejecute la operación`-

    // Obtiene el supervisor y checa si es insertadoc correctamente
    Empleado *empleadoResultado = nodo->DevolverSupervisor();

    string actual = empleadoResultado->InfoCompletaEmpleados();
    string esperada = empleadoHoraSupervisor->InfoCompletaEmpleados();

    Empleado *empleadoResultadoSupervisar = nodoSupervisor->DevolverSupervisar(2);

    string actual1 = empleadoResultadoSupervisar->InfoCompletaEmpleados();
    string esperada1 = empleadoHoras->InfoCompletaEmpleados();

    Empleado *empleadoResultadoSupervisar2 = nodoSupervisor->DevolverSupervisar(3);

    string actual2 = empleadoResultadoSupervisar2->InfoCompletaEmpleados();
    string esperada2 = empleadoNomina->InfoCompletaEmpleados();

    // Assert - valide los resultados

    // se valida nodo haya guardado correctamente el supervisor
    EXPECT_EQ(esperada, actual);

    // se valida nodo haya guardado correctamente el supervisado
    EXPECT_EQ(esperada1, actual1);

    // se valida nodo haya guardado correctamente el más de 1 supervisado
    EXPECT_EQ(esperada2, actual2);

    delete nodo;
    delete nodo1;
    delete nodoSupervisor;
  }

}