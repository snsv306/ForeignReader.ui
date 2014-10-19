#include "translator.h"


Translator::Translator(QObject *parent) :
    QObject(parent)
{
    //transFunc.insert(QString("google"), &GoogleTranslate);

    typeOfTranslator = "google";
    typeOfView = "small";

    langFrom = "en"; langTo = "ru";
    //qDebug() << "constr";

    /*qDebug() << */connect(&qnm, SIGNAL(finished(QNetworkReply*)),
                            this, SLOT(finishDownloadTranslate(QNetworkReply*)));

}


// FIRST STEP
void Translator::translate(QString word, QString type)
{
    typeOfView = type;
    QString  url;
    if(typeOfTranslator == "google")
    {
        //GoogleTranslate(word);
        QString gbase = "http://translate.google.ru/translate_a/t?client=x",
                hl = langFrom,
                sl = langFrom,
                tl = langTo;
        url = gbase + "&text=" + word + "&hl=" + hl + "&sl=" + sl + "&tl=" + tl;
    }
    else if (typeOfTranslator == "yandex")
    {
        //YandexTranslate(word);
        QString base = "https://translate.yandex.net/api/v1.5/tr/translate?", //yandex
                base2 = "https://translate.yandex.net/api/v1.5/tr.json/translate?",
                key = "trnsl.1.1.20141017T171121Z.41c9849a68f53134.65625255ca9ee1241ddeb732eb285dfd867e64fa",
                lang = "ru";
        url = base + "key=" + key + "&text=" + word + "&lang=" + lang;
    }
    else {}

    qnm.get(QNetworkRequest(QUrl(url)));

    //qDebug() << "tr";
    //return QString("123");
    //transFunc[typeOfTranslator](word)
}

//SECOND STEP
void Translator::finishDownloadTranslate(QNetworkReply *repl)
{
    //qDebug() << "finish2";
    //qDebug() << repl->readAll();
    if (repl->error() == QNetworkReply::NoError)
    {
        QString ans;

        QJsonDocument jsonResponse = QJsonDocument::fromJson(repl->readAll());

        //if (typeOfView == "small")
        //    ans = translatorWord_small(jsonResponse);
        //else if (typeOfView == "big")
        //    ans = translatorWord_big(jsonResponse);
        //else if (typeOfView == "text")
        //    ans = translatorText(jsonResponse);

        if(typeOfTranslator == "google")
            ans = GoogleTranslate(jsonResponse);
        else if (typeOfTranslator == "yandex")
            ans = YandexTranslate(jsonResponse);


        emit signalTranslated(ans);
    }
    else {}
}

//void Translator::GoogleTranslate(QString word)
QString Translator::GoogleTranslate(QJsonDocument jdoc)
{
    //QString gbase = "http://translate.google.ru/translate_a/t?client=x",
    //        hl = langFrom,
    //        sl = langFrom,
    //        tl = langTo;
    //QString g_url = gbase + "&text=" + word + "&hl=" + hl + "&sl=" + sl + "&tl=" + tl;
    //qDebug() << g_url;
    //*reply = */qnm.get(QNetworkRequest(QUrl(g_url)));
    //_downloader(g_url);
    //connect(reply, SIGNAL(finished()), this, SLOT(finishDownloadTranslate()));
    //connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(progressDownloadTranslate(qint64,qint64)));
    //connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(errorDownloadTranslate(QNetworkReply::NetworkError)));
    //connect(reply, SIGNAL(), this, SLOT(finishDownloadTranslate()));
    //while (1)


    //qDebug() << "parse";
    //typeOfView = "big";
    QString ans = "";

    if (typeOfView == "small")
    {
        QJsonArray jobj = jdoc.object().take("sentences").toArray();
        ans = jobj.first().toObject().take("trans").toString();
    }
    else if (typeOfView == "big")
    {
        QJsonObject jobj = jdoc.object().take("sentences").toArray().first().toObject();
        ans += jobj.take("orig").toString();
        ans += " - ";
        ans += jobj.take("trans").toString();
        //jobj = jdoc.object().take("dict").toArray();
        QJsonArray jar = jdoc.object().take("dict").toArray();
        //foreach (QJsonArray::iterator jIter, jdoc.object().take("dict").toArray())
        for (QJsonArray::iterator jIter = jar.begin(); jIter != jar.end(); jIter++)
        {
            ans += "\n- ";
            ans += (*jIter).toObject().take("pos").toString() + " : ";
            QJsonArray jar = (*jIter).toObject().take("terms").toArray();
            for (QJsonArray::iterator jIter = jar.begin(); jIter != jar.end()-1; jIter++)
                ans += (*jIter).toString() + ", ";
            ans += (*(jar.end()-1)).toString();
        }


    }
    else if (typeOfView == "text")
    {
        QJsonArray jobj = jdoc.object().take("sentences").toArray();
        ans = jobj.first().toObject().take("trans").toString();
    }
    qDebug() << ans;
    return ans;
}

