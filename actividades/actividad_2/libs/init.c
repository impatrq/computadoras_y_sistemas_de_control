#include "init.h"
#include "hardware/pwm.h"

// Variable para guardar el valor de temperatura
float temperatura = 0.0;
// Variable para guardar el valor del setpoint
float setpoint = 0.0;
// Creo un repeating timer
struct repeating_timer timer;

/*
 * @brief Inicializacion de perifericos
 */
 void init(void) {
  // Inicializacion de UART
  stdio_init_all();
  // Creo un callback para la interrupcion del timer
  add_repeating_timer_ms(ADC_DELAY_MS, muestreo_periodico, NULL, &timer);
  // Configuro el I2C0 a 100 KHz de clock
  i2c_init(i2c0, SCL_FREQ);
  // Elijo GPIO4 como linea de SDA
  gpio_set_function(SDA_GPIO, GPIO_FUNC_I2C);
  // Elijo GPIO5 como linea de SCL
  gpio_set_function(SCL_GPIO, GPIO_FUNC_I2C);
  // Activo pull-up en ambos GPIO, son debiles por lo que
  // es recomendable usar pull-ups externas
  gpio_pull_up(SDA_GPIO);
  gpio_pull_up(SCL_GPIO);
  // Inicializo LCD
  lcd_init();
  // Limpio LCD
  lcd_clear();
  // Escribo lo basico
  lcd_string("TEMP=");
  lcd_set_cursor(1, 0);
  lcd_string("SETP=");
  // Inicializo ADC
  adc_init();
  // Inicializo el GPIO del NTC como entrada analogica
  adc_gpio_init(NTC_GPIO);
  // Inicializo el GPIO del potenciometro como entrada analogica
  adc_gpio_init(SP_GPIO);
  // Inicializacion de PWM
  // - 100 Hz de frecuencia
  // - Ancho de pulso inicial del 0%

}

/*
 * @brief Callback para la interrupcion de timer
 * @param t: puntero a repeating_timer
 */
bool muestreo_periodico(struct repeating_timer *t) {
  // Canal elegido, no se pierde el valor aunque sea local (static)
  static uint8_t selected_channel = 0;
  // Constante de proporcionalidad de NTC
  const float beta = 3950.0;
  // Cambio de canal 0 a 1 o viceversa
  selected_channel ^= 1;
  adc_select_input(selected_channel);
  // Lectura analogica (variable adc_value)
  uint16_t adc_value = adc_read();
  // Verifico que canal lei
  if(selected_channel == 1) {
    // Canal 1: termistor. Calcular valor de temperatura (variable temperatura)
    temperatura = 1 / (log(1 / (4095. / adc_value - 1)) / beta + 1.0 / 298.15) - 273.15;
  }
  else {
    // Canal 0: potenciometro. Calcular el valor de temperatura equivalente (4095 = 35 grados)
    
  }

  // Verifico que se hayan leido ambos canales antes de activar el control
  if(setpoint != 0.0 && temperatura != 0.0) {
    // Calcular error (temperatura - setpoint)
    float error = temperatura - setpoint;
    // Llamar al control proporcional
    int16_t control_p = saturador(control_proporcional(error), PWM_WRAP);
    // Verificar el signo del control
    if((int8_t)temperatura < (int8_t)setpoint) {
      // Si es negativo: temperatura < setpoint -> caliento
      // Apagar un canal de PWM

    }
    else if((int8_t)temperatura > (int8_t)setpoint) {
      // Si es positivo: temperatura < setpoint -> enfrio
      // Apagar un canal de PWM

    }
    else {
      // Apagar canales de PWM

    }
  }
}