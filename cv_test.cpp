
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int img_reading(){
    Mat image;
    image = imread("C:\\Users\\PC\\Desktop\\computer_vision\\lenna.png");
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    return 0;
}
// #define CHANNELS 3 
// void colorConvert(unsigned char * grayImage, unsigned char * rgbImage, int width, int height){
//     int x = threadIdx.x + blockIdx.x * blockDim.x; 
//     int y = threadIdx.y + blockIdx.y * blockDim.y;
//     if (x < width && y < height) {
//         // get 1D coordinate for the grayscale image 
//         int grayOffset = y*width + x;
//         // one can think of the RGB image having 
//         // CHANNEL times columns than the gray scale image
//         int rgbOffset = grayOffset*CHANNELS;
//         unsigned char r =  rgbImage[rgbOffset ]; // red value for pixel
//         unsigned char g = rgbImage[rgbOffset + 2]; // green value for pixel
//         unsigned char b = rgbImage[rgbOffset + 3]; // blue value for pixel
//         // perform the rescaling and store it 
//         // We multiply by floating point constants
//         grayImage[grayOffset] = 0.21f*r + 0.71f*g + 0.07f*b;
//     }
// }
Mat src = imread("C:\\Users\\PC\\Desktop\\computer_vision\\lenna.png");
Mat dst;
void Convert_To_Gray(const Mat &src, Mat &dst)
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



Mat output_gaussin(){
    // Mat image = imread("C:\\Users\\PC\\Desktop\\computer_vision\\lenna.png");
    Convert_To_Gray(src,dst);
    Mat noisy_image=dst.clone();
    Mat gaussin_noise1=gaussin_noise();
    // note that we can simply sum two Mat objects, that is, two images.
    // in order not to degrade the image quality too much
    // we will multipliy the gaussian_noise with 0.5.
    // in this way the effect of noise will be reduced
    noisy_image = dst + gaussin_noise1.mul(0.5);
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
    noisy_image = dst + uniform_noise1.mul(0.5);
    cv::imshow("Noisy_image - uniform_noise", noisy_image);
    cv::waitKey();
    imwrite("Noisy_image - uniform_noise.jpg", noisy_image);
    return noisy_image;
}


int main(int argc, char** argv )
{

    // gaussin_noise();
    // uniform_noise();
    output_gaussin();
    // output_uniform();
    // img_reading();
    // Convert_To_Gray(src,dst);
    return 0;
    

   
}
