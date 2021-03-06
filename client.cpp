#include "client.h"

#include <iostream>
#include <unistd.h>

using namespace std;

extern QString MSG_CLIENT_CONN;

Client::Client(QObject* parent): QObject(parent){

    host.setAddress(clientAddress);
    connect(&clientSocket, SIGNAL(connected()), this, SLOT(connectionEstablished()));
}

Client::~Client(){

    clientSocket.close();
}

void Client::start(){

    host.setAddress(clientAddress);
    clientSocket.connectToHost(host, clientPort);
    //clientSocket.waitForConnected(5000);
}

void Client::startTransfer(){

    if (clientSocket.state() == QAbstractSocket::ConnectedState)
        //client.write(MSG_HI.toLatin1().constData(), 9);
        clientSocket.write(datagram);
}

void Client::connectionEstablished(){

    connected = true;
    //emit clientConnected();
    cout << MSG_CLIENT_CONN.toUtf8().constData() << endl;
}
