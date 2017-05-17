/*


 * ExtractFrame.cpp
 *
 *  Created on: May 10, 2017
 *      Author: dieuninh


*/

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
	    	strcpy(filename, "/home/dieuninh/Desktop/frame/img_");

	    	char frame_id[30];
	    	sprintf(frame_id,"%d",id);
	    	 strcat(filename, frame_id);
	    	 strcat(filename, ".jpg");
	    	 cout<<filename<<endl;
	    	 imwrite( filename, image2 );
	    }
}
vector<Mat> store;
void extractFromStream(VideoCapture cap)
{
//	 double count = cap.get(CV_CAP_PROP_FRAME_COUNT); //get the frame count
	 int id=0;
	 while(1)
	{
		Mat img;
		bool bSuccess = cap.read(img);

		//int conti=cap.get(CV_CAP_PROP_POS_MSEC);
		//cout<<"CV_CAP_PROP_POS_MSEC: "<<con
		//cout<<conti<<endl;
		if(!bSuccess)
		{
			//int conti=cap.get(CV_CAP_PROP_POS_MSEC);
			//cap.set(CV_CAP_PROP_POS_MSEC, conti); //start the video at 300ms
			cout<<"No frame\n";
			waitKey();

		}
		id++;
		if(img.data)
		{
			char filename[100];

			strcpy(filename, "/home/dieuninh/Desktop/ninh/i_");
			char frame_id[30];
			sprintf(frame_id,"%d",id);
			strcat(filename, frame_id);
			strcat(filename, ".jpg");
			cout<<endl<<filename<<endl;
			imwrite( filename, img );
			if(cv::waitKey(1) ==27) break;
		}
	}
}
int main() {
	string stream="http://4co2.vp9.tv/chn/VTT4/v.m3u8";
	VideoCapture cap;
	cap.open(stream);

	if( !cap.isOpened()){
		cout << "Cannot open the video file" << endl;
		return -1;
	}
	while(cap.isOpened())
	{
		cout<<"OKKKKKKKKKKKK";
		extractFromStream(cap);
		waitKey(0);
	}
}


