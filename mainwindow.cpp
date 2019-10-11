#include "graphics_view_zoom.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
    setAcceptDrops(true);
}

void MainWindow::on_ToolBoxLW_itemDoubleClicked(QListWidgetItem *item)
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

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {

    event->acceptProposedAction();
}


void MainWindow::dropEvent(QDropEvent *event) {

}
