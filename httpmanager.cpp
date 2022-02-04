#include "httpmanager.h"

HTTPManager::HTTPManager(QObject *parent) :
    QObject(parent),
    imageDownloadManager(new QNetworkAccessManager),
    weatherAPIManager(new QNetworkAccessManager)
{
    connect(imageDownloadManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(ImageDownloadedHandler(QNetworkReply*)));
    connect(weatherAPIManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(WeatherDownloadedHandeler(QNetworkReply*)));
}

HTTPManager::~HTTPManager()
{
    delete imageDownloadManager;
    delete weatherAPIManager;
}

void HTTPManager::sendImageRequest(QString zip)
{
    QNetworkRequest request;
    QString address = "https://dev.virtualearth.net/REST/V1/Imagery/Map/AerialWithLabels/"
            + zip
            + "/13?mapSize=400,400&mapLayer=TrafficFlow&format=png&key=Aq6w19hZRS0ZsBSlvVqcKPIEdHennv-YlAFHF3c5ZacMXMoZdeBqqWgYbt1gIOjg";
    request.setUrl(QUrl(address));
    imageDownloadManager->get(request);
    qDebug() << "Image Request Sent to Adress" << request.url();

}

void HTTPManager::sendWeatherRequest(QString zip)
{
    QNetworkRequest request;
    QString address = "https://api.openweathermap.org/data/2.5/weather?zip="
            + zip
            + ",us&units=imperial&appid=0e79f6f960c910c29db59b3a93b86ddd";
    request.setUrl(QUrl(address));
    weatherAPIManager->get(request);
    qDebug() << "Weather Request Sent to Adress" << request.url();
}

void HTTPManager::ImageDownloadedHandler(QNetworkReply *reply)
{
    qDebug() << "Image Reply has arrived";
    if(reply->error()){
        qDebug() << reply->errorString();
        return;
    }

    qDebug() << "Download was sucessful";
    QPixmap *image = new QPixmap;
    image->loadFromData(reply->readAll());
    reply->deleteLater();

    emit ImageReady(image);
}

void HTTPManager::WeatherDownloadedHandeler(QNetworkReply *reply)
{
    qDebug() << "Weather Reply has arrived";
    if(reply->error()){
        qDebug() << reply->errorString();
        return;
    }

    qDebug() << "Download was sucessful";

    QString answer = reply->readAll();
    reply->deleteLater();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject *jsonObj = new QJsonObject(jsonResponse.object());

    emit WeatherJsonReady(jsonObj);

}
