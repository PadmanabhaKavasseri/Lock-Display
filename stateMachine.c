/********************************************
*
*  Name:
*  Email:
*  Section:
*  Assignment: Lab 4 - Up/Down counter on LCD display
*
********************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd.h"
  /* Call lcd_stringout to print out your name */

  /* Use snprintf to create a string with your birthdate */

  /* Use lcd_moveto to start at an appropriate column 
     in the bottom row to appear centered */

  /* Use lcd_stringout to print the birthdate string */

  /* Delay 1 second */
char checkInput(char bit)
{
    if ((PINC & (1 << bit)) != 0)
        return(0);
    else
        return(1);
}

int main(void) 
{
    DDRC &= ~((1 << 2) | (1 << 4));
    PORTC |= ((1 << 2) | (1 << 4));
    lcd_init();   // Setup DDR and PORT bits for the 2 input buttons
    lcd_writecommand(1);

        lcd_moveto(0,0);
        lcd_stringout("Padmanabha Kavasseri");
        char date[18];
        unsigned char month, day, year;
        month = 11;
        day = 21;
        year = 00;
        snprintf(date, 18, "%d/%d/%d", month, day, year);
        lcd_stringout(date);
        _delay_ms(100); 
        int locked = 0;
        _delay_ms(500);
        lcd_writecommand(1);


    while (1) 
    { 
        if (locked < 4)
        {
                lcd_moveto(0,0);
                lcd_stringout("State = S0");
                lcd_moveto(1,0);
                lcd_stringout("Status = Locked");
            if (locked ==0){
            if ((PINC & (1 << 4)) == 0){
                locked++;
                lcd_moveto(0,0);
                lcd_stringout("State = S1");
                lcd_moveto(1,0);
                lcd_stringout("Status = Locked");

            }
        }
            else {
                locked = 6;
                lcd_moveto(0,0);
                lcd_stringout("State = S0");
                lcd_moveto(1,0);
                lcd_stringout("Status = Locked");
            }  

            if (locked ==1) {       
                if ((PINC & (1 << 2))== 0 ) {
                    locked++;
                lcd_moveto(0,0);
                lcd_stringout("State = S2");
                lcd_moveto(1,0);
                lcd_stringout("Status = Locked");
                
                }
                else {
                
                lcd_moveto(0,0);
                lcd_stringout("State = S0");
                lcd_moveto(1,0);
                lcd_stringout("Status = Locked");
                }
            } 

            else {
                break;
            }     

            if (locked == 2) {          
                if ((PINC & (1 << 2))== 0 ) {
                    locked++;
                lcd_moveto(0,0);
                lcd_stringout("State = S3");
                lcd_moveto(1,0);
                lcd_stringout("Status = Locked"); 
                }
                else {
                
                lcd_moveto(0,0);
                lcd_stringout("State = S0");
                lcd_moveto(1,0);
                lcd_stringout("Status = Locked");
                }
            }
            else {
                break;
            }

            if (locked == 3){               
                if ((PINC & (1 << 4)) == 0) {
                    locked++;
                }
                else {
                
                lcd_moveto(0,0);
                lcd_stringout("State = S0");
                lcd_moveto(1,0);
                lcd_stringout("Status = Locked");
                }

            }
            else {
                break;
            }
        }

        if (locked == 4)
        {
            lcd_moveto(0,0);
            lcd_stringout("Unlocked!"); 
        }
        
    }
    return 0; 
}   
// check lab 3 for debouncing **** note to self ****



