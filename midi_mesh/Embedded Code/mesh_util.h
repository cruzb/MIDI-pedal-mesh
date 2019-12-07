/* 
 * File:   mesh_util.h
 * Author: BC
 *
 * Created on December 1, 2019, 4:34 PM
 */

#ifndef MESH_UTIL_H
#define	MESH_UTIL_H

#include <stdint.h>

// Do calibration and populate arrays with starting data
void mesh_init();


////////////////////////////////////////////////////////
//
//      AXIS/ADC UTILITIES
//
////////////////////////////////////////////////////////
#define AXIS_LENGTH 6 //must be greater than 1
#define THRESHOLD 200

#define MIN_PITCH 60
#define MAX_PITCH 66
#define PITCH_RANGE (MAX_PITCH - MIN_PITCH) //must be less than 127 - start pitch

uint16_t pitch_axis[AXIS_LENGTH];
adc_channel_t pitch_channels[] = {channel_ANA0, channel_ANA1, channel_ANA2,
                                    channel_ANA3, channel_ANA4, channel_ANA5};
uint16_t param_axis[AXIS_LENGTH];
adc_channel_t param_channels[] = {channel_ANC6, channel_ANC7, channel_AND4,
                                    channel_AND5, channel_AND6, channel_AND7};

uint16_t pitch_axis_threshold[AXIS_LENGTH];
uint16_t param_axis_threshold[AXIS_LENGTH]; 

/*
 * This function polls each axis' ADC channels for new values
 * and populates an array with those values
 */
void poll_axis(uint16_t* axis, adc_channel_t* channel);

/*
 * This function checks an array and returns the index of the
 * maximum of that array
 */
uint8_t get_max(uint16_t* axis);

/*
 * This function checks an array and returns the index of the
 * maximum of that array, but takes into consideration
 * the starting calibration values for that array
 */
uint8_t get_max_pitch(uint16_t* axis);

uint8_t get_max_param(uint16_t* axis);



/*
 * This function takes in the data from both of the axis and
 * sets a calibration level for each based on the Steady State 
 * value on each of the sensors
 */
void threshold_calibration(uint16_t* x_axis, uint16_t* y_axis);





////////////////////////////////////////////////////////
//
//      MAPPING/MIDI UTILITIES
//
////////////////////////////////////////////////////////
#define MINIMUM_ADC 0 
#define MAXIMUM_ADC 1023

#define MINIMUM_DATA 0
#define MAXIMUM_DATA 127

int8_t OCTAVE_OFFSET = 0;


/*
 * Maps a range of values to another range of values
 * value s in [a1,a2] is mapped to a value in [b1,b2] and returned
 */
uint16_t mapRange(uint16_t a1,uint16_t a2,uint16_t b1,uint16_t b2,uint16_t s);

/*
 * Maps strain from ADC to an index on axis
 */
uint8_t strain_to_index(uint16_t strain);

/*
 * Maps index to a pitch with the option of changing octave
 * from the global OCTAVE_OFFSET variable
 * Used only in discrete mode
 */
#define MINIMUM_NOTE 60 //start at middle C
uint8_t scale[8] = {MINIMUM_NOTE, MINIMUM_NOTE+2,
                    MINIMUM_NOTE+4, MINIMUM_NOTE+5,
                    MINIMUM_NOTE+7, MINIMUM_NOTE+9,
                    MINIMUM_NOTE+11, MINIMUM_NOTE+12};
uint8_t index_to_pitch(uint8_t index);

/*
 * Maps strain from ADC to velocity value
 */
#define MAXIMUM_VELOCITY 127
uint8_t strain_to_velocity(uint16_t strain);

/*
 * Due to limited resolution this is the mapping method for 
 * pitchbend. Ideally this should be made generic.
 */
uint8_t index_to_pitch_bend(uint8_t index);



#endif	/* MESH_UTIL_H */

