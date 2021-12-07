//
//  Chapter6.cpp
//  OpenCv1
//
//  Created by BRIJMOHAN SIYAG on 07/12/21.
//

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int hmin = 0,smin = 110,vmin = 153;
int hmax = 19,smax = 240,vmax = 255;
Mat imgHSV,mask;
static void logger(int, void*){
    cout<<hmin<<" "<<smin<<" "<<vmin<<" "<<hmax<<" "<<smax<<" "<<vmax<<endl;
}
void colorDetect(string path){
    Mat img = imread(path);
    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    namedWindow("Trackbars",WINDOW_AUTOSIZE);
    createTrackbar("Hue min", "Trackbars", &hmin, 179,logger);
    createTrackbar("Hue max", "Trackbars", &hmax, 179,logger);
    createTrackbar("sat min", "Trackbars", &smin, 255);
    createTrackbar("sat max", "Trackbars", &smax, 255);
    createTrackbar("val min", "Trackbars", &vmin, 255);
    createTrackbar("val max", "Trackbars", &vmax, 255);
    while (true) {
        Scalar lower(hmin,smin,vmin),upper(hmax,smax,vmax);
        inRange(imgHSV, lower, upper, mask);
        imshow("Masked", mask);
//        imshow("Image Warped", imgHSV);
//        imshow("Image ord", img);
        waitKey(100);
    }
    
}
