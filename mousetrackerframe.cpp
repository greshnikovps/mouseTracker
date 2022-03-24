#include "mousetrackerframe.h"
#include "defines.h"

mouseTrackerFrame::mouseTrackerFrame(MainWindow* _parent) :
    QFrame(_parent),
    parent(_parent)
{
}

void mouseTrackerFrame::mouseMoveEvent(QMouseEvent *e)
{
    parent->setMouseCoords({e->x(), e->y()});
}
