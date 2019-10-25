/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
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
        MainWindow->resize(913, 729);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionAddDescktop_Frame = new QAction(MainWindow);
        actionAddDescktop_Frame->setObjectName(QString::fromUtf8("actionAddDescktop_Frame"));
        actionAdd_Mobile_Frame = new QAction(MainWindow);
        actionAdd_Mobile_Frame->setObjectName(QString::fromUtf8("actionAdd_Mobile_Frame"));
        actionAdd_Empty_Frame = new QAction(MainWindow);
        actionAdd_Empty_Frame->setObjectName(QString::fromUtf8("actionAdd_Empty_Frame"));
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
        WorkPlaceGV->setObjectName(QString::fromUtf8("graphicsView"));
        WorkPlaceGV->setMinimumSize(QSize(759, 652));
        WorkPlaceGV->setAcceptDrops(false);

        horizontalLayout->addWidget(WorkPlaceGV);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 913, 20));
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
        menuAdd_Frame->addAction(actionAddDescktop_Frame);
        menuAdd_Frame->addAction(actionAdd_Mobile_Frame);
        menuAdd_Frame->addAction(actionAdd_Empty_Frame);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionAddDescktop_Frame->setText(QCoreApplication::translate("MainWindow", "Add Descktop Frame", nullptr));
        actionAdd_Mobile_Frame->setText(QCoreApplication::translate("MainWindow", "Add Mobile Frame", nullptr));
        actionAdd_Empty_Frame->setText(QCoreApplication::translate("MainWindow", "Add Empty Frame", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuAdd_Frame->setTitle(QCoreApplication::translate("MainWindow", "Add Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
