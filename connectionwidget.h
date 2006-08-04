#ifndef CONNECTIONWIDGET_H
#define CONNECTIONWIDGET_H

#include <QWidget>

class QString;

class ConnectionWidget : public QWidget
{
  Q_OBJECT

public:
  ConnectionWidget(QWidget *parent = 0);

private:
  QString _host;
  QString _port;
};

#endif
