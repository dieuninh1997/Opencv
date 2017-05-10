/*
 * EditImage.cpp
 *
 *  Created on: May 10, 2017
 *      Author: dieuninh
 */

/*

#include<opencv2/opencv.hpp>
#include<iostream>
#include<string>
using namespace cv;
using namespace std;

void menu()
{
	cout<<"\n1.Enter filePath of image and Show image."
			<<"\n2.Convert gray image."
			<<"\n3.Convert binary image."
			<<"\n4.Resize image."
			<<"\n5.Extract a pixel from image and show it."
			<<"\n6.Select a part of image."
			<<"\n7.Exit"
			<<"\nChoose:";
}

int main(int argc, char **argv) {
	while(1)
	{
	menu();
	int x;
	int thoat=0;
	cin>>x;
	Mat image;
	switch(x)
	{
	case 1:
		string filePath;
		cin>>filePath;

		image = imread(filePath, 1 );
		if(!image.data)
		{
			cout<<"No image data\n";
			thoat=1;
			break;
		}
//		imshow(filePath,image);
		break;
	case 2:
		Mat grayImage;
		cvtColor(image,grayImage,CV_BGR2GRAY);
		imwrite("/home/dieuninh/Desktop/gray.jpg",grayImage);
		imshow("Gray image",grayImage);
		break;
	case 3:
		Mat binaryImage;
		threshold(image,binaryImage,128,255,CV_THRESH_BINARY);
		imwrite("/home/dieuninh/Desktop/binary.jpg",binaryImage);
		imshow("Binary image",binaryImage);
		break;
	case 4:
		Mat resizeImage;
		Size size(100,100);
		resize(image,resizeImage,size);
		imwrite("/home/dieuninh/Desktop/resize.jpg",resizeImage);
		imshow("Resize Image",resizeImage);

		break;
	case 5:
			cout<<"\n";
			break;
	case 6:
		int x1,y1,x2,y2;
		cout<<"\nEnter coordinate : x1=";cin>>x1;
		cout<<"y1=";cin>>y1;
		cout<<"x2=";cin>>x2;
		cout<<"y3=";cin>>y2;
		break;
	case 7:

			thoat=1;
			break;
	}
	if(thoat==1)exit(0);
	}
	waitKey(0);
	return 0;
}


*/
