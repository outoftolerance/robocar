#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
 
int main()
{
    int camera = 0;
    VideoCapture capture(camera);

    capture.set(CV_CAP_PROP_FPS, 5);
    capture.set(CV_CAP_PROP_FRAME_WIDTH,1920);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,1080);

    cout << "Starting video capture!" << endl;
    cout << "Camera: " << camera << endl;
    cout << "Framerate: " << capture.get(CV_CAP_PROP_FPS) << endl;
    cout << "Resolution: " << capture.get(CV_CAP_PROP_FRAME_WIDTH) << "x" << capture.get(CV_CAP_PROP_FRAME_HEIGHT) << endl;

    if(!capture.isOpened()){
        cout << "Failed to connect to the camera." << endl;
        return -1;
    }

    Mat frame;

    while(1)
    {
        capture >> frame;

        if(frame.empty()){
            cout << "Failed to capture an image" << endl;
            return -1;
        }

        imshow("Camera", frame);

        if(cvWaitKey(10) == 27)
            break;
    }
    
    return 0;
}