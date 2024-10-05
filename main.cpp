#include "mainwindow.h"

#include <QApplication>
#include <QTreeView>
#include <QVBoxLayout>
#include <QWidget>
#include "fileshierarchymodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(800, 600);
    w.show();


    return a.exec();
}
