# 1. ACTIVIDAD 1 - “MUESTREO PERIODICO DE TEMPERATURA”

## 1.1 OBJETIVOS

Repasar el funcionamiento de un ADC y hacer uso de timers para lograr un muestreo periodico. Hacer uso de una interfaz gráfica como un display 7 segmentos para mostrar la temperatura.

## 1.2 REALIZACION DE LA ACTIVIDAD

Se encuentra una simulación ya armada en Wokwi, un simulador online para algunos microcontroladores. El proyecto en cuestión puede encontrarse [aquí](https://wokwi.com/projects/357959003725467649). Consiste en un muestreo periodico de temperatura con un NTC. En este repo van a encontrar los archivos necesarios para realizar la actividad. Las tareas a realizar son:

1. La función _muestreo_periodico_ se ejecuta periódicamente gracias a una interrupción por timer. Cada vez que se dispare, debe:

    a. Hacer una lectura con el ADC y guardar el valor en la variable _adc_reading_.
    
    b. Calcular y guardar la temperatura leída del NTC en la variable _temperatura_.

2. Descargar el _firmware.uf2_ e implementarlo en un circuito real.

3. Aumentar _SLEEP_MS_ a 200, volver a descargar _firmware.uf2_ y ver la diferencia.

4. Se quiere obtener un valor más estable de temperatura, obteniendo 10 muestras (conversiones) en el mismo tiempo (500 ms) y promediándolas. Para eso:

    a. Cambiar el tiempo de conversiones que marca la variable _ADC_DELAY_MS_ a 50 (para tener conversiones cada 50 ms).

    b. Crear una variable global de contador de conversiones del tipo entero e inicializarla en cero.

    c. En la función _muestreo_periodico_, acumular cada nuevo valor de temperatura calculado en la variable temperatura e incrementar el contador.

    d. Cuando el contador llegue a 10, setearlo a cero y hacer el promedio de las diez muestras en la variable temperatura.

## 1.3 ENTREGA DE LA ACTIVIDAD

La entrega de la actividad se hace en un repositorio individual de GitHub que se deberá entregar en la tarea correspondiente en Classroom donde será calificada. La actividad tiene un parcialito asociado que se debe completar y aprobar.