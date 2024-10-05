#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "fileshierarchymodel.h"


QT_BEGIN_NAMESPACE

class QTreeView;

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //Ui::MainWindow *ui;
    QTreeView *originalView;
    FilesHierarchyModel *originalModel;
    QTreeView *selectedDataView;
    QStandardItemModel *selectedDataModel;
    void setupUi();
};
#endif // MAINWINDOW_H
