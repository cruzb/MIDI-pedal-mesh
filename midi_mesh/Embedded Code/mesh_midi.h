/* 
 * File:   mesh_midi.h
 * Author: BC
 *
 * Created on December 1, 2019, 4:33 PM
 */

#ifndef MESH_MIDI_H
#define	MESH_MIDI_H

#include <stdint.h>

//MIDI requires UART with 31250 baud
#include "mcc_generated_files/eusart1.h"


//commands
#define CMD_NOTE_OFF 0x80
#define CMD_NOTE_ON 0x90
#define CMD_PITCH_BEND 0xE0
#define CMD_AFTERTOUCH 0xD0 //channel aftertouch
#define CMD_POLY_AFTERTOUCH 0xA0
#define CMD_CONTROL_CHANGE 0xB0

//Pitches
#define PITCH_C 0x3C //middle c

//velocities
#define DEFAULT_VELOCITY 0x40 //default
#define NOTE_OFF_VELOCITY 0

//Pitchbends
#define PITCHBEND_DEFAULT_MSB 64
#define PITCHBEND_DEFAULT_LSB 0


void note_on(uint8_t channel, uint8_t pitch, uint8_t velocity);

void note_off(uint8_t channel, uint8_t pitch);

void aftertouch(uint8_t channel, uint8_t aftertouch);

void poly_aftertouch(uint8_t channel, uint8_t pitch, uint8_t aftertouch);

void pitch_bend(uint8_t channel, uint8_t msb, uint8_t lsb);

void reset_pitch_bend(uint8_t channel);

void control_change(uint8_t channel, uint8_t lsb, uint8_t msb);

#endif	/* MESH_MIDI_H */

