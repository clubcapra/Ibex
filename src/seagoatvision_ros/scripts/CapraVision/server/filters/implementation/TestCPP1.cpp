#include "opencv2/opencv.hpp"
//#include "opencv2/gpu/gpu.hpp"

#define DOCSTRING "C++ Example Test #1"

int x = 0;

void init() {
	x = ParameterAsInt("x", 0, 255, 30);
}

void configure() {
	x = ParameterAsInt("x", 0, 255, 30);
}

cv::Mat execute(cv::Mat image)
{

	cv::cvtColor(image, image, CV_BGR2HSV);
	return image;
}
