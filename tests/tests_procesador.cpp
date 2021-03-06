#include <gtest/gtest.h>
#include "../src/procesador.h"

namespace
{
  TEST(Tests_Procesador, Test_AnadirSalariosNomina)
  {
    /// AAA

    // Arrange - configurar el escenario
    string pruebaNomina = "1 4600.98 \n 2 3700.24";
    string pruebaPersonas = "cumple requisito";
    string pruebaHoras = "cumple requisito ";
    istringstream streamNomina(pruebaNomina);
    istringstream streamPersonas(pruebaPersonas);
    istringstream streamHoras(pruebaHoras);

    Procesador procesador(&streamPersonas, &streamNomina, &streamHoras);

    // Act - ejecute la operación`-
    procesador.AnadirSalariosNomina();

    float impuestosEsperado = 581.08539;
    float impuestosResultado = procesador.Obtenerimpuestos();

    // Assert - valide los resultados

    EXPECT_FLOAT_EQ(impuestosEsperado, impuestosResultado);

    float esperada = 4600.98;
    float resultado = procesador.ObtenerNomina(1);

    EXPECT_FLOAT_EQ(esperada, resultado);
  }

  TEST(Tests_Procesador, Test_AnadirSalariosHoras)
  {
    /// AAA

    // Arrange - configurar el escenario
    string pruebaNomina = "1 4600.98";
    string pruebaPersonas = "cumple requisito";
    string pruebaHoras = "452 34.84 43 ";
    istringstream streamNomina(pruebaNomina);
    istringstream streamPersonas(pruebaPersonas);
    istringstream streamHoras(pruebaHoras);

    Procesador procesador(&streamPersonas, &streamNomina, &streamHoras);

    // Act - ejecute la operación`-
    procesador.AnadirSalariosHoras();

    // Assert - valide los resultados

    string esperada = "34.84 43";
    string resultado = procesador.ObtenerHoras(452);

    EXPECT_EQ(esperada, resultado);
  }

  TEST(Tests_Procesador, TestAnadirEmpleados)
  {
    /// AAA

    // Arrange - configurar el escenario

    ostringstream streamPruebaPersonas{};
    streamPruebaPersonas << "1 Denis Tyler denis_tyler@biz.com 1 1" << endl;
    streamPruebaPersonas << "2 Clarissa Parker clarissa_parker@biz.com 1 1" << endl;
    streamPruebaPersonas << "487 Bart Noon Bart_Noon486@iatim.tech 2 1" << endl;
    streamPruebaPersonas << "516 Rosa Tait Rosa_Tait1615@tonsy.org 2 2" << endl;

    ostringstream streamPruebaNomina{};
    streamPruebaNomina << "1 4600.9" << endl;
    streamPruebaNomina << "2 3097.50" << endl;

    ostringstream streamPruebaHoras{};
    streamPruebaHoras << "487 45.91 60" << endl;
    streamPruebaHoras << "516 47.20 20" << endl;

    string pruebaPersonas = streamPruebaPersonas.str();
    string pruebaNomina = streamPruebaNomina.str();
    string pruebaHoras = streamPruebaHoras.str();

    istringstream streamNomina(pruebaNomina);
    istringstream streamPersonas(pruebaPersonas);
    istringstream streamHoras(pruebaHoras);

    Procesador procesador(&streamPersonas, &streamNomina, &streamHoras);

    // Act - ejecute la operación`-
    procesador.AnadirEmpleados();

    // Assert - valide los resultados

    float totalResultado = procesador.ObtenerTotal();
    float totalEsperado = 11397;

    EXPECT_FLOAT_EQ(totalEsperado, totalResultado);

    string esperada[4] = {"1 Denis Tyler 4278.837", "2 Clarissa Parker 2880.675", "487 Bart Noon 2754.6", "516 Rosa Tait 944.0"};
    int idResultado[4] = {1, 2, 487, 516};

    for (int i = 0; i < 4; i++)
    {
      string resultado = procesador.ObtenerEmpleado(idResultado[i]);
      EXPECT_EQ(esperada[i], resultado);
    }
  }

}