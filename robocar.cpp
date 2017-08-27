//Standard Libs
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <sstream>

//External Libs
#include <opencv2/opencv.hpp>

//My Libs
#include "include/capture/capture.hpp"

int main (int argc, char* argv[])
{
	Capture capture;
	cv::VideoWriter output;
	int opt;

	int capture_type = 0, capture_device, capture_width, capture_height;
	bool save_output = false;
	std::string input_file, output_file;

	//figure out the command line arguments
	while((opt = getopt(argc, argv, "c:x:y:f:o:")) != -1)
	{
		switch(opt)
		{
			case 'c':
				capture_device = std::atoi(optarg);
				capture_type = 1;
				break;
			case 'x':
				capture_width = std::atoi(optarg);
				break;
			case 'y':
				capture_height = std::atoi(optarg);
				break;
			case 'f':
				if(capture_type == 1)
				{
					std::cout << "Capture type already set to camera, ignoring file path" << std::endl;
				}
				else
				{
					capture_type = 2;
					input_file = optarg;
				}
				break;
			case 'o':
				output_file = optarg;
				save_output = true;
				break;
			default:
				std::cout << "Option not recognised!" << std::endl;
				return -1;
				break;
		}
	}

	if(capture_type <= 0)
	{
		std::cout << "Capture type not set!" << std::endl;
		return -1;
	}

	switch(capture_type)
	{
		//camera
		case 1:
			capture.init(capture_device, capture_width, capture_height);
			break;
		//file
		case 2:
			capture.init(input_file.c_str());
			capture.getWidth(capture_width);
			capture.getHeight(capture_height);
			break;
		default:
			std::cout << "Capture type not recognised!" << std::endl;
			return -1;
			break;
	}

	if(save_output == true)
	{
		output.open(output_file, CV_FOURCC('M','J','P','G'), 30, cv::Size(capture_width, capture_height), true);
	}

	cv::Mat frame, frame_hsv, yellow_edges, white_edges, yellow_edges_color, white_edges_color, whites, yellows, dulls, blacks, epic;
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
		cv::inRange(frame, cv::Scalar(0, 0, 0), cv::Scalar(180, 180, 180), blacks);
		cv::inRange(frame_hsv, cv::Scalar(25, 50, 50), cv::Scalar(40, 255, 255), yellows);

		//if there is stuff in yellow, remove it from white
		whites = whites & (255 - yellows);

		//if there is stuff in black, remove it from yellow
		yellows = yellows & (255 - blacks);

		//yellows line detect
		cv::blur(yellows, yellows, cv::Size(3,3));
		cv::Canny(yellows, yellow_edges, 0, 250);
		cv::dilate(yellow_edges, yellow_edges, element);
		cv::cvtColor(yellow_edges, yellow_edges_color, CV_GRAY2BGR);

		cv::HoughLinesP(yellow_edges, yellow_lines, 5, CV_PI/180, 100, 50, 300);

		for(size_t i = 0; i < yellow_lines.size(); i++)
		{
			cv::line(yellow_edges_color, cv::Point(yellow_lines[i][0], yellow_lines[i][1]),
				cv::Point(yellow_lines[i][2], yellow_lines[i][3]), cv::Scalar(0, 255, 255), 3, 8);
		}

		//whites line detect
		cv::blur(whites, whites, cv::Size(3,3));
		cv::Canny(whites, white_edges, 0, 250);
		cv::dilate(white_edges, white_edges, element);
		cv::cvtColor(white_edges, white_edges_color, CV_GRAY2BGR);

		cv::HoughLinesP(white_edges, white_lines, 5, CV_PI/180, 300, 25, 25);

		for(size_t i = 0; i < white_lines.size(); i++)
		{
			cv::line(white_edges_color, cv::Point(white_lines[i][0], white_lines[i][1]),
				cv::Point(white_lines[i][2], white_lines[i][3]), cv::Scalar(0, 255, 0), 3, 8);
		}

		//combine the line outputs
		epic = yellow_edges_color | white_edges_color;

		if(save_output == true)
		{
			output.write(epic);
		}

		//viewing windows
		cv::resize(frame, frame, cv::Size(), 0.25, 0.25);
		cv::imshow("Input View", frame);
		cv::moveWindow("Input View", 100, 100);

		cv::resize(frame_hsv, frame_hsv, cv::Size(), 0.25, 0.25);
		cv::imshow("Input HSV View", frame_hsv);
		cv::moveWindow("Input HSV View", 100, 300);

		//Thresholds
		cv::resize(whites, whites, cv::Size(), 0.25, 0.25);
		cv::imshow("White Threshold View", whites);
		cv::moveWindow("White Threshold View", 100 + 500, 100);

		cv::resize(yellows, yellows, cv::Size(), 0.25, 0.25);
		cv::imshow("Yellow Threshold View", yellows);
		cv::moveWindow("Yellow Threshold View", 100 + 500, 100 + 200);

		cv::resize(blacks, blacks, cv::Size(), 0.25, 0.25);
		cv::imshow("Black Threshold View", blacks);
		cv::moveWindow("Black Threshold View", 100 + 500, 100 + 400);

		//Lines
		cv::resize(white_edges_color, white_edges_color, cv::Size(), 0.25, 0.25);
		cv::imshow("White Lines View", white_edges_color);
		cv::moveWindow("White Lines View", 100 + 500 * 2, 100);

		cv::resize(yellow_edges_color, yellow_edges_color, cv::Size(), 0.25, 0.25);
		cv::imshow("Yellow Lines View", yellow_edges_color);
		cv::moveWindow("Yellow Lines View", 100 + 500 * 2, 100 + 200);

		cv::resize(epic, epic, cv::Size(), 0.25, 0.25);
		cv::imshow("Combined Lines View", epic);
		cv::moveWindow("Combined Lines View", 100 + 500 * 2, 100 + 400);

        if(cvWaitKey(10) == 27)
            break;
	}
}