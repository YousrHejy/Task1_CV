#include "mainwindow.h"
#define _USE_MATH_DEFINES
#include<cmath>
#include <QApplication>
#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace std;
#include <iostream>
#include<vector>
#include<algorithm>
#pragma ide diagnostic ignored "EndlessLoop"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/utility.hpp>

using namespace cv;
double minVal;
double maxVal;
Mat upper;
double lower;
Mat normalized_img;
Mat sobel_Gx =(Mat_<float>(3,3)<<1,0,-1,2,0,2,1,0,-1);
Mat sobel_Gy =(Mat_<float>(3,3)<<1,2,1,0,0,0,-1,-2,-1);
Mat gx_s,gy_s,gx_p;
Mat filter_mag;
//Mat img_reading(){         /// function to show image only
////    Mat image;
////    image = imread("C:\\Users\\PC\\Desktop\\computer_vision\\lenna.png");
//    // int row=image.rows;
//    // int col=image.cols;
//    if ( !image.data )
//    {
//        printf("No image data \n");

//    }
////    namedWindow("Display Image", WINDOW_AUTOSIZE );
////    imshow("Display Image", image);
////    waitKey(0);
//    // std::cout<<image;
//    // std::cin.get();
//    // std::endl;
//    // std::cout<<image.size;
//    return image;
//}

//Mat src = img_reading();
//Mat dst;
Mat dst2;

void Convert_To_Gray(const Mat &src, Mat &dst)    // func convert to gray
{

    int rows = src.rows, cols = src.cols;

    dst.create(src.size(), 0);

    cols = rows * cols;
    rows = 1;

    for (int row = 0; row < rows; row++)
    {
        const uchar* src_ptr = src.ptr<uchar>(row);
        uchar* dst_ptr = dst.ptr<uchar>(row);

        for (int col = 0; col < cols; col++)
        {
            dst_ptr[col] = (uchar)(src_ptr[0] * 0.114f + src_ptr[1] * 0.587f + src_ptr[2] * 0.299f);
            src_ptr += 3;
        }
    }
    // imshow("gray", dst );
    // waitKey();
}

Mat gaussin_noise(){

    // Mat image = imread("C:\\Users\\PC\\Desktop\\computer_vision\\lenna.png", IMREAD_GRAYSCALE);
     Convert_To_Gray(src,dst);

    // Let's first create a zero image with the same dimensions of the loaded image

    Mat gaussian_noise = Mat::zeros (dst.rows, dst.cols, CV_8UC1);

    // cv::imshow("All zero values", gaussian_noise);
    // cv::waitKey();

    // now, we can set the pixel values as a Gaussian noise
    // we have set a mean value to 128 and a standard deviation to 20
    randn(gaussian_noise, 128, 20);

    // Let's plot this image and see how it looks like
    // imshow("Gaussian noise", gaussian_noise); // make it commented when calling output function
    // waitKey();

    imwrite("Gaussian random noise.jpg", gaussian_noise);
    return gaussian_noise;
}


Mat uniform_noise(){
    // Mat image = imread("C:\\Users\\PC\\Desktop\\computer_vision\\lenna.png", IMREAD_GRAYSCALE);
    Convert_To_Gray(src,dst);
    Mat uniform_noise = cv::Mat::zeros (dst.rows, dst.cols, CV_8UC1);

    randu(uniform_noise, 0, 255);
    // imshow("Uniform random noise", uniform_noise ); // make it commented when calling output function
    // waitKey();
    imwrite("Uniform random noise.jpg", uniform_noise);
    return uniform_noise;
}



Mat spl(){
    Convert_To_Gray(src,dst);
    Mat saltpepper_noise = Mat::zeros(dst.rows, dst.cols,CV_8U);
    randu(saltpepper_noise,0,255);

    Mat black = saltpepper_noise < index2;
    Mat white = saltpepper_noise > (255-index2);

    Mat saltpepper_img = dst.clone();
    saltpepper_img.setTo(255,white);
    saltpepper_img.setTo(0,black);
    Mat output;
    hconcat(dst, saltpepper_img,output);
    imshow("saltpepper_noise", output ); // make it commented when calling output function
    waitKey();
    imwrite("saltpepper_noise.jpg", output);
    return output;
}




