/* 
 * File:   mesh_continuous.h
 * Author: BC
 *
 * Created on December 1, 2019, 4:52 PM
 */

#ifndef MESH_CONTINUOUS_H
#define	MESH_CONTINUOUS_H

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adc.h"
#include "mesh_midi.h"
#include "mesh_util.h"
#include <stdio.h>


#define MIN_PITCH 60
#define MAX_PITCH 66
#define PITCH_RANGE (MAX_PITCH - MIN_PITCH) //must be less than 127 - start pitch

#define MIN_PARAM 0
#define MAX_PARAM 126
#define PARAM_RANGE (MAX_PARAM - MIN_PARAM)



/*
 * This function takes in an axis of strain sensors outputs a value between
 * MIN_PITCH and MAX_PITCH according to an interpolation of the largest 
 * sensor value and the values of the sensor around it.
 * 
 * This function has parameters adjustable with the AXIS_LENGTH, MIN_PITCH,
 * MAX_PITCH, THRESHOLD
 * 
 * This function uses the get_max() function to find the maximum on an axis
 * 
 * **be careful of order of operations when dividing int into fraction**
 * 
 * Spencer 11.21.2019
 */
uint8_t get_interp_pitch(uint16_t* axis);



/*
 * This function takes in an axis of strain sensors outputs a value between
 * MIN_PARAM and MAX_PARAM according to an interpolation of the largest 
 * sensor value and the values of the sensor around it.
 * 
 * This function has parameters adjustable with the AXIS_LENGTH, MIN_PARAM,
 * MAX_PARAM, THRESHOLD
 * 
 * This function uses the get_max() function to find the maximum on an axis
 * 
 * **be careful of order of operations when dividing int into fraction**
 * 
 * Spencer 12.1.2019
 */
uint8_t get_interp_param(uint16_t* axis);




/*
 *	continuous()
 *
 *	This function generates MIDI music signals based on continuous input
 *  each string on the mesh can be used to represent one pitch or parameter
 *  But pushing between strings can yield notes in between them.
 *  After playing a note, aftertouch is sent to change sound based on continued
 *  pressure on the device.
 */
#define CHANNEL 0
void continuous(void);


#endif	/* MESH_CONTINUOUS_H */

