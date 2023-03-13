#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <opencv2/opencv.hpp>
#include <QMainWindow>
using namespace cv;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
extern float index1;

extern int index2;

extern float index3;

extern int index4;

extern int index5;

extern int index6;

extern int index7;

extern int index8;

extern Mat src;

extern Mat src2;

extern Mat dst;

extern Mat resized_up;

extern int index9;

extern int index10;


//extern Mat resized_up2;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

//    void on_pushButton_4_clicked();





//    void on_pushButton_5_clicked();

//    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

//    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();



    void on_pushButton_10_clicked();

//    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

//    void on_pushButton_14_clicked();

//    void on_pushButton_15_clicked();

//    void on_pushButton_16_clicked();

//    void on_pushButton_17_clicked();

//    void on_pushButton_18_clicked();

//    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

//    void on_pushButton_23_clicked();

//    void on_pushButton_24_clicked();

//    void on_pushButton_25_clicked();

//    void on_pushButton_26_clicked();

//    void on_pushButton_29_clicked();

//    void on_pushButton_27_clicked();

//    void on_pushButton_28_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

//    void on_pushButton_33_clicked();

//    void on_pushButton_34_clicked();

//    void on_pushButton_35_clicked();

//    void on_pushButton_36_clicked();

//    void on_pushButton_37_clicked();


    void on_high_textHighlighted(const QString &arg1);

    void on_noise_textHighlighted(const QString &arg1);

    void on_low_textHighlighted(const QString &arg1);

    void on_add_g_editingFinished();

    void on_add_u_editingFinished();

    void on_add_s_editingFinished();

    void on_guasian_editingFinished();

    void on_mean_editingFinished();

    void on_median_editingFinished();

    void on_options_textHighlighted(const QString &arg1);

    void on_normalize_editingFinished();

    void on_manual_editingFinished();

    void on_local_editingFinished();

    void on_Histogram_textHighlighted(const QString &arg1);

//    void on_options_activated(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
