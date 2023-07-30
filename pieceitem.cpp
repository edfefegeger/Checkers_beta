
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QBrush>
#include "qgraphicsitem.h"
#include "qgraphicsscene.h"
#include <QGraphicsEllipseItem>

class PieceItem : public QGraphicsEllipseItem
{
public:
    PieceItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr)
        : QGraphicsEllipseItem(x, y, width, height, parent), isHighlighted(false), isActive(false), currentPosition(QPointF())
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

        // Другие действия при нажатии на шашку...
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
    bool isHighlighted;
    bool isActive;
    QPointF currentPosition;
};


