/*
#include<opencv2/opencv.hpp>
#include<iostream>
#include<string.h>
using namespace cv;
using namespace std;
RNG rng(12345);
bool loadAnh(int so, Mat &image)
{
	char filename[100];
	strcpy(filename, "/home/dieuninh/Desktop/anh/a");
	char frame_id[30];
	sprintf(frame_id,"%d",so);
	strcat(filename, frame_id);
	strcat(filename, ".jpg");
	image=imread(filename,1);//load color image bgr
	if(!image.data)
	{
		strcat(filename,": No image data!");
		cout<<"\n";
		return false;
	}

	return true;
}

void cutAnh(Mat image, int so)
{
	Mat img1=image.clone();
	Mat img;
	cvtColor(image, img, COLOR_BGR2GRAY );
	//blur(img,img,Size(10,10));//loc anh
	Mat binary_img,morph,morph_inv, b_inv;

	threshold(img,binary_img,120,255,CV_THRESH_BINARY);
//	adaptiveThreshold(img,binary_img,255,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY,3,1.5);
	imshow("Binary ",binary_img);
	threshold(binary_img,b_inv,0,255,CV_THRESH_BINARY_INV);
	imshow("Binary inv ",b_inv);
	//ham dinh hinh khoi
	Mat kernel=getStructuringElement(MORPH_CROSS,Size(5,5),Point(1,1));//mac dinh Point(-1,-1), anh matrix 3x3
	erode(b_inv,  morph,kernel,Point(1,1),1);//make white smaller
//	dilate(binary_img,morph_inv,kernel,Point(1,1),1);

//	imshow("Gray Image ",img);

	//ham tim bien dang, tim vien anh
	vector<vector<Point> > contour;
	findContours(morph,contour,CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLECV_
	RETR_LIST,CV_CHAIN_APPROX_NONE);


	char saveFilePath[100];
	strcpy(saveFilePath, "/home/dieuninh/Desktop/save/b");
	char _id[30];
	sprintf(_id,"%d",so);
	strcat(saveFilePath, _id);
	strcat(saveFilePath, ".jpg");

	Rect r;
	Mat anh;
	  vector<vector<Point> >hull( contour.size() );

	for(int i=0;i<contour.size();i++)
	{

		/// Find the convex hull object for each contour

		     convexHull( Mat(contour[i]), hull[i], false );


//		 r=boundingRect(contour[i]);
//		 if(r.height*r.width>0)
		 {
			 //if(r.width/(double)r.height>=1.0f && r.width/(double)r.height<1.5f)
			 {
//				 rectangle(img1,r,Scalar(0,0,255),1,8,0);//mau do
//				 drawContours(binary_img,,Scalar(0,0,255));
//				 anh=img1(r);
				// imwrite(saveFilePath,anh);
				 imshow("Cut Image ",img1);
//				 break;
			 }else
			 {
				 rectangle(img1,r,Scalar(0,0,255),1,8,0);//mau do
				//				 drawContours(binary_img,,Scalar(0,0,255));
								 anh=img1(r);
				//				 imwrite(saveFilePath,anh);
								 imshow("Cut Image ",anh);
								 break;
			 }
		 }
	}

	 Mat drawing = Mat::zeros( binary_img.size(), CV_8UC3 );
	   for( int i = 0; i< contour.size(); i++ )
	      {
	        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
	        drawContours( drawing, contour, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
	        drawContours( drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
	      }
	   imshow( "Hull demo", drawing );
//	imshow("Color Image ",img1);

}

int main(int argc, char **argv) {


	int numberOfImages=17;
//	while(numberOfImages)
	{
		cout<<numberOfImages<<endl;
		Mat i;
		char filename[100];
		strcpy(filename, "Anh ");
		char nameWindow[30];
		sprintf(nameWindow,"%d",numberOfImages);
		if(loadAnh(numberOfImages,i))
		{
			imshow(nameWindow,i);
			cutAnh(i,numberOfImages);

		}
//		numberOfImages--;

	}
	waitKey(0);
	return 0;
}


*/
