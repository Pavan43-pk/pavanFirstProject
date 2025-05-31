 #include<regx51.h>
#include "LCD4SEG.h"   //header filename
void main(void){
 LCD_init();
 while(1){
  LCD_cmd(0x80);
  LCD_data('H');
  LCD_cmd(0x82);
  LCD_string("Charani");
  LCD_cmd(0xC5);
  LCD_numb(45678);
 }}