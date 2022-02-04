/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLCDNumber *hourLCD;
    QLCDNumber *minuteLCD;
    QLCDNumber *secondLCD;
    QPushButton *imageDownloadButton;
    QLabel *imageLabel;
    QLCDNumber *minuteTimeZoneLCD;
    QLCDNumber *secondTimeZoneLCD;
    QLCDNumber *hourTimeZoneLCD;
    QLineEdit *zipcodeEdit;
    QPushButton *weatherDownloadButton;
    QLabel *weatherLabel;
    QLabel *weatherImageLabel;
    QLabel *welcomeMessageLabel;
    QLabel *timeZoneLabel;
    QLabel *imageSlideShowLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1122, 672);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(125, 125, 125);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hourLCD = new QLCDNumber(centralwidget);
        hourLCD->setObjectName(QString::fromUtf8("hourLCD"));
        hourLCD->setGeometry(QRect(330, 10, 141, 131));
        hourLCD->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255,255,255);    \n"
"}"));
        hourLCD->setDigitCount(2);
        hourLCD->setProperty("value", QVariant(22.000000000000000));
        minuteLCD = new QLCDNumber(centralwidget);
        minuteLCD->setObjectName(QString::fromUtf8("minuteLCD"));
        minuteLCD->setGeometry(QRect(480, 10, 141, 131));
        minuteLCD->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255,255,255);    \n"
"}"));
        minuteLCD->setDigitCount(2);
        minuteLCD->setProperty("value", QVariant(22.000000000000000));
        secondLCD = new QLCDNumber(centralwidget);
        secondLCD->setObjectName(QString::fromUtf8("secondLCD"));
        secondLCD->setGeometry(QRect(630, 10, 141, 131));
        secondLCD->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255,255,255);    \n"
"}"));
        secondLCD->setDigitCount(2);
        secondLCD->setProperty("value", QVariant(22.000000000000000));
        imageDownloadButton = new QPushButton(centralwidget);
        imageDownloadButton->setObjectName(QString::fromUtf8("imageDownloadButton"));
        imageDownloadButton->setGeometry(QRect(450, 370, 221, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft New Tai Lue"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        imageDownloadButton->setFont(font);
        imageDownloadButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(30, 310, 401, 281));
        minuteTimeZoneLCD = new QLCDNumber(centralwidget);
        minuteTimeZoneLCD->setObjectName(QString::fromUtf8("minuteTimeZoneLCD"));
        minuteTimeZoneLCD->setGeometry(QRect(500, 190, 101, 91));
        minuteTimeZoneLCD->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255, 255, 255);    \n"
"\n"
"}"));
        minuteTimeZoneLCD->setDigitCount(2);
        minuteTimeZoneLCD->setProperty("value", QVariant(22.000000000000000));
        secondTimeZoneLCD = new QLCDNumber(centralwidget);
        secondTimeZoneLCD->setObjectName(QString::fromUtf8("secondTimeZoneLCD"));
        secondTimeZoneLCD->setGeometry(QRect(600, 190, 101, 91));
        secondTimeZoneLCD->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255, 255, 255);    \n"
"\n"
"}"));
        secondTimeZoneLCD->setDigitCount(2);
        secondTimeZoneLCD->setProperty("value", QVariant(22.000000000000000));
        hourTimeZoneLCD = new QLCDNumber(centralwidget);
        hourTimeZoneLCD->setObjectName(QString::fromUtf8("hourTimeZoneLCD"));
        hourTimeZoneLCD->setGeometry(QRect(400, 190, 101, 91));
        hourTimeZoneLCD->setStyleSheet(QString::fromUtf8("QLCDNumber{\n"
"    color: rgb(255, 255, 255);    \n"
"\n"
"}"));
        hourTimeZoneLCD->setDigitCount(2);
        hourTimeZoneLCD->setProperty("value", QVariant(22.000000000000000));
        zipcodeEdit = new QLineEdit(centralwidget);
        zipcodeEdit->setObjectName(QString::fromUtf8("zipcodeEdit"));
        zipcodeEdit->setGeometry(QRect(500, 300, 101, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft New Tai Lue"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        zipcodeEdit->setFont(font1);
        zipcodeEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        weatherDownloadButton = new QPushButton(centralwidget);
        weatherDownloadButton->setObjectName(QString::fromUtf8("weatherDownloadButton"));
        weatherDownloadButton->setGeometry(QRect(450, 440, 221, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft New Tai Lue"));
        font2.setPointSize(10);
        weatherDownloadButton->setFont(font2);
        weatherDownloadButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        weatherLabel = new QLabel(centralwidget);
        weatherLabel->setObjectName(QString::fromUtf8("weatherLabel"));
        weatherLabel->setGeometry(QRect(760, 210, 321, 71));
        weatherLabel->setFont(font);
        weatherLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        weatherImageLabel = new QLabel(centralwidget);
        weatherImageLabel->setObjectName(QString::fromUtf8("weatherImageLabel"));
        weatherImageLabel->setGeometry(QRect(870, 110, 91, 91));
        welcomeMessageLabel = new QLabel(centralwidget);
        welcomeMessageLabel->setObjectName(QString::fromUtf8("welcomeMessageLabel"));
        welcomeMessageLabel->setGeometry(QRect(360, 150, 391, 31));
        welcomeMessageLabel->setFont(font1);
        welcomeMessageLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        timeZoneLabel = new QLabel(centralwidget);
        timeZoneLabel->setObjectName(QString::fromUtf8("timeZoneLabel"));
        timeZoneLabel->setGeometry(QRect(160, 200, 231, 71));
        timeZoneLabel->setFont(font);
        timeZoneLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        imageSlideShowLabel = new QLabel(centralwidget);
        imageSlideShowLabel->setObjectName(QString::fromUtf8("imageSlideShowLabel"));
        imageSlideShowLabel->setGeometry(QRect(680, 310, 401, 281));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1122, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        imageDownloadButton->setText(QCoreApplication::translate("MainWindow", "Image Download/Display", nullptr));
        imageLabel->setText(QCoreApplication::translate("MainWindow", "image Label", nullptr));
        zipcodeEdit->setText(QCoreApplication::translate("MainWindow", "98119", nullptr));
        weatherDownloadButton->setText(QCoreApplication::translate("MainWindow", "Weather Download", nullptr));
        weatherLabel->setText(QCoreApplication::translate("MainWindow", "weather label", nullptr));
        weatherImageLabel->setText(QCoreApplication::translate("MainWindow", "weather Image label", nullptr));
        welcomeMessageLabel->setText(QString());
        timeZoneLabel->setText(QCoreApplication::translate("MainWindow", "Current Time in Nairobi, Kenya", nullptr));
        imageSlideShowLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
