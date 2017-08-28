/*
 * threshold.cpp
 */

#include <opencv2/opencv.hpp>

bool threshold(cv::Mat input, cv::Mat &white, cv::Mat &yellow)
{
	cv::Mat hsv, black;

	//convert to HSV
	cv::cvtColor(input, hsv, CV_BGR2HSV);

	//threshold out whites and yellows
	cv::inRange(input, cv::Scalar(180, 180, 180), cv::Scalar(255, 255, 255), white);
	cv::inRange(input, cv::Scalar(0, 0, 0), cv::Scalar(180, 180, 180), black);
	cv::inRange(hsv, cv::Scalar(25, 50, 50), cv::Scalar(40, 255, 255), yellow);

	//if there is stuff in yellow, remove it from white
	white = white & (255 - yellow);

	//if there is stuff in black, remove it from yellow
	yellow = yellow & (255 - black);

	return true;
}