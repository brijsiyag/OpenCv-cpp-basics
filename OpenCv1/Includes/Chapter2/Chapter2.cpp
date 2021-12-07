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

void converToGray(string path){
    Mat img = imread(path);
    Mat imgGray;
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    imshow("Image", imgGray);
    waitKey(0);
}

void basicFunctions(string path){
    Mat img = imread(path),blurImg,cannyImg,dilImg,erdImg;
    
    GaussianBlur(img,blurImg,Size(7,7),5,1);
    
    Canny(blurImg, cannyImg, 100, 1);
    
    Mat kernal = getStructuringElement(MORPH_RECT, Size(3,3));
    
    dilate(cannyImg, dilImg, kernal);
    
    erode(dilImg, erdImg, kernal);
    
    imshow("Image", img);
    imshow("Blur Image", blurImg);
    imshow("Canny Image", cannyImg);
    imshow("Dilation Image", dilImg);
    imshow("Erode Image", erdImg);
    waitKey(0);
}
