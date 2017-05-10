#include <opencv2/opencv.hpp>
#include <iostream>
#include<string>
using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	char *fileImage="/home/dieuninh/Desktop/oencv.png";
	Mat image= imread( fileImage, 1 );
	if(!image.data)
	{
		cout<<"No image data\n";
		return -1;

	}
	Mat resizeImage;
	Size size(100,100);
	resize(image,resizeImage,size);
	imshow("Before",image);
	imshow("After", resizeImage);
	waitKey(0);
	return 0;

}

