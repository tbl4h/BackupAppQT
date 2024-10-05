#include "mainwindow.h"
#include "selecteddatamodel.h"
#include "fileshierarchymodel.h"
#include <QTreeView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QObject>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
}
MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::setupUi() {
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    originalView = new QTreeView(this);
    originalModel = new FilesHierarchyModel(this);
    originalView->setModel(originalModel);

    mainLayout->addWidget(originalView);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    selectedDataView = new QTreeView(this);
    selectedDataModel = new SelectedDataModel(this);
    selectedDataView->setModel(selectedDataModel);
    mainLayout->addWidget(selectedDataView);


    connect(originalModel,
            &QFileSystemModel::dataChanged,
            selectedDataModel,
            &SelectedDataModel::updateSelectedData);
}
