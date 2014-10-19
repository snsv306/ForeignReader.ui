#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>

//typedef int TypeofTranslation;
//static QNetworkAccessManager qnm;

class Translator : public QObject
{
    Q_OBJECT
private:
    //typedef QJsonDocument (*func)(QString);
    //QMap<QString, func> transFunc;

    //yandex, google
    QString typeOfTranslator;
    //small, big, text
    QString typeOfView;

    QNetworkAccessManager qnm;

    QString langFrom, langTo;

    QString GoogleTranslate(QJsonDocument);
    QString YandexTranslate(QJsonDocument);
    //QString translatorWord_small(QJsonDocument jdoc);
    //QString translatorWord_big(QJsonDocument jdoc);
    //QString translatorText(QJsonDocument jdoc);

    //void _downloader(QString link);

public:
    explicit Translator(QObject *parent = 0);


    //QNetworkAccessManager qnm;

public slots:
    //void finishDownloadTranslate();
    void finishDownloadTranslate(QNetworkReply*);
    void errorDownloadTranslate(QNetworkReply::NetworkError);
    void translate(QString, QString);


signals:
    void signalTranslated(QString answer);




};

#endif // TRANSLATOR_H
