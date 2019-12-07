/* 
 * File:   mesh_util.c
 * Author: BC
 *
 * Created on December 1, 2019, 4:34 PM
 */

#include "mesh_util.h"

void mesh_init() {
    poll_axis(&pitch_axis, &pitch_channels);
    poll_axis(&param_axis, &param_channels);
    threshold_calibration(&pitch_axis,&param_axis);
}


////////////////////////////////////////////////////////
//
//      AXIS/ADC UTILITIES
//
////////////////////////////////////////////////////////

void poll_axis(uint16_t* axis, adc_channel_t* channel) {
	uint8_t i = 0;
	for(i = 0; i < AXIS_LENGTH; i++) {
		axis[i] = ADC_GetConversion(channel[i]);
	}
}

uint8_t get_max(uint16_t* axis) {
	uint16_t max = 0;
    uint8_t max_index = 0;
    uint8_t i = 0;
    for(i = 0; i < AXIS_LENGTH; i++) {
        if(axis[i] > max) {
            max = axis[i];
            max_index = i;
        }
    }
    return max_index;
}


uint8_t get_max_pitch(uint16_t* axis) {
	uint16_t max = 0;
    uint8_t max_index = 0;
    uint8_t i = 0;
    for(i = 0; i < AXIS_LENGTH; i++) {
        if(axis[i] > pitch_axis_threshold[i]) {
            if(axis[i] - pitch_axis_threshold[i] > max) {
                max = axis[i] - pitch_axis_threshold[i];
                max_index = i;
            }
        }
    }
    return max_index;
}

uint8_t get_max_param(uint16_t* axis) {
	uint16_t max = 0;
    uint8_t max_index = 0;
    uint8_t i = 0;
    for(i = 0; i < AXIS_LENGTH; i++) {
        if(axis[i] > param_axis_threshold[i]) {
            if(axis[i] - param_axis_threshold[i] > max) {
                max = axis[i] - param_axis_threshold[i];
                max_index = i;
            }
        }
    }
    return max_index;
}




void threshold_calibration(uint16_t* x_axis, uint16_t* y_axis) {
    uint8_t i = 0;
    for(i = 0; i < AXIS_LENGTH; i++){
        pitch_axis_threshold[i] = x_axis[i] + 0;
        param_axis_threshold[i] = y_axis[i] + 0;
    }
}





////////////////////////////////////////////////////////
//
//      MAPPING/MIDI UTILITIES
//
////////////////////////////////////////////////////////
//value s in [a1,a2] is mapped to return value in [b1,b2]
uint16_t mapRange(uint16_t a1,uint16_t a2,uint16_t b1,uint16_t b2,uint16_t s) {
	return b1 + (s-a1)*(b2-b1)/(a2-a1);
}

uint8_t strain_to_index(uint16_t strain) {
    //there are 6 strings, index 0 - 5
    return mapRange(MINIMUM_ADC, MAXIMUM_ADC, 0, 5, strain);

}


uint8_t index_to_pitch(uint8_t index) {
    return scale[index] + OCTAVE_OFFSET * 12;
}


uint8_t strain_to_velocity(uint16_t strain) {
    return mapRange(MINIMUM_ADC, MAXIMUM_ADC, MINIMUM_DATA, MAXIMUM_DATA, strain);
}

uint8_t index_to_pitch_bend(uint8_t index) {
    //change this later
    if(index == 0)
        return 44;
    if(index == 1)
        return 54;
    if(index == 4)
        return 74;
    if(index == 5)
        return 84;
    else return 64;
}




