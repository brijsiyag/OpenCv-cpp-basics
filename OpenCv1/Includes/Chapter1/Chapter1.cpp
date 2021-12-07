
//
//  FirstChapter.cpp
//  OpenCv1
//
//  Created by BRIJMOHAN SIYAG on 06/12/21.
//

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void showImg(string path){
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);
}

void showVideo(string path){
    VideoCapture cap(path);
    Mat img;
    while (true) {
        cap.read(img);
        imshow("Image", img);
        waitKey(40);
    }
}
void showWebCam(){
    VideoCapture cap(0);
    Mat img,imgBlur,imgCanny,imgDil,imgErod;
    Mat kernal = getStructuringElement(MORPH_RECT, Size(3,3));
    while (1) {
        cap.read(img);
        GaussianBlur(img,imgBlur,Size(7,7),5,1);
        Canny(imgBlur, imgCanny, 50, 75);
        dilate(imgCanny, imgDil, kernal);
        erode(imgDil, imgErod, kernal);
        imshow("Image", imgErod);
        waitKey(10);
    }
}
