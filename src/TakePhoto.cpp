/*
 * TakePhoto.cpp
 *
 *  Created on: May 10, 2017
 *      Author: dieuninh
 */


#include "opencv2/opencv.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main(int argc, char **argv) {
		VideoCapture cap;
		string filename="/home/dieuninh/Desktop/photo1.jpg";

		//	    	 cout<<filename<<endl;
	    // open the default camera, use something different from 0 otherwise;
	    // Check VideoCapture documentation.
		if(!cap.open(0))  // check if we succeeded

		{	cout << "Cannot open the camera" << endl;
	        return -1;
		}
		int time=0;
	    while(1)
	    {

	          Mat frame;
	          cap >> frame;
	          if( frame.empty()) break; // end of video stream
	          imshow("Camera :)", frame);
	          time++;


	          if( waitKey(10) == 13 )
	        	  {
	        	  cap.set(CV_CAP_PROP_POS_FRAMES,time);
	        	  imwrite( filename, frame );
	        	  break; // stop capturing by pressing ESC
	        	  }
	    }
	    // the camera will be closed automatically upon exit

	    return 0;
}


