#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#define RED_DETECT 1
#define YELLOW_DETECT 2
#define BLUE_DETECT 3
#define GREEN_DETECT 4
#define BLACK_DETECT 5
#define ORANGE_DETECT 6


using namespace cv;
using namespace std;

 int main( int argc, char** argv )
{
  int detect_color=GREEN_DETECT;
  int iLowH =  170;
  int iHighH = 179;

  int iLowS = 150;
  int iHighS = 255;

  int iLowV = 60;
  int iHighV = 255;

    VideoCapture cap(0); //capture the video from webcam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }


 namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"
 cout << "Please, what color do you want detect ?" << endl;
 cout << "RED=1 YELLOW=2 BLUE=3 GREEN=4 BLACK=5 ORANGE=6 ?" << endl;
 cin >> detect_color;


 if (detect_color==RED_DETECT)
 {
   cout << "Color to detect: RED" << endl;
   iLowH =  160;
   iHighH = 179;

   iLowS = 160;
   iHighS = 255;

   iLowV = 60;
   iHighV = 255;
 }
 else if (detect_color==YELLOW_DETECT)
 {
   cout << "Color to detect: YELLOW" << endl;
   iLowH =  22;
   iHighH = 38;

   iLowS = 107;
   iHighS = 255;

   iLowV = 126;
   iHighV = 255;

 }
 else if (detect_color==GREEN_DETECT)
 {
   cout << "Color to detect: GREEN" << endl;
   iLowH =  38;
   iHighH = 75;

   iLowS = 0;
   iHighS = 255;

   iLowV = 0;
   iHighV = 255;

 }
 else if (detect_color==BLUE_DETECT)
 {
   cout << "Color to detect: BLUE" << endl;
   iLowH =  75;
   iHighH = 130;

   iLowS = 0;
   iHighS = 255;

   iLowV = 0;
   iHighV = 255;

 }
  else if (detect_color==ORANGE_DETECT)
 {
   cout << "Color to detect: ORANGE" << endl;
   iLowH =  0;
   iHighH = 22;

   iLowS = 107;
   iHighS = 255;

   iLowV = 189;
   iHighV = 255;

 }
   else if (detect_color==BLACK_DETECT)
 {
   cout << "Color to detect: BLACK" << endl;
   iLowH =  0;
   iHighH = 46;

   iLowS = 0;
   iHighS = 255;

   iLowV = 16;
   iHighV = 131;

 }
 else
 {
    /* nothing to do */
 }

 //Create trackbars in "Control" window
 createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
 createTrackbar("HighH", "Control", &iHighH, 179);

 createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
 createTrackbar("HighS", "Control", &iHighS, 255);

 createTrackbar("LowV", "Control", &iLowV, 255);//Value (0 - 255)
 createTrackbar("HighV", "Control", &iHighV, 255);

 int iLastX = -1;
 int iLastY = -1;

 //Capture a temporary image from the camera
 Mat imgTmp;
 cap.read(imgTmp);

 //Create a black image with the size as the camera output
 Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;


 while (true)
 {
        Mat imgOriginal;

        bool bSuccess = cap.read(imgOriginal); // read a new frame from video


         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }
        //imgOriginal = imread("/home/eliott/Downloads/Pictures/webcam-shot-20180324_014603.jpg");
        //imgOriginal = imread("/home/eliott/Downloads/Pictures/webcam-shot-20180324_014317.jpg");

  Mat imgHSV;

  cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

  Mat imgThresholded;

  inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

  //morphological opening (removes small objects from the foreground)
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

  //morphological closing (removes small holes from the foreground)
  dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

  //Calculate the moments of the thresholded image
  Moments oMoments = moments(imgThresholded);

  double dM01 = oMoments.m01;
  double dM10 = oMoments.m10;
  double dArea = oMoments.m00;

  // if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero
  if (dArea > 10000)
  {
   //calculate the position of the ball
   int posX = dM10 / dArea;
   int posY = dM01 / dArea;

   if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
   {
    //Draw a red line from the previous point to the current point
    line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0,0,255), 2);
   }

   iLastX = posX;
   iLastY = posY;
  }

  imshow("Thresholded Image", imgThresholded); //show the thresholded image

  imgOriginal = imgOriginal + imgLines;
  imshow("Original", imgOriginal); //show the original image
  wait();
        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break;
       }
}/* end while */

   return 0;
}
