#include "monrect.h"
#include <QPen>

MonRect::MonRect(QColor color)
{
    setRect(0, 0, 10, 10);
    setPen(QPen(Qt::black));
    setBrush(QBrush(color));
}
