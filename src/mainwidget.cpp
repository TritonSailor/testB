#include "mainwidget.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent) :  QWidget(parent)
{
    layout=new QVBoxLayout(this);

    QHBoxLayout* buttonsBox=new QHBoxLayout(this);

    QPushButton* startButton=new QPushButton("Start",this);
    buttonsBox->addWidget(startButton);
    QPushButton* quitButton=new QPushButton("Quit",this);
    buttonsBox->addWidget(quitButton);
    QPushButton* connectButton=new QPushButton("Connect",this);
    buttonsBox->addWidget(connectButton);

    QHBoxLayout *LedButtonsBox=new QHBoxLayout(this);
    QHBoxLayout *LedButtonsBox2=new QHBoxLayout(this);


    QVBoxLayout *blueButtons=new QVBoxLayout(this);
    QVBoxLayout *redButtons=new QVBoxLayout(this);
    QVBoxLayout *greenButtons=new QVBoxLayout(this);

    QVBoxLayout *orangeButtons=new QVBoxLayout(this);
    QVBoxLayout *extButtons=new QVBoxLayout(this);






    QPushButton *blueLedOnButton=new QPushButton("Blue On",this);
    blueButtons->addWidget(blueLedOnButton);
    QPushButton *blueLedOffButton=new QPushButton("Blue Off",this);
    blueButtons->addWidget(blueLedOffButton);
    QPushButton *blueLedUpButton=new QPushButton("Blue Up",this);
    blueButtons->addWidget(blueLedUpButton);
    QPushButton *blueLedDownButton=new QPushButton("Blue Down",this);
    blueButtons->addWidget(blueLedDownButton);


    QPushButton *redLedOnButton=new QPushButton("red On",this);
    redButtons->addWidget(redLedOnButton);
    QPushButton *redLedOffButton=new QPushButton("red Off",this);
    redButtons->addWidget(redLedOffButton);
    QPushButton *redLedUpButton=new QPushButton("red Up",this);
    redButtons->addWidget(redLedUpButton);
    QPushButton *redLedDownButton=new QPushButton("red Down",this);
    redButtons->addWidget(redLedDownButton);

    QPushButton *greenLedOnButton=new QPushButton("green On",this);
    greenButtons->addWidget(greenLedOnButton);
    QPushButton *greenLedOffButton=new QPushButton("green Off",this);
    greenButtons->addWidget(greenLedOffButton);
    QPushButton *greenLedUpButton=new QPushButton("green Up",this);
    greenButtons->addWidget(greenLedUpButton);
    QPushButton *greenLedDownButton=new QPushButton("green Down",this);
    greenButtons->addWidget(greenLedDownButton);

    QPushButton *orangeLedOnButton=new QPushButton("orange On",this);
    orangeButtons->addWidget(orangeLedOnButton);
    QPushButton *orangeLedOffButton=new QPushButton("orange Off",this);
    orangeButtons->addWidget(orangeLedOffButton);
    QPushButton *orangeLedUpButton=new QPushButton("orange Up",this);
    orangeButtons->addWidget(orangeLedUpButton);
    QPushButton *orangeLedDownButton=new QPushButton("orange Down",this);
    orangeButtons->addWidget(orangeLedDownButton);

    QPushButton *extLedOnButton=new QPushButton("ext On",this);
    extButtons->addWidget(extLedOnButton);
    QPushButton *extLedOffButton=new QPushButton("ext Off",this);
    extButtons->addWidget(extLedOffButton);
    QPushButton *extLedUpButton=new QPushButton("ext Up",this);
    extButtons->addWidget(extLedUpButton);
    QPushButton *extLedDownButton=new QPushButton("ext Down",this);
    extButtons->addWidget(extLedDownButton);

    LedButtonsBox->addLayout(blueButtons);
    LedButtonsBox->addLayout(redButtons);
    LedButtonsBox->addLayout(greenButtons);

    LedButtonsBox2->addLayout(orangeButtons);
    LedButtonsBox2->addLayout(extButtons);


    layout->addLayout(buttonsBox);
    layout->addLayout(LedButtonsBox);
    layout->addLayout(LedButtonsBox2);



    connect(startButton, SIGNAL(clicked()), this, SLOT(runTest()));
    connect(quitButton,  SIGNAL(clicked()), this, SLOT(close()));
    connect(connectButton,  SIGNAL(clicked()), this, SLOT(connectBt()));

    connect(blueLedOnButton,  SIGNAL(clicked()), this, SLOT(blueLedOn()));
    connect(blueLedOffButton,  SIGNAL(clicked()), this, SLOT(blueLedOff()));
    connect(blueLedUpButton,  SIGNAL(clicked()), this, SLOT(blueLedUp()));
    connect(blueLedDownButton,  SIGNAL(clicked()), this, SLOT(blueLedDown()));

    connect(redLedOnButton,  SIGNAL(clicked()), this, SLOT(redLedOn()));
    connect(redLedOffButton,  SIGNAL(clicked()), this, SLOT(redLedOff()));
    connect(redLedUpButton,  SIGNAL(clicked()), this, SLOT(redLedUp()));
    connect(redLedDownButton,  SIGNAL(clicked()), this, SLOT(redLedDown()));

    connect(greenLedOnButton,  SIGNAL(clicked()), this, SLOT(greenLedOn()));
    connect(greenLedOffButton,  SIGNAL(clicked()), this, SLOT(greenLedOff()));
    connect(greenLedUpButton,  SIGNAL(clicked()), this, SLOT(greenLedUp()));
    connect(greenLedDownButton,  SIGNAL(clicked()), this, SLOT(greenLedDown()));

    connect(orangeLedOnButton,  SIGNAL(clicked()), this, SLOT(orangeLedOn()));
    connect(orangeLedOffButton,  SIGNAL(clicked()), this, SLOT(orangeLedOff()));
    connect(orangeLedUpButton,  SIGNAL(clicked()), this, SLOT(orangeLedUp()));
    connect(orangeLedDownButton,  SIGNAL(clicked()), this, SLOT(orangeLedDown()));


    connect(extLedOnButton,  SIGNAL(clicked()), this, SLOT(extLedOn()));
    connect(extLedOffButton,  SIGNAL(clicked()), this, SLOT(extLedOff()));
    connect(extLedUpButton,  SIGNAL(clicked()), this, SLOT(extLedUp()));
    connect(extLedDownButton,  SIGNAL(clicked()), this, SLOT(extLedDown()));




    // List paired devices
    if (rfcomm.isEnabled()) {
        layout->addWidget(new QLabel("Paired Devices:"));
        QMap<QString,QString> map=rfcomm.getPairedDevices();
        QMapIterator<QString,QString> iterator(map);
        while (iterator.hasNext()) {
            iterator.next();
            QString label=iterator.key();
            label.append("=");
            label.append(iterator.value());
            layout->addWidget(new QLabel(label));
        }
    }
    else {
        layout->addWidget(new QLabel("Bluetooth is disabled"));
    }
}

