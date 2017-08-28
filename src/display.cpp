/*
 * display.cpp
 */

#include <opencv2/opencv.hpp>

bool lines2color(cv::vector<cv::Vec4i> lines, cv::Mat &output, int r, int g, int b)
{
	for(int i = 0; i < lines.size(); i++)
	{
		cv::line(
			output, 
			cv::Point(lines[i][0], lines[i][1]),
			cv::Point(lines[i][2], lines[i][3]), 
			cv::Scalar(b, g, r), 
			3, 
			8
		);
	}

	return true;
}

bool show(cv::Mat input, cv::Mat white, cv::Mat yellow, cv::Mat result)
{
	//viewing windows
	cv::resize(input, input, cv::Size(), 0.25, 0.25);
	cv::imshow("Input View", input);
	cv::moveWindow("Input View", 100, 100);

	//Thresholds
	cv::resize(white, white, cv::Size(), 0.25, 0.25);
	cv::imshow("White Threshold View", white);
	cv::moveWindow("White Threshold View", 100 + 500, 100);

	cv::resize(yellow, yellow, cv::Size(), 0.25, 0.25);
	cv::imshow("Yellow Threshold View", yellow);
	cv::moveWindow("Yellow Threshold View", 100 + 500, 100 + 200);

	//Lines
	cv::resize(result, result, cv::Size(), 0.25, 0.25);
	cv::imshow("Combined Lines View", result);
	cv::moveWindow("Combined Lines View", 100 + 1000, 100);

	return true;
}