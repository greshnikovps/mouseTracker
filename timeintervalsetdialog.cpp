#include "timeintervalsetdialog.h"
#include "ui_timeintervalsetdialog.h"

timeIntervalSetDialog::timeIntervalSetDialog(MainWindow* _parent) :
    QDialog(_parent),
    ui(new Ui::timeIntervalSetDialog),
    parent(_parent)
{
    ui->setupUi(this);
}

QString timeIntervalSetDialog::text() const noexcept
{
    return ui->lineEdit->text();
}

timeIntervalSetDialog::~timeIntervalSetDialog()
{
    delete ui;
}

void timeIntervalSetDialog::on_buttonBox_accepted()
{
    parent->setTimeInterval(ui->lineEdit->text().toInt());
}
