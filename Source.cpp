#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat rotate(Mat img, double angle)   //rotate function returning mat object with parametres imagefile and angle    
{
    Mat rot;      //Mat object for output image file
    Point2f pt(img.cols / 2., img.rows / 2.);          //point from where to rotate    
    Mat r = getRotationMatrix2D(pt, angle, 1.0);      //Mat object for storing after rotation
    warpAffine(img, rot, r, Size(img.cols, img.rows));  ///applie an affine transforation to image.
    return rot;         //returning Mat object for output image file
}

int main()
{
    Mat img = imread("./images/ujjwal.png");           //reading image file in mat object

    Mat rot;      //Mat object for output image file
    rot = rotate(img, 45);       //rotating image with 30 degree angle

    imshow("img", img);          //displaying input image file
    imshow("rot", rot);         //displaying output image file
    waitKey(0);                     //to exit press escape
    return 0;
}