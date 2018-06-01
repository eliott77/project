#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdlib.h>
#include <stdio.h>

#define RED_DETECT 1
#define YELLOW_DETECT 2
#define BLUE_DETECT 3
#define GREEN_DETECT 4
#define BLACK_DETECT 5
#define ORANGE_DETECT 6
#define COLOR_NBR 6
//#define DEBUG

#define GREEN_SIDE 1
#define ORANGE_SIDE 0

#define ZOOM_X_G 286
#define ZOOM_Y_G 309
#define ZOOM_WITH_G 68
#define ZOOM_HEIGHT_G 57

#define ZOOM_X_O 286
#define ZOOM_Y_O 309
#define ZOOM_WITH_O 68
#define ZOOM_HEIGHT_O 57
//#define DEBUG_MENU


using namespace cv;
using namespace std;

unsigned char u8OpenFileFirst = true;

int save_data (const char* s8Color)
{
  const char *s8FileName = "/home/eliott/color_detected.txt";
  fstream outputFile;
  string line;

  if (u8OpenFileFirst == true)
  {
    //Clean all file
    outputFile.open(s8FileName, ios::out | ios::trunc);
    u8OpenFileFirst = false;
  }
  else
  {
    outputFile.open(s8FileName);
  }
  outputFile.clear();
  while ( getline (outputFile,line) )
  {
      cout << line << '\n';
  }
  outputFile.clear();
  outputFile << s8Color << " Color has been detected" <<  endl;
  outputFile.close();

  return 0;
}

// Prints the usage for this program
static void print_usage(bool help)
{
    FILE* stream = (help) ? stdout : stderr;

    printf("Usage: opencv-detect-color <color side>\n");

    if (!help) {
        return;
    }

    printf("\t<color side>:\t\tSelect the color side: GREEN or ORANGE.\n");

    return;
}


