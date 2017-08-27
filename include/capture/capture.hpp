/*
 * capture.hpp
 */

#ifndef CAPTURE_HPP
#define CAPTURE_HPP

#include <sstream>

#include <opencv2/opencv.hpp>

	class Capture
	{
		public:
			Capture();
			bool init(int device_number, int width, int height);
			bool init(const char* filename);
			bool getFrame(cv::Mat &frame);
			bool getWidth(int &width);
			bool getHeight(int &height);
		private:
			cv::VideoCapture* _capture;
	};

#endif