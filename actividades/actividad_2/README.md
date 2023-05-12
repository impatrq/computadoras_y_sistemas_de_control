# 2. ACTIVIDAD 2 - “CONTROL PROPORCIONAL DE TEMPERATURA”

## 2.1 OBJETIVOS

Repasar el funcionamiento de un ADC y hacer uso de timers para lograr un muestreo periodico. Hacer uso de una interfaz gráfica como un display LCD 16x2 con I2C para mostrar la temperatura y referencia. Entender e implementar un control proporcional mediante la aplicación de PWM.

## 2.2 REALIZACIÓN DE LA ACTIVIDAD

Se encuentra una simulación ya armada en Wokwi, un simulador online para algunos microcontroladores. Todo lo necesario para resolver la actividad se encuentra en el repositorio. Consiste en un muestreo periodico de temperatura con un NTC y una referencia indicada con un potenciómetro para luego controlar dos salidas de PWM de manera proporcional al error.

Las tareas a realizar son:

1. En el archivo _init.c_ se va a encontrar una función llamada _init_ que se encarga de inicializar todos los periféricos que se usan en el proyecto. Al final de la función, debe inicializarse el PWM para dos salidas. Estas salidas deben:

    a. Estar asociadas a los `GPIO16` y `GPIO17`.
    
    b. Tener una frecuencia de 100 Hz.
    
    c. Tener un ciclo de actividad inicial del 0%.

2. En la función _muestreo_periodico_ en el mismo archivo, se debe completar la acción de control. En esta función se hacen las lecturas analógicas del NTC y del potenciómetro para obtener la referencia.

    a. En la línea 69 (primera línea luego del else), se debe calcular cual es el valor de referencia de temperatura, sabiendo que el valor analogico leido (0 a 4095) se encuentra en la variable _adc_value_ y que la equivalencia será que 4095 son 35 grados centígrados. El resultado se debe guardar en la variable _setpoint_.

    b. Casi al final de la función, se evalúa la variable de control llamada _control_p_ y de acuerdo a su signo, se apaga una salida de PWM y se debe prender la otra con el valor de esa variable.

3. En el archivo _control.h_ se tiene una única función que calcula en base al error, la acción proporcional de control necesaria. Se debe calcular la constante de proporcionalidad necesaria para esto, sabiendo que a 10 grados centígrados de diferencia entre la referencia y la real se debe tener un ancho de pulso del 100%.

## 2.3 ENTREGA DE LA ACTIVIDAD

La entrega de la actividad se hace en un repositorio individual de GitHub que se deberá entregar en la tarea correspondiente en Classroom donde será calificada. La
actividad tiene un parcialito asociado que se debe completar y aprobar.