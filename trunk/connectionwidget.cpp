
#include <QString>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>

#include "connectionwidget.h"

ConnectionWidget::ConnectionWidget(QWidget *parent) : QWidget(parent)
{
  _host = "";
  _port = "";

  QLabel *hostLabel = new QLabel(tr("Host:"));
  QLabel *portLabel = new QLabel(tr("Port:"));

  QLineEdit *hostLineEdit = new QLineEdit;
  QLineEdit *portLineEdit = new QLineEdit;

  QGroupBox *connGroupBox = new QGroupBox(tr("Connection Details"));

  QGridLayout *grid = new QGridLayout;
  grid->addWidget(hostLabel, 0, 0);
  grid->addWidget(portLabel, 1, 0);
  grid->addWidget(hostLineEdit, 0, 1);
  grid->addWidget(portLineEdit, 1, 1);
  connGroupBox->setLayout(grid);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(connGroupBox);
  setLayout(layout);  
}