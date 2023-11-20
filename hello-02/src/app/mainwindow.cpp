#include "mainwindow.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);
    setWindowTitle("多目录构建与动态库");
    QWidget * widget = new QWidget();
    setCentralWidget(widget);

    QHBoxLayout *layout = new QHBoxLayout();

    QPushButton * btn1 = new QPushButton("按钮一");
    btn1->setFixedSize(90,27);
    layout->addWidget(btn1);
    connect(btn1,&QPushButton::clicked,[](){
//        Person * p = new Person();
//        qDebug() << p->sayHello();
        QMessageBox msgBox;
        msgBox.setText("使用动态库");
//        msgBox.setInformativeText(p->sayHello());
        msgBox.setInformativeText("hello world");
        msgBox.exec();
    });

    QPushButton * btn2 = new QPushButton();
    btn2->setFixedSize(90,27);
    btn2->setIcon(QPixmap(":/image/add.png"));
    connect(btn2,&QPushButton::clicked,[](){
        qDebug() << "你好世界";
        QMessageBox msgBox;
        msgBox.setText("没有动态库");
        msgBox.setInformativeText("你好世界");
        msgBox.exec();
    });
    layout->addWidget(btn2);


    centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
}

