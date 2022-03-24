#ifndef SETSAVEDIRPATH_H
#define SETSAVEDIRPATH_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class setSaveDirPath;
}

class setSaveDirPath : public QDialog
{
    Q_OBJECT

public:
    explicit setSaveDirPath(MainWindow* _parent = nullptr);
    ~setSaveDirPath();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::setSaveDirPath *ui;
    MainWindow* parent;
};

#endif // SETSAVEDIRPATH_H
