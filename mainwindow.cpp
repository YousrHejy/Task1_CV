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
#include "filters.h"
#include "frequency.h"
#include "histogram.h"
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
}


void MainWindow::on_pushButton_7_clicked()
{

    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
        src=imread(name);
    int up_width = 512;
    int up_height = 512;

    resized_up=src;
    cv::resize(src,resized_up, Size(up_width, up_height), INTER_LINEAR);
    QImage image2((uchar*)resized_up.data,resized_up.cols,resized_up.rows,QImage::Format_BGR888);
    QPixmap pix=QPixmap::fromImage(image2);
    int width_img=ui->label->width();
    int height_img=ui->label->height();

    ui->label->setPixmap(pix.scaled(width_img,height_img,Qt::KeepAspectRatio));
}





void MainWindow::on_pushButton_9_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
        src=imread(name);
        int up_width = 512;
        int up_height = 512;
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

void MainWindow::on_pushButton_12_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
}


void MainWindow::on_pushButton_13_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
}

void MainWindow::on_pushButton_20_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
        src=imread(name);
        int up_width = 512;
        int up_height = 512;
        resized_up=src;
        cv::resize(src,resized_up, Size(up_width, up_height), INTER_LINEAR);
        QImage image2((uchar*)resized_up.data,resized_up.cols,resized_up.rows,QImage::Format_BGR888);
        QPixmap pix=QPixmap::fromImage(image2);
        int width_img=ui->label->width();
        int height_img=ui->label->height();

        ui->label->setPixmap(pix.scaled(width_img,height_img,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_21_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png *.JFIF)");
        String name =directory.toStdString();
        src2=imread(name);
        int up_width = 512;
        int up_height = 512;
        resized_up=src2;
        cv::resize(src2,resized_up, Size(up_width, up_height), INTER_LINEAR);
        QImage image2((uchar*)resized_up.data,resized_up.cols,resized_up.rows,QImage::Format_BGR888);
        QPixmap pix=QPixmap::fromImage(image2);
        int width_img=ui->label_2->width();
        int height_img=ui->label_2->height();

        ui->label_2->setPixmap(pix.scaled(width_img,height_img,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_22_clicked()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float index=ui->spinBox_6->value();
    index8=index;
    Mat Result=hyprid(index8);
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
    QImage qimage2(modify.data,modify.cols,modify.rows,QImage::Format_Grayscale8);
    QPixmap outputPix = QPixmap::fromImage(qimage2);
    int width_img2=ui->label_3->width();
    int height_img2=ui->label_3->height();
    ui->label_3->setPixmap(outputPix.scaled(width_img2,height_img2,Qt::KeepAspectRatio));

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
    Mat Result=DisplayHistogram(histogram);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_3->width();
    int height_img2=ui->label_3->height();
    ui->label_3->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
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

void MainWindow::on_high_textHighlighted(const QString &arg1)
{
    if(arg1=="sobel"){
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
            int width_img2=ui->label_2->width();
            int height_img2=ui->label_2->height();
            ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));

    }else if(arg1=="berwit"){
        if ( !src.data )
            {
                printf("No image data \n");
                return;
            }
        float prewitt_x[]={-1, 0, 1, -1, 0, 1, -1, 0, 1};
        float prewitt_y[]={-1, -1, -1, 0, 0, 0, 1, 1, 1};
        Mat Result=filters(prewitt_x,prewitt_y,3,3);
        imwrite("Result.jpg", Result);
        QPixmap pix2("Result.jpg");
        int width_img2=ui->label_2->width();
        int height_img2=ui->label_2->height();
        ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));

    }else if(arg1=="robert"){
        if ( !src.data )
            {
                printf("No image data \n");
                return;
            }
        float roberts_x[]={0,1,-1,0};
        float roberts_y[]={1,0,0,-1};
        Mat Result=filters(roberts_x,roberts_y,2,2);
        imwrite("Result.jpg", Result);
        QPixmap pix2("Result.jpg");
        int width_img2=ui->label_2->width();
        int height_img2=ui->label_2->height();
        ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
    }
}


void MainWindow::on_noise_textHighlighted(const QString &arg1)
{
    if(arg1=="spi"){
        ui->add_g->hide();
        ui->add_u->hide();
        ui->add_s->show();
     }else if(arg1=="guasian"){
        ui->add_u->hide();
        ui->add_s->hide();
        ui->add_g->show();
    }else if(arg1=="uniform"){
        ui->add_s->hide();
        ui->add_g->hide();
        ui->add_u->show();
    }
}


void MainWindow::on_low_textHighlighted(const QString &arg1)
{
    if(arg1=="mean"){
        ui->median->hide();
        ui->guasian->hide();
        ui->mean->show();
     }else if(arg1=="guasian"){
        ui->median->hide();
        ui->guasian->show();
        ui->mean->hide();
    }else if(arg1=="median"){
        ui->median->show();
        ui->guasian->hide();
        ui->mean->hide();
    }
}


void MainWindow::on_add_g_editingFinished()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float index=ui->add_g->value();
    index1=index;
    Mat Result=output_gaussin();
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_add_u_editingFinished()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float index=ui->add_u->value();
    index3=index;
    Mat Result=output_uniform();
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_add_s_editingFinished()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    int index=ui->add_s->value();
    index2=index;
    Mat Result=spl();
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_guasian_editingFinished()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float index=ui->guasian->value();
    index4=index;
    Mat Result=guasian_filter(index4);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_mean_editingFinished()
{
    float index=ui->mean->value();
    index9=index;
    Mat Result=mean_filter(index9);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_median_editingFinished()
{
    float index=ui->median->value();
    index10=index;
    Mat Result=median_filter(index10);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}

void MainWindow::on_options_textHighlighted(const QString &arg1)
{
    if(arg1=="normalize"){
        ui->local->hide();
        ui->manual->hide();
        ui->normalize->show();
     }else if(arg1=="manual"){
        ui->local->hide();
        ui->manual->show();
        ui->normalize->hide();
    }else if(arg1=="local"){
        ui->local->show();
        ui->manual->hide();
        ui->normalize->hide();
    }else if(arg1=="auto"){
        if ( !src.data )
            {
                printf("No image data \n");
                return;
            }
        Mat Result=automatic_global_threshold();
        imwrite("Result.jpg", Result);
        QPixmap pix2("Result.jpg");
        int width_img2=ui->label_2->width();
        int height_img2=ui->label_2->height();
        ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
        }
}


void MainWindow::on_normalize_editingFinished()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float index=ui->normalize->value();
    index5=index;
    Mat Result=normalization_fun();
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}


void MainWindow::on_manual_editingFinished()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float index=ui->manual->value();
    index6=index;
    Mat Result=manual_global_threshold(index6);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));

}


void MainWindow::on_local_editingFinished()
{
    if ( !src.data )
        {
            printf("No image data \n");
            return;
        }
    float index=ui->local->value();
    index7=index;
    Mat Result=local_threshold(index7);
    imwrite("Result.jpg", Result);
    QPixmap pix2("Result.jpg");
    int width_img2=ui->label_2->width();
    int height_img2=ui->label_2->height();
    ui->label_2->setPixmap(pix2.scaled(width_img2,height_img2,Qt::KeepAspectRatio));
}
