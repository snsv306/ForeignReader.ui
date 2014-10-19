#include "mainprogram.h"

MainProgram::MainProgram(QObject *parent) :
    QObject(parent)
{
    mw.show();

    number_of_symbols_on_page = 1500;
    current_page_on_screen = 0;
    connect(&mw, SIGNAL(clickOpen()), this, SLOT(setFile()));
    QObject::connect(&mw, SIGNAL(clickNext()), this, SLOT(nextPage()));
    QObject::connect(&mw, SIGNAL(clickPrev()), this, SLOT(prevPage()));
    connect(this, SIGNAL(next1(QString)), &mw, SLOT(nextPage1(QString)));
    connect(this, SIGNAL(next2(QString)), &mw, SLOT(nextPage2(QString)));
    connect(this, SIGNAL(prev1(QString)), &mw, SLOT(prevPage1(QString)));
    connect(this, SIGNAL(prev2(QString)), &mw, SLOT(prevPage2(QString)));

    connect(&translator, SIGNAL(signalTranslated(QString)), &mw, SLOT(translated(QString)));
    connect(&mw, SIGNAL(signaltoTranslate(QString, QString /*type*/)),
            &translator, SLOT(translate(QString,QString)));
}

QString MainProgram::next_text_page()
{
    QString cur = "";
    if(current_page_on_screen + 1 <= number_of_pages)
    {
        for(QString::iterator i = all_the_pages[current_page_on_screen];i != all_the_pages[current_page_on_screen+1];i++)
                cur.append(*i);
        current_page_on_screen++;
    }

    return cur;
}

QString MainProgram::prev_text_page()
{
    QString cur = "";
    if(current_page_on_screen - 1 >= 0)
    {
        for(QString::iterator i = all_the_pages[current_page_on_screen-1];i != all_the_pages[current_page_on_screen];i++)
                cur.append(*i);
        current_page_on_screen--;
    }
    return cur;
}
void MainProgram::text_reader_txt(QString& filename)
{
    all_text_str = "";
    QFile inFile(filename);
    inFile.open(QIODevice::ReadOnly);
    QTextStream in(&inFile);

    while (!in.atEnd())
    {
        QString line = in.readLine();
        //qDebug() << line;
        if(line == "")
            all_text_str.append('\n');
        else
            all_text_str.append(line);
    }
    pointer_for_text = all_text_str.begin();
    number_of_pages = all_text_str.size() / number_of_symbols_on_page + 1; // =)

    all_the_pages = new QString::iterator[number_of_pages*2];

    QString cur = "";

    int global_count = 0;

    while(pointer_for_text != all_text_str.end())
    {
        cur = "";
        all_the_pages[global_count] = pointer_for_text;
        all_the_pages[global_count+1] = all_text_str.end();



        for(int i = 0 ; i < number_of_symbols_on_page ; i++)
        {
            if(pointer_for_text != all_text_str.end())
                cur.append(*pointer_for_text++);
            else{
                //all_the_pages[global_count+1] = all_text_str.end();
                break;
            }
        }

        if(((cur[number_of_symbols_on_page-1] >= 60) && (cur[number_of_symbols_on_page-1] <=90)) ||
                ((cur[number_of_symbols_on_page-1] >= 97) && (cur[number_of_symbols_on_page-1] <= 122)))
        {
            int i = number_of_symbols_on_page-1;
            while((((cur[i] >= 60) && (cur[i] <=90)) || ((cur[i] >= 97) && (cur[i] <= 122))))
            {
                pointer_for_text--;
                i--;
            }
        }
        global_count++;
    }
}



void MainProgram::setFile()
{
    qDebug() << "jjj";
    QString fileName;
    fileName = QFileDialog::getOpenFileName(0, tr("Выберите файл"), "D:\\Documents", tr("Файлы текст (*.txt)"));
    text_reader_txt(fileName);
    QString Next_Page = MainProgram::next_text_page();
    emit next1(Next_Page);
    Next_Page = next_text_page();
    emit next2(Next_Page);
}

void MainProgram::nextPage()
{
    QString Next_Page = MainProgram::next_text_page();
    emit next1(Next_Page);
    Next_Page = next_text_page();
    emit next2(Next_Page);
}

void MainProgram::prevPage()
{
    QString Prev_Page = prev_text_page();
    emit prev2(Prev_Page);
    Prev_Page = prev_text_page();
    emit prev1(Prev_Page);
}

QString MainProgram::Convert(QString path)
{
    QFile book(path);
    book.open(QIODevice::ReadOnly);
    QString MainString;
    QXmlStreamReader xml(&book);
    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement)
        {
            if (xml.name() != "p")
                continue;
            if (xml.name() == "p")
                MainString+=xml.text();
        }
    }
    book.close();
    return MainString;
}




