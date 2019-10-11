#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAdd_Descktop_Frame_triggered()
{
    //scene = new QGraphicsScene(this);
    scene->clear();
    scene->addPixmap(QString(":/resource/frames/tablet_frame.png"));
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
}

void MainWindow::on_actionAdd_Mobile_Frame_triggered()
{
    //scene = new QGraphicsScene(this);
    scene->clear();

    scene->addPixmap(QString(":/resource/frames/phone_frame.png"));
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
}

void MainWindow::on_actionAdd_Empty_Frame_triggered()
{
    //scene = new QGraphicsScene(this);
    scene->clear();
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
}
