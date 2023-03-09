#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include "testing.h"
#include <opencv2/opencv.hpp>
#include<QString>
#include <QFileDialog>
#include <QFile>
#include <string.h>
#include<QDir>
#include <QPixmap>
#include <QImage>
float index1=0;
int index2=0;
float index3=0;
int index4=9;
int index5=255;
int index6=0;
int index7=0;
int index8=30;
int index9=9;
int index10=9;
Mat src;
Mat src2;

Mat dst;
Mat resized_up;
Mat imgg;
//Mat resized_up2;

using namespace cv;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_3_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
//    output_uniform();
}

void MainWindow::on_pushButton_8_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
//    normalization_fun();
}


void MainWindow::on_pushButton_4_clicked()
{

    float index=ui->doubleSpinBox->value();
    index1=index;
    Mat Result=output_gaussin();
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_5_clicked()
{

    int index=ui->spinBox->value();
    index2=index;
    Mat Result=spl();
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_6_clicked()
{
    float index=ui->doubleSpinBox_2->value();
    index3=index;
    Mat Result=output_uniform();
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_7_clicked()
{

    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);
//        imshow("img",image);
    int up_width = 512;
    int up_height = 512;
//    Convert_To_Gray(src,dst);
    resized_up=src;
    cv::resize(src,resized_up, Size(up_width, up_height), INTER_LINEAR);
    QImage image2((uchar*)resized_up.data,resized_up.cols,resized_up.rows,QImage::Format_BGR888);
    QPixmap pix=QPixmap::fromImage(image2);
    int width_img=ui->label->width();
    int height_img=ui->label->height();

    ui->label->setPixmap(pix.scaled(width_img,height_img,Qt::KeepAspectRatio));


//    QPixmap pix2("Result.jpg");
//    int width_img2=ui->label_2->width();
//    int height_img2=ui->label_2->height();
//    ui->label_2->setPixmap(pix.scaled(width_img2,height_img2,Qt::KeepAspectRatio));



//    int up_width1 = 512;
//    int up_height1 = 512;
//    resized_up2=dst;
//    cv::resize(dst,resized_up2, Size(up_width1, up_height1), INTER_LINEAR);
//    QImage image3((uchar*)dst.data,dst.cols,dst.rows,QImage::Format_BGR888);
//    QPixmap pix2=QPixmap::fromImage(image3);
//    int width_img1=ui->label_2->width();
//    int height_img1=ui->label_2->height();
//    ui->label_2->setPixmap(pix2.scaled(width_img1,height_img1,Qt::KeepAspectRatio));



}





void MainWindow::on_pushButton_9_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);
//        imshow("img",image);
        int up_width = 512;
        int up_height = 512;
    //    Convert_To_Gray(src,dst);
        resized_up=src;
        cv::resize(src,resized_up, Size(up_width, up_height), INTER_LINEAR);
        QImage image2((uchar*)resized_up.data,resized_up.cols,resized_up.rows,QImage::Format_BGR888);
        QPixmap pix=QPixmap::fromImage(image2);
        int width_img=ui->label->width();
        int height_img=ui->label->height();

        ui->label->setPixmap(pix.scaled(width_img,height_img,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_10_clicked()
{
        if ( !src.data )
            {
                printf("No image data \n");
                return;
            }


}


void MainWindow::on_pushButton_11_clicked()
{
    float index=ui->spinBox_2->value();
    index4=index;
    Mat Result=guasian_filter(index4);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_12_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }

//    mean_filter(index4);
}


void MainWindow::on_pushButton_13_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }

//    median_filter(index4);
}


void MainWindow::on_pushButton_14_clicked()
{
    float index=ui->spinBox_3->value();
    index5=index;
    Mat Result=guasian_filter(index5);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_15_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
//    automatic_global_threshold();
    Mat Result=automatic_global_threshold();
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_16_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
//    manual_global_threshold(index6);

}


void MainWindow::on_pushButton_17_clicked()
{
    float index=ui->spinBox_4->value();
    index6=index;
    Mat Result=manual_global_threshold(index6);
//    std::cout<<Result;
//    imshow("ss",Result);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
    //    Result.convertTo(modify,CV_8U);
    //    QImage qimage2(modify.data,modify.cols,modify.rows,QImage::Format_RGB888);
    //    QPixmap outputPix = QPixmap::fromImage(qimage2);
    //    int width_img2=ui->label_3->width();
    //    int height_img2=ui->label_3->height();
    //    ui->label_3->setPixmap(outputPix.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_18_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
//    local_threshold(index7);
}


