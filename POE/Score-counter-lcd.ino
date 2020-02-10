/*****************************************
 * name: I2C LCD2004
 * function: You should now see your I2C LCD2004 display "Hello,world!","IIC/I2C LCD2004"
 * "20 cols, 4 rows","www.sunfounder.com"
 ********************************/
//Email:service@sunfounder.com
//Website:www.sunfounder.com

/********************************/
// include the library code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int score = 0;
String strScore(){
  score = score % 100;
  String str = "";
  if(score<10){
    str="         0"+String(score);
  }else{
    str="         "+String(score);
  }
  return str;
}
/*********************************************************/
void setup()
{
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
   
  
  
}
/*********************************************************/
void loop() 
{
lcd.setCursor ( 0, 0 );            // go to the top left corner
  lcd.print("       Score:       "); // write this string on the top row
  lcd.setCursor (0,1);
  lcd.print(strScore());
  lcd.setCursor(0,2);
  lcd.print("        Time:       ");
  lcd.setCursor (0,3);
  lcd.print("12345678901234567890");
  delay(100);
  score++;
}
/************************************************************/
