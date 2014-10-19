#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    //box = new QMessageBox();
    //box->setWindowTitle(QString("Hello"));
    //box->setText(QString("You Pressed: ")/*+ (QString)(int)e->text()*/);
    //box->show();
}

void MainWindow::nextPage1(QString page)
{
    ui->leftText->setPlainText(page);
}
void MainWindow::nextPage2(QString page)
{
    ui->rightText->setPlainText(page);
}
void MainWindow::prevPage1(QString page)
{
    ui->leftText->setPlainText(page);
}
void MainWindow::prevPage2(QString page)
{
    ui->rightText->setPlainText(page);
}

void MainWindow::on_prevButton_clicked()
{
    emit clickPrev();
}

void MainWindow::on_nextButton_clicked()
{
    emit clickNext();
}

void MainWindow::on_openButton_clicked()
{
    emit clickOpen();
}

void MainWindow::translated(QString word)
{
    ui->textEdit->setPlainText(word);
}

void MainWindow::on_textEdit_textChanged()
{
    if((*((ui->textEdit->toPlainText().end()-1)))=='\n')
            emit signaltoTranslate(ui->textEdit->toPlainText(),"small");
}
