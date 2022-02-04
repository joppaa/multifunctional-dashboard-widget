#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QTimeZone>
#include "httpmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setCurrentTime();
    void setNewTimeZone();
    void imageSlideShow();
    void processImage(QPixmap *);
    void processWeatherJson(QJsonObject *json);

    void on_imageDownloadButton_clicked();

    void on_weatherDownloadButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *picTimer;
    int selectedPic;
    HTTPManager *httpManager;


    QPixmap imageClearSky;
    QPixmap imageFewClouds;
    QPixmap imageScatteredClouds;
    QPixmap imageBrokenClouds;
    QPixmap imageShowerRain;
    QPixmap imageRain;
    QPixmap imageThunderstorm;
    QPixmap imageSnow;

    QPixmap image01;
    QPixmap image02;
    QPixmap image03;
    QPixmap image04;
    QPixmap image05;
    QPixmap image06;

    //QPixmap slideShowImages[];


    void loadImage();



};
#endif // MAINWINDOW_H
