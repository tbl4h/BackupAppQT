#include "selecteddatamodel.h"

SelectedDataModel::SelectedDataModel(QObject *parent) : QStandardItemModel(parent) {
    // Ustawiamy nagłówki kolumn
    setHorizontalHeaderLabels(QStringList() << "Selected elements");
}

void SelectedDataModel::updateSelectedData(const QModelIndex &topLeft, const QModelIndex &bottomRight,  const QList<int> &roles = QList<int>()) {

    // Iterujemy przez zmienione elementy w originalModel
    for (int row = topLeft.row(); row <= bottomRight.row(); ++row) {
        QModelIndex index = topLeft.sibling(row, 0);  // Pobieramy indeks elementu w pierwszej kolumnie

        // Sprawdzamy stan checkboxa
        QVariant checkState = index.data(Qt::CheckStateRole);
        if (checkState == Qt::Checked) {
            // Jeśli element został zaznaczony, dodajemy go do selectedDataModel
            QString itemName = index.data(Qt::DisplayRole).toString();
            addSelectedItem(itemName);
        } else {
            // Jeśli checkbox został odznaczony, możemy usunąć element z selectedDataModel
            // (tutaj można zaimplementować logikę usuwania)
        }
    }
}

void SelectedDataModel::addSelectedItem(const QString &itemName) {
    // Dodajemy nowy element do modelu selectedDataModel
    QStandardItem *item = new QStandardItem(itemName);
    appendRow(item);
}
