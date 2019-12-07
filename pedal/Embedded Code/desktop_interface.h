#ifndef DESKTOP_INTERFACE_H
#define	DESKTOP_INTERFACE_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdint.h>
#include "mcc_generated_files/eusart1.h"
#include "mcc_generated_files/mcc.h"

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    bool USBincomingMessage() {
        if (!EUSART1_is_rx_ready()){
            return false;
        }

        uint8_t input = EUSART1_Read();
        if (input == 0xAA) {
            return true;
        } else {
            return false;
        }
    }

    void confirmTransaction() {
        EUSART1_Write(0xAA);
    }
    
    void denyTransaction() {
        EUSART1_Write(0x55);
    }

    bool USBgetHeader(uint8_t* buf) {
        uint8_t cs = 0x00;
        for (uint8_t i = 0; i < 29; i++) {
            buf[i] = EUSART1_Read();
            cs ^= buf[i];
        }
        uint8_t cs_sent = EUSART1_Read();

        if (cs == cs_sent) {
            return true;
        } else {
            return false;
        }
    }

    bool USBgetProgChunk(uint8_t* buf) {
        uint8_t cs = 0x00;
        for (uint8_t i = 0; i < 64; i++) {
            buf[i] = EUSART1_Read();
            cs ^= buf[i];
        }
        uint8_t cs_sent = EUSART1_Read();

        if (cs == cs_sent) {
            return true;
        } else {
            return false;
        }
    }

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* DESKTOP_INTERFACE_H */