void MainWindow::on_pushButton_19_clicked()
{
    float index=ui->spinBox_5->value();
    index7=index;
    Mat Result=local_threshold(index7);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_20_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);
        int up_width = 512;
        int up_height = 512;
    //    Convert_To_Gray(src,dst);
        resized_up=src;
        cv::resize(src,resized_up, Size(up_width, up_height), INTER_LINEAR);
        QImage image2((uchar*)resized_up.data,resized_up.cols,resized_up.rows,QImage::Format_BGR888);
        QPixmap pix=QPixmap::fromImage(image2);
        int width_img=ui->label->width();
        int height_img=ui->label->height();

        ui->label->setPixmap(pix.scaled(width_img,height_img,Qt::KeepAspectRatio));

//        imshow("img",image);
}


void MainWindow::on_pushButton_21_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src2=imread(name);
        int up_width = 512;
        int up_height = 512;
    //    Convert_To_Gray(src,dst);
        resized_up=src2;
        cv::resize(src2,resized_up, Size(up_width, up_height), INTER_LINEAR);
        QImage image2((uchar*)resized_up.data,resized_up.cols,resized_up.rows,QImage::Format_BGR888);
        QPixmap pix=QPixmap::fromImage(image2);
        int width_img=ui->label_2->width();
        int height_img=ui->label_2->height();

        ui->label_2->setPixmap(pix.scaled(width_img,height_img,Qt::KeepAspectRatio));

//        imshow("img",image);
}


void MainWindow::on_pushButton_22_clicked()
{
    float index=ui->spinBox_6->value();
    index8=index;
    Mat Result=hyprid(index8);

//    imwrite("Result.png", Result);
//    imshow("sd",Result);
//    std::cout<<Result;
    double minVal;
    double maxVal;
    Mat upper;
    double lower;
    Mat normalized_img;
    minMaxLoc( Result, &minVal, &maxVal );
    upper=Result-minVal;
    lower=maxVal-minVal;
    normalized_img=(upper/lower)*255;
//    QPixmap pix2("Result.png");
//    std::cout<<normalized_img;
    Mat modify;
    normalized_img.convertTo(modify,CV_8U);
    QImage qimage2(modify.data,modify.cols,modify.rows,QImage::Format_Grayscale8);
    QPixmap outputPix = QPixmap::fromImage(qimage2);
    int width_img2=ui->label_3->width();
    int height_img2=ui->label_3->height();
    ui->label_3->setPixmap(outputPix.scaled(width_img2,height_img2,Qt::KeepAspectRatio));

}


void MainWindow::on_pushButton_23_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
//    hyprid(index8);

}

void MainWindow::on_pushButton_25_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);
        int up_width = 512;
        int up_height = 512;
    //    Convert_To_Gray(src,dst);
        resized_up=src;
        cv::resize(src,resized_up, Size(up_width, up_height), INTER_LINEAR);
        QImage image2((uchar*)resized_up.data,resized_up.cols,resized_up.rows,QImage::Format_BGR888);
        QPixmap pix=QPixmap::fromImage(image2);
        int width_img=ui->label->width();
        int height_img=ui->label->height();

        ui->label->setPixmap(pix.scaled(width_img,height_img,Qt::KeepAspectRatio));

//        imshow("img",image);
}

void MainWindow::on_pushButton_24_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
//    return_image(0,30);
    Mat Result=return_image(0,30);
//    imwrite("Result.jpg", Result);
//    QPixmap pix2("Result.jpg");
//    int width_img2=ui->label_3->width();
//    int height_img2=ui->label_3->height();
//    ui->label_3->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
    double minVal;
    double maxVal;
    Mat upper;
    double lower;
    Mat normalized_img;
    minMaxLoc( Result, &minVal, &maxVal );
    upper=Result-minVal;
    lower=maxVal-minVal;
    normalized_img=(upper/lower)*255;

    Mat modify;
    normalized_img.convertTo(modify,CV_8U);
    imwrite("Result.jpg", modify);

    QImage qimage2(modify.data,modify.cols,modify.rows,QImage::Format_Grayscale8);
    QPixmap outputPix = QPixmap::fromImage(qimage2);
    int width_img2=ui->label_3->width();
    int height_img2=ui->label_3->height();
    ui->label_3->setPixmap(outputPix.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}




void MainWindow::on_pushButton_26_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
//    return_image(1,30);
    Mat Result=return_image(1,30);
