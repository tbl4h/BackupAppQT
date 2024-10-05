#ifndef SELECTEDDATAMODEL_H
#define SELECTEDDATAMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QVector>

class SelectedDataModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit SelectedDataModel(QObject *parent = nullptr);

public slots:
    // Slot do odbierania sygnału o zmianie danych z originalModel

    // Dodaj metodę, która będzie dodawała elementy na podstawie zaznaczenia
    void updateSelectedData(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &roles);

    void addSelectedItem(const QString &itemName);
};

#endif // SELECTEDDATAMODEL_H
