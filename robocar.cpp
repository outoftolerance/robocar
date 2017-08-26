//Standard Libs
#include <iostream>

//External Libs
#include <opencv2/opencv.hpp>

//My Libs
#include "include/camera.hpp"

int main (void)
{
	Camera camera;
	camera.init(0);

	cv::Mat frame;

	while(1)
	{
		if(!camera.getFrame(frame))
		{
			return -1;
		}

		imshow("Camera", frame);

        if(cvWaitKey(10) == 27)
            break;
	}
}