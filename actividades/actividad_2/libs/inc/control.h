/**
 * @brief Calcula el valor que aporta el control proporcional
 * a la variable de control
 * @param error valor del error calculado para el sistema 
 * @return valor porcentual de ancho de pulso
 */
static inline float control_proporcional(float error) {
  // Constante de proporcionalidad
  const float k = 1.0;
  // Devolver el porcentaje de ciclo de actividad
  return k * error;
}

/**
 * @brief Verifica que el valor de control no exceda el maximo
 * valor posible de PWM
 * @param duty_ticks cantidad de ticks del duty de PWM para corregir el error
 * @param duty_max_ticks maxima cantidad de ticks del duty de PWM
 * @return valor final de ticks de PWM entre mas menos duty_max_ticks
 */
static inline int16_t saturador(float duty_ticks, int16_t duty_max_ticks) {
  // Variable para el valor final de ticks
  int16_t ticks = (int16_t) duty_ticks;
  // Verifico que los ticks no superen el maximo
  if(duty_ticks > duty_max_ticks) { ticks = duty_max_ticks; }
  // Verifico que los ticks no superen el minimo
  else if(duty_ticks < (-1 * duty_max_ticks)) { ticks = -1 * duty_max_ticks; }
  // Devuelvo el valor de ticks
  return ticks;
}