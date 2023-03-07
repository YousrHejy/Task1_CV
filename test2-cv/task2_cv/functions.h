#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
Mat spl();
int img_reading();
void Convert_To_Gray(const Mat &src, Mat &dst);
Mat gaussin_noise();
Mat uniform_noise();
Mat output_gaussin();
Mat output_uniform();
Mat normalization_fun();
#endif // FUNCTIONS_H
