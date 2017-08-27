//Standard Libs
#include <iostream>

//External Libs
#include <opencv2/opencv.hpp>

//My Libs
#include "include/capture/capture.hpp"

int main (void)
{
	Capture capture;
	//capture.init(0, 1920, 1080);
	capture.init("../video3.mp4");

	cv::Mat frame, frame_hsv, yellow_edges, white_edges, yellow_edges_color, white_edges_color, whites, yellows, epic;
	cv::Mat input_view, input_hsv_view, input_blur_view, edges_view, lines_view, whites_view, yellows_view, epic_view;
	cv::vector<cv::Vec4i> yellow_lines, white_lines;

	//set dilation element for edge gap filling
	cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(2, 2));

	//set the roi
	cv::Rect roi(0, 400, 1920, 1080 - 400);

	while(1)
	{
		//capture next frame
		if(!capture.getFrame(frame))
		{
			return -1;
		}

		//crop frame to ROI
		frame = frame(roi);

		//create HSV version of frame
		cv::cvtColor(frame, frame_hsv, CV_BGR2HSV);

		//cut out whites and yellows
		cv::inRange(frame, cv::Scalar(180, 180, 180), cv::Scalar(255, 255, 255), whites);
		cv::inRange(frame_hsv, cv::Scalar(25, 50, 50), cv::Scalar(40, 255, 255), yellows);

		//yellows
		cv::blur(yellows, yellows, cv::Size(3,3));
		cv::Canny(yellows, yellow_edges, 0, 250);
		cv::dilate(yellow_edges, yellow_edges, element);
		cv::cvtColor(yellow_edges, yellow_edges_color, CV_GRAY2BGR);

		cv::HoughLinesP(yellow_edges, yellow_lines, 5, CV_PI/180, 100, 50, 150);

		for(size_t i = 0; i < yellow_lines.size(); i++)
		{
			cv::line(yellow_edges_color, cv::Point(yellow_lines[i][0], yellow_lines[i][1]),
				cv::Point(yellow_lines[i][2], yellow_lines[i][3]), cv::Scalar(0, 0, 255), 3, 8);
		}

		//whites
		cv::blur(whites, whites, cv::Size(3,3));
		cv::Canny(whites, white_edges, 0, 250);
		cv::dilate(white_edges, white_edges, element);
		cv::cvtColor(white_edges, white_edges_color, CV_GRAY2BGR);

		cv::HoughLinesP(white_edges, white_lines, 5, CV_PI/180, 300, 100, 25);

		for(size_t i = 0; i < white_lines.size(); i++)
		{
			cv::line(white_edges_color, cv::Point(white_lines[i][0], white_lines[i][1]),
				cv::Point(white_lines[i][2], white_lines[i][3]), cv::Scalar(0, 0, 255), 3, 8);
		}

		//combine the line outputs
		epic = yellow_edges_color | white_edges_color;

		//viewing windows
		cv::resize(frame, input_view, cv::Size(), 0.25, 0.25);
		cv::imshow("Input View", input_view);
		cv::moveWindow("Input View", 0, 0);

		cv::resize(frame_hsv, input_hsv_view, cv::Size(), 0.25, 0.25);
		cv::imshow("Input HSV View", input_hsv_view);
		cv::moveWindow("Input HSV View", 0, frame.rows/3);

		cv::resize(whites, whites_view, cv::Size(), 0.25, 0.25);
		cv::imshow("White Threshold View", whites_view);
		cv::moveWindow("White Threshold View", 500 + 60, 0);

		cv::resize(yellows, yellows_view, cv::Size(), 0.25, 0.25);
		cv::imshow("Yellow Threshold View", yellows_view);
		cv::moveWindow("Yellow Threshold View", 500 + 60, frame.rows/3);

		cv::resize(epic, epic_view, cv::Size(), 0.25, 0.25);
		cv::imshow("Combined Frame View", epic_view);
		cv::moveWindow("Combined Frame View", 500 + 60, frame.rows*2/3);

        if(cvWaitKey(10) == 27)
            break;
	}
}