//
//  Chapter3.cpp
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


void crop(string path){
    Mat img = imread(path);
    Rect rect(100,100,300,300);
    img = img(rect);
    imshow("Image",img);
    waitKey(0);
}

void resize(string path){
    Mat img = imread(path);
    resize(img, img, Size(),5,0.5);
    imshow("Image Resized", img);
    waitKey(0);
}
