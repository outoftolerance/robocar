# Robocar
This is my robocar project code. It's not very good... Have fun!

 - See complete details of the project on my website (coming soon)
 - Supports Raspberry Pi 3 as main application processor
 - Requires my [robocar_firmware](https://github.com/outoftolerance/robocar_firmware) project to interface the Pi with the car hardware
 - Uses input images from a Pi camera to detect road lines
 - Road line location determines desired behaviour of the vehicle
 - Will output via serial terminal steering, and throttle commands

### Installation

Robocar requires [OpenCV 3](https://opecv.org)

OpenCV Download
```
$ cd ~/Documents
$ git clone https://github.com/opencv/opencv.git
```

OpenCV Build
```
$ cd opencv
$ mkdir build
$ cd build
$ cmake ..
$ make
```

OpenCV Install
```
$ sudo make install
```

OR

OpenCV Install
```
$ sudo apt-get install libopencv-dev
```

Once OpenCV is installed the Robocar project can be built correctly as follows.

Clone
```sh
$ cd ~/Documents
$ git clone http://github.com/outoftolerance/robocar
```

Build
```sh
$ cd robocar
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Run
```sh
$ ./robocar
```