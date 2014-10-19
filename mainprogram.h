#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include "./translator.h"
#include "./mainwindow.h"
#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QXmlStreamReader>


class MainProgram : public QObject
{
    Q_OBJECT
public:
    explicit MainProgram(QObject *parent = 0);
    ~MainProgram() {}
    QString next_text_page();
    QString prev_text_page();

    void text_reader_txt(QString& filename);

private:
    Translator translator;
    MainWindow mw;

    QString all_text_str;
    QString::iterator pointer_for_text;
    QString::iterator* all_the_pages;
    int number_of_symbols_on_page;
    int number_of_pages;
    int current_page_on_screen;

    QString Convert(QString path);
signals:
    void next1(QString nextString);
    void next2(QString nextString);
    void prev1(QString prevString);
    void prev2(QString prevString);

public slots:
    void setFile();
    void nextPage();
    void prevPage();

};

#endif // MAINPROGRAM_H
