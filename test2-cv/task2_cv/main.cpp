#include "mainwindow.h"

#include <QApplication>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
double minVal;
double maxVal;
Mat upper;
double lower;
Mat normalized_img;

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
Mat dst;

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
    imshow("saltpepper_noise", saltpepper_img ); // make it commented when calling output function
    waitKey();
    imwrite("saltpepper_noise.jpg", saltpepper_img);
    return saltpepper_img;
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
    imshow("Noisy_image - Gaussian noise", noisy_image);
    waitKey();
    imwrite("Noisy_image - Gaussian noise.jpg", noisy_image);
    return noisy_image;
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
    cv::imshow("Noisy_image - uniform_noise", noisy_image);
    cv::waitKey();
    imwrite("Noisy_image - uniform_noise.jpg", noisy_image);
    return noisy_image;
}


Mat normalization_fun(){
    Convert_To_Gray(src,dst);
    minMaxLoc( dst, &minVal, &maxVal );
    upper=dst-minVal;
    lower=maxVal-minVal;
    normalized_img=(upper/lower)*200;
    imshow("gray", normalized_img);
    waitKey();
    imwrite("gray", normalized_img);
    return normalized_img;

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

    w.show();
    return a.exec();
}
