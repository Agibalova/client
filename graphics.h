#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QPainter>
namespace Ui {
class graphics;
}

class graphics : public QWidget
{
    Q_OBJECT

public:
    explicit graphics(QWidget *parent = nullptr);
    ~graphics();
public slots:
    bool reciveTransferData(int id,int x, int y, int z,int time);

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    Ui::graphics *ui;
    int X;
    int Y;
};

#endif // GRAPHICS_H