//void Translator::YandexTranslate(QString word)
QString Translator::YandexTranslate(QJsonDocument jdoc)
{

    //QString base = "https://translate.yandex.net/api/v1.5/tr/translate?", //yandex
    //        base2 = "https://translate.yandex.net/api/v1.5/tr.json/translate?",
    //        key = "trnsl.1.1.20141017T171121Z.41c9849a68f53134.65625255ca9ee1241ddeb732eb285dfd867e64fa",
    //        lang = "ru";
    //QString ya_url = base + "key=" + key + "&text=" + word + "&lang=" + lang;
    //qnm.get(QNetworkRequest(QUrl(ya_url)));
    //qDebug() << ya_url;
    //reply = qnm.get(QNetworkRequest(QUrl(ya_url)));
    //connect(reply, SIGNAL(finished()), this, SLOT(finishDownloadTranslate()));
    //connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(progressDownloadTranslate(qint64,qint64)));
    //connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(errorDownloadTranslate(QNetworkReply::NetworkError)));
    //qDebug() << reply->isRunning();


    QString ans = "";
    if (typeOfView == "small")
    {
        //QJsonArray jobj = jdoc.object().value("sentences").toArray();
        //qDebug() << jobj;
    }
    else if (typeOfView == "big")
    {

    }
    else if (typeOfView == "text")
    {

    }

    return ans;
}

void Translator::errorDownloadTranslate(QNetworkReply::NetworkError e)
{
    emit signalTranslated("Error");
}

/*
QString Translator::translatorWord_small(QJsonDocument jdoc)
{
    qDebug() << "small";
    QString ans;
    QJsonObject jobj = jdoc.object().value("sentences")
    return ans;
}

QString Translator::translatorWord_big(QJsonDocument jdoc)
{
    qDebug() << "big";
    QString ans;
    return ans;
}


QString Translator::translatorText(QJsonDocument jdoc)
{
    qDebug() << "text";
    QString ans;
    return ans;
}

void Translator::finishDownloadTranslate()
{
    qDebug() << "finish1";
    /*if (reply->error() == QNetworkReply::NoError)
    {
        QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
        qDebug() << reply->readAll();
        if (typeOfView == "small")
            translatorWord_small(jsonResponse);
        else if (typeOfView == "big")
            translatorWord_big(jsonResponse);
        else if (typeOfView == "text")
            translatorText(jsonResponse);
        else
            translatorText(jsonResponse);
    }
}*/





/*void Translator::progressDownloadTranslate(qint64 a ,qint64 b)
{
    qDebug() << a << "/" << b;
}*/



/*QString _downloader1(QString link)
{
    qDebug() << "_down" << link;
    QEventLoop s;
    QNetworkAccessManager qnm;
    //reply = qnm.get(QNetworkRequest(QUrl("http://translate.google.ru/translate_a/t?client=x&text=good&hl=en&sl=en&tl=ru")));
    QNetworkReply *r = qnm.get(QNetworkRequest(QUrl(link)));
    QObject::connect(r, SIGNAL(finished()), &s, SLOT(quit()));
    //s.exec();
    qDebug() << r->readAll();
    return r->readAll();
}*/

/*void Translator::_downloader(QString link)
{
    _Download d;
    //QNetworkAccessManager qnm;
    qDebug() << "_down" << link;
    QEventLoop s;
    //;
    //reply = qnm.get(QNetworkRequest(QUrl("http://translate.google.ru/translate_a/t?client=x&text=good&hl=en&sl=en&tl=ru")));
    QNetworkReply *r = qnm.get(QNetworkRequest(QUrl(link)));
    r->deleteLater();
    QObject::connect(&qnm, SIGNAL(finished(QNetworkReply*)), &d, SLOT(sl2(QNetworkReply*)));
    //QObject::connect(&qnm, SIGNAL(finished(QNetworkReply*)), p, SLOT(finishDownloadTranslate(QNetworkReply*)));
    QObject::connect(r, SIGNAL(finished()), this, SLOT(finishDownloadTranslate()));
    QObject::connect(r, SIGNAL(finished()), &s, SLOT(quit()));
    //s.exec();
    qDebug() << r->readAll();
}*/

