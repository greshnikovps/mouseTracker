#include "setsavedirpath.h"
#include "ui_setsavedirpath.h"
#include <QDir>

setSaveDirPath::setSaveDirPath(MainWindow* _parent) :
    QDialog(_parent),
    ui(new Ui::setSaveDirPath),
    parent(_parent)
{
    ui->setupUi(this);
}

setSaveDirPath::~setSaveDirPath()
{
    delete ui;
}

void setSaveDirPath::on_buttonBox_accepted()
{
    if (!QDir(ui->dirNameLine->text()).exists()){
        return;
    }
    parent->setSaveFileDirPath(ui->dirNameLine->text());
}
