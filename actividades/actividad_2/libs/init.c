#include "init.h"

// Variable para guardar el valor de temperatura
float temperatura = 0.0;
// Variable para guardar el valor del setpoint
float setpoint = 0.0;

/*
 * @brief Inicializacion de perifericos
 */
 void init(void) {
  // Inicializacion de UART
  stdio_init_all();
  // Creo un repeating timer
  struct repeating_timer timer;
  // Creo un callback para la interrupcion del timer
  add_repeating_timer_ms(ADC_DELAY_MS, muestreo_periodico, NULL, &timer);
  // Configuro el I2C0 a 100 KHz de clock
  i2c_init(i2c0, 100 * 1000);
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
  const uint16_t beta = 3950;
  // Cambio de canal 0 a 1 o viceversa
  adc_select_input(selected_channel ^ 1);
  // Lectura analogica (variable adc_value)
  uint16_t adc_value = adc_read();
  // Verifico que canal lei
  if(selected_channel == 0) {
    // Canal 0: termistor. Calcular valor de temperatura (variable temperatura)
    temperatura = 1 / (log(1 / (4095. / adc_value - 1)) / beta + 1.0 / 298.15) - 273.15;
  }
  else {
    // Canal 1: potenciometro. Calcular el valor de temperatura equivalente (4095 = 35 grados)
    
    // Calcular error (temperatura - setpoint)
    float error = temperatura - setpoint;
    // Llamar al control proporcional
    float control_p = control_proporcional(error);
    // Verificar el signo del control
    if(control_p < 0) {
      // Si es negativo: temperatura > setpoint -> enfrio
      // Apagar un canal de PWM
      
      // Encender el otro
      
    }
    else {
      // Si es positivo: temperatura < setpoint -> caliento
      // Apagar un canal de PWM

      // Encender el otro

    }
  }
}