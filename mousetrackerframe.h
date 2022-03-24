#ifndef MOUSETRACKERFRAME_H
#define MOUSETRACKERFRAME_H

#include <QFrame>
#include <QMouseEvent>
#include <QtDebug>
#include "mainwindow.h"

class mouseTrackerFrame : public QFrame
{
public:
    mouseTrackerFrame(MainWindow* _parent = 0);
protected:
    void mouseMoveEvent(QMouseEvent *e);
private:
    MainWindow* parent;
};

#endif // MOUSETRACKERFRAME_H
