/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QToolButton *righttranslate;
    QPushButton *openButton;
    QPlainTextEdit *leftText;
    QPlainTextEdit *rightText;
    QPushButton *nextButton;
    QPushButton *prevButton;
    QToolButton *lefttranslate;
    QFrame *frame;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(640, 510);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(640, 513));
        MainWindow->setBaseSize(QSize(640, 513));
        MainWindow->setAnimated(false);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Triangular);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(640, 480));
        centralWidget->setBaseSize(QSize(640, 480));
        righttranslate = new QToolButton(centralWidget);
        righttranslate->setObjectName(QStringLiteral("righttranslate"));
        righttranslate->setGeometry(QRect(590, -10, 51, 51));
        righttranslate->setStyleSheet(QStringLiteral("border-image: url(:/icns/Translate2.png);"));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(2, 2, 27, 27));
        openButton->setStyleSheet(QStringLiteral("border-image: url(:/icns/Add-icn2.png);"));
        leftText = new QPlainTextEdit(centralWidget);
        leftText->setObjectName(QStringLiteral("leftText"));
        leftText->setGeometry(QRect(0, 30, 320, 480));
        leftText->setFocusPolicy(Qt::NoFocus);
        leftText->setAcceptDrops(false);
        leftText->setReadOnly(true);
        rightText = new QPlainTextEdit(centralWidget);
        rightText->setObjectName(QStringLiteral("rightText"));
        rightText->setGeometry(QRect(320, 30, 320, 480));
        rightText->setFocusPolicy(Qt::NoFocus);
        rightText->setAcceptDrops(false);
        rightText->setReadOnly(true);
        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(608, 478, 30, 30));
        nextButton->setStyleSheet(QLatin1String("border-image: url(:/icns/forward-icn.png);pacity: 0.8;\n"
""));
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));
        prevButton->setGeometry(QRect(3, 477, 30, 30));
        prevButton->setStyleSheet(QLatin1String("border-image: url(:/icns/back-icn.png);\n"
"opacity: 0.8;\n"
""));
        prevButton->setFlat(false);
        lefttranslate = new QToolButton(centralWidget);
        lefttranslate->setObjectName(QStringLiteral("lefttranslate"));
        lefttranslate->setGeometry(QRect(270, -10, 51, 51));
        lefttranslate->setStyleSheet(QStringLiteral("border-image: url(:/icns/Translate2.png);"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 475, 641, 34));
        frame->setStyleSheet(QLatin1String("color: rgb(188, 190, 186);\n"
"background-color: rgb(206, 203, 203);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(190, 478, 261, 27));
        MainWindow->setCentralWidget(centralWidget);
        righttranslate->raise();
        openButton->raise();
        leftText->raise();
        rightText->raise();
        lefttranslate->raise();
        frame->raise();
        prevButton->raise();
        nextButton->raise();
        textEdit->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_STATUSTIP
        MainWindow->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_TOOLTIP
        righttranslate->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        righttranslate->setText(QString());
#ifndef QT_NO_TOOLTIP
        openButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        openButton->setText(QString());
        nextButton->setText(QString());
        prevButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        lefttranslate->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        lefttranslate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