Mat output_gaussin(){
    // Mat image = imread("C:\\Users\\PC\\Desktop\\computer_vision\\lenna.png");
    Convert_To_Gray(src,dst);
    Mat noisy_image=dst.clone();
    Mat gaussin_noise1=gaussin_noise();
    // note that we can simply sum two Mat objects, that is, two images.
    // in order not to degrade the image quality too much
    // we will multipliy the gaussian_noise with 0.5.
    // in this way the effect of noise will be reduced
//    float index=1;
    noisy_image = dst + gaussin_noise1.mul(index1);
    Mat output;
    hconcat(dst, noisy_image,output);
    imshow("Noisy_image - Gaussian noise", output);
    waitKey();
    imwrite("Noisy_image - Gaussian noise.jpg", output);
    return output;
}


Mat output_uniform(){
    // Mat image = imread("C:\\Users\\PC\\Desktop\\computer_vision\\lenna.png", IMREAD_GRAYSCALE);
    Convert_To_Gray(src,dst);
    Mat noisy_image=dst.clone();
    Mat uniform_noise1=uniform_noise();
    // note that we can simply sum two Mat objects, that is, two images.
    // in order not to degrade the image quality too much
    // we will multipliy the gaussian_noise with 0.5.
    // in this way the effect of noise will be reduced
    std::cout<<index3;
    noisy_image = dst + uniform_noise1.mul(index3);
    Mat output;
    hconcat(dst, noisy_image,output);
    cv::imshow("Noisy_image - uniform_noise", output);
    cv::waitKey();
    imwrite("Noisy_image - uniform_noise.jpg", output);
    return output;
}


Mat normalization_fun(){
    Convert_To_Gray(src,dst);
    minMaxLoc( dst, &minVal, &maxVal );
    upper=dst-minVal;
    lower=maxVal-minVal;
    normalized_img=(upper/lower)*index5;
    Mat output;
    hconcat(dst, normalized_img,output);
    imshow("gray", output);
    waitKey();
    imwrite("gray", output);
    return output;

}

Mat conv (Mat &image,int rows,int columns,int width,int height,int r,Mat &mask){
    Mat filtered_image=Mat(rows ,columns, CV_8UC1, Scalar(0, 0, 0));
    for(int y=r;y<rows-r;++y){
        for(int x=r;x<columns-r;++x) {
            for(int i=0;i<width;++i){
                for(int j=0;j<height;j++){
                    filtered_image.at<uchar>(y,x)+=(image.at<uchar>(y+i-r, x+j-r)*mask.at<float>(i,j) );
                }
            }
        }
    }
    return filtered_image;
}

Mat filter_create(int width ,int height,int shift) {
    int sigma = 1;
    float r, s = 2.0 * sigma * sigma;
    // sum is for normalization
    float sum = 0.0;
    Mat mask = Mat(width, height, CV_32F);
    //shift calculate form w,h =root((2r+1)^2)
    for (int x = -shift; x <= shift; x++) {
        for (int y = -shift; y <= shift; y++) {
            r = sqrt(x * x + y * y);
            mask.at<float>(x+shift,y+shift) = (exp(-(r * r) / s)) / (M_PI * s);
            sum +=  mask.at<float>(x+shift,y+shift) ;
        }
    }
    // normalising the Kernel
    for (int i = 0; i < width; ++i){
        for (int j = 0; j < height; ++j){
            mask.at<float>(i,j) /= sum;
}}
    return mask;
}

Mat guasian_filter(int size){
    Convert_To_Gray(src,dst);
    int width =sqrt(size);
    int height =sqrt(size);
    int radius=ceil(float (width-1)/2);
    int rows = dst.rows;
    int columns = dst.cols;
    Mat mask_g = Mat(width, height, CV_32F);
    mask_g =filter_create( width ,height,radius);
    Mat result_image= conv(dst,rows,columns, width,height, radius,mask_g);
    Mat output;
    hconcat(dst,result_image,output);
    imshow("sama", output);
    waitKey();
    imwrite("sama", output);
    return output;
}
Mat mean_filter(int size){
    Convert_To_Gray(src,dst);
    int width =sqrt(size);
    int height =sqrt(size);
    int radius=ceil(float (width-1)/2);
    int rows = dst.rows;
    int columns = dst.cols;
    Mat mask = Mat(width,height, CV_32F, Scalar(1));
    mask=mask/(width*height);
    Mat result_image=conv (dst,rows,columns, width,height, radius,mask);
    Mat output;
    hconcat(dst,result_image,output);
    imshow("sama", output);
    waitKey();
    imwrite("sama", output);
    return output;
}
Mat median_filter(int size){
    Convert_To_Gray(src,dst);
    int width =sqrt(size);
    int height =sqrt(size);
    int r=ceil(float (width-1)/2);
//    float size=width*height;
    vector<uchar> v(size, 1);
    int rows = dst.rows;
    int columns = dst.cols;
    Mat filtered_image = Mat(rows, columns, CV_8UC1);
    for (int y = r; y < rows - r; ++y) {
        for (int x = r; x < columns - r; ++x) {
            int m=0;
            for (int i = 0; i< width ; ++i) {
                for (int j=0;j<height; ++j){
                    v[m] = dst.at<uchar>(y+i - r, x+j-r);
                    m++;
                }
            }
            std::sort(v.begin(), v.end());
            filtered_image.at<uchar>(y, x) = v[int(ceil ((size-1)/2) )];
        }
    }
    Mat output;
    hconcat(dst,filtered_image,output);
    imshow("sama", output);
    waitKey();
    imwrite("sama", output);
    return output;
}

