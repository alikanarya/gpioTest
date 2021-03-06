#include <QCoreApplication>
#include <QtNetwork>
#include <iostream>

#include "globals.h"

using namespace std;

QSettings *settings;
Server *serverx;
Client *clientx;
gpioThread *gpioX;

const int aInpSize = 7;
const int aOutSize = 4;

//bool readSettings(){}

int main(int argc, char *argv[]){

    QCoreApplication app(argc, argv);

    serverx = new Server();
    clientx = new Client();
    gpioX = new gpioThread();

    settings = new QSettings(INIFILENAME, QSettings::IniFormat);

    if (QFile::exists(INIFILENAME)){

        clientx->clientAddress = settings->value("clientAddress0", _CLIENT_ADR).toString();
        cout << clientx->clientAddress.toUtf8().constData() << endl; //return true;

    } else {
        qDebug() << "ini file not found" << endl; //return false;
    }

    cout << gpioX->PWMCHIP0_PATH.toUtf8().constData() << " chip:" << gpioX->pwmchip0_No.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP1_PATH.toUtf8().constData() << " chip:" << gpioX->pwmchip1_No.toUtf8().constData() << endl;

    cout << gpioX->PWMCHIP0_EXPORT.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP0_P0_ENABLE.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP0_P0_PERIOD.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP0_P0_DUTYCYCLE.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP0_P1_ENABLE.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP0_P1_PERIOD.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP0_P1_DUTYCYCLE.toUtf8().constData() << endl;

    cout << gpioX->PWMCHIP1_EXPORT.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP1_P0_ENABLE.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP1_P0_PERIOD.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP1_P0_DUTYCYCLE.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP1_P1_ENABLE.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP1_P1_PERIOD.toUtf8().constData() << endl;
    cout << gpioX->PWMCHIP1_P1_DUTYCYCLE.toUtf8().constData() << endl;


    //gpioX->pwmPeriod(0,0,1000000);
    //gpioX->pwmDutyCycle(0,0,500000);

    QObject::connect(serverx, SIGNAL(readFinished()), gpioX, SLOT(enableWrite()));

    // 1sec timer
    timerSec = new QTimer();
    QObject::connect(timerSec, SIGNAL(timeout()), gpioX, SLOT(gpioOps()));
    timerSec->start(1000);


    return app.exec();
}

