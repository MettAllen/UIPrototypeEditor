#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include "editorscene.h"
#include "basicshapeitem.h"
#include "graphics_view_zoom.h"
#include <QDebug>
#include <QStyleFactory>
#include <QApplication>
#include <QGraphicsProxyWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->WorkPlaceGV->setDragMode(QGraphicsView::RubberBandDrag);

    LoadTools();

    Graphics_view_zoom *z = new Graphics_view_zoom(ui->WorkPlaceGV);
    z->set_modifiers(Qt::NoModifier);

    ui->WorkPlaceGV->setBackgroundBrush(QPixmap(":/Resources/frames/bg_grid.gif"));

    connect(ui->ToolBoxLW, SIGNAL(itemClicked(QListWidgetItem*)),this, SLOT(onListMailItemClicked(QListWidgetItem*)));
    setAcceptDrops(true);

    scene = new EditorScene();

    ui->WorkPlaceGV->setScene(scene);

    new QShortcut(QKeySequence::Delete, this, SLOT(delete_selected()));

}

void MainWindow::LoadTools()
{
    //WigetLoad
    ui->ToolBoxLW->setDragEnabled(true);
    ui->ToolBoxLW->setAcceptDrops(true);
    ui->ToolBoxLW->setDropIndicatorShown(true);
    ui->ToolBoxLW->setDefaultDropAction(Qt::MoveAction);

    ui->ToolBoxLW->setIconSize(QSize(100,100));

    item = new QListWidgetItem(QIcon(":/Resources/items/button.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/Resources/items/label.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/Resources/items/checkbox.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/Resources/items/slider.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/Resources/items/textarea.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/Resources/items/textinput.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem(QIcon(":/Resources/items/toggle.png"),nullptr);
    ui->ToolBoxLW->addItem(item);

    item = new QListWidgetItem("Add marker");
    ui->ToolBoxLW->addItem(item);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ToolBoxLW_itemDoubleClicked(QListWidgetItem *item)
{

        if (ui->ToolBoxLW->item(0) == item)
        {
            BasicShapesItem *item = new BasicShapesItem(12,12,100,30,BasicShapesItem::ITEM_TOOL,scene);
            item->setPixmap(":/Resources/items/button.png");
        }

        if (ui->ToolBoxLW->item(1) == item)
        {
            BasicShapesItem *item = new BasicShapesItem(12,12,100,30,BasicShapesItem::ITEM_TOOL,scene);
            item->setPixmap(":/Resources/items/label.png");
        }

        if (ui->ToolBoxLW->item(2) == item)
        {
            BasicShapesItem *item = new BasicShapesItem(12,12,100,30,BasicShapesItem::ITEM_TOOL,scene);
            item->setPixmap(":/Resources/items/checkbox.png");
        }

        if (ui->ToolBoxLW->item(3) == item)
        {
            BasicShapesItem *item = new BasicShapesItem(12,12,100,30,BasicShapesItem::ITEM_TOOL,scene);
            item->setPixmap(":/Resources/items/slider.png");
        }

        if (ui->ToolBoxLW->item(4) == item)
        {
            BasicShapesItem *item = new BasicShapesItem(12,12,100,30,BasicShapesItem::ITEM_TOOL,scene);
            item->setPixmap(":/Resources/items/textarea.png");
        }

        if (ui->ToolBoxLW->item(5) == item)
        {
            BasicShapesItem *item = new BasicShapesItem(12,12,100,30,BasicShapesItem::ITEM_TOOL,scene);
            item->setPixmap(":/Resources/items/textinput.png");

        }

        if (ui->ToolBoxLW->item(6) == item)
        {
            BasicShapesItem *item = new BasicShapesItem(12,12,100,30,BasicShapesItem::ITEM_TOOL,scene);
            item->setPixmap(":/Resources/items/toggle.png");
        }

        if (ui->ToolBoxLW->item(7) == item)
        {
            /// до реализовать жесткие размеры

            auto *mark_color = new QGraphicsRectItem(0, 0, 100, 40);
            auto *mark_text =new QGraphicsTextItem(mark_color);

            mark_text->setTextWidth(100);
            mark_text->setPlainText("Add text");

            scene->addItem(mark_color);
            mark_text->setTextInteractionFlags(Qt::TextEditorInteraction);
            mark_color->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
            mark_color->setBrush(Qt::green);

//            scene->addText("text");
//            scene->addItem(field);

//                        auto *proxy = new QGraphicsProxyWidget(item);
//                        auto *btn = new QLabel("Mark1");

//                        btn->setGeometry(0, 0, 77, 26);

//                        item->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);
//                        item->setBrush(Qt::darkYellow);

//                        proxy->setWidget(btn);
//                        proxy->setPos(0, 15);
//                        proxy->setFlags(QGraphicsItem::ItemIsMovable|QGraphicsItem::ItemIsSelectable);

//                        scene->addItem(item);

//                        QGraphicsTextItem * field = scene->addText("text");
//                        field->setTextInteractionFlags(Qt::TextEditorInteraction);
//                        scene->addItem(field);
//                        BasicShapesItem *item = new BasicShapesItem(0,0,100,30,BasicShapesItem::ITEM_TOOL,scene);


//                        QGraphicsTextItem * field = scene->addText("text");
//                        field->setTextInteractionFlags(Qt::TextEditorInteraction);
//                        scene->addItem(field);
        }
}


void MainWindow::SaveProject()
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

void MainWindow::OpenProject()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());
    BasicShapesItem *item = new BasicShapesItem(12,12,100,100,BasicShapesItem::ITEM_TOOL,scene);
    item->setPixmap(fileName);
    ui->WorkPlaceGV->setScene(scene);
}

void MainWindow::delete_selected()
{
  foreach(QGraphicsItem *item, scene->selectedItems())
  {
    delete item;
  }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
        event->acceptProposedAction();

//    if ( ui->WorkPlaceGV->items().empty())
//    {
//        QMessageBox TrueInputMsgBox;
//        TrueInputMsgBox.setWindowTitle("Data entry error");
//        TrueInputMsgBox.setText("Select one of the frames for the application.This can be done in the menu at the top, the item <Add Frame>.");
//        QPushButton *OKButton = TrueInputMsgBox.addButton(QMessageBox::Ok);
//        TrueInputMsgBox.exec();
//    }
//    else
//    {
//        if (event->mimeData()->hasUrls())
//        {
//            event->acceptProposedAction();
//        }
//    }
}

void MainWindow::dropEvent(QDropEvent *event) {

    foreach(QUrl url, event->mimeData()->urls())
    {
      BasicShapesItem *item = new BasicShapesItem(12,12,100,100,BasicShapesItem::ITEM_TOOL,scene);
      item->setPixmap(url.toLocalFile());
      item->setPos(ui->WorkPlaceGV->mapToScene(ui->WorkPlaceGV->viewport()->mapFrom(this, event->pos())));
    }

}

void MainWindow::on_actionOpen_triggered()
{
    OpenProject();
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
        SaveProject();
    }
}

void MainWindow::on_actionAddDescktop_Frame_triggered()
{
    scene->clear();
    scene->addPixmap(QString(":/Resources/frames/tablet_frame.png"));
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
    setAcceptDrops(true);
}

void MainWindow::on_actionAdd_Mobile_Frame_triggered()
{
    scene = new EditorScene();
    scene->clear();
    scene->addPixmap(QString(":/Resources/frames/phone_frame.png"));
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
    setAcceptDrops(true);
}

void MainWindow::on_actionAdd_Empty_Frame_triggered()
{
    scene->clear();
    scene->addPixmap((QPixmap(":/Resources/frames/bg_grid.gif")));
    ui->WorkPlaceGV->setScene(scene);
    ui->WorkPlaceGV->show();
    setAcceptDrops(true);
}

