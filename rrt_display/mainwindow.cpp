#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupQuadraticDemo(ui->customPlot);

    setWindowTitle("RRT Search: ");
    statusBar()->clearMessage();
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// See http://www.workslikeclockwork.com/index.php/components/qt-plotting-widget/comment-page-14/
void MainWindow::setupQuadraticDemo(QCustomPlot *customPlot)
{
  demoName = "Quadratic Demo";
  // generate some data:
  QVector<double> x(101), y(101); // initialize with entries 0..100
  for (int i=0; i<101; ++i)
  {
    x[i] = i/50.0 - 1; // x goes from -1 to 1
    if (i < 50) {
      y[i] = x[i]*x[i];  // let's plot a quadratic function
    } else {
      y[i] = 0.5;
    }


  }
  // create graph and assign data to it:
  customPlot->addGraph();
  customPlot->graph(0)->setData(x, y);
  // give the axes some labels:
  customPlot->xAxis->setLabel("x");
  customPlot->yAxis->setLabel("y");
  // set axes ranges, so we see all data:
  customPlot->xAxis->setRange(-1, 1);
  customPlot->yAxis->setRange(0, 1);
}
