/*
 * CatAnh.cpp
 *
 *  Created on: May 11, 2017
 *      Author: dieuninh
 */


#include<opencv2/opencv.hpp>
#include<iostream>
#include<string.h>
using namespace cv;
using namespace std;
Mat loadAnh(int so)
{
	Mat image;
	char filename[100];
	strcpy(filename, "/home/dieuninh/Desktop/anh/a");
	char frame_id[30];
	sprintf(frame_id,"%d",so);
	strcat(filename, frame_id);
	strcat(filename, ".jpg");
	//cout<<filename<<endl;
	image=imread(filename,1);//load color image bgr
	return image;
}
int main(int argc, char **argv) {
	imshow("Anh 0",loadAnh(0));
	imshow("Anh 1",loadAnh(1));
}


