#include <LiquidCrystal.h>
const int si = 2, so = 3;
float h11, h12, h21, h22, vi, vo, ii, io;
float vi1, vi2, vo1, vo2;
float R = 100;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
void setup() {
  pinMode(si, OUTPUT);
  pinMode(so, OUTPUT);
  lcd.begin(16, 2);
}
float VoltageDtoA(int x) {
float voltage;
voltage = x *  (5.0  / 1024);
return voltage;
}
float CurrentDtoA(int y) {
float current;
current = y *  (5.0  / (R * 1024));
return current;
}

void loop() {
  digitalWrite(so, HIGH);
  digitalWrite(si, LOW);
  vi1 = analogRead(A3);
  vi2 = analogRead(A2);
  ii = analogRead(A4);
  const float h11 = (VoltageDtoA(vi1) - VoltageDtoA(vi2)) /  CurrentDtoA(ii);
  lcd.setCursor(0, 0);
  lcd.print("hi=");lcd.print(h11);
  delay(300);
  
  digitalWrite(so, LOW);
  digitalWrite(si, LOW);
  vo1 = analogRead(A0);
  vo2 = analogRead(A1);
  vi1 = analogRead(A2);
  vi2 = analogRead(A3);
  h12 = (VoltageDtoA(vi2) - VoltageDtoA(vi1)) / (VoltageDtoA(vo2) - VoltageDtoA(vo1));
  lcd.setCursor(7, 0);
  lcd.print(" hr=");lcd.print(h12);
  delay(300);

  digitalWrite(so, HIGH);
  digitalWrite(si, LOW);
  ii = analogRead(A4);
  io = analogRead(A5);
  const float h21 = CurrentDtoA(io) /  CurrentDtoA(ii);
  lcd.setCursor(0, 1);
  lcd.print("hf=");lcd.print(h21);
  delay(300);

  digitalWrite(so, LOW);
  digitalWrite(si, LOW);
  vo1 = analogRead(A0);
  vo2 = analogRead(A1);
  io = analogRead(A5);
  const float h22 = CurrentDtoA(io)/( VoltageDtoA(vo1)-VoltageDtoA(vo2)) ;
  lcd.setCursor(7, 1);
  lcd.print(" ho=");lcd.print(h22);
  delay(300);
}
