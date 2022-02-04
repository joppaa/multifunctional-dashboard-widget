#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonObject>
#include <QJsonArray>
#include <iostream>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer)
    , picTimer(new QTimer)
    , httpManager(new HTTPManager)
{
    ui->setupUi(this);
    selectedPic = 0;

    connect(timer, SIGNAL(timeout()),
            this, SLOT(setCurrentTime()));
    connect(timer, SIGNAL(timeout()),
            this, SLOT(setNewTimeZone()));

    setCurrentTime();
    setNewTimeZone();
    timer->start(1000);

    connect(picTimer, SIGNAL(timeout()),
            this, SLOT(imageSlideShow()));
    imageSlideShow();
    picTimer->start(10000);

    connect(httpManager, SIGNAL(ImageReady(QPixmap *)),
            this, SLOT(processImage(QPixmap *)));
    connect(httpManager, SIGNAL(WeatherJsonReady(QJsonObject *)),
            this, SLOT(processWeatherJson(QJsonObject *)));

    loadImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCurrentTime()
{
    QTime time = QTime::currentTime();
    QString hour = time.toString("hh");
    QString minute = time.toString("mm");
    QString second = time.toString("ss");

    if(hour == "00" || hour == "0" || hour == "01" ||hour == "1" ||hour == "02" ||hour == "2"
            ||hour == "03" ||hour == "3" ||hour == "04" ||hour == "4" ||hour == "05" ||hour == "5" ||hour == "06" ||hour == "6"
            ||hour == "07" ||hour == "7" ||hour == "08" ||hour == "8" ||hour == "09" ||hour == "9" ||hour == "10" ||hour == "11"){
        ui->welcomeMessageLabel->setText("Good Morning");
        ui->welcomeMessageLabel->setAlignment(Qt::AlignCenter);
    }
    else if(hour == "12" || hour == "13" || hour == "14" ||hour == "15" ||hour == "16"){
        ui->welcomeMessageLabel->setText("Good Afternoon");
        ui->welcomeMessageLabel->setAlignment(Qt::AlignCenter);

    }
    else{
        ui->welcomeMessageLabel->setText("Good Evening");
        ui->welcomeMessageLabel->setAlignment(Qt::AlignCenter);

    }

    ui->hourLCD->display(hour);
    ui->minuteLCD->display(minute);
    ui->secondLCD->display(second);

}

void MainWindow::processImage(QPixmap *image)
{
    ui->imageLabel->setPixmap(*image);
}

void MainWindow::processWeatherJson(QJsonObject *json)
{
    QString weather = json->value("weather").toArray()[0].toObject()["main"].toString();
    QString weatherDesc = json->value("weather").toArray()[0].toObject()["description"].toString();

    double temp = json->value("main").toObject()["temp"].toDouble();
    double tempMin = json->value("main").toObject()["temp_min"].toDouble();
    double tempMax = json->value("main").toObject()["temp_max"].toDouble();
    double humidity = json->value("main").toObject()["humidity"].toDouble();


    qDebug() << weather;
    qDebug() << weatherDesc;
    qDebug() << temp;
    qDebug() << tempMin;
    qDebug() << tempMax;
    qDebug() << humidity;

    ui->weatherLabel->setAlignment(Qt::AlignCenter);
    ui->weatherLabel->setText("Current Weather: " + weather + ", temp: " + QString::number(temp) + ", humidity: " + QString::number(humidity) );

    if(weatherDesc == "clear sky"){
        ui->weatherImageLabel->setPixmap(imageClearSky);
    }
    else if(weatherDesc == "few clouds"){
        ui->weatherImageLabel->setPixmap(imageFewClouds);
    }
    else if(weatherDesc == "scattered clouds"){
        ui->weatherImageLabel->setPixmap(imageScatteredClouds);
    }
    else if(weatherDesc == "broken clouds"){
        ui->weatherImageLabel->setPixmap(imageBrokenClouds);
    }
    else if(weatherDesc == "shower rain" || "Rain"){
        ui->weatherImageLabel->setPixmap(imageShowerRain);
    }
    else if(weatherDesc == "rain"){
        ui->weatherImageLabel->setPixmap(imageRain);
    }
    else if(weatherDesc == "thunderstorm"){
        ui->weatherImageLabel->setPixmap(imageThunderstorm);
    }
    else if(weatherDesc == "snow"){
        ui->weatherImageLabel->setPixmap(imageSnow);
    }
    else{
        ui->weatherImageLabel->setText("No Image Available");
    }
}

void MainWindow::on_imageDownloadButton_clicked()
{
    QString zip = ui->zipcodeEdit->text();
    qDebug() << zip;
    httpManager->sendImageRequest(zip);

}

void MainWindow::on_weatherDownloadButton_clicked()
{
    QString zip = ui->zipcodeEdit->text();
    qDebug() << zip;
    httpManager->sendWeatherRequest(zip);
}

void MainWindow::setNewTimeZone()
{
    // Getting the current time
    QDateTime dateTime = QDateTime::currentDateTime();
    // Debug: Current time in local timezone
    qDebug() << dateTime.toString();
    // Debug: Current time / local timezone, formatted
    qDebug() << dateTime.toString("hh");
    qDebug() << dateTime.toString("mm");
    qDebug() << dateTime.toString("ss");

    // Create a new timezone object to convert
    QTimeZone newZone("Africa/Nairobi");
    // Debug: Check if the new zone is valid
    qDebug() << newZone;

    // Convert the current time to the new timezone
    QDateTime newDateTime = dateTime.toTimeZone(newZone);

    // Debug: The converted time
    qDebug() << newDateTime.toString();

    // Debug: The converted time (formatted: hr, min, sec)
    qDebug() << newDateTime.toString("hh");
    QString hour = newDateTime.toString("hh");
    ui->hourTimeZoneLCD->display(hour);
    qDebug() << newDateTime.toString("mm");
    QString min = newDateTime.toString("mm");
    ui->minuteTimeZoneLCD->display(min);
    qDebug() << newDateTime.toString("ss");
    QString sec = newDateTime.toString("ss");
    ui->secondTimeZoneLCD->display(sec);

    // To list all available timezone IDs, use the following's output
    //qDebug() << QTimeZone::availableTimeZoneIds();
}

void MainWindow::imageSlideShow()
{
    selectedPic ++;
    if(selectedPic == 7){
        selectedPic = 1;
    }
    QString pic = QString::number(selectedPic);
    qDebug() << pic;

    QString imageFileName = "photo0" + pic + ".JPG";
    qDebug() << imageFileName;
    QPixmap image;

    if(image.load(imageFileName)){
        std::cout << "image01 image loaded successfully" << std::endl;
        image = image.scaled(ui->imageSlideShowLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
    ui->imageSlideShowLabel->setPixmap(image);
}

void MainWindow::loadImage()
{
    QString clearSkyFileName = "01d.png";
    QString fewCloudsFileName = "02d.png";
    QString scatteredCloudsFileName = "03d.png";
    QString brokenCloudsFileName = "04d.png";
    QString showerRainFileName = "09d.png";
    QString rainFileName = "10d.png";
    QString thunderstormFileName = "11d.png";
    QString snowFileName = "13d.png";

    if(imageClearSky.load(clearSkyFileName)){
        std::cout << "clear sky image loaded successfully" << std::endl;
        imageClearSky = imageClearSky.scaled(ui->weatherImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
    if(imageFewClouds.load(fewCloudsFileName)){
        std::cout << "few clouds image loaded successfully" << std::endl;
        imageFewClouds = imageFewClouds.scaled(ui->weatherImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
    if(imageScatteredClouds.load(scatteredCloudsFileName)){
        std::cout << "scattered clouds image loaded successfully" << std::endl;
        imageScatteredClouds = imageScatteredClouds.scaled(ui->weatherImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
    if(imageBrokenClouds.load(brokenCloudsFileName)){
        std::cout << "broken clouds image loaded successfully" << std::endl;
        imageBrokenClouds = imageBrokenClouds.scaled(ui->weatherImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
    if(imageShowerRain.load(showerRainFileName)){
        std::cout << "shower rain image loaded successfully" << std::endl;
        imageShowerRain = imageShowerRain.scaled(ui->weatherImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
    if(imageRain.load(rainFileName)){
        std::cout << "rain image loaded successfully" << std::endl;
        imageRain = imageRain.scaled(ui->weatherImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
    if(imageThunderstorm.load(thunderstormFileName)){
        std::cout << "thunderstorm image loaded successfully" << std::endl;
        imageThunderstorm = imageThunderstorm.scaled(ui->weatherImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
    if(imageSnow.load(snowFileName)){
        std::cout << "snow image loaded successfully" << std::endl;
        imageSnow = imageSnow.scaled(ui->weatherImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
}
