/*
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
using namespace cv;
RNG rng(12345);
double alpha; *< Simple contrast control
int beta;  *< Simple brightness control

void i_crop(Mat image)
{
	Mat img1=image.clone();
	Mat img;
	cvtColor( image, img, COLOR_BGR2GRAY );
//	Mat img1=imread("/home/dieuninh/Desktop/plate_832.1(18,192).jpg",1);

	//load anh gray
//	Mat img=imread("/home/dieuninh/Desktop/plate_832.1(18,192).jpg",0);

	//sao chep anh
	Mat src_gray=img.clone();

	//loc anh
	blur(img,img,Size(10,10));

	Mat binary_img,morph;
	//chuyen sang anh nhi phan
	//threshold(img,binary_img,130,255,CV_THRESH_BINARY);
	//dung chuyen nhi phan voi nguong dong

	adaptiveThreshold(img,binary_img,255,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY,7,1.2);

	imshow("BInary Image ",binary_img);
	//ham dinh hinh khoi
	Mat element=getStructuringElement(MORPH_CROSS,Size(3,3),Point(1,1));//mac dinh Point(-1,-1), anh matrix 3x3
	Rectangular box: MORPH_RECT
	Cross: MORPH_CROSS
	Ellipse: MORPH_ELLIPSE
	imshow("ELEMENT",element);

	//erode(binary_img,morph,element,Point(-1,1),3);//make white smaller
	erode(binary_img,morph,element);
	imshow("Binary Image Erode ",morph);
	imshow("Gray Image ",img1);

	//ham tim bien dang, tim vien anh
	vector<vector<Point> > contour;

	findContours(binary_img,contour,CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLECV_RETR_LIST,CV_CHAIN_APPROX_NONE);


	//CV_RETR_LIST retrieves all of the contours without establishing any hierarchical relationships.
	//CV_CHAIN_APPROX_NONE stores absolutely all the contour points.

	// Draw polygonal contour + bonding rects
	Rect r;
	for(int i=0;i<contour.size();i++)
	{
		 r=boundingRect(contour[i]);
		 //loai bo nhung hcn qua nho hoac qua to
		if(r.width/(double)r.height>1.36f && r.width/(double)r.height<2.0f)
			rectangle(img1,r,Scalar(0,0,255),1,8,0);//mau do
		else
			rectangle(img1,r,Scalar(0,255,0),1,8,0);//green
	}
//	imshow("Rect Image",img1);

	 * void rectangle(Mat& img, Point pt1, Point pt2, const Scalar& color, int thickness=1, int lineType=8, int shift=0)
	 * Parameters:
	img – Image.
	pt1 – Vertex of the rectangle.
	pt2 – Vertex of the rectangle opposite to pt1 .
	rec – Alternative specification of the drawn rectangle.
	color – Rectangle color or brightness (grayscale image).
	thickness – Thickness of lines that make up the rectangle. Negative values, like CV_FILLED , mean that the function has to draw a filled rectangle.
	lineType – Type of the line. See the line() description.
	shift – Number of fractional bits in the point coordinates.
//	imshow("Resutl",img1);

	Rect roi;
		if(r.width>r.height)
		{
			roi.height=r.width;
			roi.width=r.width;

		}else
		{
			roi.width=r.height;
			roi.height=r.width;
		}
//		cout<<"w="<<r.width<<", h="<<r.height<<endl;
	Mat crop=img1(r);
//
		imshow("Resutl",crop);

	//return crop;
}
Mat i_brighter()
{
	Mat image = imread("/home/dieuninh/Desktop/a33.jpg");
	 Mat new_image = Mat::zeros( image.size(), image.type() );

	 /// Initialize values
//	 std::cout<<" Basic Linear Transforms "<<std::endl;
//	 std::cout<<"-------------------------"<<std::endl;
//	 std::cout<<"* Enter the alpha value [1.0-3.0]: ";std::cin>>alpha;
//	 std::cout<<"* Enter the beta value [0-100]: "; std::cin>>beta;
	 alpha=1.1;
	 beta=50;
	 /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
	 for( int y = 0; y < image.rows; y++ )
	    { for( int x = 0; x < image.cols; x++ )
	         { for( int c = 0; c < 3; c++ )
	              {
	      new_image.at<Vec3b>(y,x)[c] =
	         saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
	             }
	    }
	    }

	 /// Create Windows
//	 namedWindow("Original Image", 1);
//	 namedWindow("New Image", 1);

	 /// Show stuff
//	 imshow("Original Image", image);
//	 imshow("New Image", new_image);
	 return new_image;
}
int main() {

//	while()
	Mat image = imread("/home/dieuninh/Desktop/a33.jpg");
	i_crop(image);

waitKey(0);
return 0;
}
*/
