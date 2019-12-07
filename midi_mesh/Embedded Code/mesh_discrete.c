/* 
 * File:   mesh_discrete.c
 * Author: BC
 *
 * Created on December 1, 2019, 4:34 PM
 */

#include "mesh_discrete.h"


void discrete() {
    //poll ADC for data on each axis
    poll_axis(&pitch_axis, &pitch_channels);
    poll_axis(&param_axis, &param_channels);

    //find max on each axis and get index
    uint8_t max_pitch_index = get_max_pitch(&pitch_axis);
    uint8_t max_param_index = get_max_param(&param_axis);

    //get values from index
    uint8_t pitch = index_to_pitch(max_pitch_index);
    uint8_t param = index_to_pitch_bend(max_param_index); //No mapping from index
                                                     //to param yet, but it takes
                                                     //a value 0-127 so this is fine for now
    uint8_t velocity = strain_to_velocity(pitch_axis[max_pitch_index]);

    //play a note based on found values

    if(pitch_axis[max_pitch_index] > 240 && can_play == 1) {
        start_timer();
        
        //cannot use a single sample for velocity because it would just use whatever value took it
        //over the threshold
        note_on(CHANNEL, pitch, 127);

        
        while(pitch_axis[max_pitch_index] > 200 || can_play == 0) { //while we hold the note harder than THRESHOLD
            //do aftertouch


            //do pitch bend
            poll_axis(&param_axis, &param_channels);
            max_param_index = get_max_param(&param_axis);
            
            //pitch_bend(CHANNEL, index_to_pitch_bend(max_param_index), 0);//coarse bend, no fine
            if((param_axis[max_param_index] > 200 && can_bend == 1) || can_bend == 0) {
                param = index_to_pitch_bend(max_param_index);
                pitch_bend(CHANNEL, param, 0);
            }
            else {
                reset_pitch_bend(CHANNEL);
            }

            poll_axis(&pitch_axis, &pitch_channels); //repopulate axis for loop check
            can_exit();
        }

        note_on(CHANNEL, pitch, 0); //more commonly supported note off
        reset_pitch_bend(CHANNEL);
    }
    
}
