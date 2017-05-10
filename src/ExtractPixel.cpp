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
Xay dung chtr sd opencv de trich chon bk diem anh ma co bit khac 0
	//cach 1: sd Vec3b : Vec3b vec = image.at<Vec3b>(i, j);
	//Point2f point = pointsMat.at<Point2f>(i, 0);
	//Vec3f intensity = img.at<Vec3f>(y, x);
	//cach 2: type elem_a= matrix.at<type>[c](i,j);
			//type elem = matrix.ptr<type>(i)[Nc * j + c]
			//type elem_a= matrix.at<type>[c](i,j);
			//Point p=Point(x,y); float elem_a= a.at<float>(p);
	//cach 3: sd macro CV_MAT_ELEM
	//cach 4: sd imageData array: vd myimage.imageData[3*(y*myimage.width+x)+0] for red an RGB image


void solve(Mat m)
{
	int rows=m.rows;
	int cols=m.cols;
	srand (time(NULL));
	 //generate secret number between min and max : output = min + (rand() % (int)(max - min + 1))


	do
	{
		int irow = rand() %(rows+1) ;
		int jcol = rand() %(cols+1) ;
		Vec3b vec = m.at<Vec3b>(irow, jcol);
		if(vec[0]!=0 || vec[1]!=0 || vec[2]!=0)
		{
			cout<<"Pixel("<<irow<<","<<jcol<<")="<<vec<<endl;
			break;
		}
	}while(1);
}


int main( int argc, char** argv )
{
	 string imageName="/home/dieuninh/workspace/ConvertImage/images/16.jpg" ;//=new char;//= argv[1];
	//cin>>imageName;
	Mat image;
	image = imread( imageName, 1 );

	if( /argc != 2 || !image.data )
	{
		printf( " No image data \n " );
		return -1;
	}

	namedWindow( imageName, WINDOW_NORMAL );
	imshow( imageName, image );
//	solve(image);
	srand (time(NULL));
	int rows=image.rows;
	int cols=image.cols;
	cout<<"rows="<<rows<<endl;
	cout<<"cols="<<cols<<endl;
	int i = rand() %(rows+1) ;
	int j = rand() %(cols+1) ;
//	cout<<image.ptr<unsigned int>(i)[3*j+0]<<endl;
//	cout<<(uchar)image.ptr<uchar>(i)[3*j+0]<<endl;
//	cout<<(uchar)image.ptr<uchar>(i)[3*j+1]<<endl;
//	cout<<(int)image.ptr<uchar>(i)[3*j+2]<<endl;

	waitKey(0);
return 0;
}

*/
