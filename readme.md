# Para correr este programa use en su terminal linux

make all
bin/organizador

# Para correr los tests

make tests
bin/tests


# Libreria de planilla

Especificación de requerimientos:
Se requiere construir un sistema que lea tres archivos de datos, los procese y luego genere un
archivo con la información del monto a pagar por persona y qué supervisor debe realizar el
pago (excepto el director, el cual se paga a sí mismo).


# Clases presentes
## Empleados y subclases
En la empresa trabajan empleados los cuales presentan las siguientes características generales:



|  ID_Empleado |  Nombre  |  Apellido  | Email |id_TipoEmpleado | ID_Supervisor 1 | ID_Supervisor 2 |   |
|---|---|---|---|---|---|---|---|

De los cuales hay 2 tipo de empleado

## Empleado de Nomina con id  1 con formula de pago:

Se cuenta con un los salarios mensuales brutos  de los empleados de nomina en el archivo Nomina.txt con el siguiente desglose:
|  ID_Empleado |  Pago mensual bruto (sin cálculo de retención)  | 
|---|---|

Por lo que el calculo se realizará:
Monto bruto - retención del 7%* 

*:El 7% se cobra segun legislación actual


## Profesional por horas con id 2 con formula de pago: 
Se cuenta con un los salarios mensuales brutos  de los profesionales por horas en el archivo HorasTrabajadas.txt con el siguiente desglose:
|  ID_Empleado |  Monto por hora  |Horas laboradas en el mes |
|---|---|---|

Por lo que el calculo se realizará:
Monto por hora*Horas laboradas en el mes

## - Archivo de salida

Archivo de salida - Reporte.csv

-El archivo de salida debe ser un archivo separado por comas (csv).

-En cada línea, incluir por empleado y profesional por horas:
ID_Empleado,Nombre completo,Nombre completo del supervisor,Monto a pagar (monto neto)

-Al final del archivo, incluir a manera de resumen:
Subtotal (suma de montos a pagar), total de impuestos a retener, total (subtotal más total de
impuestos).


## - Requerimiento no funcional


- Se espera la implementación de las relaciones entre empleado y supervisor a través de
un árbol.
- La tarea debe de entregarse como un repositorio en Git (ya sea en git.ucr.ac.cr o en
github.com). En la entrega en mediación virtual, se indica el URL del repositorio.
- El repositorio no debe de incluir ningún ejecutable (sólo código fuente y nada
compilado).
- Asuman que los archivos de entrada vienen sin errores (happy path).
- Se definen los streams de entrada y de salida desde el main y se inyectan en el
constructor de la clase principal (ver ejemplo 5 de inyección de dependencias del
istream en ejemplo 10).


# Contribuciones
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.