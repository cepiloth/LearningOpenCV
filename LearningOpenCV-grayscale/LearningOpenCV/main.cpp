#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

using namespace std;
using namespace cv;

/*
* @brief - grayscale �������� �����ϴ� �޼ҵ� 
*/ 
void showGrayScaleImage(Mat img) {

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	imshow("Gray", gray);
}

int main() {

	Mat img = imread("image.png", IMREAD_COLOR);
	
	if(img.empty()) {
		cout << "�̹����� ���ų�, ��ȿ�� ���� ������ �ƴմϴ�." << endl;
		return -1;
	}

	imshow("���� �̹���", img);
	
	showGrayScaleImage(img);

	waitKey(0);
	
	return 0;
}