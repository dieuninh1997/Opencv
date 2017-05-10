/*
 * TakePhoto.cpp
 *
 *  Created on: May 10, 2017
 *      Author: dieuninh
 */


#include "opencv2/opencv.hpp"
#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace cv;
using namespace std;
int main(int argc, char **argv) {
		VideoCapture cap;
		//string filename="/home/dieuninh/Desktop/photo";

		//	    	 cout<<filename<<endl;
	    // open the default camera, use something different from 0 otherwise;
	    // Check VideoCapture documentation.
		if(!cap.open(0))  // check if we succeeded

		{	cout << "Cannot open the camera" << endl;
	        return -1;
		}
		int time=0;
		int id=0;
		Mat frame, photo;
	    while(1)
	    {


	          cap >> frame;
	          if( frame.empty()) break; // end of video stream
	          imshow("Camera :)", frame);
	          time++;

	          char frame_id[30];
	          char filename[100];
	          strcpy(filename, "/home/dieuninh/Desktop/photo_");

	          cap.set(CV_CAP_PROP_POS_FRAMES,time);
	          if( waitKey(10) == 13 )
	        	  {

	        	  sprintf(frame_id,"%d",id);
	        	  strcat(filename,frame_id);
	        	  strcat(filename,".jpg");

//	        	  strcat(filename, frame_id);
//	        	  strcat(filename, ".jpg");
	        	  imwrite( filename, frame );
	        	  photo=frame.clone();
	        	  imshow("Anh vua chup",photo);
	        	  id++;
	        	  //break; // stop capturing by pressing ESC
	        	  }
	          if(waitKey(10)==27)break;
	    }

//	    cap.release();
//	    waitKey(0);
	    // the camera will be closed automatically upon exit

	    return 0;
}


