/* 
 * File:   mesh_continuous.c
 * Author: BC
 *
 * Created on December 1, 2019, 4:52 PM
 */

#include "mesh_continuous.h"

uint8_t get_interp_pitch(uint16_t* axis) {
    uint8_t div = PITCH_RANGE / (AXIS_LENGTH-1);
    uint8_t maxIndex1 = get_max_pitch(axis);
    
    //return maxIndex1;
    //return ((axis[1] *div)/ axis[0])+ MIN_PITCH;
    
    if(axis[maxIndex1] > pitch_axis_threshold[maxIndex1]){
        if(maxIndex1 == 0){
            if( axis[1] > pitch_axis_threshold[1]){
                //do interpolation between first and second string
                //if we are on the first string
                
                return ((axis[1] *div)/ axis[0])+ MIN_PITCH;
                //ratio of smaller/larger * the div of the different
                //between two strings + the starting pitch
            }
            else{
                //return ((axis[1] *div)/ axis[0])+ MIN_PITCH;
                return MIN_PITCH;
            }
        } else if (maxIndex1 == AXIS_LENGTH - 1){
            if( axis[AXIS_LENGTH - 2] > pitch_axis_threshold[AXIS_LENGTH - 2]){
                //the max string is on the last string
                return MAX_PITCH - ((axis[AXIS_LENGTH - 2] *div)/ axis[AXIS_LENGTH - 1]);
            }
            else {
                return MAX_PITCH;
            }
        } 
        else {
            //we are somewhere in the middle of the strings
            //return the div number times the string we are on,
            //minus the value of the string below, plus the value of the string above
            if( (axis[maxIndex1 - 1] > pitch_axis_threshold[maxIndex1 - 1]) && (axis[maxIndex1+ 1] > pitch_axis_threshold[maxIndex1 + 1])){
                return (maxIndex1*div) - ( ( axis[maxIndex1 - 1]*div) / axis[maxIndex1] ) + ( (axis[maxIndex1 + 1]*div) / axis[maxIndex1] ) + MIN_PITCH;
            } else if ( axis[maxIndex1 - 1] > pitch_axis_threshold[maxIndex1 - 1] ){
                return (maxIndex1*div) - ( ( axis[maxIndex1 - 1] *div)/ axis[maxIndex1] ) + MIN_PITCH;
            }
            else if ( axis[maxIndex1 + 1] > pitch_axis_threshold[maxIndex1 + 1]){
                return (maxIndex1*div) + ( (axis[maxIndex1 + 1] *div )/ axis[maxIndex1] ) + MIN_PITCH;
            } 
            else {
                return maxIndex1 * div + MIN_PITCH;
            }
        }
        }
    else {
        return MIN_PITCH;
    }
}




uint8_t get_interp_param(uint16_t* axis) {
    uint8_t div = PARAM_RANGE / (AXIS_LENGTH-1);
    uint8_t maxIndex1 = get_max_param(axis);
    
    if(axis[maxIndex1] > param_axis_threshold[maxIndex1]){
        if(maxIndex1 == 0){
            if( axis[1] > param_axis_threshold[1]){
                //do interpolation between first and second string
                //if we are on the first string
                
                return ((axis[1] *div)/ axis[0])+ MIN_PARAM;
                //ratio of smaller/larger * the div of the different
                //between two strings + the starting pitch
            }
            else{
                //return ((axis[1] *div)/ axis[0])+ MIN_PITCH;
                return MIN_PARAM;
            }
        } else if (maxIndex1 == AXIS_LENGTH - 1){
            if( axis[AXIS_LENGTH - 2] > param_axis_threshold[AXIS_LENGTH - 2]){
                //the max string is on the last string
                return MAX_PARAM - ((axis[AXIS_LENGTH - 2] *div)/ axis[AXIS_LENGTH - 1]);
            }
            else {
                return MAX_PARAM;
            }
        } 
        else {
            //we are somewhere in the middle of the strings
            //return the div number times the string we are on,
            //minus the value of the string below, plus the value of the string above
            if( (axis[maxIndex1 - 1] > param_axis_threshold[maxIndex1 - 1]) && (axis[maxIndex1+ 1] > param_axis_threshold[maxIndex1 + 1])){
                return (maxIndex1*div) - ( ( axis[maxIndex1 - 1]*div) / axis[maxIndex1] ) + ( (axis[maxIndex1 + 1]*div) / axis[maxIndex1] ) + MIN_PARAM;
            } else if ( axis[maxIndex1 - 1] > param_axis_threshold[maxIndex1 - 1] ){
                return (maxIndex1*div) - ( ( axis[maxIndex1 - 1] *div)/ axis[maxIndex1] ) + MIN_PARAM;
            }
            else if ( axis[maxIndex1 + 1] > param_axis_threshold[maxIndex1 + 1]){
                return (maxIndex1*div) + ( (axis[maxIndex1 + 1] *div )/ axis[maxIndex1] ) + MIN_PARAM;
            } 
            else {
                return maxIndex1 * div + MIN_PARAM;
            }
        }
        }
    else {
        return MIN_PARAM;
    }
}





/*
 *	continuous()
 *
 *	This function generates MIDI music signals based on continuous input
 *  each string on the mesh can be used to represent one pitch or parameter
 *  But pushing between strings can yield notes in between them.
 *  After playing a note, aftertouch is sent to change sound based on continued
 *  pressure on the device.
 */
void continuous() {
    //poll ADC for data on each axis
    poll_axis(&pitch_axis, &pitch_channels);
    poll_axis(&param_axis, &param_channels);

    //find max on each axis and get index
    uint8_t max_pitch_index = get_max_pitch(&pitch_axis);
    uint8_t max_param_index = get_max_param(&param_axis);

    //get values from index
    uint8_t pitch = get_interp_pitch(&pitch_axis);
    uint8_t param = get_interp_param(&param_axis); //No mapping from index
                                                     //to param yet, but it takes
                                                     //a value 0-127 so this is fine for now
    uint8_t velocity = strain_to_velocity(pitch_axis[max_pitch_index]);

    //play a note based on found values

    if(pitch_axis[max_pitch_index] > pitch_axis_threshold[max_pitch_index]) {
        //cannot use a single sample for velocity because it would just use whatever value took it
        //over the threshold
        note_on(CHANNEL, pitch, 127);

        while(pitch_axis[max_pitch_index] > pitch_axis_threshold[max_pitch_index]) { //while we hold the note harder than THRESHOLD
            //re-poll this
            poll_axis(&pitch_axis, &pitch_channels);
            poll_axis(&param_axis, &param_channels);

            //update pitch and parameters
            pitch = get_interp_pitch(&pitch_axis);
            param = get_interp_param(&param_axis);

            //find possible new max for parameter axis
            max_param_index = get_max_param(&param_axis);

            //do aftertouch
            aftertouch(CHANNEL,pitch_axis[max_pitch_index]);

            //do pitch bend
            pitch_bend(CHANNEL, param, 0);
        }

        note_on(CHANNEL, pitch, 0); ///more commonly supported note off
        reset_pitch_bend(CHANNEL);
    }

}

