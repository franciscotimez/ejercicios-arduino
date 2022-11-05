// Consigna:
// Conectar:
// - Una pantalla LCD i2c

// Imprimir en pantalla un mensaje de bienvenida.

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hola, mundo!");
  lcd.setCursor(2,1);
  lcd.print("Janssen 2022!");
}


void loop()
{
}