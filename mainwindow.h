#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "basicshapeitem.h"
#include "editorscene.h"

#include <QListWidget>
#include <QMainWindow>
#include <QFileDialog>
#include <QMimeData>
#include <QMessageBox>
#include <QPushButton>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void LoadTools();

    void SaveProject();
    void OpenProject();
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
private slots:

    void delete_selected();

    void on_ToolBoxLW_itemDoubleClicked(QListWidgetItem *item);

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionAddDescktop_Frame_triggered();

    void on_actionAdd_Mobile_Frame_triggered();

    void on_actionAdd_Empty_Frame_triggered();

private:
    Ui::MainWindow *ui;
    QListWidgetItem *item;
    EditorScene *scene;
};

#endif // MAINWINDOW_H