Mat sobel_filter(){
    Convert_To_Gray(src,dst);
    gx_s=conv(dst,dst.rows,dst.cols ,3,3,1 ,sobel_Gx);
    gy_s=conv(dst,dst.rows,dst.cols ,3,3,1,sobel_Gy);
    magnitude(gx_s,gy_s,filter_mag);
    return filter_mag;
}


// Function to differentiate between the image objects and the background using global thresholding
Mat automatic_global_threshold() {
    // Initialisations
    Convert_To_Gray(src,dst);
    Mat image=dst.clone();
    int pixels_avg = 0;
    int pixels_sum = 0;

    // Get the dimensions of the image
    int rows = image.rows;
    int cols = image.cols;

    // Iterate on the pixels of the image
    for (int i=0 ; i<rows ; i++)
    {
        for (int j=0 ; j<cols ; j++)
        {
            // Calculate the summation of the pixels
            pixels_sum = pixels_sum + image.at<uchar>(i,j);
        }
    }

    // Calculate the average of the pixels
    pixels_avg = pixels_sum / (rows * cols);

    // Set the threshold to be the average of the pixels
    int threshold = pixels_avg;

    for (int i=0 ; i<rows ; i++)
    {
        for (int j=0 ; j<cols ; j++)
        {
            // check the pixel value
            if ( image.at<uchar>(i,j) < threshold )
            {
                image.at<uchar>(i,j) = 0;
            }

            else
            {
                image.at<uchar>(i,j) = 255;
            }

        }
    }
    Mat output;
    hconcat(dst,image,output);
    imshow("misara", output);
    waitKey();
    imwrite("misara", output);
    return output;
}

// Function to differentiate between the image objects and the background using global thresholding
Mat manual_global_threshold(int threshold) {
    // Get the dimensions of the image
    Convert_To_Gray(src,dst);
    Mat image=dst.clone();
    int rows = image.rows;
    int cols = image.cols;

    // Iterate on the pixels of the image
    for (int i=0 ; i<rows ; i++)
    {
        for (int j=0 ; j<cols ; j++)
        {
            // check the pixel value
            if ( image.at<uchar>(i,j) < threshold )
            {
                image.at<uchar>(i,j) = 0;
            }

            else
            {
                image.at<uchar>(i,j) = 255;
            }
        }
    }
    Mat output;
    hconcat(dst,image,output);
    imshow("misara", output);
    waitKey();
    imwrite("misara", output);
    return output;

}

// Function to differentiate between the image objects and the background using local thresholding
Mat local_threshold( int T_minus)
{
    //Get the dimensions of the image
    Convert_To_Gray(src,dst);
    Mat image=dst.clone();
    int rows = image.rows;
    int cols = image.cols;

    //Divide the image into smaller windows
    int window_x = rows / 3;
    int window_y = cols / 3;

    //Calculate the size of each window
    int window_dim = window_x * window_y;

    // Iterate on the pixels of the image
    for (int m=0 ; m<3 ; m++)
    {
        for(int n=0 ; n<3 ; n++)
        {
            // Initialisations
            int pixels_avg = 0;
            int pixels_sum = 0;

            // Iterate on the pixels of the window
            for (int i=window_x * m ; i<window_x*(m+1) ; i++)
            {
                for(int j=window_y*n ; j<window_y*(n+1) ; j++)
                {
                    // Calculate the summation of the pixels
                    pixels_sum = pixels_sum + image.at<uchar>(i,j);
                }
            }
            // Calculate the average of the window
            pixels_avg = pixels_sum / (window_dim);

            // Set the threshold
            int threshold = pixels_avg - T_minus;

            // Iterate on the pixels of the window
            for (int i=window_x * m ; i<window_x*(m+1) ; i++)
            {
                for (int j=window_y * n ; j<window_y*(n+1) ; j++)
                {
                    // check the pixels value
                    if ( image.at<uchar>(i,j) < threshold )
                    {
                        image.at<uchar>(i,j) = 0;
                    }
                    else
                    {
                        image.at<uchar>(i,j) = 255;
                    }
                }
            }
        }
    }
    Mat output;
    hconcat(dst,image,output);
    imshow("misara", output);
    waitKey();
    imwrite("misara", output);
    return output;

}

