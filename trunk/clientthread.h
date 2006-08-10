#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class ClientThread : public QThread
{
    Q_OBJECT

public:
    ClientThread(const QString &hostName, quint16 port, QObject *parent=0);
    ~ClientThread();

    void sendMessage(QString &msg);
    void run();

signals:
    void serverResponse(const QString &resp);
    void error(int socketError, const QString &message);

private:
    QString hostName;
    quint16 port;

    QString msgToSend;

    QMutex mutex;
    QWaitCondition cond;
    bool quit;
};

#endif
