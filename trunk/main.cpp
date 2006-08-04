#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

#include "connectionwidget.h"


class MainWindow : public QWidget
{
public:
  MainWindow(QWidget *parent = 0);
};

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
  ConnectionWidget *connWidget = new ConnectionWidget;

  QPushButton *quitBtn = new QPushButton(tr("Quit"));
  connect(quitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(connWidget);
  layout->addWidget(quitBtn);
  setLayout(layout);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  MainWindow mw;
  mw.resize(200, 200);
  mw.show();

  return app.exec();
}
