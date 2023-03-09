/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton;
    QSpinBox *spinBox;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton_6;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QSpinBox *spinBox_7;
    QPushButton *pushButton_33;
    QSpinBox *spinBox_8;
    QPushButton *pushButton_34;
    QPushButton *pushButton_7;
    QWidget *tab_3;
    QPushButton *pushButton_22;
    QSpinBox *spinBox_6;
    QPushButton *pushButton_23;
    QPushButton *pushButton_24;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;
    QPushButton *pushButton_29;
    QPushButton *pushButton_35;
    QPushButton *pushButton_36;
    QPushButton *pushButton_37;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QWidget *tab_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QSpinBox *spinBox_4;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_19;
    QPushButton *pushButton_30;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QWidget *tab_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1149, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("color: red;\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 511, 511));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(false);
        font.setStrikeOut(false);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 232, 199);\n"
"color:rgb(0, 0, 0)\n"
""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        pushButton = new QPushButton(tab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 20, 111, 24));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        pushButton->setFont(font1);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:blue;\n"
"	color:white;\n"
"}\n"
"\n"
"\n"
""));
        spinBox = new QSpinBox(tab);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(10, 60, 111, 25));
        spinBox->setStyleSheet(QString::fromUtf8(""));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(140, 60, 91, 24));
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:black;\n"
"	color:white;\n"
"}"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 110, 111, 24));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:blue;\n"
"	color:white;\n"
"}"));
        doubleSpinBox = new QDoubleSpinBox(tab);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(10, 150, 111, 25));
        doubleSpinBox->setStyleSheet(QString::fromUtf8(""));
        doubleSpinBox->setMaximum(1.000000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(140, 150, 91, 24));
        pushButton_4->setFont(font1);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:black;\n"
"	color:white;\n"
"}"));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 200, 101, 24));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:blue;\n"
"	color:white;\n"
"}"));
        doubleSpinBox_2 = new QDoubleSpinBox(tab);
        doubleSpinBox_2->setObjectName("doubleSpinBox_2");
        doubleSpinBox_2->setGeometry(QRect(10, 240, 101, 25));
        doubleSpinBox_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:gray;\n"
"	color:white;\n"
"}\n"
"QPushButton:!pressed{\n"
"	background-color:gray;\n"
"	color:red;\n"
"}"));
        doubleSpinBox_2->setMaximum(1.000000000000000);
        doubleSpinBox_2->setSingleStep(0.100000000000000);
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(140, 240, 91, 24));
        pushButton_6->setFont(font1);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:black;\n"
"	color:white;\n"
"}"));
        spinBox_2 = new QSpinBox(tab);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(250, 60, 101, 25));
        pushButton_10 = new QPushButton(tab);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(250, 20, 80, 24));
        pushButton_11 = new QPushButton(tab);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(370, 60, 80, 24));
        pushButton_12 = new QPushButton(tab);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(250, 110, 80, 24));
        pushButton_13 = new QPushButton(tab);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(250, 200, 80, 24));
        spinBox_7 = new QSpinBox(tab);
        spinBox_7->setObjectName("spinBox_7");
        spinBox_7->setGeometry(QRect(250, 150, 101, 25));
        pushButton_33 = new QPushButton(tab);
        pushButton_33->setObjectName("pushButton_33");
        pushButton_33->setGeometry(QRect(370, 150, 80, 24));
        spinBox_8 = new QSpinBox(tab);
        spinBox_8->setObjectName("spinBox_8");
        spinBox_8->setGeometry(QRect(250, 240, 101, 25));
        pushButton_34 = new QPushButton(tab);
        pushButton_34->setObjectName("pushButton_34");
        pushButton_34->setGeometry(QRect(370, 240, 80, 24));
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(180, 320, 91, 24));
        pushButton_7->setFont(font1);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:blue;\n"
"	color:white;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        pushButton_22 = new QPushButton(tab_3);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(340, 130, 80, 24));
        spinBox_6 = new QSpinBox(tab_3);
        spinBox_6->setObjectName("spinBox_6");
        spinBox_6->setGeometry(QRect(120, 130, 131, 25));
        pushButton_23 = new QPushButton(tab_3);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(150, 90, 80, 24));
        pushButton_24 = new QPushButton(tab_3);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(120, 220, 101, 24));
        pushButton_25 = new QPushButton(tab_3);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(250, 220, 80, 24));
        pushButton_26 = new QPushButton(tab_3);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(30, 220, 80, 24));
        pushButton_27 = new QPushButton(tab_3);
        pushButton_27->setObjectName("pushButton_27");
        pushButton_27->setGeometry(QRect(760, 190, 80, 24));
        pushButton_28 = new QPushButton(tab_3);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setGeometry(QRect(640, 190, 80, 24));
        pushButton_29 = new QPushButton(tab_3);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setGeometry(QRect(890, 193, 211, 81));
        pushButton_29->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);\n"
