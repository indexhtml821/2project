#include <gtest/gtest.h>
#include "../src/empleadoNomina.h"

namespace
{
  TEST(Tests_Empleado_Nomina, Test_CalculoPago)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoNomina empleadonomina(1, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 4000.67);

    // Act - ejecute la operación`-
    empleadonomina.CalculoPago();
    float actual = empleadonomina.DevolverSalario();
    float esperada = 3720.6231;

    // Assert - valide los resultados
    EXPECT_FLOAT_EQ(esperada, actual);
  }

  TEST(Tests_Empleado_Nomina, Test_InfoEmpleadoParaArchivo)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoNomina empleadonomina(1, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 4000.67);

    // Act - ejecute la operación`-
    empleadonomina.CalculoPago();
    string actual = empleadonomina.InfoEmpleadoParaArchivo();
    string esperada = "1 Denis Tyler 3720.623";

    // Assert - valide los resultados
    EXPECT_EQ(esperada, actual);
  }

  TEST(Tests_Empleado_Nomina, Test_InfoCompletaEmpleados)
  {
    /// AAA

    // Arrange - configurar el escenario
    EmpleadoNomina empleadonomina(1, "Denis", "Tyler", "denis_tyler@biz.com", 1, 1, 4000.67);

    // Act - ejecute la operación`-
    empleadonomina.CalculoPago();
    string actual = empleadonomina.InfoCompletaEmpleados();
    string esperada = "1 Denis Tyler denis_tyler@biz.com 1 1 4000.67 0.000";

    // Assert - valide los resultados
    EXPECT_EQ(esperada, actual);
  }

}