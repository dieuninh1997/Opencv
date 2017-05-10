/*
 * ResizeImage.cpp
 *
 *  Created on: May 10, 2017
 *      Author: dieuninh
 */


#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc, char **argv) {
	string imageName = "/home/dieuninh/workspace/ConvertImage/images/16.jpg";
	 Mat image;
	 image = imread( imageName, 1);//mau: CV_LOAD_IMAGE_COLOR
	  if(!image.data )
	  {
	    printf( " No image data \n " );
	    return -1;
	  }


	  Mat imageResize;
	  Size size(100,100);
	  resize(image,imageResize,size);//resize image


	  namedWindow( "Before", WINDOW_AUTOSIZE );
	  namedWindow( "After", WINDOW_AUTOSIZE );
	   imshow( "Before", image );
	   imshow( "After", imageResize );
	  waitKey(0);
	  return 0;
}



