// Inclusion de librerias
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "lcd_i2c.h"
#include <math.h>

// GPIO del ADC
#define ANALOG_GPIO
// Canal del ADC
#define ANALOG_C

// Tiempo de refresco para el siete segmentos
#define SLEEP_MS 10
// Tiempo entre conversiones
#define ADC_DELAY_MS  500

// Constante de proporcionalidad para el NTC
#define BETA
// Resistencia a 25 grados del NTC
#define RT0
// Resistencia en serie al NTC
#define RS

// Variable para almacenar el resultado del ADC
uint16_t adc_value = 0;
// Variable para guardar el valor de temperatura
float temperatura = 0.0;

/*
 * @brief Callback para la interrupcion de timer
 * @param t: puntero a repeating_timer
 */
bool muestreo_periodico(struct repeating_timer *t) {
  // Lectura analogica (variable adc_value)

  // Calcular valor de temperatura (variable temperatura)

}

/*
 * @brief Display temperature value in 7 segment display
 * @param temperature: value to display
 */
void display_temp(float temperatura) {
  // Variable para armar el string
  char str[16];
  // Armo string con temperatura
  sprintf(str, "Temp=%.2f C", temperatura);
  // Limpio display (si lo hubiese)

  // Muestro (printf o lcd_string)

}

/*
 * @brief Programa principal
 */
int main() {
  // Inicializacion de UART
  stdio_init_all();
  // Creo un repeating timer
  struct repeating_timer timer;
  // Creo un callback para la interrupcion del timer
  add_repeating_timer_ms(ADC_DELAY_MS, muestreo_periodico, NULL, &timer);
  // Inicializo ADC

	// Inicializo GPIO26 como entrada analogica

  // Selecciono canal analogico


	// Solo si se usa LCD con I2C
	// Configuro el I2C0 a 100 KHz de clock

	// Elijo GPIO4 como linea de SDA

	// Elijo GPIO5 como linea de SCL

	// Activo pull-up en ambos GPIO, son debiles por lo que
	// es recomendable usar pull-ups externas

	// Inicializo display (si lo hubiese)


	// Bucle infinito
  	while (true) {
    	// Muestro temperatura
    	display_temp(temperatura);
    	// Espero
    	sleep_ms(SLEEP_MS);
  	}
}
