#include "init.h"

/*
 * @brief Display temperature value in 7 segment display
 * @param valor: value to display
 * @param linea: linea donde mostrar el valor
 */
void display(float valor, uint8_t linea) {
  // String para LCD
  char str[16];
  // Armo string
  sprintf(str, "%.2f", valor);
  // Limpio el LCD
  lcd_set_cursor(linea, 5);
  // Muestro valor de temperatura en el LCD
  lcd_string(str);
}

/*
 * @brief Programa principal
 */
int main() {
  // Inicializacion
  init();
  // Bucle infinito
  while (true) {
    // Muestro temperatura
    display(temperatura, 0);
    // Muestro setpoint
    display(setpoint, 1);
    // Espero
    sleep_ms(SLEEP_MS);
  }
}