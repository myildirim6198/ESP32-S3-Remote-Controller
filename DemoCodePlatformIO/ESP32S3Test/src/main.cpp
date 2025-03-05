#include <Arduino.h>

// gpio pin defines
#define LED_R 35
#define LED_G 36
#define LED_B 37

#define JOY_1_1 8
#define JOY_1_2 7
#define JOY_2_1 5
#define JOY_2_2 4

#define JOY_SW_1 21
#define JOY_SW_2 6

// adc resolution in bits
#define ADC_RES 8

uint32_t chipId = 0;

void setup() {
  // start serial port
  Serial.begin(115200);
  
  // set pins and pin directions
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(JOY_SW_1, INPUT);
  pinMode(JOY_SW_2, INPUT);

  // set default state on common anode rgb led
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_B, HIGH);

  // set adc resolution
  analogReadResolution(ADC_RES);

}

void loop() {

  // test rgb cases with serial monitor
  /* digitalWrite(LED_R, LOW);
  Serial.println("Hallo");
  delay(1000);
  digitalWrite(LED_R, HIGH);
  Serial.println("Hallo");
  delay(1000);
  digitalWrite(LED_G, LOW);
  Serial.println("Hallo");
  delay(1000);
  digitalWrite(LED_G, HIGH);
  Serial.println("Hallo");
  delay(1000);
  digitalWrite(LED_B, LOW);
  Serial.println("Hallo");
  delay(1000);
  digitalWrite(LED_B, HIGH);
  Serial.println("Hallo");
  delay(1000);*/

  // read joystick states and buttons, formatted for serial plotter
  int analogJoy_1_1 = analogRead(JOY_1_1);
  int analogJoy_1_2 = analogRead(JOY_1_2);
  int analogJoy_2_1 = analogRead(JOY_2_1);
  int analogJoy_2_2 = analogRead(JOY_2_2);
  int joyBut_1 = digitalRead(JOY_SW_1);
  int joyBut_2 = digitalRead(JOY_SW_2);

  Serial.print("Joystick 1_1:");
  Serial.print(analogJoy_1_1);
  Serial.print(",");
  Serial.print("Joystick 1_2:");
  Serial.print(analogJoy_1_2);
  Serial.print(",");
  Serial.print("Joystick 2_1:");
  Serial.print(analogJoy_2_1);
  Serial.print(",");
  Serial.print("Joystick 2_2:");
  Serial.print(analogJoy_2_2);
  Serial.print(",");
  Serial.print("Joystick 1 SW:");
  Serial.print(joyBut_1);
  Serial.print(",");
  Serial.print("Joystick 2 SW:");
  Serial.println(joyBut_2);
  delay(250);
}
