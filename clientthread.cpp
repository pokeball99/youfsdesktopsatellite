#include <QtNetwork>
#include "clientthread.h"

ClientThread::ClientThread(const QString &hostName, quint16 port, QObject *parent) 
    : QThread(parent), quit(false)
{
  this->hostName = hostName;
  this->port = port;
  start();
}

ClientThread::~ClientThread()
{
  quit = true;
  cond.wakeOne();
  wait();
}

void ClientThread::sendMessage(QString &msg)
{
  QMutexLocker locker(&mutex);
  this->msgToSend = msg;
  cond.wakeOne();
}

void ClientThread::run()
{
  const int TIMEOUT = 5000;
  QTcpSocket socket;

  QMutexLocker locker(&mutex);

  socket.connectToHost(hostName, port);
  if (! socket.waitForConnected(TIMEOUT))
  {
    emit error(socket.error(), socket.errorString());
    return;
  }

  cond.wait(&mutex);
  while (! quit)
  {
    msgToSend = msgToSend.trimmed().append("\r\n");
    socket.write(msgToSend.toUtf8());

    while (1)
    {
      if (!socket.waitForReadyRead(TIMEOUT))
      {
        emit error(socket.error(), socket.errorString());
        return;
      }

      if (socket.canReadLine())
      {
        char buf[8192];
        qint64 bytesRead = socket.readLine(buf, 8192);
        if (bytesRead == -1)
        {
          emit error(socket.error(), socket.errorString());
          return;
        }
        
        QString resp = QString::fromUtf8(buf);
        emit serverResponse(resp);
      }
    }    

    cond.wait(&mutex);
  }

}
