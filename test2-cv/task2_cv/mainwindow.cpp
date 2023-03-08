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
Mat src;
Mat src2;

Mat dst;
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






void MainWindow::on_pushButton_clicked() /// functions
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;

        }
    spl();
}


void MainWindow::on_pushButton_2_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    output_gaussin();

}


void MainWindow::on_pushButton_3_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    output_uniform();
}

void MainWindow::on_pushButton_8_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    normalization_fun();
}





void MainWindow::on_pushButton_4_clicked()
{

    float index=ui->doubleSpinBox->value();
    index1=index;
}





void MainWindow::on_pushButton_5_clicked()
{
    int index=ui->spinBox->value();
    index2=index;
}


void MainWindow::on_pushButton_6_clicked()
{
    float index=ui->doubleSpinBox_2->value();
    index3=index;
}




void MainWindow::on_pushButton_7_clicked()
{

    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);
//        imshow("img",image);
//    QImage image2((uchar*)src.data,src.cols,src.rows,QImage::Format_RGB888);
//    QPixmap pix=QPixmap::fromImage(image2);
//    int width_img=ui->label->width();
//    int height_img=ui->label->height();
//    ui->label->setPixmap(pix.scaled(width_img,height_img,Qt::KeepAspectRatio));
}





void MainWindow::on_pushButton_9_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);
//        imshow("img",image);
}


//void MainWindow::on_pushButton_10_clicked()
//{
//    if ( !src.data )
//        {
//            printf("No image data \n");
//            return;
//        }

//    guasian_filter(index4);

//}


//void MainWindow::on_pushButton_11_clicked()
//{
//    if ( !src.data )
//        {
//            printf("No image data \n");
//            return;
//        }

//    mean_filter(index4);

//}





//void MainWindow::on_pushButton_12_clicked()
//{
//    if ( !src.data )
//        {
//            printf("No image data \n");
//            return;
//        }

//    median_filter(index4);

//}



//void MainWindow::on_pushButton_13_clicked()
//{
//    float index=ui->doubleSpinBox_2->value();
//    index4=index;
//}


void MainWindow::on_pushButton_10_clicked()
{
        if ( !src.data )
            {
                printf("No image data \n");
                return;
            }

        guasian_filter(index4);
}


void MainWindow::on_pushButton_11_clicked()
{
    float index=ui->spinBox_2->value();
    index4=index;
}



void MainWindow::on_pushButton_12_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }

    mean_filter(index4);
}


void MainWindow::on_pushButton_13_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }

    median_filter(index4);
}


void MainWindow::on_pushButton_14_clicked()
{
    float index=ui->spinBox_3->value();
    index5=index;
}


void MainWindow::on_pushButton_15_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    automatic_global_threshold();
}


void MainWindow::on_pushButton_16_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    manual_global_threshold(index6);
}


void MainWindow::on_pushButton_17_clicked()
{
    float index=ui->spinBox_4->value();
    index6=index;
}


void MainWindow::on_pushButton_18_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    local_threshold(index7);
}


void MainWindow::on_pushButton_19_clicked()
{
    float index=ui->spinBox_5->value();
    index7=index;
}


void MainWindow::on_pushButton_20_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);

//        imshow("img",image);
}


void MainWindow::on_pushButton_21_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src2=imread(name);

//        imshow("img",image);
}


void MainWindow::on_pushButton_22_clicked()
{
    float index=ui->spinBox_6->value();
    index8=index;
}


void MainWindow::on_pushButton_23_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    hyprid(index8);
}

void MainWindow::on_pushButton_25_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);

//        imshow("img",image);
}

void MainWindow::on_pushButton_24_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    return_image(0,30);
}




void MainWindow::on_pushButton_26_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    return_image(1,30);
}


void MainWindow::on_pushButton_29_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float roberts_x[]={0,1,-1,0};
    float roberts_y[]={1,0,0,-1};
    filters(roberts_x,roberts_y,2,2);
}


void MainWindow::on_pushButton_27_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float prewitt_x[]={-1, 0, 1, -1, 0, 1, -1, 0, 1};
    float prewitt_y[]={-1, -1, -1, 0, 0, 0, 1, 1, 1};
    filters(prewitt_x,prewitt_y,3,3);
}



void MainWindow::on_pushButton_28_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float  x[] = { 1,0,-1,2,0,-2,1,0,-1 };
    float  y[] = { 1,2,1,0,0,0,-1,-2,-1};
    filters(x,y,3,3);
}



void MainWindow::on_pushButton_30_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    int histogram[256];
    Histogram( histogram);
    DisplayHistogram(histogram);
}


void MainWindow::on_pushButton_31_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    equalization();
}


void MainWindow::on_pushButton_32_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    testing();


}

