/* 
 * File:   lcd.h
 * Author: BC
 *
 * Created on October 20, 2019, 3:57 PM
 */

#ifndef LCD_H
#define	LCD_H

#include "mcc_generated_files/mcc.h"
#include <stdint.h>

//#define _XTAL_FREQ  8000000     // System clock frequency
/***    Send command:   RS=0, EN=1
        Send data:      RS=1, EN=1 */

/*** Define the pins used */
#define LCD_EN  PORTAbits.RA1
#define LCD_RS  PORTAbits.RA0
#define LCD_D   PORTA
#define LCD_D4  PORTAbits.RA2
#define LCD_D5  PORTAbits.RA3
#define LCD_D6  PORTAbits.RA4
#define LCD_D7  PORTAbits.RA5

/*** Define commands */
#define LCD_CLEAR   0x01
#define LCD_ON      0x0C    // Display ON, cursor and blink OFF
#define LCD_ON_CURSOR 0x0E
#define LCD_MODE    0x38    // 8-bit mode, 2 lines, 5x8dots characters
#define LCD_HOME    0x02    // Moves cursor to line 0, column 0

void LCDInit();
void LCDClear();
void LCDCommand(uint8_t cmd);
void LCDWriteChar(unsigned char data);
void LCDWriteString(unsigned char* str);
void LCDMoveCursor(uint8_t line, uint8_t column);
void LCDSetBacklight(uint8_t r, uint8_t g, uint8_t b);

void LCDEnable() {
    LCD_EN = 0;
    __delay_ms(1);
    LCD_EN = 1;
    __delay_ms(1);
    LCD_EN = 0;
    __delay_ms(10);
}

void LCDInit() {
    // Init pins to 0:
    LCD_EN = 0;
    LCD_RS = 0;
    LCD_D4 = 0;
    LCD_D5 = 0;
    LCD_D6 = 0;
    LCD_D7 = 0;

    // Set pins as output:
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0;

    // Init LCD:
    LCDCommand(0x00);
    __delay_ms(10);
    LCDCommand(0x03);
    __delay_ms(10);
    LCDCommand(0x03);
    __delay_ms(10);
    LCDCommand(0x03);
    __delay_ms(10);
    LCDCommand(0x02);
    __delay_ms(10);
    LCDCommand(LCD_CLEAR);
    __delay_ms(10);
    LCDCommand(LCD_ON_CURSOR);
    __delay_ms(10);
    LCDCommand(LCD_MODE);
    __delay_ms(10);
    LCDCommand(LCD_HOME);
    __delay_ms(10);
}

/***
 * Clear the LCD and move cursor to origin
 */
void LCDClear() {
    // Send clear command:
    LCDCommand(LCD_CLEAR);
    LCDCommand(LCD_HOME);
}

/***
 * Send a command to the LCD display
 */
void LCDCommand(uint8_t cmd) {
    LCD_RS = 0;
    LCD_D = (LCD_D & (0xC3)) | ((cmd & 0xF0) >> 2);
    LCDEnable();
    LCD_D = (LCD_D & (0xC3)) | ((cmd & 0x0F) << 2);
    LCDEnable();
}

/***
 * Send a character to display
 */
void LCDWriteChar(unsigned char data) {
    LCD_RS = 1;
    LCD_D = (LCD_D & (0xC3)) | ((data & 0xF0) >> 2);
    LCDEnable();
    LCD_D = (LCD_D & (0xC3)) | ((data & 0x0F) << 2);
    LCDEnable();
}

/***
 * Write a String on the display
 */
void LCDWriteString(unsigned char* str) {
    while (*str != '\0') // Print characters until end of line
    {
        LCDWriteChar(*str);
        str++;
    }
}

/* First line addresses: from 0x00 to 0x27
 Second line addresses: from 0x40 to 0x67 */
void LCDMoveCursor(uint8_t line, uint8_t column) {
    uint8_t AC = 0x80;
    if (line > 1 || column > 15) {
        return;
    }
    AC += line * 0x40;
    AC += column;
    LCDCommand(AC);
}

void LCDSetBacklight(uint8_t r, uint8_t g, uint8_t b) {
    uint16_t dc = ((255 - r) << 2) + 0b11;
    PWM3_LoadDutyValue(dc);
    dc = ((255 - g) << 2) + 0b11;
    PWM4_LoadDutyValue(dc);
    dc = ((255 - b) << 2) + 0b11;
    PWM5_LoadDutyValue(dc);
}


#endif	/* LCD_H */

