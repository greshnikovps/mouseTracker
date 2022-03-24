#ifndef TIMEINTERVALSETDIALOG_H
#define TIMEINTERVALSETDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class timeIntervalSetDialog;
}

class timeIntervalSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit timeIntervalSetDialog(MainWindow* _parent = nullptr);
    ~timeIntervalSetDialog();

    QString text() const noexcept;

public slots:

private slots:
    void on_buttonBox_accepted();

private:
    Ui::timeIntervalSetDialog *ui;
    MainWindow* parent;
};

#endif // TIMEINTERVALSETDIALOG_H
