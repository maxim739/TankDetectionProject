Tried object detection on my windows 10 computer from 3/18-20/2022
  - It did not work out

3/18-19 - Followed a tutorial by Edje Electronics, but the video was old, and after ~8 hours of following the tutorial and troubleshooting I decided that it was too meticulous to try and change all of the syntax required to run the program

https://www.youtube.com/watch?v=Rgpfk6eYxJA

3/20 - Gave up on Edje Electronics Tutorial and moved to abdelrahman-gaber's tutorial, which had a similar problem. Then I moved to this video series by CODE MENTAL which worked well, however, it did not work for me even though it was in correlation with the TensorFlow 2 Object detection api tutorial
  
  https://medium.com/@marklabinski/installing-tensorflow-object-detection-api-on-windows-10-7a4eb83e1e7b
  https://www.youtube.com/watch?v=flgJoIrZv2w
  https://tensorflow-object-detection-api-tutorial.readthedocs.io/en/latest/install.html
  https://www.youtube.com/watch?v=T_vcUhoPX2U
  
Things to learn:
  - My NVIDIA Jetson is very helpful and streamlined for training and using all of the toolkits from NVIDIA that I need. Everything is very automatic with their included docker containers.
  - I could use a windows computer if I wanted to have one workstation where I could utilize my powerful NVIDIA GPU; however, my GTX 770 is not recent enough, so the computational power it has is too low for the most recent version of tensorflow.
  - It is a lot easier to run tensorflow in Ubuntu or linux because Tensorflow and others were developed and meant to be ran here. If I really wanted to get into machine learning I would look more towards creating an Ubuntu machine, or learning how to run a virtual environment that could take advantage of my GPU. 
    - My Jetson does this right now, so I don't need to buy anything or convert my computer to windows unless I want to run machine learning in something like Unity or something like that.
  - There are more tutorials like this, so I probaly could get it to work, but after dedicating a weekend to low results, I will continue training and running object detection with my Jetson
  - If I wanted to get into segmentation, I would want to use a bigger GPU, in the tests I was able to run the computer handled it very smoothly
  - If I get a laptop with a good enough GPU, I will definitley try to run this again
  - I could also look into using a cloud Ubuntu machine or using an online GPU
  - Anaconda is very helpful, especially on Windows where I can use the environments to seperate my different projects. Use this more in the future.