Mat calculateDFt(Mat &img){
    Mat padded;
    int m = getOptimalDFTSize( img.rows );
    int n = getOptimalDFTSize( img.cols ); // on the border add zero values
    copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complex;
    merge(planes, 2, complex);         // Add to the expanded another plane with zeros
    dft(complex, complex, DFT_COMPLEX_OUTPUT);
    return complex;
}

void fftShift(Mat &imgComplex) {
    // crop if it has an odd number of rows or columns
    imgComplex= imgComplex(Rect(0, 0, imgComplex.cols & -2, imgComplex.rows & -2));
    int cx = imgComplex.cols/2;
    int cy = imgComplex.rows/2;
    Mat q0(imgComplex, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(imgComplex, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(imgComplex, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(imgComplex, Rect(cx, cy, cx, cy)); // Bottom-Right
    Mat pos;                            // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(pos);
    q3.copyTo(q0);
    pos.copyTo(q3);
    q1.copyTo(pos);                     // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    pos.copyTo(q2);
}
void filterImage(const cv::Mat &dft_Filter, int radius,int filterType)
{
    Mat tmp = Mat(dft_Filter.rows, dft_Filter.cols, CV_32F);

    Point centre = Point(dft_Filter.rows / 2, dft_Filter.cols / 2);
    double distance;

    for(int i = 0; i < dft_Filter.rows; i++)
    {
        for(int j = 0; j < dft_Filter.cols; j++)
        {
            distance = (double) sqrt(pow((i - centre.x), 2.0) + pow((double) (j - centre.y), 2.0));
            if(distance>radius){
                if(filterType==0){
                    tmp.at<float>(i,j) = (float)0;
                }else {
                    tmp.at<float>(i, j) = (float) 1;
                }
            }else{
                if(filterType==0){
                    tmp.at<float>(i,j) = (float)1;
                }else{
                    tmp.at<float>(i,j) = (float)0;
                }
            }

        }
    }

    Mat toMerge[] = {tmp, tmp};
    merge(toMerge, 2, dft_Filter);
}



Mat fft_image(Mat &img,int type,int radius){
    Mat complexImg, filter;
    complexImg = calculateDFt(img);
    filter = complexImg.clone();
    filterImage(filter, radius,type);
    fftShift(complexImg);
    mulSpectrums(complexImg, filter, complexImg, 1); // multiply 2 spectrums
    return complexImg;
}
Mat return_image(int type,int radius){
    Convert_To_Gray(src,dst);
    Mat imgOutput, planes[2];
    Mat complexImg=fft_image(dst,type,radius);
    fftShift(complexImg); // rearrange quadrants
    // compute inverse
    idft(complexImg, complexImg);
    split(complexImg, planes);
    normalize(planes[0], imgOutput, 0, 1,cv::NORM_MINMAX);
    imshow("misara", imgOutput);
    waitKey();
    imwrite("misara", imgOutput);
    return imgOutput;
}

Mat hyprid(int radius){
    Convert_To_Gray(src,dst);
    Convert_To_Gray(src2,dst2);
    Mat image1=dst.clone();
    Mat image2=dst2.clone();
    Mat DFT_image1, DFT_image2,  sum, planes[2], result;
    DFT_image1=fft_image(dst,0,radius);
    DFT_image2=fft_image(dst2,1,radius);
    sum = DFT_image1 + DFT_image2;

    fftShift(sum);

    // compute inverse
    idft(sum, sum);
    split(sum, planes);
//    split(DFT_image2, plane);
    normalize(planes[0], result, 0, 1,cv::NORM_MINMAX);

//    Mat output;
//    hconcat(result1,result2,output);
    imshow("misara", result);
    waitKey();
    imwrite("misara", result);

    return result;
}

Mat filters( float  x[] ,  float  y[],int row , int col){
    Convert_To_Gray(src,dst);
    Mat data_x,data_y,result;
    Mat filter_x =Mat(row,col,CV_32F,x);
    Mat filter_y =Mat(row,col,CV_32F,y);
    filter2D(dst, data_x, -1 ,filter_x);
    filter2D(dst, data_y, -1 ,filter_y);
    data_x.convertTo(data_x,CV_32F);
    data_y.convertTo(data_y,CV_32F);
    magnitude(data_x,data_y,result);
    result.convertTo(result,CV_8UC1);
    imshow("misara", result);
    waitKey();
    imwrite("misara", result);
    return result;
}

void Histogram( int histogram[])
{
    Convert_To_Gray(src,dst);
    // initialize all intensity values to 0
    for(int i = 0; i < 256; i++)
    {
        histogram[i] = 0;
    }
    // calculate the no of pixels for each intensity values
    for(int y = 0; y < dst.rows; y++)
        for(int x = 0; x < dst.cols; x++)
            histogram[(int)dst.at<uchar>(y,x)]++;
}

void CumulativeHist(int histogram[], int cumhistogram[])
{
    cumhistogram[0] = histogram[0];
    for(int i = 1; i < 256; i++)
    {
        cumhistogram[i] = histogram[i] + cumhistogram[i-1];
    }
}

Mat DisplayHistogram(int histogram[])
{
    int hist[256];
    for(int i = 0; i < 256; i++)
    {
        hist[i]=histogram[i];
    }
    // draw the histograms
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double) hist_w/256);
    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));
    // find the maximum intensity element from histogram
    int max = hist[0];
    for(int i = 1; i < 256; i++){
        if(max < hist[i]){
            max = hist[i];
        }
    }
    // normalize the histogram between 0 and histImage.rows
    for(int i = 0; i < 256; i++){
        hist[i] = ((double)hist[i]/max)*histImage.rows;
    }
    // draw the intensity line for histogram
    for(int i = 0; i < 256; i++)
    {
        line(histImage, Point(bin_w*(i), hist_h),
             Point(bin_w*(i), hist_h - hist[i]),
             Scalar(0,0,0), 1, 8, 0);
    }
    // display histogram