void MainWidget::runTest() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("Start Bluetooth test")));

    // Connect and communicate
    rfcomm.connect("HC-06");
    if (rfcomm.isConnected()) {
        layout->addWidget(new QLabel(QString("Connected")));

        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("oPA3,0");

            // Receive the answer
            qWarning("receiving");
            QString received=rfcomm.receiveLine(100,1000);
            QString label("Received: ");
            label.append(received);
            layout->addWidget(new QLabel(label));
        }

        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("oPA4,0");

            // Receive the answer
            qWarning("receiving");
            QString received=rfcomm.receiveLine(100,1000);
            QString label("Received: ");
            label.append(received);
            layout->addWidget(new QLabel(label));
        }

        rfcomm.disconnect();
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }

    layout->addWidget(new QLabel(QString("Test finished")));
}

void MainWidget::connectBt() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("Connecting")));

    if (!(rfcomm.isConnected())) {
    // Connect and communicate
    rfcomm.connect("HC-06");
    }

    if (rfcomm.isConnected()) {
        layout->addWidget(new QLabel(QString("Connected")));
    }
}

void MainWidget::blueLedOn() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("Blue Led On")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("f");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::blueLedOff() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("Blue Led Off")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("F");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::blueLedUp() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("Blue Led Up")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("r");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::blueLedDown() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("Blue LED Down")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("v");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::redLedOn() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("red Led On")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("d");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::redLedOff() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("red Led Off")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("D");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::redLedUp() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("red Led Up")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("e");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::redLedDown() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("red LED Down")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("c");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}


void MainWidget::greenLedOn() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("green Led On")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("s");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::greenLedOff() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("green Led Off")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("S");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::greenLedUp() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("green Led Up")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("w");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::greenLedDown() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("green LED Down")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("x");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::orangeLedOn() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("orange Led On")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("a");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::orangeLedOff() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("orange Led Off")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("A");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::orangeLedUp() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("orange Led Up")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("q");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::orangeLedDown() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("orange LED Down")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("z");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::extLedOn() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("ext Led On")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("g");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::extLedOff() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("ext Led Off")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("G");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::extLedUp() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("ext Led Up")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("t");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}

void MainWidget::extLedDown() {
    qWarning("Button clicked");
    layout->addWidget(new QLabel(QString("ext LED Down")));


    if (rfcomm.isConnected()) {
       // layout->addWidget(new QLabel(QString("Connected")));
        {
            // Send command
            qWarning("sending");
            rfcomm.sendLine("b");
        }
    }
    else {
        layout->addWidget(new QLabel(QString("Cannot connect")));
    }
}