//    std::cout<<Result;
//    imwrite("Result.jpg", Result);
//    QPixmap pix2("Result.jpg");
//    int width_img2=ui->label_3->width();
//    int height_img2=ui->label_3->height();
//    ui->label_3->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));

    double minVal;
    double maxVal;
    Mat upper;
    double lower;
    Mat normalized_img;
    minMaxLoc( Result, &minVal, &maxVal );
    upper=Result-minVal;
    lower=maxVal-minVal;
    normalized_img=(upper/lower)*255;

    Mat modify;
    normalized_img.convertTo(modify,CV_8U);
    imwrite("Result.jpg", modify);
    QImage qimage2(modify.data,modify.cols,modify.rows,QImage::Format_Grayscale8);
    QPixmap outputPix = QPixmap::fromImage(qimage2);
    int width_img2=ui->label_3->width();
    int height_img2=ui->label_3->height();
    ui->label_3->setPixmap(outputPix.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


//void MainWindow::on_pushButton_29_clicked()
//{
//    if ( !src.data )
//        {
//            printf("No image data \n");
//            return;
//        }
//    float roberts_x[]={0,1,-1,0};
//    float roberts_y[]={1,0,0,-1};
//    filters(roberts_x,roberts_y,2,2);
//}


//void MainWindow::on_pushButton_27_clicked()
//{
//    if ( !src.data )
//        {
//            printf("No image data \n");
//            return;
//        }
//    float prewitt_x[]={-1, 0, 1, -1, 0, 1, -1, 0, 1};
//    float prewitt_y[]={-1, -1, -1, 0, 0, 0, 1, 1, 1};
//    filters(prewitt_x,prewitt_y,3,3);
//}



//void MainWindow::on_pushButton_28_clicked()
//{
//    if ( !src.data )
//        {
//            printf("No image data \n");
//            return;
//        }
//    float  x[] = { 1,0,-1,2,0,-2,1,0,-1 };
//    float  y[] = { 1,2,1,0,0,0,-1,-2,-1};
//    filters(x,y,3,3);
//}


void MainWindow::on_pushButton_30_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    int histogram[256];
    Histogram( histogram);
//    Mat imgg;
//    imgg=DisplayHistogram(histogram);
//    std::cout<<imgg;
    Mat Result=DisplayHistogram(histogram);
//    imshow("ss",Result);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_3->width();
    int height_img2=ui->label_3->height();
    ui->label_3->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
//    std::cout<<imgg;
//    double minVal;
//    double maxVal;
//    Mat upper;
//    double lower;
//    Mat normalized_img;
//    minMaxLoc( imgg, &minVal, &maxVal );
//    upper=imgg-minVal;
//    lower=maxVal-minVal;
//    normalized_img=(upper/lower)*255;

//    Mat modify;
//    Result.convertTo(modify,CV_8U);
//    QImage qimage2(modify.data,modify.cols,modify.rows,QImage::Format_RGB888);
//    QPixmap outputPix = QPixmap::fromImage(qimage2);
//    int width_img2=ui->label_3->width();
//    int height_img2=ui->label_3->height();
//    ui->label_3->setPixmap(outputPix.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_31_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    Mat Result= equalization();
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
//    equalization();
}


void MainWindow::on_pushButton_32_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
//    Mat Result= imgg;
//    imwrite("Result.jpg", Result);
//    QPixmap pix2("Result.jpg");
//    int width_img2=ui->label_3->width();
//    int height_img2=ui->label_3->height();
//    ui->label_3->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
    testing();


}


void MainWindow::on_pushButton_33_clicked()
{
    float index=ui->spinBox_7->value();
    index9=index;
    Mat Result=mean_filter(index9);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_34_clicked()
{
    float index=ui->spinBox_8->value();
    index10=index;
    Mat Result=median_filter(index10);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_35_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float roberts_x[]={0,1,-1,0};
    float roberts_y[]={1,0,0,-1};
//    filters(roberts_x,roberts_y,2,2);
    Mat Result=filters(roberts_x,roberts_y,2,2);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_3->width();
    int height_img2=ui->label_3->height();
    ui->label_3->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_36_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
        float  x[] = { 1,0,-1,2,0,-2,1,0,-1 };
        float  y[] = { 1,2,1,0,0,0,-1,-2,-1};
        filters(x,y,3,3);
        Mat Result=filters(x,y,3,3);
        imwrite("Result.jpg", Result);
        QPixmap pix2("Result.jpg");
        int width_img2=ui->label_3->width();
        int height_img2=ui->label_3->height();
        ui->label_3->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));

}


void MainWindow::on_pushButton_37_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float prewitt_x[]={-1, 0, 1, -1, 0, 1, -1, 0, 1};
    float prewitt_y[]={-1, -1, -1, 0, 0, 0, 1, 1, 1};
//    filters(prewitt_x,prewitt_y,3,3);
    Mat Result=filters(prewitt_x,prewitt_y,3,3);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_3->width();
    int height_img2=ui->label_3->height();
    ui->label_3->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}

