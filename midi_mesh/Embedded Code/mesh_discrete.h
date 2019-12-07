/* 
 * File:   mesh_discrete.h
 * Author: BC
 *
 * Created on December 1, 2019, 4:34 PM
 */

#ifndef MESH_DISCRETE_H
#define	MESH_DISCRETE_H

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/tmr0.h"
#include "mesh_midi.h"
#include "mesh_util.h"
#include <stdio.h>


/*
 *	TIMER CODE
 *
 *	The following functions are used for debouncing input signals
 *  to prevent them from rapidly switchin on and off
 *  Timer 2 and 1 are needed for other applications so Timer 0 is used here
 *  but Timer 0  has a smaller maximum period so we count overflows
 *  instead of using the timer itself
 */

uint8_t can_play = 1;
void start_timer() {
    TMR0_Reload(0);
    can_play = 0;
}

uint8_t timer_overflows = 0;
void can_exit() {
    uint8_t timer_value = TMR0_ReadTimer();
    if(timer_value == 255 || TMR0_HasOverflowOccured()) {
        timer_overflows++;
        TMR0_Reload(0);
    }
    if(timer_overflows > 200) {
        can_play = 1;
        timer_overflows = 0;
        TMR0_StopTimer();
    }
}


/*
 *	discrete()
 *
 *	This function generates MIDI music signals based on discrete input
 *  each string on the mesh can be used to represent one pitch or parameter
 *  After playing a note, aftertouch is sent to change sound based on continued
 *  pressure on the device.
 */
#define CHANNEL 0
void discrete();

#endif	/* MESH_DISCRETE_H */

