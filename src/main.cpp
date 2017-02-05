#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{



    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(71,71), 2, 2);
        Canny(edges, edges, 0, 30, 3);
        if(! edges.data)
        {
        	 cout <<  "No data 2" << endl ;
        }
        imshow("edges", edges);
       // waitKey(30);
        if(waitKey(30) == 27) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
