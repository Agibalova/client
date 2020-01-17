#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "table.h"
#include "graphics.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    bool transferNewData(int id, int x, int y, int z,int time);

public slots:
    bool clicGraphic();
    bool clicTable();
    bool reciveNewData(int id,int x,int z,int,int);
private:
    Table m_table;
    graphics m_graphics;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