//    namedWindow(name, CV_WINDOW_AUTOSIZE);
    imshow("yousr", histImage);
    waitKey();
    imwrite("yousr", histImage);
    return histImage;
}
Mat equalization(){
    Convert_To_Gray(src,dst);
    int histogram[256];
    Histogram(histogram);
    // Caluculate the size of image
    int size = dst.rows * dst.cols;
    float alpha = 255.0/size;
    // Calculate the probability of each intensity
    float PrRk[256];
    for(int i = 0; i < 256; i++)
    {
        PrRk[i] = (double)histogram[i] / size;
    }
    // Generate cumulative frequency histogram
    int cumhistogram[256];
    CumulativeHist(histogram,cumhistogram );
    // Scale the histogram
    int Sk[256];
    for(int i = 0; i < 256; i++)
    {
        Sk[i] = cvRound((double)cumhistogram[i] * alpha);
    }
    // Generate the equlized histogram
    float PsSk[256];
    for(int i = 0; i < 256; i++)
    {
        PsSk[i] = 0;
    }
    for(int i = 0; i < 256; i++)
    {
        PsSk[Sk[i]] += PrRk[i];
    }
    int final[256];
    for(int i = 0; i < 256; i++)
        final[i] = cvRound(PsSk[i]*255);
    // Generate the equlized image
    Mat new_image = dst.clone();
    for(int y = 0; y < dst.rows; y++)
        for(int x = 0; x < dst.cols; x++)
            new_image.at<uchar>(y,x) = saturate_cast<uchar>(Sk[dst.at<uchar>(y,x)]);
    Mat output;
    hconcat(dst,new_image,output);
    imshow("yousr", output);
    waitKey();
    imwrite("yousr", output);
    return output;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // gaussin_noise();
    // uniform_noise();
    // output_gaussin();
    // output_uniform();
    // img_reading();
    // Convert_To_Gray(src,dst);
    // spl();

//    std::cout<<gx_s;
//    std::cout<<gy_s;

//    std::cout<<sobel_Gx;
//    std::cout<<sobel_Gy;
    w.show();
    return a.exec();
}
