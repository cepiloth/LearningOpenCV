
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

using namespace std;
using namespace cv;
int main() {

	Mat img = imread("image.png", IMREAD_COLOR);
	imshow("OpenCV_Test", img);
	waitKey(0);
	return 0;
}