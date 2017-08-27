/*
 * capture.cpp
 */

#include "capture.hpp"

#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>

Capture::Capture()
{

}

/*
 * Initializes the library
 * Sets device and image resolution
 */
bool Capture::init(int device_number, int width, int height)
{
	std::cout << "Connecting to camera" << std::endl;
	std::cout << "Device number: " << device_number << std::endl;

	_capture = new cv::VideoCapture(device_number);

	_capture->set(CV_CAP_PROP_FRAME_WIDTH, width);
    _capture->set(CV_CAP_PROP_FRAME_HEIGHT, height);

	if(!_capture->isOpened()){
        std::cout << "Failed to connect to camera" << std::endl;
        return false;
    }

    std::cout << "Connected to camera" << std::endl;

    return true;
}

/*
 * Initializes the library
 * Sets device and image resolution
 */
bool Capture::init(char* filename)
{
	std::cout << "Loading video file" << std::endl;
	//std::cout << "Filepath: " << filename << std::endl;

	_capture = new cv::VideoCapture(filename);

	if(!_capture->isOpened()){
        std::cout << "Failed to load file" << std::endl;
        return false;
    }

    std::cout << "File loaded successfuly" << std::endl;

    return true;
}

/*
 * Returns latest frame from capture stream
 */
bool Capture::getFrame(cv::Mat &frame)
{
	cv::Mat tmp;

	_capture->read(tmp);

	if(tmp.empty())
	{
		std::cout << "Failed to capture frame!" << std::endl;
		return false;
	}

	frame = tmp;

	return true;
}