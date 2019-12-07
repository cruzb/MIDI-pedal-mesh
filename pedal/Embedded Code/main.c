#include "mcc_generated_files/mcc.h"
#include "eeprom.h"
#include "desktop_interface.h"
#include "lcd.h"
#include "fv1.h"
#include <stdint.h>
#include <stdlib.h>

uint8_t getProgram(uint16_t adc_val);

void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    GPIO_SetLow();
    

    //Initialize data eeprom with internal program descriptions
    char * internalDescriptions[8] = {
        "Chorus-Reverb   RmixCratCmix",
        "Flange-Reverb   RmixFratFmix",
        "Trem-Reverb     RmixTratTmix",
        "Pitch Shift     Shft --  -- ",
        "Pitch Echo      ShftTime Mix",
        "TEST             --  --  -- ",
        "Reverb 1        Time HF  LF ",
        "Reverb 2        Time HF  LF "
    };



    /*for (uint8_t i = 0; i < 8; i++) {
        EEPROMwrite(DATA_EEPROM, DATA_ADDR[i], (uint8_t*) internalDescriptions[i], 28);
    }*/


    LCDInit();
    //LCDClear();
    LCDSetBacklight(0, 0, 255);

    //Handle different tasks stuff
#define     IDLE    0x0
#define     USB     0x1 
#define     MIDI    0x2
#define     LCD     0x3

    uint8_t state = LCD;
    uint8_t int_ext = INT_EXT_GetValue();
    uint8_t program = getProgram(ADC_GetConversion(PGM_SELECT) >> 6);


    //Program Select/LCD stuff
    uint8_t LCDbuf[28];

    //USB UART Stuff
    uint8_t USBbuf[64]; //64 byte message

    /* MESSAGES
     *
     * 1: 1 byte location + 16 byte name + 3*4 byte pot names
     * 2: program data 0 - 63
     * 3: program data 64 - 127
     * 4: program data 128 - 191
     * 5: program data 192 - 255
     * 6: program data 256 - 319
     * 7: program data 320 - 383
     * 8: program data 384 - 447
     * 9: program data 448 - 511
     *
     */

    uint8_t i = 0;

    while (1) {

        __delay_ms(100);
        if (i) {
            //GPIO_SetHigh();
        } else {
            //GPIO_SetLow();
        }
        i = (i + 1) % 2;


        switch (state) {

            case USB:
                                
                confirmTransaction();          
                
                uint8_t location;
                while (1) {
                    if (USBgetHeader(USBbuf)) {
                        location = USBbuf[0];
                        EEPROMwrite(DATA_EEPROM, DATA_ADDR[location + 8], USBbuf + 1, 28);
                        confirmTransaction();
                        break;
                    } else {
                        denyTransaction();
                    }
                }
                
                for (uint8_t i = 0; i < 8; i++) {
                    while (1) {
                        if (USBgetProgChunk(USBbuf)) {
                            EEPROMwrite(PROG_EEPROM, PROG_ADDR[location] + (32 * (2 * i)), USBbuf, 32);
                            EEPROMwrite(PROG_EEPROM, PROG_ADDR[location] + (32 * (2 * i + 1)), USBbuf + 32, 32);
                            confirmTransaction();
                            break;
                        } else {
                            denyTransaction();
                        }
                    }
                }
                
                state = LCD;
                break;
            case MIDI:


                state = LCD;
                break;
            case LCD:

                //patch changed, get description data
                EEPROMread(DATA_EEPROM, DATA_ADDR[program + 8 * int_ext], LCDbuf, 28);
                LCDMoveCursor(0, 0);
                for (uint8_t i = 0; i < 16; i++) {
                    LCDWriteChar(LCDbuf[i]);
                }
                LCDMoveCursor(1, 0);
                for (uint8_t i = 0; i < 4; i++) {
                    LCDWriteChar(LCDbuf[i + 24]);
                }
                LCDWriteChar(' ');
                LCDWriteChar(' ');
                for (uint8_t i = 0; i < 4; i++) {
                    LCDWriteChar(LCDbuf[i + 20]);
                }
                LCDWriteChar(' ');
                LCDWriteChar(' ');
                for (uint8_t i = 0; i < 4; i++) {
                    LCDWriteChar(LCDbuf[i + 16]);
                }

                //__delay_ms(50);

                //Tell the FV-1 to switch programs
                setSource(int_ext);
                setPatch(program);

                state = IDLE;
                break;
            case IDLE:
            default:

                if (USBincomingMessage()) {
                    state = USB;
                    break;
                }

                uint8_t program_input = getProgram(ADC_GetConversion(PGM_SELECT) >> 6);
                uint8_t int_ext_input = INT_EXT_GetValue();

                if (program_input != program || int_ext_input != int_ext) {

                    program = program_input;
                    int_ext = int_ext_input;

                    state = LCD;
                    break;
                }

                //if (incoming MIDI) {
                //    state = MIDI;
                //    break;
                //}

        }
    }
}

uint8_t getProgram(uint16_t adc_val) {

    //10 bit range is 0 to 1023
    if (adc_val < 128) {
        return 7;
    } else if (adc_val < 256) {
        return 6;
    } else if (adc_val < 384) {
        return 5;
    } else if (adc_val < 512) {
        return 4;
    } else if (adc_val < 640) {
        return 3;
    } else if (adc_val < 768) {
        return 2;
    } else if (adc_val < 896) {
        return 1;
    } else if (adc_val < 1024) {
        return 0;
    }

    return 0;
}