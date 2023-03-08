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
Mat guasian_filter(int size);
Mat mean_filter(int size);
Mat median_filter(int size);
Mat automatic_global_threshold();
Mat manual_global_threshold(int threshold);
Mat local_threshold(int T_minus);
Mat return_image(int type,int radius);
Mat hyprid(int radius);
Mat filters( float  x[] ,  float  y[],int row , int col);
#endif // FUNCTIONS_H
