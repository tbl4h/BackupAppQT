#ifndef FILESHIERARCHYMODEL_H
#define FILESHIERARCHYMODEL_H

#include <QObject>
#include <QFileSystemModel>


class FilesHierarchyModel : public QFileSystemModel
{
    Q_OBJECT
public:
    explicit FilesHierarchyModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
signals:
private:
    QMap<QPersistentModelIndex, Qt::CheckState> checkStates;
    void updateChildCheckStates(const QModelIndex &parent, Qt::CheckState state);
};

#endif // FILESHIERARCHYMODEL_H
