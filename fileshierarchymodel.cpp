#include "fileshierarchymodel.h"
#include <QDir>

FilesHierarchyModel::FilesHierarchyModel(QObject *parent) : QFileSystemModel(parent) {
    setRootPath(QDir::rootPath());
}

QVariant FilesHierarchyModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::CheckStateRole && index.column() == 0) {
        // Sprawdzamy, czy dla tego elementu mamy stan checkboxa w mapie
        if (checkStates.contains(index)) {
            return checkStates.value(index);  // Zwracamy stan checkboxa z mapy
        } else {
            return Qt::Unchecked;  // Domyślnie checkbox jest odznaczony
        }
    }

    if (role == Qt::DisplayRole) {
        return QFileSystemModel::data(index, role);  // Zwraca nazwę pliku/folderu
    }
    return QFileSystemModel::data(index, role);  // Standardowa obsługa dla innych ról
}

Qt::ItemFlags FilesHierarchyModel::flags(const QModelIndex &index) const {
    if (index.isValid() && index.column() == 0) {
        return QFileSystemModel::flags(index) | Qt::ItemIsUserCheckable;
    }
    return QFileSystemModel::flags(index);

}

bool FilesHierarchyModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::CheckStateRole && index.column() == 0) {
        // Ustawiamy nowy stan checkboxa w mapie
        checkStates[index] = static_cast<Qt::CheckState>(value.toInt());
        emit dataChanged(index, index);

        // Rekursywne zaznaczanie/odznaczanie dzieci
        updateChildCheckStates(index, static_cast<Qt::CheckState>(value.toInt()));
        return true;
    }

    // Standardowe zachowanie dla innych ról
    return QFileSystemModel::setData(index, value, role);
}

void FilesHierarchyModel::updateChildCheckStates(const QModelIndex &parent, Qt::CheckState state) {
    int rowCount = this->rowCount(parent);
    for (int row = 0; row < rowCount; ++row) {
        QModelIndex childIndex = this->index(row, 0, parent);
        checkStates[childIndex] = state;  // Ustawiamy stan dla dziecka
        emit dataChanged(childIndex, childIndex);  // Emitujemy sygnał o zmianie stanu

        // Rekursywne wywołanie dla dzieci
        if (this->hasIndex(row, 0, childIndex)) {
            updateChildCheckStates(childIndex, state);
        }
    }
}
