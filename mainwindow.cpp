#include "graphics_view_zoom.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //scene = new QGraphicsScene(this);

    Graphics_view_zoom *z = new Graphics_view_zoom(ui->WorkPlaceGV);
    z->set_modifiers(Qt::NoModifier);

    LoadTools();

    connect(ui->ToolBoxLW, SIGNAL(itemClicked(QListWidgetItem*)),
            this, SLOT(onListMailItemClicked(QListWidgetItem*)));
    setAcceptDrops(true);

    ui->WorkPlaceGV->setBackgroundBrush(QPixmap(":/resource/frames/bg_grid.gif"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadTools()
{
    //WigetLoad
    ui->ToolBoxLW->setDragEnabled(true);
    ui->ToolBoxLW->setAcceptDrops(true);
    ui->ToolBoxLW->setDropIndicatorShown(true);
    ui->ToolBoxLW->setDefaultDropAction(Qt::MoveAction);

    ui->ToolBoxLW->setIconSize(QSize(100,100));

    item = new QListWidgetItem(QIcon(":/resource/items/button.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/resource/items/label.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/resource/items/progress.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/resource/items/slider.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/resource/items/textarea.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/resource/items/textinput.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/resource/items/toggle.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

}


void MainWindow::on_actionAdd_Descktop_Frame_triggered()
{
    scene = new QGraphicsScene(this);
    scene->clear();
    //ui->WorkPlaceGV->mapToScene(ui->WorkPlaceGV->viewport()->rect().center());
    scene->addPixmap(QString(":/resource/frames/tablet_frame.png"));
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
    setAcceptDrops(true);
}

void MainWindow::on_actionAdd_Mobile_Frame_triggered()
{
    scene = new QGraphicsScene(this);
    scene->clear();
    ui->WorkPlaceGV->mapToScene(ui->WorkPlaceGV->viewport()->rect().center());
    scene->addPixmap(QString(":/resource/frames/phone_frame.png"));
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
    setAcceptDrops(true);
}

void MainWindow::on_actionAdd_Empty_Frame_triggered()
{
    scene = new QGraphicsScene(this);
    scene->clear();
    scene->addPixmap((QPixmap(":/resource/frames/bg_grid.gif")));
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
    setAcceptDrops(true);
}

void MainWindow::on_ToolBoxLW_itemDoubleClicked(QListWidgetItem *item)
{
    if ( ui->WorkPlaceGV->items().empty())
    {
        QMessageBox TrueInputMsgBox;
        TrueInputMsgBox.setWindowTitle("Data entry error");
        TrueInputMsgBox.setText("Select one of the frames for the application.This can be done in the menu at the top, the item <Add Frame>.");
        QPushButton *OKButton = TrueInputMsgBox.addButton(QMessageBox::Ok);
        TrueInputMsgBox.exec();
    }
    else
    {
        if (ui->ToolBoxLW->item(0) == item) {

            QGraphicsPixmapItem* item = scene->addPixmap(QPixmap(":/resource/items/button.png"));
            item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        }

        if (ui->ToolBoxLW->item(1) == item) {

            QGraphicsPixmapItem* item = scene->addPixmap(QPixmap(":/resource/items/label.png"));
            item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        }

        if (ui->ToolBoxLW->item(2) == item) {

            QGraphicsPixmapItem* item = scene->addPixmap(QPixmap(":/resource/items/progress.png"));
            item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        }

        if (ui->ToolBoxLW->item(3) == item) {

            QGraphicsPixmapItem* item = scene->addPixmap(QPixmap(":/resource/items/slider.png"));
            item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        }

        if (ui->ToolBoxLW->item(4) == item) {

            QGraphicsPixmapItem* item = scene->addPixmap(QPixmap(":/resource/items/textarea.png"));
            item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        }

        if (ui->ToolBoxLW->item(5) == item) {

            QGraphicsPixmapItem* item = scene->addPixmap(QPixmap(":/resource/items/textinput.png"));
            item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        }

        if (ui->ToolBoxLW->item(6) == item) {

            QGraphicsPixmapItem* item = scene->addPixmap(QPixmap(":/resource/items/toggle.png"));
            item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        }
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {

    event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event) {

}

void MainWindow::on_actionSave_As_triggered()
{
    if ( scene->items().empty())
    {
        QMessageBox TrueInputMsgBox;
        TrueInputMsgBox.setWindowTitle("Data entry error");
        TrueInputMsgBox.setText("Please check that your project is not empty.");
        QPushButton *OKButton = TrueInputMsgBox.addButton(QMessageBox::Ok);
        TrueInputMsgBox.exec();

    }
    else
    {
        QMessageBox SaveQstnMsgBox;
        SaveQstnMsgBox.setWindowTitle("Save project");
        SaveQstnMsgBox.setText("Finish your project?");
        QPushButton *YESButton = SaveQstnMsgBox.addButton(QMessageBox::Yes);
        QPushButton *NOButton = SaveQstnMsgBox.addButton(QMessageBox::No);

        SaveQstnMsgBox.exec();

        if (SaveQstnMsgBox.clickedButton()==YESButton)
        {
            QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                                                            tr("PNG Files (*.png);;JPG Files (*.jpg)"));
            if (fileName != "")
            {
                QFile file(fileName);
                QImage image(ui->WorkPlaceGV->width(),ui->WorkPlaceGV->height(), QImage::Format_ARGB32_Premultiplied);
                QPainter painter(&image);
                ui->WorkPlaceGV->render(&painter);
                image.save(fileName);
            }
            else
            {
                if (SaveQstnMsgBox.clickedButton()==NOButton)
                {
                    SaveQstnMsgBox.close();
                }
            }
        }
    }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());
    scene->addPixmap(QPixmap(fileName));
    ui->WorkPlaceGV->setScene(scene);
}
