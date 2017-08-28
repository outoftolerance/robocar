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
#include "src/threshold.cpp"
#include "src/lines.cpp"
#include "src/display.cpp"

void printHelp(void)
{
	std::cout << "Out Of Tolerance Robocar!" << std::endl;
	std::cout << "\t-c\tSets input mode to camera, connects to given device id" << std::endl;
	std::cout << "\t-x\tFrame width, sets camera width resolution" << std::endl;
	std::cout << "\t-y\tFrame height, sets camera height resolution" << std::endl;
	std::cout << "\t-f\tSets input mode to file, loads given filepath" << std::endl;
	std::cout << "\t-o\tOutput flag, saves output.avi to disk" << std::endl;
	std::cout << "\t-v\tViewing window flag, set to display outputs" << std::endl;
}

int main (int argc, char* argv[])
{
	Capture capture;
	cv::VideoWriter output;
	int opt;

	int capture_type = 0, capture_device, capture_width, capture_height;
	bool save_output = false, display = false;
	std::string input_file, output_file;

	//figure out the command line arguments
	while((opt = getopt(argc, argv, "c:x:y:f:ovh")) != -1)
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
				output_file = "output.avi";
				save_output = true;
				break;
			case 'v':
				display = true;
				break;
			case 'h':
				printHelp();
				return 1;
				break;
			default:
				std::cout << "Option not recognised!" << std::endl;
				printHelp();
				return -1;
				break;
		}
	}

	if(capture_type <= 0)
	{
		std::cout << "Capture type not set!" << std::endl;
		printHelp();
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
			printHelp();
			return -1;
			break;
	}

	if(save_output == true)
	{
		output.open(output_file, CV_FOURCC('M','J','P','G'), 30, cv::Size(capture_width, capture_height), true);
	}

	cv::Mat frame;
	cv::Mat yellow_display, white_display, combined_display;
	cv::Mat whites, yellows;
	cv::vector<cv::Vec4i> yellow_lines, white_lines;

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

		//threshold
		threshold(frame, whites, yellows);

		//hough lines
		lines(whites, white_lines, 300, 25, 25);
		lines(yellows, yellow_lines, 100, 50, 300);

		//colorize for viewing
		cv::cvtColor(whites, white_display, CV_GRAY2RGB);
		cv::cvtColor(yellows, yellow_display, CV_GRAY2RGB);

		lines2color(white_lines, white_display, 0, 255, 0);
		lines2color(yellow_lines, yellow_display, 255, 255, 0);

		//combine the line outputs
		combined_display = white_display | yellow_display;

		//save output
		if(save_output == true)
		{
			output.write(combined_display);
		}

		//display results
		if(display == true)
		{
			show(frame, whites, yellows, combined_display);
		}

		//wait for escape
        if(cvWaitKey(10) == 27)
            break;
	}
}
