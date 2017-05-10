/*



 * ConvertImage.cpp
 *
 *  Created on: May 8, 2017
 *      Author: dieuninh



#include <opencv2/opencv.hpp>
#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
using namespace cv;
//Xay dung chtr sd opencv de trich chon bk diem anh ma co bit khac 0
	//cach 1: sd Vec3b : Vec3b vec = image.at<Vec3b>(i, j);
	//Point2f point = pointsMat.at<Point2f>(i, 0);
	//Vec3f intensity = img.at<Vec3f>(y, x);
	//cach 2: type elem_a= matrix.at<type>[c](i,j);
			//type elem = matrix.ptr<type>(i)[Nc * j + c]
			//type elem_a= matrix.at<type>[c](i,j);
			//Point p=Point(x,y); float elem_a= a.at<float>(p);
	//cach 3: sd macro CV_MAT_ELEM
	//cach 4: sd imageData array: vd myimage.imageData[3*(y*myimage.width+x)+0] for red an RGB image


Mat convert2binary(Mat m)
{
	Mat binaryImage;
	threshold(m,binaryImage,128,255,CV_THRESH_BINARY);
	return binaryImage;
}
Mat convert2Gray(Mat m)
{
	Mat grayImage;
	cvtColor(m,grayImage,CV_BGR2GRAY);
	return grayImage;
}

int main( int argc, char** argv )
{
	 string imageName="/home/dieuninh/workspace/ConvertImage/images/16.jpg" ;//=new char;//= argv[1];
	//cin>>imageName;
	Mat image;
	image = imread( imageName, 1 );

	if(!image.data )
	{
		printf( " No image data \n " );
		return -1;
	}

	namedWindow( imageName, WINDOW_NORMAL );
	imshow( imageName, image );
	Mat i1=convert2binary(image);
	namedWindow( imageName, WINDOW_NORMAL );
	imshow( "binary Image",i1 );
	Mat i=convert2Gray(image);
	namedWindow( "gray image", WINDOW_NORMAL );
	imshow( "i", i );
	waitKey(0);
return 0;
}



*/
