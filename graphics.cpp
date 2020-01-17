#include "graphics.h"
#include "ui_graphics.h"
#include <QDebug>
graphics::graphics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphics)
{
    ui->setupUi(this);

}
graphics::~graphics()
{
    delete ui;
}

bool graphics::reciveTransferData(int id, int x, int y,int z, int time)
{
    qDebug()<<"GraphicreciveTransferData" <<"id= "<<id<<"x = "<<x <<" y= "<< y << " z= " << z;
    if (id % 2 != 0) {
        X=x;
        Y=y;
        repaint();
    }
    return true;

}

void graphics::paintEvent(QPaintEvent *event)
    {

    qDebug()<<"paintEvent" << " "<<width()<<height();
    QPainter p(this);

    QPen pen;
    int w = width();
    int h = height();
    X=w/2+X;
    Y=h/2-Y;
    pen.setColor(Qt::black);
    p.setPen(pen);
    p.drawLine(0,h/2,w,h/2);
    p.drawLine(w,h/2,w-10,h/2-5);
    p.drawLine(w,h/2,w-10,h/2+5);
    p.drawLine(w/2,0,w/2,h);
    p.drawLine(w/2,0,w/2-5,10);
    p.drawLine(w/2,0,w/2+5,10);
for (int i = w/2; i>0;i=i-10)
    p.drawLine(i-10,h/2-5,i-10,h/2+5);
for (int i = w/2; i<w-20; i=i+10)
    p.drawLine(i+10,h/2-5,i+10,h/2+5);


for (int i = h/2; i>21;i=i-10)
    p.drawLine(w/2-5,i-10,w/2+5,i-10);
for (int i = h/2; i<h; i=i+10)
    p.drawLine(w/2-5,i+10,w/2+5,i+10);


    pen.setColor(Qt::red);
    p.setPen(pen);
    p.drawPoint(X,Y);
    pen.setColor(Qt::gray);
    p.setPen(pen);
    p.drawLine(X+10, Y, X+30, Y);
    p.drawLine(X+30, Y, X+20, Y+15);
    p.drawLine(X+10, Y, X+20, Y+15);
}

