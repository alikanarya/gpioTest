#ifndef GLOBALS_H
#define GLOBALS_H

#include "server.h"
#include "client.h"
#include "gpiothread.h"

#define INIFILENAME         "settings.ini"
#define _CLIENT_ADR         "localhost"

QString MSG_SERVER_INIT = "Server is listening...";
QString MSG_CLIENT_CONN = "Client connected";
QString MSG_HI = "Hi by BBB";

QTimer *timerSec;


#endif // GLOBALS_H
