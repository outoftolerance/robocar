/*
 * camera.cpp
 */

#include "camera.hpp"

#include <iostream>
#include <opencv2/opencv.hpp>

Camera::Camera()
{
	std::cout << "Created camera instance." << std::endl;	
}

/*
 * Initializes the library
 */
bool Camera::init(int device_number)
{
	std::cout << "Connecting to camera." << std::endl;
	std::cout << "Device number: " << device_number << std::endl;

	_capture = new cv::VideoCapture(device_number);

	if(!_capture->isOpened()){
        std::cout << "Failed to connect to camera!" << std::endl;
        return false;
    }

    return true;
}

/*
 * Returns latest frame from camera
 */
bool Camera::getFrame(cv::Mat &frame)
{
	frame = _capture->grab();

	if(frame.empty())
	{
		std::cout << "Failed to capture frame!" << std::endl;
		return false;
	}

	return true;
}