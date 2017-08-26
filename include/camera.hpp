/*
 * camera.hpp
 */

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <opencv2/opencv.hpp>

	class Camera
	{
		public:
			Camera();
			bool init(int device_number);
			bool getFrame(cv::Mat &frame);
		private:
			cv::VideoCapture* _capture;
	};

#endif