# MIDI Pedal and Mesh
Digital music production today has a lot of limits. In an analog world a musician can slightly tweak the angle of their bow on a violin to get a different sound. The aim of the “Mesh” is to create a digital instrument with analog levels of control in package compatible with existing digital workflows.

Effects pedals are a common tool used by guitarists to modify the sound of their instrument. These devices are often designed to make one specific sound. The aim of the “Pedal” is to create a customizable audio processing device that gives users direct access to DSP hardware while maintaining the functionality and ease of use that musicians expect.

### Watch this video to see it in action
[![Watch the video](https://i.imgur.com/Uck8nC0.jpg)](https://www.youtube.com/watch?v=qIbVKWIkZBc)

## Implementation
### Overview
The Mesh and Pedal work as standard audio components that can fit seamlessly into any musician’s kit. The Mesh outputs a MIDI signal which can be use to generate sound through any MIDI-capable synthesizer. The Pedal takes in analog audio and performs effects processing on it before outputting it to an amplifier or speaker for play. These devices can work in tandem, independently, or with other music devices.

![How it Works Together](https://i.imgur.com/jpbeJkH.png)

### Pedal
- Users create effects programs on desktop and upload to the device EEPROM via a desktop application and USB connection
- Once loaded to the pedal programs can be selected via a knob
- An LCD screen in the pedal displays the active program and up to three associated parameters for it
- Input analog audio is split into two independent signal paths and processed by the selected program on an FV-1 DSP chip
- The affected signal then runs through an analog equalizer and is blended with the clean signal before it is output.

### Mesh
- Use strain sensors to read force data on two axes via ADC
- Use ADC data to do basic 2D localization of which point in grid is most pressed and by how much
- Map that point to a pitch, pitch-bend, and velocity for MIDI
- Generate MIDI packets from these data
- Send MIDI via UART at 31250 baud


## PCB Design
Three PCBs were created for this project. One for the pedal and two for the mesh. The pedal PCB contains over 160 components that handle digital and analog signals. The mesh PCBs are simpler but took special design considerations into account. Because of the analog nature of the device all analog runs were made as short as possible and processing occurs close to the sensors to deal with noise issues.

![Pedal PCB Image](https://i.imgur.com/LcBRi7f.png)

## Major Compontents
### Pedal
- PIC16F15355 Microcontroller
- FV-1 Spin Semiconductor DSP Chip
- HD44780-Compatible RGB 16x2 Character LCD
- FT232 USB-UART Interface
- 24LC32A External EEPROM Chip
- MAX4910ETE Audio Switch

### Mesh
- PIC16F15376 Microcontroller
- TAL221 Load Cell
- AD620 Differential Amplifier


