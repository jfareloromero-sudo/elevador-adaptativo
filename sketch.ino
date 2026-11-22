#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Prototipo academico de elevador de tres pisos para Wokwi.
// Potenciometro en A0: simulacion del sensor FSR.
// Boton en D2: simulacion de alerta de inundacion.

Servo elevador;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte PIN_PESO = A0;
const byte PIN_INUNDACION = 2;
const byte BOTON_PISO1 = 3;
const byte BOTON_PISO2 = 4;
const byte BOTON_PISO3 = 5;
const byte LED_VERDE = 6;
const byte LED_ROJO = 7;
const byte BUZZER = 8;
const byte PIN_SERVO = 9;

const int UMBRAL_PESO = 600;
const int ANGULO_PISO1 = 0;
const int ANGULO_PISO2 = 90;
const int ANGULO_PISO3 = 180;

int posicionActual = ANGULO_PISO1;

void mostrarPiso() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema seguro");
  lcd.setCursor(0, 1);
  lcd.print("Piso: ");
  if (posicionActual == ANGULO_PISO1) lcd.print("1");
  else if (posicionActual == ANGULO_PISO2) lcd.print("2");
  else lcd.print("3");
}

bool haySobrecarga() {
  return analogRead(PIN_PESO) >= UMBRAL_PESO;
}

bool hayInundacion() {
  return digitalRead(PIN_INUNDACION) == LOW;
}

void detenerPorAlerta(const char* mensaje) {
  elevador.write(posicionActual);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_ROJO, HIGH);
  tone(BUZZER, 1200);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(mensaje);
  lcd.setCursor(0, 1);
  lcd.print("Movimiento parado");
}

void moverElevador(int destino) {
  if (destino == posicionActual) return;

  digitalWrite(LED_VERDE, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moviendo al piso");

  int paso = (destino > posicionActual) ? 1 : -1;
  for (int angulo = posicionActual; angulo != destino + paso; angulo += paso) {
    if (haySobrecarga()) {
      detenerPorAlerta("SOBRECARGA");
      return;
    }
    if (hayInundacion()) {
      detenerPorAlerta("ALERTA INUND.");
      return;
    }
    elevador.write(angulo);
    delay(20);
  }

  posicionActual = destino;
  noTone(BUZZER);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  mostrarPiso();
}

void setup() {
  Serial.begin(9600);

  pinMode(PIN_INUNDACION, INPUT_PULLUP);
  pinMode(BOTON_PISO1, INPUT_PULLUP);
  pinMode(BOTON_PISO2, INPUT_PULLUP);
  pinMode(BOTON_PISO3, INPUT_PULLUP);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  elevador.attach(PIN_SERVO);
  elevador.write(posicionActual);

  lcd.init();
  lcd.backlight();

  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_ROJO, LOW);
  mostrarPiso();
}

void loop() {
  int lecturaPeso = analogRead(PIN_PESO);
  Serial.print("Lectura simulada de peso: ");
  Serial.println(lecturaPeso);

  if (hayInundacion()) {
    detenerPorAlerta("ALERTA INUND.");
    delay(150);
    return;
  }

  if (haySobrecarga()) {
    detenerPorAlerta("SOBRECARGA");
    delay(150);
    return;
  }

  noTone(BUZZER);
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, HIGH);

  if (digitalRead(BOTON_PISO1) == LOW) {
    moverElevador(ANGULO_PISO1);
    delay(250);
  } else if (digitalRead(BOTON_PISO2) == LOW) {
    moverElevador(ANGULO_PISO2);
    delay(250);
  } else if (digitalRead(BOTON_PISO3) == LOW) {
    moverElevador(ANGULO_PISO3);
    delay(250);
  }

  delay(50);
}
