# Arduino-plotter
A little CNC/plotter, made from CD drive's steppers, L293D chips and arduino 



Here is a tutorial how to make an extremely cheap CNC or plotter using only 2-3 old CD or floppy drives, stepper motor driver chips and arduino. 

Arduino playground provides very user-friendly library for using bipolar stepper motors(Stepper.h). Why we use stepper motors? because they are way more accurate in compare with motor direct current. 
Bipolar stepper has 4 headers, 2 in pairs. It allows to step a small part of full turn, not to spin continuously. 

![My image](http://i.stack.imgur.com/vfHqC.gif)

Usually CD/floppy drive consitsts from stepper and some mechanic for optical reader. So you can get a platform, drived by stepper with almost zero efforts. All you need is to disassemble disk drive till that platform and connect some wires to it's stepper. Also this motors needs a stepper driver chip. In my project i use L293D chip. Here is an example of wiring up.

![My image](http://www.arduino-diy.com/wp-content/uploads/2015/07/Arduino_A298N_stepper.jpg)
