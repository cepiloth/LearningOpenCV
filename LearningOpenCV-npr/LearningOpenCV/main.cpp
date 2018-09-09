#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

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


int main() {

	Mat img = imread("image.jpg", IMREAD_COLOR);
	
	if(img.empty()) {
		cout << "internal error." << endl;
		return -1;
	}

	imshow("src", img);


	// pecilSketch Effect
	{
		CV_STOPWATCH("pencilSketch");
		Mat img1, dst;
		pencilSketch(img,img1, dst, 10 , 0.1f, 0.03f);
		imshow("Pencil Sketch",img1);
		imshow("Color Pencil Sketch",dst);
	}
	
	{
		CV_STOPWATCH("edgePreservingFilter");
		Mat edge;
		edgePreservingFilter(img, edge, 1);
		imshow("Edge Preserve Smoothing", edge);
	}

	{
		CV_STOPWATCH("detail");
		Mat detail;
		detailEnhance(img, detail);
		imshow("Detail Enhanced",detail);;
	}

	{
		CV_STOPWATCH("stylization");
		Mat style;
		stylization(img, style);
		imshow("Stylization",style);;
	}


	waitKey(0);
	
	return 0;
}