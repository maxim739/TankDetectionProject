I want to control an arduino with my Jetson nano, so I set up Serial communication

I followed this tutorial for the basics:
http://blog.rareschool.com/2019/05/five-steps-to-connect-jetson-nano-and.html

ArduinoCommunication.ino uploaded to the arduino, and serial_send.py running on the Jetson you can communicate from the Jetson to the arduino to tell the bult in LED to turn on

If you run the examples/04/ASCIITable script on the arduino and run the ser.py script on the Jetson, the ASCII output from the arduino is pasted to the Jetson

Now I just need to figure out how to use this to impliment back and forth control and tell the arduino to control a motor and other stuff from serial - 3/15/2022
