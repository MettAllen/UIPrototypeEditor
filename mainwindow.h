#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QListWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void LoadTools();
private slots:
    void on_actionAdd_Descktop_Frame_triggered();

    void on_actionAdd_Mobile_Frame_triggered();

    void on_actionAdd_Empty_Frame_triggered();

    void on_ToolBoxLW_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QListWidgetItem *item;
};
#endif // MAINWINDOW_H
