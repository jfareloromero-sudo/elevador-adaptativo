# SISTEMA EMBEBIDO DE CONTROL PARA ELEVADOR ADAPTATIVO

## 1. Descripción del proyecto

Este proyecto consiste en el desarrollo de un prototipo de elevador adaptativo mediante un sistema embebido basado en Arduino Uno, que permite simular el desplazamiento entre tres pisos, monitorear condiciones de sobrecarga y generar alertas ante situaciones de riesgo.

El sistema integra sensores, actuadores y dispositivos de señalización para facilitar el monitoreo y control del funcionamiento del elevador.

## 2. Objetivo general

Desarrollar un prototipo de elevador adaptativo mediante tecnologías de sistemas embebidos, incorporando mecanismos de monitoreo de peso y alertas multimodo para contribuir a la prevención de riesgos durante su funcionamiento.

## 3. Objetivos específicos

- Implementar un sistema de control mediante Arduino Uno.
- Simular la detección de sobrecarga utilizando un sensor FSR o potenciómetro.
- Incorporar un servomotor para representar el movimiento entre tres pisos.
- Implementar alertas visuales y sonoras mediante LEDs y buzzer.
- Simular una alerta de inundación mediante un pulsador.
- Evaluar el funcionamiento del prototipo mediante pruebas en Wokwi.

## 4. Componentes utilizados

| Componente | Función |
|---|---|
| Arduino Uno | Unidad principal de control |
| Sensor FSR 402 | Detección de presión o peso |
| Potenciómetro | Simulación del sensor de peso en Wokwi |
| Servomotor | Simulación del movimiento del elevador |
| LCD 16x2 I2C | Visualización de información |
| LED verde | Indicación de funcionamiento normal |
| LED rojo | Señalización de alertas |
| Buzzer | Alarma sonora |
| Pulsadores | Selección de pisos y alerta de inundación |

## 5. Funcionamiento del sistema

El prototipo permite seleccionar tres niveles mediante pulsadores. El servomotor representa el desplazamiento del elevador entre los pisos.

El sistema monitorea continuamente la lectura del sensor de peso. Cuando supera el umbral establecido, activa una alerta de sobrecarga, enciende el LED rojo y genera una señal sonora.

También incorpora un pulsador para simular una condición de inundación. Cuando se activa, el sistema genera una alerta visual y sonora y detiene el movimiento normal.

La pantalla LCD permite visualizar el estado del sistema y las condiciones de funcionamiento.

## 6. Tecnologías utilizadas

- Arduino IDE.
- Lenguaje de programación C++.
- Plataforma de simulación Wokwi.
- GitHub para el almacenamiento y control de versiones del código.
- Librerías Servo y LiquidCrystal_I2C.

## 7. Archivos del proyecto

- `sketch.ino`: código fuente del sistema de control.
- `diagram.json`: configuración de los componentes y conexiones del circuito en Wokwi.

## 8. Pruebas del prototipo

Se contemplan las siguientes pruebas:

1. Funcionamiento normal del elevador.
2. Desplazamiento entre los tres pisos.
3. Detección de sobrecarga.
4. Activación de alertas visuales y sonoras.
5. Simulación de alerta de inundación.

## 9. Resultados esperados

Se espera obtener un prototipo funcional en simulación que permita representar el control del elevador, identificar condiciones de sobrecarga y generar alertas ante situaciones de riesgo, demostrando la integración de tecnologías embebidas.

## 10. Autoría

Proyecto académico desarrollado como parte del proceso de formación en Ingeniería de Sistemas.

**Repositorio:** GitHub - elevador-adaptativo.

**Nota:** Este prototipo tiene fines académicos y de simulación. No está certificado para controlar elevadores reales.

**Enlace de simulación del proyecto:** 

https://wokwi.com/projects/481427909843398657

Plataforma utilizada: Wokwi.

Microcontrolador: Arduino Uno.

Lenguaje de programación: C++. 
