#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class Table;
}

class Table : public QWidget
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();
public slots:
    bool reciveTransferData(int id,int x, int y, int z,int time);

private:
    Ui::Table *ui;
    QStandardItemModel *m_model;
};

#endif // TABLE_H
