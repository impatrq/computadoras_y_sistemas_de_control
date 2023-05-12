/*
 * @brief Calcula el valor que aporta el control proporcional
 * a la variable de control
 * @param error: valor del error calculado para el sistema 
 * @return valor porcentual de ancho de pulso
 */
static inline float control_proporcional(float error) {
  // Constante de proporcionalidad
  const float k = 1.0;
  // Devolver el porcentaje de ciclo de actividad
  return k * error;
}