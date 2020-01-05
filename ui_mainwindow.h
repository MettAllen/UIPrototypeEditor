/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave_As;
    QAction *actionAddDescktop_Frame;
    QAction *actionAdd_Mobile_Frame;
    QAction *actionAdd_Empty_Frame;
    QAction *actionSave_SVG;
    QAction *actionOpen_SVG;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *ToolBoxLW;
    QGraphicsView *WorkPlaceGV;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAdd_Frame;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(913, 730);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/icon/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/icon/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon1);
        actionAddDescktop_Frame = new QAction(MainWindow);
        actionAddDescktop_Frame->setObjectName(QString::fromUtf8("actionAddDescktop_Frame"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Resources/frames/tablet_frame.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddDescktop_Frame->setIcon(icon2);
        actionAdd_Mobile_Frame = new QAction(MainWindow);
        actionAdd_Mobile_Frame->setObjectName(QString::fromUtf8("actionAdd_Mobile_Frame"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Resources/frames/phone_frame.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Mobile_Frame->setIcon(icon3);
        actionAdd_Empty_Frame = new QAction(MainWindow);
        actionAdd_Empty_Frame->setObjectName(QString::fromUtf8("actionAdd_Empty_Frame"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Resources/frames/bg_grid.gif"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Empty_Frame->setIcon(icon4);
        actionSave_SVG = new QAction(MainWindow);
        actionSave_SVG->setObjectName(QString::fromUtf8("actionSave_SVG"));
        actionOpen_SVG = new QAction(MainWindow);
        actionOpen_SVG->setObjectName(QString::fromUtf8("actionOpen_SVG"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ToolBoxLW = new QListWidget(centralWidget);
        ToolBoxLW->setObjectName(QString::fromUtf8("ToolBoxLW"));
        ToolBoxLW->setMaximumSize(QSize(130, 16777215));

        horizontalLayout->addWidget(ToolBoxLW);

        WorkPlaceGV = new QGraphicsView(centralWidget);
        WorkPlaceGV->setObjectName(QString::fromUtf8("WorkPlaceGV"));
        WorkPlaceGV->setMinimumSize(QSize(759, 652));
        QBrush brush(QColor(154, 153, 153, 255));
        brush.setStyle(Qt::SolidPattern);
        WorkPlaceGV->setBackgroundBrush(brush);

        horizontalLayout->addWidget(WorkPlaceGV);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 913, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuAdd_Frame = new QMenu(menuBar);
        menuAdd_Frame->setObjectName(QString::fromUtf8("menuAdd_Frame"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAdd_Frame->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionSave_SVG);
        menuFile->addAction(actionOpen_SVG);
        menuAdd_Frame->addAction(actionAddDescktop_Frame);
        menuAdd_Frame->addAction(actionAdd_Mobile_Frame);
        menuAdd_Frame->addAction(actionAdd_Empty_Frame);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionAddDescktop_Frame->setText(QApplication::translate("MainWindow", "Add Descktop Frame", nullptr));
        actionAdd_Mobile_Frame->setText(QApplication::translate("MainWindow", "Add Mobile Frame", nullptr));
        actionAdd_Empty_Frame->setText(QApplication::translate("MainWindow", "Add Empty Frame", nullptr));
        actionSave_SVG->setText(QApplication::translate("MainWindow", "Save SVG", nullptr));
        actionOpen_SVG->setText(QApplication::translate("MainWindow", "Open SVG", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuAdd_Frame->setTitle(QApplication::translate("MainWindow", "Add Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
