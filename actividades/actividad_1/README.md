# 1. ACTIVIDAD 1 - “MUESTREO PERIODICO DE TEMPERATURA”

## 1.1 OBJETIVOS

Repasar el funcionamiento de un ADC y hacer uso de timers para lograr un muestreo periodico. Hacer uso de una interfaz gráfica como un display LCD con I2C para mostrar la temperatura. De no haber display LCD con I2C, usar la consola.

## 1.2 REALIZACION DE LA ACTIVIDAD

Abriendo el [main.c](main.c), vamos a realizar lo siguiente:

1. Inicializar el ADC para poder hacer la lectura de temperatura en cualquiera de los GPIO apropiados.

2. De contar con un display LCD, hacer la inicializacion del I2C y el display.

3. La función _muestreo\_periodico_ se ejecuta periódicamente gracias a una interrupción por timer. Cada vez que se dispare, debe:

    a. Hacer una lectura con el ADC y guardar el valor en la variable _adc_reading_.

    b. Calcular y guardar la temperatura leída del NTC en la variable **global** _temperatura_.

2. Compilar, flashear el microcontrolador e implementarlo en un circuito real. Seguir instrucciones correspondientes.

3. Se quiere obtener un valor más estable de temperatura, obteniendo 10 muestras (conversiones) en el mismo tiempo (500 ms) y promediándolas.

## 1.3 ENTREGA DE LA ACTIVIDAD

La entrega de la actividad se hace en un repositorio individual de GitHub que se deberá entregar en la tarea correspondiente en Classroom donde será calificada. La actividad tiene un parcialito asociado que se debe completar y aprobar.
