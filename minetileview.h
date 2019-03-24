#ifndef MINETILEVIEW_H
#define MINETILEVIEW_H

#include <QGraphicsRectItem>


enum TileStatus{
    hidden, flagged, open
};

class MineTileView : public QGraphicsRectItem
{
private:
    TileStatus status = hidden;
public:
    MineTileView();
};

#endif // MINETILEVIEW_H
