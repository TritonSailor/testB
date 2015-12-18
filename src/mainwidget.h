#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "androidrfcomm.h"
#include <QWidget>
#include <QVBoxLayout>

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

    void redLedOn();
    void redLedOff();
    void redLedUp();
    void redLedDown();

    void greenLedOn();
    void greenLedOff();
    void greenLedUp();
    void greenLedDown();

    void orangeLedOn();
    void orangeLedOff();
    void orangeLedUp();
    void orangeLedDown();

    void extLedOn();
    void extLedOff();
    void extLedUp();
    void extLedDown();


private:
    AndroidRfComm rfcomm;
    QVBoxLayout* layout;
};

#endif // MAINWIDGET_H
