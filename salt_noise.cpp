// created by ning zhang 2018/4/25
// The function of this program is to add noise to the image
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


void salt_noise( Mat image, int time );

int main ( int argc, char** argv )
{
	//Mat image = imread("../lena.jpg",0); //input the gray image
	Mat image = imread("../lena.jpg",1);; //input the rgb image
	if ( image.empty() )
	{
		cout << "Load image error" << endl;
		return -1;
	}
	salt_noise(image, 3000);
	namedWindow("image", 1);
	imshow("image", image);

	waitKey();
	return 0;
}

void salt_noise ( Mat image, int time )
{
	for (int k = 0; k < time; k++ ) //time is the number of noise you add
	{
		int i = rand() % image.rows;
		int j = rand() % image.cols;
		if (image.channels() == 1) //single channel
		{
			image.at<uchar>(i,j) = rand() % 255;
		}
		else if (image.channels() == 3) //RGB channel
		{
			image.at<Vec3b>(i, j)[0] = rand() % 255;
			image.at<Vec3b>(i, j)[1] = rand() % 255;
			image.at<Vec3b>(i, j)[2] = rand() % 255;
		}
	}
}