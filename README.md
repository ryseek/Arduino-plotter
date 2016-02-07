# Arduino-plotter
A little CNC/plotter, made from CD drive's steppers, L293D chips and arduino 



Here is a tutorial how to make an extremely cheap CNC or plotter using only 2-3 old CD or floppy drives, stepper motor driver chips and arduino. 

Arduino playground provides very user-friendly library for using bipolar stepper motors(Stepper.h). Why we use stepper motors? because they are way more accurate in compare with motor direct current. 
Bipolar stepper has 4 headers, 2 in pairs. It allows to step a small part of full turn, not to spin continuously. 

![My image](http://i.stack.imgur.com/vfHqC.gif)

Usually CD/floppy drive consitsts from stepper and some mechanic for optical reader. So you can get a platform, drived by stepper with almost zero efforts. All you need is to disassemble disk drive till that platform and connect some wires to it's stepper. Also this motors needs a stepper driver chip. In my project i use L293D chip. Here is an example of wiring up:

![My image](http://www.arduino-diy.com/wp-content/uploads/2015/07/Arduino_A298N_stepper.jpg)

After that it's needed to find out good settings for your steppers (I suppose they are similar to mine's settings). 
Connect 2-3 steppers and optionally servo, glue platoform and marker or pen. As the result you get something like this: 

![My image](http://cs620627.vk.me/v620627171/19a0a/wODZ2-6TIqk.jpg)

Now software. Usually CNC and 3d printers use G-code. It's special language for machine for coordination. Let's look at example: 
50x 20y 10z - it means that header moves to the coordinate with this values. 
So, arduino firmware should understand this code. I used coordinate system, related to zero point. First, declare zero position. After, send absolute coordinates. Arduino will save it's postion every time. This is the most difficult thing. 

To use my code you need to adopt it to your project. Because directions of moving depend on wiring, and it's only my example. 
For sending G-code arduino IDe can be used. For automatization I code a spesial programm for windows pc. But you can find another G-code sender soft for free.  

![My image](http://cs620627.vk.me/v620627171/19a13/6sIYDCc3mvk.jpg)

That's what can be written with this:

![My image](http://cs620627.vk.me/v620627171/19a00/lB3IpbR2rCg.jpg)

If you have questions, ask them ^_^ 
ryseek1@gmail.com
