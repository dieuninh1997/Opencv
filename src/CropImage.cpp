/*
 * CropImage.cpp
 *
 *  Created on: May 10, 2017
 *      Author: dieuninh
 */


#include "opencv2/opencv.hpp"

#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main()
{
/// Load source image, convert it to gray and blur it
Mat src, gray,canny_output;
src = imread("/home/dieuninh/Desktop/plate_0.0(957,116).jpg");
cvtColor( src, gray, CV_BGR2GRAY );
blur( gray, gray, Size(3,3) );
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;

/// Detect edges using canny
Canny( gray, canny_output, 50, 150, 3 );
/// Find contours
findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

/// Get the moments
vector<Moments> mu(contours.size() );
for( int i = 0; i < contours.size(); i++ )
{ mu[i] = moments( contours[i], false ); }

/// Get the mass centers:
vector<Point2f> mc( contours.size() );
for( int i = 0; i < contours.size(); i++ )
{ mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); }

/// Draw contours
Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );

for( int i = 0; i< contours.size(); i++ )
{
drawContours( drawing, contours, i, Scalar(255,0,0), 2, 8, hierarchy, 0, Point() );
rectangle(drawing, boundingRect(contours[i]), Scalar(0,255,0),2, 8,0);
circle( drawing, mc[i], 4, Scalar(0,255,255), -1, 8, 0 );
}

imshow( "Contours", drawing );
imshow("Source",src);

printf("\t Info: Area and Contour Length \n");
printf("\t Width: %d \t\t Height: %d \n",src.cols,src.rows);
for( int i = 0; i< contours.size(); i++ )
printf("Contour[%d] - Central(x[%d],y[%d]):(%.2f,%.2f) - Area[%d]: %.2f - Length: %.2f \n", i,i,i, mu[i].m10/mu[i].m00,mu[i].m01/mu[i].m00 ,i, contourArea(contours[i]), arcLength( contours[i], true ) );
waitKey(0);
return(0);
}
