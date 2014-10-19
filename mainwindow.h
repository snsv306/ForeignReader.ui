#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_prevButton_clicked();
    void on_nextButton_clicked();
    void on_openButton_clicked();
    void on_textEdit_textChanged();

signals:
    void clickNext()        ;
    void clickPrev()        ;
    void clickOpen();
    void signaltoTranslate(QString, QString);

public slots:
    void keyPressEvent(QKeyEvent*);
    void nextPage1(QString page);
    void nextPage2(QString page);
    void prevPage1(QString page);
    void prevPage2(QString page);
    void translated(QString word);

private:
    QMessageBox* box;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
