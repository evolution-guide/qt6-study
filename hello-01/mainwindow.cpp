#include "mainwindow.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    resize(800,600);

    QWidget * widget = new QWidget();
    setCentralWidget(widget);

    QHBoxLayout *layout = new QHBoxLayout();

    QPushButton * btn1 = new QPushButton("按钮一");
    btn1->setFixedSize(90,27);
    layout->addWidget(btn1);

    QPushButton * btn2 = new QPushButton();
    btn2->setFixedSize(90,27);
    btn2->setIcon(QPixmap(":/image/add.png"));
    layout->addWidget(btn2);

    centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
}

