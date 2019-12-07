/* 
 * File:   mesh_midi.c
 * Author: BC
 *
 * Created on December 1, 2019, 4:33 PM
 */

#include "mesh_midi.h"


void note_on(uint8_t channel, uint8_t pitch, uint8_t velocity){
    EUSART1_Write(CMD_NOTE_ON | channel);  
    EUSART1_Write(pitch); 
    EUSART1_Write(velocity);  
}

void note_off(uint8_t channel, uint8_t pitch){
    EUSART1_Write(CMD_NOTE_OFF | channel);    
    EUSART1_Write(pitch);  
    EUSART1_Write(NOTE_OFF_VELOCITY);  
}

void aftertouch(uint8_t channel, uint8_t aftertouch){
    EUSART1_Write(CMD_AFTERTOUCH | channel); 
    EUSART1_Write(aftertouch);    
}

void poly_aftertouch(uint8_t channel, uint8_t pitch, uint8_t aftertouch) {
	EUSART1_Write(CMD_POLY_AFTERTOUCH | channel); 
	EUSART1_Write(pitch);
    EUSART1_Write(aftertouch); 
}

void pitch_bend(uint8_t channel, uint8_t msb, uint8_t lsb) {
    EUSART1_Write(CMD_PITCH_BEND | channel);
    EUSART1_Write(lsb);
    EUSART1_Write(msb);
}

void reset_pitch_bend(uint8_t channel) {
    //reset pitchbend to 0 (zero pitchbend is lsb = 0, msb = 64)
    EUSART1_Write(CMD_PITCH_BEND | channel);
    EUSART1_Write(PITCHBEND_DEFAULT_LSB);
    EUSART1_Write(PITCHBEND_DEFAULT_MSB);
}

void control_change(uint8_t channel, uint8_t lsb, uint8_t msb){
    EUSART1_Write(CMD_CONTROL_CHANGE | channel);
    EUSART1_Write(lsb);
    EUSART1_Write(msb);
}


