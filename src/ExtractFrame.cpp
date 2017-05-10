/*

 * ExtractFrame.cpp
 *
 *  Created on: May 10, 2017
 *      Author: dieuninh




#include "opencv2/opencv.hpp"
#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
using namespace cv;

void showCamera(VideoCapture cap)
{
	    //Mat edges;
	    //namedWindow("edges",1);
	    for(;;)
	    {
	        Mat frame;
	        cap >> frame; // get a new frame from camera
	        if( frame.empty() )
	        	break; // end of video stream
	        imshow("Video", frame);
	        if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC
	    }
	    // the camera will be deinitialized automatically in VideoCapture destructor

}

void extractImageFromVideo(VideoCapture cap)
{

	    double count = cap.get(CV_CAP_PROP_FRAME_COUNT); //get the frame count
	    cout<<"count frame in video="<<count;
	    while((count)!=-1)
	    {
	    	int id=count-1;
	    	count-=1;
	    	cap.set(CV_CAP_PROP_POS_FRAMES,id); //Set index to last frame
	    	Mat image2;
	    	cap>>image2;
	    	char filename[100];
	    	strcpy(filename, "/home/dieuninh/Desktop/video/frame_");

	    	char frame_id[30];
	    	sprintf(frame_id,"%d",id);
	    	 strcat(filename, frame_id);
	    	 strcat(filename, ".jpg");
//	    	 cout<<filename<<endl;
	    	 imwrite( filename, image2 );
	    }
}




int main( int argc, char** argv )
{
	VideoCapture cap(0); // open the default camera

	if(!cap.isOpened())  // check if we succeeded
	{	cout << "Cannot open the camera" << endl;
        return -1;
	}


	VideoCapture cap("/home/dieuninh/Desktop/video/1.mp4");
	if( !cap.isOpened()){
		cout << "Cannot open the video file" << endl;
		return -1;
	}
	showCamera(cap);
	extractImageFromVideo(cap);

	return 0;
}
*/
