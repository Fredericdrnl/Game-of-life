#include "customwidget.h"
#include <QPainter>

customWidget::customWidget(QWidget *parent) : QWidget(parent)
{

}

void customWidget::paintEvent(QPaintEvent *event){
    QPainter p(this);

    p.setPen(Qt::black);
    p.setBrush(Qt::purple);
    p.drawRoundedRect(0, 0, this->width(), this->height(), 20, 20);
    p.drawText(20, 20, "ToutApprendre");
}