int main( int argc, char *argv[] )
{
  int detect_color=YELLOW_DETECT;
  char option;
  const char *s8ColorName = "GREEN";
  const char *s8ImgName = "/home/eliott/Downloads/Pictures/webcam-shot.jpg";
  int iLowH, iHighH;
  int iLowS, iHighS;
  int iLowV, iHighV;
  const char *s8Color = "GREEN";
  Mat imgOriginal;
  int color_side;

  while ((option = getopt(argc, argv, "t:r:s:o:h")) != (char)-1)
  {
    switch (option)
    {

       case 'h':
           print_usage(true);
           exit(0);

       default:
           print_usage(false);
           return -1;
    }
  }


  // Check that there are enough command line arguments
  if (optind > argc-1) {
        fprintf(stderr, "Error: Too few command line arguments.\n");
        print_usage(false);
        return -1;
  }

  // Check if there are too many command line arguments remaining
  if (optind < argc-1) {
        printf("Error: Too many command line arguments.\n");
        print_usage(false);
        return -1;
  }

  /* Check the color: GREEN or ORANGE */
  if ( strcmp(argv[1],"GREEN") == 0)
  {
    color_side = GREEN_SIDE;
  }
  else if ( strcmp(argv[1],"ORANGE") == 0)
  {
    color_side = ORANGE_SIDE;
  }
  else
  {
    printf("Error: Please select a color side\n");
    return -1;
  }

  #ifdef DEBUG_MENU
  cout << "Please, what color do you want detect ?" << endl;
  cout << "RED=1 YELLOW=2 BLUE=3 GREEN=4 BLACK=5 ORANGE=6 ?" << endl;
  cin >> detect_color;
  #endif

  VideoCapture cap(0); //capture the video from webcam

  if ( !cap.isOpened() )  // if not success, exit program
  {
     cout << "Cannot open the web cam" << endl;
     return -1;
  }

  //Capture a temporary image from the camera
  Mat imgTmp;
  bool bSuccess = cap.read(imgTmp); // read a new frame from video
  if (!bSuccess) //if not success, break loop
  {
    cout << "Cannot read a frame from video stream" << endl;
    return -1;
  }
  sleep(1);
  imwrite(s8ImgName,imgTmp);
  cap.release(); // close the video file

  // Main Loop
while (detect_color <= COLOR_NBR)
{

  #ifdef DEBUG_MENU
  //Create trackbars in "Control" window
  namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

  createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
  createTrackbar("HighH", "Control", &iHighH, 179);

  createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
  createTrackbar("HighS", "Control", &iHighS, 255);

  createTrackbar("LowV", "Control", &iLowV, 255);//Value (0 - 255)
  createTrackbar("HighV", "Control", &iHighV, 255);

  #else

  switch (detect_color)
  {
    case GREEN_DETECT:
       s8Color = "GREEN";
       break;
    case YELLOW_DETECT:
       s8Color = "YELLOW";
       break;
    case BLUE_DETECT:
       s8Color = "BLUE";
       break;
    case BLACK_DETECT:
       s8Color = "BLACK";
       break;
    case ORANGE_DETECT:
       s8Color = "ORANGE";
       break;

  };

  if (detect_color==RED_DETECT)
  {
     cout << "Color to detect: RED" << endl;
     iLowH =  160;
     iHighH = 179;

     iLowS = 160;
     iHighS = 255;

     iLowV = 60;
     iHighV = 255;

     s8ColorName = "RED";
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

     s8ColorName = "YELLOW";

  }
  else if (detect_color==GREEN_DETECT)
  {
     cout << "Color to detect: GREEN" << endl;
     iLowH =  38;
     iHighH = 75;

     iLowS = 39;
     iHighS = 255;

     iLowV = 0;
     iHighV = 255;

     s8ColorName = "GREEN";

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

     s8ColorName = "BLUE";

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

     s8ColorName = "ORANGE";

  }
  else if (detect_color==BLACK_DETECT)
  {
     cout << "Color to detect: BLACK" << endl;
     iLowH =  105;
     iHighH = 179;

     iLowS = 0;
     iHighS = 255;

     iLowV = 16;
     iHighV = 131;

     s8ColorName = "BLACK";

  }
  else
  {
     /* nothing to do */
  }
  #endif
//Create trackbars in "Control" window
  namedWindow("Control_Image", CV_WINDOW_AUTOSIZE); //create a window called "Control"

  #ifndef DEBUG
  imgOriginal = imread(s8ImgName);

  /* Zoom code color */
  if (color_side == GREEN_SIDE)
  {
    Rect roi = Rect(ZOOM_X_G, ZOOM_Y_G, ZOOM_WITH_G, ZOOM_HEIGHT_O);
    // Crop image
    imgOriginal = imgOriginal(roi);
  }
  else if (color_side == ORANGE_SIDE)
  {
    Rect roi = Rect(ZOOM_X_O, ZOOM_Y_O, ZOOM_WITH_O, ZOOM_HEIGHT_O);
    // Crop image
    imgOriginal = imgOriginal(roi);
  }
  else
  {
    printf("Error: Please select a color side\n");
    return -1;
  }

  #else
  imgOriginal = imread("/home/eliott/workstation/projects/project/detect-color-position/pictures/image1-cropped.jpg");
  #endif

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

  imshow("Thresholded Image", imgThresholded); //show the thresholded image


    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    Mat dst = Mat::zeros(imgThresholded.rows, imgThresholded.cols, CV_8UC3);

    findContours( imgThresholded, contours, hierarchy,
        CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );

    // iterate through all the top-level contours,
    // draw each connected component with its own random color
    int idx = 0;
    int cpt = 0;
    for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
      sScalar color( rand()&255, rand()&255, rand()&255 );
      drawContours( dst, contours, idx, color, CV_FILLED, 8, hierarchy );
      cpt++;
    }

    if ( cpt > 1)
    {
      /* nothing to do */
    }
   else
    {
      cout << s8Color << " Color has been detected" <<  endl;

      save_data(s8Color);
    }

  imshow( "Components", dst );
  imshow("Original", imgOriginal); //show the original image

//cvWaitKey(0);
  #ifdef DEBUG_MENU
   cvWaitKey(0);
   if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
   {
    cout << "esc key is pressed by user" << endl;
    return 0;
   }
  #else
   detect_color++;
  #endif

} /* end main loop */


  //cleaning up
  cvDestroyAllWindows();

  return 0;
}
