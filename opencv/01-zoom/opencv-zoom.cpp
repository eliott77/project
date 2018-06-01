#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
  int iTpX=0, iTpY=0, iTpWidth=1000, iTpHeight=1000;
  Mat imgOriginal;
  Mat cropped;

  while(1)
  {

    imgOriginal = imread("/home/eliott/workstation/projects/project/detect-color-position/pictures/image1-resize-800x600.jpg");
  //Create trackbars in "Control" window
  namedWindow("Control_Image", CV_WINDOW_AUTOSIZE); //create a window called "Control"
    createTrackbar("iTpX", "Control_Image", &iTpX, 4000); 
    createTrackbar("iTpY", "Control_Image", &iTpY, 4000);
    createTrackbar("iTpWidth", "Control_Image", &iTpWidth, 4000);
    createTrackbar("iTpHeight", "Control_Image", &iTpHeight, 4000);

    // Select ROI
    //Rect roi = Rect(iTpX, iTpY, iTpWidth, iTpHeight);
    Rect roi = selectROI("Image", imgOriginal);

    //Update data
    iTpX = roi.x;
    printf("roi.x: %d\n",roi.x);
    iTpY = roi.y;
    printf("roi.y: %d\n",roi.y);
    iTpWidth = roi.width;
    printf("roi.width: %d\n",roi.width);
    iTpHeight = roi.height;
    printf("roi.height: %d\n",roi.height);

    // Crop image
    cropped = imgOriginal(roi);

    imwrite("/home/eliott/workstation/projects/project/detect-color-position/pictures/image1-cropped.jpg",cropped);
    imshow("cropped", cropped);
    cvWaitKey(1000);
  }
  return 0;
}
