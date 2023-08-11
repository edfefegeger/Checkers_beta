#ifndef PIECEITEM_H
#define PIECEITEM_H

#include "qgraphicsscene.h"
#include <QGraphicsEllipseItem>
#include <QBrush>

class PieceItem : public QGraphicsEllipseItem
{
public:
    PieceItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr);

    void setActive(bool active);
    bool isActivePiece() const;
    void setCurrentPosition(const QPointF& position);
    QPointF getCurrentPosition() const;

protected:
    void showPossibleMove();
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

private:
    bool isActive;
    QPointF currentPosition;
};

#endif // PIECEITEM_H
