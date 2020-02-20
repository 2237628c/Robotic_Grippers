## Timelog

* PROJECT NAME
* ADAM CHRISTIE
* 2237628C
* DR CAMARASA

## Guidance

* This file contains the time log for your project. It will be submitted along with your final dissertation.
* **YOU MUST KEEP THIS UP TO DATE AND UNDER VERSION CONTROL.**
* This timelog should be filled out honestly, regularly (daily) and accurately. It is for *your* benefit.
* Follow the structure provided, grouping time by weeks.  Quantise time to the half hour.
†¥^øπåß∂ƒ©˙∆˚¬Ω≈ç≈Ω≈ç√∫~µ~~~µµ≤≥÷æ«…“‘ºª•¶§∞¢#€€¡≠–“‘«æ…≥÷…æ«÷≥≤…
## Week 1
### 30th Sept 2019
* *4 hours* Prepared for meeting, collecting together summer work completed, questions I had about the project and timescales I should be trying to meet.ß

##1st Oct 2019
* *1 hour* Meeting with supervisor, going over questions.
* *3 hours* Researching different types of grippers, collecting together a group I believed to be suitable to go over with supervisor at the next meeting.

## 3rd Oct 2019
* *2 hour* Meeting with supervisor and post graduate. Here we selected the two grippers from the list I had, after discussion about their pro's and cons. Was also given a tour of the room I will be working in.
* *3 hours* Getting a virtual machine set up and going through more ROS tutorials.



## Week 2
###8th Oct 2019
* *1 hour* Getting a repository set up, committing dissertation template.
* *2 hours* Running designs on CAD software, assembling and committing to dissertation
* *1.5 hours* Researching on the components needed aside from plastic for 3D printing
* *1 hour* Collating components into list with quantities, prices and links for buying

###9th Oct 2019
* *2 hours* Reading documents to aid in writing dissertation
* *1 hour* Going through a few of the given previous dissertations

###10th Oct 2019
* *2 hours* Safety demonstration with Dr Camarasa so that I can use the robotics lab
* *1 hour* 3D Printing a simple cog to ensure that I know the procedure and can do it myself in the future.

###12th Oct 2019
* *1 hour* Planning rough outline for dissertation
* *2 hours* Research on motors and microprocessors


## Week 3 
###15th October
* *7 hours* 3D Printing, whilst also doing tutorials on ROS

###16th October
* *4 hours* 3D Printing, completed 3D printing first claw. 
* *2 hours* Began 3D printing 2nd Claw

###19th October
* *2 hours* researching another 3 fingered claw to print instead of original


## Week 4
###22nd October
* *1 hour* Research on other claw
* *3 hours* Assembling first claw, took longer due to not having screwdrivers that fit

###26th October
* *4 hours* Working through ROS tutorials, research on how to implement code onto Arduino and powering motor.
* *3 hours* Started writing the introduction of dissertation


## Week 5
###29th October
* *4 hours* Researching for background section of dissertation
* *4 hours* Began writing background, needs revision

###30th 
* *7 hours* 3D printing second claw, whilst doing dissertation work in between. 
* *1 hour* Creating parts list for second claw. 


##Week 6
###5th November 
* *7 hours* Finished 3D printing of second claw, assembling majority of it. 

###6th November
* *3 hours* Programmed arduino to control first claw, simple open close loop. 
* *2 hours* Trying to integrate ros subscriber/publisher with arduino 


##Week 7
###11th November
* *5 hours* Trying to find work around for running out of space on Ubuntu VM, not successful

###12th November
* *2 hours* Trying to boot from USB, successful but less storage than VM 
* *5 hours* Trying to increase storage, 32GB USB but only giving 4GB storage space when booting due to Fat32 formatting. 

###13th November 
* *5 hours* Trying to dual boot from PC by creating partition, unsuccessfully.
* *1 hour* Creating UML diagram for code. 
 
 
 ##Week 8
 ###19th November
 * *1 hour* Setting up ROS and arduino on Robotics room pc
 * *4 hours* working on code to open and close claw on key hit 
 
 ###20th November 
 * *3 hours* More writing and editing off introduction and background, some more research involved. 
 * *4 hours* Working on code for opening and closing motor, can now get claw to open and close using o/p keys. 
 
 
 ##Week 9 
 ###26th November
 * *4 hours* Researching into what kind of feedback we can get from the motor, to see if it can close automatically and know when to stop. Research showed ability to "hack" ways to get feedback on certain servo motors.  
 * *1 hour* Taking apart motor to view internals, see if I can get underneath the board to try and get feedback but would be very difficult and not worth it as it isn't necessary.
 
 ###27th November 
 * *3 hours* Research and writing for Background and Introduction, getting closer to final version.
 * *3 hours* Research into motor for gripper2, a lot more complex than the servos we've been using so far. 

###28th November
* *3 hours* proof reading and finalising first two sections, ready to be submitted for feedback. 


##Week 10 
###5th December
* *2 hours* Meeting with supervisor about slowing progress due to exams, got another claw that has the motor I will use on the second claw, as the one ordered is still in a backlog. 

------Finished For Christmas Exams---------

##Week 0 
###2nd January 
* *2 hours* research on dynamixel MX-64 to see how to interface with Arduino without complex circuitry
* *1 hour* Research on TTL and RS-485 data transmissions, must find out what the motor uses before designing circuit for it. 
* *2 hours* Planning of Requirements section of dissertation. 

###3rd January
* *2 hours* Finished planning and write up of Requirements section, tidying up of repository done as well
* *1 hour* Planning out Design section of dissertation.

