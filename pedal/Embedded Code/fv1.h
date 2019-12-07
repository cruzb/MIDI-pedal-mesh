
#ifndef FV1_H
#define	FV1_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc_generated_files/pin_manager.h"
#include <stdio.h>
#include <stdint.h>  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    //0 or 1 input
    void setSource(uint8_t input){
        if(input == 1){
            FV1_T0_SetHigh();
        }else if(input == 0){
            FV1_T0_SetLow();
        }
    }
    
    //0 - 7 input
    void setPatch(uint8_t input){
        PORTB = (PORTB & (0xE3)) | ((input & 0x07) << 2);
    }
    
    
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* FV1_H */

