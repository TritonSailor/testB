#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "androidrfcomm.h"
#include <QWidget>
#include <QVBoxLayout>
//#include <QScrollArea>

//class QScrollBar;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
private slots:
    void runTest();
    void connectBt();

    void blueLedOn();
    void blueLedOff();
    void blueLedUp();
    void blueLedDown();
    void blueLedFade();
    void blueLedBlink();

    void redLedOn();
    void redLedOff();
    void redLedUp();
    void redLedDown();
    void redLedFade();
    void redLedBlink();

    void greenLedOn();
    void greenLedOff();
    void greenLedUp();
    void greenLedDown();
    void greenLedFade();
    void greenLedBlink();

    void orangeLedOn();
    void orangeLedOff();
    void orangeLedUp();
    void orangeLedDown();
    void orangeLedFade();
    void orangeLedBlink();

    void extLedOn();
    void extLedOff();
    void extLedUp();
    void extLedDown();
    void extLedFade();
    void extLedBlink();


private:
    AndroidRfComm rfcomm;
    QVBoxLayout* layout;
    //QScrollArea *scrollArea;

};


#endif // MAINWIDGET_H
