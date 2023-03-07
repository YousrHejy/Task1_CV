#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include <opencv2/opencv.hpp>
#include<QString>
#include <QFileDialog>
#include <QFile>
#include <string.h>
#include<QDir>
float index1=0;
int index2=0;
float index3=0;
Mat src;
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






void MainWindow::on_pushButton_clicked()
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
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);
//        imshow("img",image);
}





void MainWindow::on_pushButton_9_clicked()
{
    QString directory = QFileDialog::getOpenFileName(this,
                                  tr("Find Files"), QDir::homePath(),"Image files (*.jpg *.png)");
        String name =directory.toStdString();
//        Mat image;
        src=imread(name);
//        imshow("img",image);
}

