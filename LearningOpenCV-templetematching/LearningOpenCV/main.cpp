#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cv;

class cvTimerCustom {

public:
	cvTimerCustom(string name) {
		this->name = name;
		tm.start();
	}

	~cvTimerCustom() {
		tm.stop();
		double average_time = tm.getTimeSec() / tm.getCounter();
		std::cout << name << " - " << "Average time in second per iteration is: " << average_time << std::endl;
	}

private:
	string name;
	TickMeter tm;
};

#define CV_STOPWATCH(arg) cvTimerCustom(arg)

int main()
{
	Mat img, templ, result;
	double minVal, maxVal; 
	Point minLoc, maxLoc, matchLoc;

	img = imread( "source.jpg", 1 );
	templ = imread( "pat.jpg", 1 );

	Mat img_display;
	img.copyTo( img_display );

	int result_cols =  img.cols - templ.cols + 1;
	int result_rows = img.rows - templ.rows + 1;
	result.create( result_rows, result_cols, CV_32FC1 );

	matchTemplate( img, templ, result, TM_CCOEFF_NORMED );
	normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

	minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

	matchLoc = maxLoc;
	rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), 0xff00ff, 2, 8, 0 );

	imshow( "source", img_display );
	imshow( "match", templ );

	waitKey(0);

	return 0;
}