"background-color: rgb(170, 0, 0);"));
        pushButton_29->setFlat(false);
        pushButton_35 = new QPushButton(tab_3);
        pushButton_35->setObjectName("pushButton_35");
        pushButton_35->setGeometry(QRect(60, 280, 80, 24));
        pushButton_36 = new QPushButton(tab_3);
        pushButton_36->setObjectName("pushButton_36");
        pushButton_36->setGeometry(QRect(170, 280, 80, 24));
        pushButton_37 = new QPushButton(tab_3);
        pushButton_37->setObjectName("pushButton_37");
        pushButton_37->setGeometry(QRect(290, 280, 80, 24));
        pushButton_20 = new QPushButton(tab_3);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(60, 40, 80, 24));
        pushButton_21 = new QPushButton(tab_3);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(220, 40, 80, 24));
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        pushButton_8 = new QPushButton(tab_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(40, 20, 101, 24));
        pushButton_8->setFont(font1);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:blue;\n"
"	color:white;\n"
"}"));
        pushButton_9 = new QPushButton(tab_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(180, 20, 80, 24));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        pushButton_9->setFont(font2);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius:15px;\n"
"	border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"	background-color:blue;\n"
"	color:white;\n"
"}\n"
""));
        spinBox_3 = new QSpinBox(tab_2);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(40, 60, 171, 25));
        spinBox_3->setMaximum(255);
        pushButton_14 = new QPushButton(tab_2);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(230, 60, 80, 24));
        pushButton_15 = new QPushButton(tab_2);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(40, 120, 80, 24));
        pushButton_16 = new QPushButton(tab_2);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(40, 170, 101, 24));
        spinBox_4 = new QSpinBox(tab_2);
        spinBox_4->setObjectName("spinBox_4");
        spinBox_4->setGeometry(QRect(40, 220, 121, 25));
        spinBox_4->setMaximum(255);
        pushButton_17 = new QPushButton(tab_2);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(200, 220, 80, 24));
        pushButton_18 = new QPushButton(tab_2);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(50, 270, 80, 24));
        spinBox_5 = new QSpinBox(tab_2);
        spinBox_5->setObjectName("spinBox_5");
        spinBox_5->setGeometry(QRect(41, 320, 111, 25));
        spinBox_5->setMaximum(100);
        pushButton_19 = new QPushButton(tab_2);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(200, 320, 80, 24));
        pushButton_30 = new QPushButton(tab_2);
        pushButton_30->setObjectName("pushButton_30");
        pushButton_30->setGeometry(QRect(350, 110, 80, 24));
        pushButton_31 = new QPushButton(tab_2);
        pushButton_31->setObjectName("pushButton_31");
        pushButton_31->setGeometry(QRect(350, 160, 80, 24));
        pushButton_32 = new QPushButton(tab_2);
        pushButton_32->setObjectName("pushButton_32");
        pushButton_32->setGeometry(QRect(350, 220, 80, 24));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tab_4->setEnabled(true);
        tabWidget->addTab(tab_4, QString());
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(520, 0, 301, 281));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 232, 199);\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(830, 0, 301, 281));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 232, 199);\n"
""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(690, 290, 241, 221));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 232, 199);\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1149, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "spl", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Add_gaussion", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Add_uniform", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "ADd", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "mean", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "median", nullptr));
        pushButton_33->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_34->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "upload", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "filters", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "radius", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "Result", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "low", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "upload", nullptr));
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "high", nullptr));
        pushButton_27->setText(QCoreApplication::translate("MainWindow", "prewitt", nullptr));
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "sobel", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "Robert", nullptr));
        pushButton_35->setText(QCoreApplication::translate("MainWindow", "Robert", nullptr));
        pushButton_36->setText(QCoreApplication::translate("MainWindow", "Sobel", nullptr));
        pushButton_37->setText(QCoreApplication::translate("MainWindow", "Prewitt", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "upload1", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "upload2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "hybrid", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Normalize", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "upload", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "auto_global", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Manaual_global", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Local", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "Histogram", nullptr));
        pushButton_31->setText(QCoreApplication::translate("MainWindow", "Equallization", nullptr));
        pushButton_32->setText(QCoreApplication::translate("MainWindow", "canny", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "histogram", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Page", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
