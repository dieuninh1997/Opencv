#include<iostream>
#include<dirent.h>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

const int MIN_PIXEL_WIDTH = 2;
const int MIN_PIXEL_HEIGHT = 8;
const int MIN_PIXEL_AREA = 80;


const double MIN_ASPECT_RATIO =1.0;// 0.25;
const double MAX_ASPECT_RATIO =1.3; //1.0;

bool flag=false;
int threshold=5;
int b_size=10;
int dist_scale=4;
int area;

bool checkExtension(string path, string ex)
{
	string e="";
	for(int i=path.length()-1; i>=0; i--)
	{
		if(path[i]=='.')break;
		e=path[i]+e;
	}
	return ex.compare(e)==0;
}
vector<string> getListItem(char *url)
{
	vector<string> v;
	DIR *dir;
	struct dirent *ent;
	if((dir=opendir(url))!=NULL)
	{
		while((ent=readdir(dir))!=NULL)
		{
			if(checkExtension(ent->d_name,"jpg"))
			{
				v.push_back(ent->d_name);
			}
		}
		closedir(dir);
	}else
	{
		cout<<"could not open directory"<<endl;
		perror("");
	}
	return v;
}
Mat convertBinaryImg(Mat gray)
{
	Mat binary;
	adaptiveThreshold(gray,binary,255,CV_ADAPTIVE_THRESH_MEAN_C,CV_THRESH_BINARY,15,7.0);
	return binary;
}

Mat findPLate(Mat binary)
{
	Mat plate,canny;
	vector<vector<Point> >contours;
	vector<Vec4i> hierachy;

	Canny(binary,canny,100,100*2,3);
	findContours(canny,contours,hierachy,CV_RETR_LIST,CV_CHAIN_APPROX_SIMPLE);


	return plate;
}

Scalar GetPixel(int x, int y, Mat input)
{
	uchar *d1=(uchar *)(input.data);
	int index=3*x+(input.step*y);
	int v1=d1[index];
	int v2=d1[index+1];
	int v3=d1[index+2];
	Scalar xx=Scalar(v1,v2,v3,0);
	return xx;
}
//setting the label for pixel at location x,y
void SetPixel(int x, int y, Mat output, int area)
{
	uchar *d1=(uchar *)(output.data);
	int index=3*x+(output.step*y);
	d1[index]=0;
	d1[index+1]=255;
	d1[index+2]=255;
	area=area+1;
}
/* seed fill recurive function */
void SeedFill(int x, int y,Mat input)
{
	flag=false;
	area=0;

}
Mat regionGrowing(Mat a, int x, int y, Scalar color)
{
	Mat input,output;
	flag=false;
	//setting up input and output matrices
	a.copyTo(input);
	a.copyTo(output);

	area=0;
	int nMinY=0;
	int nMinX=0;
	int nMaxY=input.rows-1;
	int nMaxX=input.cols-1;
	int morph_size=1;
	Mat element=getStructuringElement(MORPH_RECT,Size(2*morph_size+1, 2*morph_size+1),Point(morph_size,morph_size));
	output.setTo(Scalar::all(0));
	//getting seed pixel values





	return a;
}

int main(int argc, char **argv) {
	/*char *url=("/home/dieuninh/Downloads/Car/");
	string rs="home/dieuninh/Downloads/Kq/";
	vector<string> files=getListItem(url);
	for(int i=0; i<files.size();i++)
	{
		Mat image=imread(url+files[i],1);
		Mat gray;
		cvtColor(image,gray,COLOR_BGR2GRAY );
		Mat binary=convertBinaryImg(gray);
		'imshow("Gray",gray);
		'imshow("Image",image);
		'imshow("Adaptive Binary",binary);

		Mat plate=findPLate(binary);
		string name=rs+files[i];
		imwrite(name,plate);
	}
	waitKey(0)*/;
	return 0;
}
