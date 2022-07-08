#include <gtest/gtest.h>
#include "../src/nodo.h"
#include "../src/empleadoHoras.h"
#include "../src/empleadoNomina.h"

namespace
{
  TEST(Tests_Empleado_Horas, Test_CrearNodo)
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

  TEST(Tests_Empleado_Horas, Test_InsertarSupervisorySupervisado)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoHoras *empleadoHoras = new EmpleadoHoras(2, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 55, 42.26);
    Nodo *nodo = new Nodo(empleadoHoras->ObtenerIdEmpleado(), empleadoHoras);

    EmpleadoHoras *empleadoHoraSupervisor = new EmpleadoHoras(1, "Steven", "Tyler", "steven_tyler@biz.com", 1, 1, 50, 42.26);
    Nodo *nodoSupervisor = new Nodo(empleadoHoraSupervisor->ObtenerIdEmpleado(), empleadoHoraSupervisor);

    nodo->InsertarSupervisor(nodoSupervisor);

    nodoSupervisor->InsertarSupervisar(nodo);

    // Act - ejecute la operación`-

    // Obtiene el supervisor y checa si es insertadoc correctamente
    Empleado *empleadoResultado = nodo->DevolverSupervisor();

    string actual = empleadoResultado->InfoCompletaEmpleados();
    string esperada = empleadoHoraSupervisor->InfoCompletaEmpleados();

    Empleado *empleadoResultadoSupervisar = nodoSupervisor->DevolverSupervisar(2);

    string actual1 = empleadoResultadoSupervisar->InfoCompletaEmpleados();
    string esperada1 = empleadoHoras->InfoCompletaEmpleados();

    // Assert - valide los resultados

    // se valida nodo haya guardado correctamente el supervisor
    EXPECT_EQ(esperada, actual);

    // se valida nodo haya guardado correctamente el supervisado
    EXPECT_EQ(esperada1, actual1);

    delete nodo;
    delete nodoSupervisor;
  }

  TEST(Tests_Empleado_Horas, Test_DevolverInfoNodo)
  {
    /// AAA
   //
    // Arrange - configurar el escenario

    EmpleadoHoras *empleadoHoraSupervisor = new EmpleadoHoras(1, "Steven", "Tyler", "steven_tyler@biz.com", 1, 1, 50, 42.26);
    Nodo *nodoSupervisor = new Nodo(empleadoHoraSupervisor->ObtenerIdEmpleado(), empleadoHoraSupervisor);

    EmpleadoHoras *empleadoHoras = new EmpleadoHoras(2, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 55, 42.26);
    Nodo *nodo = new Nodo(empleadoHoras->ObtenerIdEmpleado(), empleadoHoras);

    EmpleadoNomina *empleadoNomina = new EmpleadoNomina(3, "juan", "carrillo", "juancarrillo@ucr", 1, 1, 4600);
    Nodo *nodo = new Nodo(empleadoHoras->ObtenerIdEmpleado(), empleadoHoras);

        EmpleadoNomina *empleadoNomina = new EmpleadoNomina(3, "juan", "carrillo", "juancarrillo@ucr", 1, 1, 4600);
    Nodo *nodo = new Nodo(empleadoHoras->ObtenerIdEmpleado(), empleadoHoras);

    nodo->InsertarSupervisor(nodoSupervisor);

    nodoSupervisor->InsertarSupervisar(nodo);

    // Act - ejecute la operación`-

    // Obtiene el supervisor y checa si es insertadoc correctamente
    Empleado *empleadoResultado = nodo->DevolverSupervisor();

    string actual = empleadoResultado->InfoCompletaEmpleados();
    string esperada = empleadoHoraSupervisor->InfoCompletaEmpleados();

    Empleado *empleadoResultadoSupervisar = nodoSupervisor->DevolverSupervisar(2);

    string actual1 = empleadoResultadoSupervisar->InfoCompletaEmpleados();
    string esperada1 = empleadoHoras->InfoCompletaEmpleados();

    // Assert - valide los resultados

    // se valida nodo haya guardado correctamente el supervisor
    EXPECT_EQ(esperada, actual);

    // se valida nodo haya guardado correctamente el supervisado
    EXPECT_EQ(esperada1, actual1);

    delete nodo;
    delete nodoSupervisor;
  }

}