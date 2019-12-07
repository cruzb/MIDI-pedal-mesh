/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16LF15355
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LCD_RS aliases
#define LCD_RS_TRIS                 TRISAbits.TRISA0
#define LCD_RS_LAT                  LATAbits.LATA0
#define LCD_RS_PORT                 PORTAbits.RA0
#define LCD_RS_WPU                  WPUAbits.WPUA0
#define LCD_RS_OD                   ODCONAbits.ODCA0
#define LCD_RS_ANS                  ANSELAbits.ANSA0
#define LCD_RS_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LCD_RS_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LCD_RS_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LCD_RS_GetValue()           PORTAbits.RA0
#define LCD_RS_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LCD_RS_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LCD_RS_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LCD_RS_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LCD_RS_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LCD_RS_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LCD_RS_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LCD_RS_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LCD_EN aliases
#define LCD_EN_TRIS                 TRISAbits.TRISA1
#define LCD_EN_LAT                  LATAbits.LATA1
#define LCD_EN_PORT                 PORTAbits.RA1
#define LCD_EN_WPU                  WPUAbits.WPUA1
#define LCD_EN_OD                   ODCONAbits.ODCA1
#define LCD_EN_ANS                  ANSELAbits.ANSA1
#define LCD_EN_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LCD_EN_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LCD_EN_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LCD_EN_GetValue()           PORTAbits.RA1
#define LCD_EN_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LCD_EN_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LCD_EN_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LCD_EN_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LCD_EN_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LCD_EN_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LCD_EN_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LCD_EN_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LCD_D4 aliases
#define LCD_D4_TRIS                 TRISAbits.TRISA2
#define LCD_D4_LAT                  LATAbits.LATA2
#define LCD_D4_PORT                 PORTAbits.RA2
#define LCD_D4_WPU                  WPUAbits.WPUA2
#define LCD_D4_OD                   ODCONAbits.ODCA2
#define LCD_D4_ANS                  ANSELAbits.ANSA2
#define LCD_D4_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LCD_D4_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LCD_D4_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LCD_D4_GetValue()           PORTAbits.RA2
#define LCD_D4_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LCD_D4_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LCD_D4_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LCD_D4_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LCD_D4_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LCD_D4_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LCD_D4_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LCD_D4_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LCD_D5 aliases
#define LCD_D5_TRIS                 TRISAbits.TRISA3
#define LCD_D5_LAT                  LATAbits.LATA3
#define LCD_D5_PORT                 PORTAbits.RA3
#define LCD_D5_WPU                  WPUAbits.WPUA3
#define LCD_D5_OD                   ODCONAbits.ODCA3
#define LCD_D5_ANS                  ANSELAbits.ANSA3
#define LCD_D5_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LCD_D5_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LCD_D5_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LCD_D5_GetValue()           PORTAbits.RA3
#define LCD_D5_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LCD_D5_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LCD_D5_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LCD_D5_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LCD_D5_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LCD_D5_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LCD_D5_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define LCD_D5_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set LCD_D6 aliases
#define LCD_D6_TRIS                 TRISAbits.TRISA4
#define LCD_D6_LAT                  LATAbits.LATA4
#define LCD_D6_PORT                 PORTAbits.RA4
#define LCD_D6_WPU                  WPUAbits.WPUA4
#define LCD_D6_OD                   ODCONAbits.ODCA4
#define LCD_D6_ANS                  ANSELAbits.ANSA4
#define LCD_D6_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LCD_D6_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LCD_D6_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LCD_D6_GetValue()           PORTAbits.RA4
#define LCD_D6_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LCD_D6_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LCD_D6_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LCD_D6_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LCD_D6_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LCD_D6_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LCD_D6_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define LCD_D6_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set LCD_D7 aliases
#define LCD_D7_TRIS                 TRISAbits.TRISA5
#define LCD_D7_LAT                  LATAbits.LATA5
#define LCD_D7_PORT                 PORTAbits.RA5
#define LCD_D7_WPU                  WPUAbits.WPUA5
#define LCD_D7_OD                   ODCONAbits.ODCA5
#define LCD_D7_ANS                  ANSELAbits.ANSA5
#define LCD_D7_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LCD_D7_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LCD_D7_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LCD_D7_GetValue()           PORTAbits.RA5
#define LCD_D7_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LCD_D7_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LCD_D7_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LCD_D7_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LCD_D7_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LCD_D7_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LCD_D7_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LCD_D7_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set PGM_SELECT aliases
#define PGM_SELECT_TRIS                 TRISAbits.TRISA6
#define PGM_SELECT_LAT                  LATAbits.LATA6
#define PGM_SELECT_PORT                 PORTAbits.RA6
#define PGM_SELECT_WPU                  WPUAbits.WPUA6
#define PGM_SELECT_OD                   ODCONAbits.ODCA6
#define PGM_SELECT_ANS                  ANSELAbits.ANSA6
#define PGM_SELECT_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define PGM_SELECT_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define PGM_SELECT_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define PGM_SELECT_GetValue()           PORTAbits.RA6
#define PGM_SELECT_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define PGM_SELECT_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define PGM_SELECT_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define PGM_SELECT_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define PGM_SELECT_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define PGM_SELECT_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define PGM_SELECT_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define PGM_SELECT_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set INT_EXT aliases
#define INT_EXT_TRIS                 TRISAbits.TRISA7
#define INT_EXT_LAT                  LATAbits.LATA7
#define INT_EXT_PORT                 PORTAbits.RA7
#define INT_EXT_WPU                  WPUAbits.WPUA7
#define INT_EXT_OD                   ODCONAbits.ODCA7
#define INT_EXT_ANS                  ANSELAbits.ANSA7
#define INT_EXT_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define INT_EXT_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define INT_EXT_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define INT_EXT_GetValue()           PORTAbits.RA7
#define INT_EXT_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define INT_EXT_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define INT_EXT_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define INT_EXT_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define INT_EXT_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define INT_EXT_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define INT_EXT_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define INT_EXT_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set FV1_S0 aliases
#define FV1_S0_TRIS                 TRISBbits.TRISB2
#define FV1_S0_LAT                  LATBbits.LATB2
#define FV1_S0_PORT                 PORTBbits.RB2
#define FV1_S0_WPU                  WPUBbits.WPUB2
#define FV1_S0_OD                   ODCONBbits.ODCB2
#define FV1_S0_ANS                  ANSELBbits.ANSB2
#define FV1_S0_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define FV1_S0_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define FV1_S0_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define FV1_S0_GetValue()           PORTBbits.RB2
#define FV1_S0_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define FV1_S0_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define FV1_S0_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define FV1_S0_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define FV1_S0_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define FV1_S0_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define FV1_S0_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define FV1_S0_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set FV1_S1 aliases
#define FV1_S1_TRIS                 TRISBbits.TRISB3
#define FV1_S1_LAT                  LATBbits.LATB3
#define FV1_S1_PORT                 PORTBbits.RB3
#define FV1_S1_WPU                  WPUBbits.WPUB3
#define FV1_S1_OD                   ODCONBbits.ODCB3
#define FV1_S1_ANS                  ANSELBbits.ANSB3
#define FV1_S1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define FV1_S1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define FV1_S1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define FV1_S1_GetValue()           PORTBbits.RB3
#define FV1_S1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define FV1_S1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define FV1_S1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define FV1_S1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define FV1_S1_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define FV1_S1_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define FV1_S1_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define FV1_S1_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set FV1_S2 aliases
#define FV1_S2_TRIS                 TRISBbits.TRISB4
#define FV1_S2_LAT                  LATBbits.LATB4
#define FV1_S2_PORT                 PORTBbits.RB4
#define FV1_S2_WPU                  WPUBbits.WPUB4
#define FV1_S2_OD                   ODCONBbits.ODCB4
#define FV1_S2_ANS                  ANSELBbits.ANSB4
#define FV1_S2_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define FV1_S2_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define FV1_S2_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define FV1_S2_GetValue()           PORTBbits.RB4
#define FV1_S2_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define FV1_S2_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define FV1_S2_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define FV1_S2_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define FV1_S2_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define FV1_S2_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define FV1_S2_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define FV1_S2_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set FV1_T0 aliases
#define FV1_T0_TRIS                 TRISBbits.TRISB5
#define FV1_T0_LAT                  LATBbits.LATB5
#define FV1_T0_PORT                 PORTBbits.RB5
#define FV1_T0_WPU                  WPUBbits.WPUB5
#define FV1_T0_OD                   ODCONBbits.ODCB5
#define FV1_T0_ANS                  ANSELBbits.ANSB5
#define FV1_T0_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define FV1_T0_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define FV1_T0_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define FV1_T0_GetValue()           PORTBbits.RB5
#define FV1_T0_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define FV1_T0_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define FV1_T0_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define FV1_T0_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define FV1_T0_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define FV1_T0_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define FV1_T0_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define FV1_T0_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC5
#define SDA1_LAT                  LATCbits.LATC5
#define SDA1_PORT                 PORTCbits.RC5
#define SDA1_WPU                  WPUCbits.WPUC5
#define SDA1_OD                   ODCONCbits.ODCC5
#define SDA1_ANS                  ANSELCbits.ANSC5
#define SDA1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SDA1_GetValue()           PORTCbits.RC5
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISCbits.TRISC6
#define SCL1_LAT                  LATCbits.LATC6
#define SCL1_PORT                 PORTCbits.RC6
#define SCL1_WPU                  WPUCbits.WPUC6
#define SCL1_OD                   ODCONCbits.ODCC6
#define SCL1_ANS                  ANSELCbits.ANSC6
#define SCL1_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SCL1_GetValue()           PORTCbits.RC6
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set GPIO aliases
#define GPIO_TRIS                 TRISCbits.TRISC7
#define GPIO_LAT                  LATCbits.LATC7
#define GPIO_PORT                 PORTCbits.RC7
#define GPIO_WPU                  WPUCbits.WPUC7
#define GPIO_OD                   ODCONCbits.ODCC7
#define GPIO_ANS                  ANSELCbits.ANSC7
#define GPIO_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define GPIO_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define GPIO_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define GPIO_GetValue()           PORTCbits.RC7
#define GPIO_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define GPIO_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define GPIO_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define GPIO_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define GPIO_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define GPIO_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define GPIO_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define GPIO_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/