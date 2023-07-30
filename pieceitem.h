#ifndef PIECEITEM_H
#define PIECEITEM_H

#include "qgraphicsscene.h"
#include <QGraphicsEllipseItem>
#include <QBrush>

class PieceItem : public QGraphicsEllipseItem
{
public:
    PieceItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr)
        : QGraphicsEllipseItem(x, y, width, height, parent), isActive(false), currentPosition(QPointF())
    {
        setBrush(Qt::black);
        setAcceptHoverEvents(true);
    }

    void setActive(bool active)
    {
        isActive = active;
    }

    bool isActivePiece() const
    {
        return isActive;
    }

    void setCurrentPosition(const QPointF& position)
    {
        currentPosition = position;
    }

    void showPossibleMove()
    {
        // Удаляем все предыдущие отображения возможных ходов
        QList<QGraphicsItem*> items = scene()->items();
        for (QGraphicsItem* item : items)
        {
            if (item->type() == QGraphicsEllipseItem::Type)
            {
                scene()->removeItem(item);
                delete item;
            }
        }

        // Получаем текущую позицию шашки
        qreal x = rect().x();
        qreal y = rect().y();
        qreal width = rect().width();
        qreal height = rect().height();

        // Вычисляем возможные ходы на поле
        qreal moveX1 = x - width; // Влево
        qreal moveX2 = x + width; // Вправо
        qreal moveY1 = y - height; // Вверх
        qreal moveY2 = y + height; // Вниз

        // Создаем отображения возможных ходов на поле
        QGraphicsEllipseItem* possibleMoveItem1 = new QGraphicsEllipseItem(moveX1, moveY1, width, height);
        possibleMoveItem1->setBrush(Qt::blue);
        scene()->addItem(possibleMoveItem1);

        QGraphicsEllipseItem* possibleMoveItem2 = new QGraphicsEllipseItem(moveX2, moveY2, width, height);
        possibleMoveItem2->setBrush(Qt::blue);
        scene()->addItem(possibleMoveItem2);
    }

    QPointF getCurrentPosition() const
    {
        return currentPosition;
    }

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        Q_UNUSED(event);

        // Показать возможные ходы для данной шашки
        showPossibleMove();
    }


    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override
    {
        Q_UNUSED(event);
        setBrush(Qt::red); // Изменить цвет подсветки при наведении
    }

    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override
    {
        Q_UNUSED(event);
        setBrush(Qt::black); // Вернуть исходный цвет при уходе курсора
    }

private:
    bool isActive;
    QPointF currentPosition;
};

#endif // PIECEITEM_H
