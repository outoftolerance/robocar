/*
 * lines.cpp
 */

#include <opencv2/opencv.hpp>

bool lines(cv::Mat input, cv::vector<cv::Vec4i> &lines, int votes, int min_length, int max_gap)
{
	cv::Mat edges;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(2, 2));

	cv::blur(input, input, cv::Size(3,3));
	cv::Canny(input, edges, 0, 250);
	cv::dilate(edges, edges, element);
	cv::HoughLinesP(edges, lines, 5, CV_PI/180, votes, min_length, max_gap);

	return true;
}