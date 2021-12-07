#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


void playWithBlank(){
    Mat img(512,512,CV_8UC3,Scalar(255,255,255));
//    circle(img, Point(256, 256),100, Scalar(0,0,0),10);
    circle(img, Point(256, 256),155, Scalar(254,206,139),FILLED);
    rectangle(img, Point(130,226), Point(382,286), Scalar(139,206,254),FILLED);
    line(img, Point(130,296), Point(382,296), Scalar(139,206,254),2);
    putText(img, "BrijSiyag", Point(160,270), FONT_ITALIC, 1.5, Scalar(254,206,139),3);
    imshow("Image", img);
    waitKey(0);
}
