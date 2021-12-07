//
//  Chapter5.cpp
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


void wrapPresPective(string path){
    float w = 250,h = 350;
    Mat matrix,imgWrap;
    Mat img = imread(path);
    Point2f src[4] = {{529,142},{771,190},{405,395},{674, 457}};
    Point2f dst[4] = {{0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};
    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img,imgWrap,matrix,Point(w,h));
    for (int i = 0; i<4; i++) {
        circle(img, src[i],10, Scalar(0,0,255),FILLED);
    }
    imshow("Image Warped", imgWrap);
    imshow("Image ord", img);
    waitKey(0);
}