###6th January
* *7 hours* Got motor and began trying to program in order to get it to work. Came across many issues that caused this to take a lot longer. Will need a second power supply of 12V to power the motor, as arduino Yun has no voltage regulator so can't take anything over 5V. Got this second power supply and got the motor to spin on a pre-defined loop. 

###7th January 
* *7 hours* Working on getting feedback from the motor, such as position, load, torque and temperature. This has been more intense than anticipated, however I have started earlier to account for issues like this. External Circuitry is necessary it would seem in order to get data back from the motor, creating a half-duplex circuit. Have had no success with getting feedback so far, all data I get back is "61568". 

###8th January
* *3 hours* Still trying to get feedback, have tried a few different circuits, as well as a software library that simulates the half duplex circuit, however none have seemed to work.  
* *3 hours* Decided to leave the feedback for today. Worked on getting motor moving using ROS. Can now control motor from keyboard. Three keys are used in total, Spin left, Spin right, stop spinning. This way the user can simply tap a key and it will spin until told otherwise. This differs from the previous motors code, in which you held the key until the desired position was reached. 
* *2 hours* Trying to integrate the two programs, almost finished, just need a few bug fixes. It's still a slightly manual system in that you must comment/uncomment two lines depending on which motor you're using, however if I get the feedback working this might help me make it more automatic.


##Week 1
###14th January
* *3 hours* Beginning the writeup of the design section, roughly jotting down my main points and getting the general layout, so that I can then expand on later
* *3 hours* Working on some bug fixes to code, it seems as though the arduino may not have enough memory to hold both the servo and dynamixel controls, as well as the second subscriber setup to determine which motor is in use. 

###17th January
* *4 hours* Research and work going into how to reduce memory usage on the arduino, although it seems like it isn't possible at the minute. I have also researched a bit about roslaunch, which would allow for deploying both publisher and subscriber with one command.
* *2 hours* Getting roslaunch to work. You can now upload either the servo or dynamixel arduino files, then run the python publisher and the arduino subscriber from one command. 


##Week 2
###20th January
* *4 hours* Fleshing out design section, now half way through.

###24th January 
* *3 hours* Research into using DynamixelWizard to test feedback, had to wire up the USB2DYNAMIXEL device with my dynamixel motor and power supply. By testing this I can see if the motor returns feedback at all. 
* *2 hours* Setting up Dynamixel wizard on PC, should be ready for use, had to update the dynamixels firmware.


##Week 3
###28th January
* *5 hours* Installing and using DynamixelWizard in order to test if feedback is working. Took a long time to get set up properly and to get the hardware set up. Updated the firmware, and was able to control and get feedback through this software. However none of the feedback available will help us to detect whether an object is gripped or not. I believed that "torque" would have been an indicator however this relates to when the motor is changing position. Will have to discuss with Supervisor. 

###31s January 
* *3 hours* Finishing up the Design section , will have another read through before submitting to supervisor for revision. 


###1st February
* *2 hours* Revising Sections 1-4. Sent to supervisor to get feedback. 


##Week 4 
###5th February
* *2 hours* After meeting with supervisor discussed the possibility of using shields on top of the arduino to interface with the dynamixel and get feedback. Decided on Robotis' own shield that they produce, Dynamixel Shield. This will be the best solution as Robotis provide Arduino libraries to be used with the shield to control the Dynamixel. 
 
 ###7th February
 * *5 hours* Dynamixel Shield arrived, testing out on the Dynamixel. Still unable to get feedback. With the Shield on the dynamixel doesn't respond to anything. 
 
 ###8th February
 * *5 hours* Trying to get the Shield to work. Had to email Dynamixel Tech support as it should work once setup. 
 * *4 hours* Changed back to my original circuit that worked with ROS, but dynamixel no longer responds. Tried attaching it to the USB2Dynamixel to see if the DynamixelWizard could help me troubleshoot, but it couldn't even find the motor. 
 
 ##Week 5
 ###10th February
 * *2 hours* Fixing issues pointed out in the feedback from my supervisor about sections 3 and 4.
 * *3 hours* Still trying to get Dynamixel to work
 * *4 hours* Researching other types of motors incase I have to switch to another. 
 
 ###12th February
 * *3 hours* Beginning to plan out implementation section of dissertation. 
 
 ###14th February
 * *1 hour* Meeting with supervisor where I stated that given the situation with the Dynamixel motor and our time constraints it might be best to change motors. I stated that I believe a stepper motor is a good choice as I was aware he had some on hand and the alternative would be a DC motor which would have to be ordered.
 * *4 hours* research on controlling a stepper motor, how the driver works and software used for configuring them. Also on how they can be integrated with Arduino. 
 
 ###15th February
 * *5 hours* Working on configuring stepper motor with Tic GUI, testing out different modes of turning, working out which will be most useful and efficient for arduino integration. 
 * *3 hours* Planning what 3D printed pieces will have to be changed to fit the new motor and how, taking necessary measurements so I can make appropriate changes to the Base, worm driver and possibly the holding struts. 
 
 ###16th February 
 * *3 hours* Using Fusion360 to create new CAD parts.
 
 ###17th February 
 * *2 hours* Issue when trying to slice the CAD STL files, had to go back to drawings and make changes, Then slicing again. 
 * *4 hours* Working on getting stepper motor to move, decided on Analogue speed control, I can output a pwm signal from Arduino that I can change to appear as certain voltages, then using TicGUI I can set the motor to turn certain ways on these signals. 
 * *2 hours* Integrating code to work with ROS, now works perfectly. 
 
 
