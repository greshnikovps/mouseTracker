#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "timeintervalsetdialog.h"
#include "mousetrackerframe.h"
#include "setsavedirpath.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readSaveResInterval();
    readSaveFileDirPath();
    mouseTrackLength = 0;
    isRunning = true;

    saveResThrdFuture = std::async(&MainWindow::saveResThread, this);
    setUIupdateTimer();

    mouseTrackerFrame* frame = new mouseTrackerFrame(this);
    frame->setMouseTracking(true);
    frame->setGeometry({25, 45, 500, 500});
    frame->setStyleSheet("background-color:red;");
}

void MainWindow::setUIupdateTimer(){
    uiUpdateTimer = new QTimer();
    connect(uiUpdateTimer, SIGNAL(timeout()), this, SLOT(slotUIupdateTimerAlarm()));
    uiUpdateTimer->start(UI_UPDATE_INTERVAL);
}

void MainWindow::slotUIupdateTimerAlarm(){
    ui->coordsField->setText( QString::number(mouseCoords.x) + " " + QString::number(mouseCoords.y));
    ui->mouseTrackLengthField->setText(QString::number(mouseTrackLength));
}

void MainWindow::setMouseCoords(const MouseCoords& _mouseCoords){
    std::lock_guard<std::mutex> guard(m);
    mouseTrackLength += std::sqrt((_mouseCoords.x - mouseCoords.x) * (_mouseCoords.x - mouseCoords.x)
                             + (_mouseCoords.y - mouseCoords.y) * (_mouseCoords.y - mouseCoords.y));
    mouseCoords.x = _mouseCoords.x;
    mouseCoords.y = _mouseCoords.y;
}

void MainWindow::saveResThread(){
    while (isRunning){
        QThread::msleep(msecSaveResInterval);
        saveResToFile();
        std::lock_guard<std::mutex> guard(m);
        mouseTrackLength = 0;
    }
}

void MainWindow::readSaveResInterval(){
    QFile timeIntervalFile(QDir().dirName() + "/" + TIME_INTERVAL_SETTING_FILE_NAME);
    if (timeIntervalFile.open(QIODevice::ReadOnly)) {
        QTextStream stream(&timeIntervalFile);
        stream >> msecSaveResInterval;
    } else {
        msecSaveResInterval = DEFAULT_MSEC_TIME_INTERVAL;
    }
}

void MainWindow::readSaveFileDirPath(){
    QFile saveFileNameFile(QDir().dirName() + "/" + PATH_TO_SAVE_DIR_SETTING_FILE_NAME);
    if (saveFileNameFile.open(QIODevice::ReadOnly)) {
        QTextStream stream(&saveFileNameFile);
        stream >> saveFileDirPath;
    } else {
        saveFileDirPath = "./logs/";
    }
}

void MainWindow::saveResToFile(){
    QString filename = saveFileDirPath + QDateTime::currentDateTimeUtc().toString("dd_MM_yyyy_hh:mm:ss") + ".txt";
    QFile resFile(filename);
    if (resFile.open(QIODevice::WriteOnly)) {
        QTextStream stream(&resFile);
        stream << mouseTrackLength << endl;
    }
}

MainWindow::~MainWindow()
{
    isRunning = false;
    delete ui;
}

void MainWindow::setTimeInterval(int _msecTimeInterval){
    QFile resFile(QDir().dirName() + "/" + TIME_INTERVAL_SETTING_FILE_NAME);
    if (resFile.open(QIODevice::WriteOnly)) {
        QTextStream stream(&resFile);
        stream << _msecTimeInterval << endl;
    }
    std::lock_guard<std::mutex> guard(m);
    msecSaveResInterval = _msecTimeInterval;
}

void MainWindow::setSaveFileDirPath(const QString& _saveFileDirPath){
    QFile resFile(QDir().dirName() + "/" + PATH_TO_SAVE_DIR_SETTING_FILE_NAME);
    qDebug() << QDir().dirName() + "/" + PATH_TO_SAVE_DIR_SETTING_FILE_NAME;
    if (resFile.open(QIODevice::WriteOnly)) {
        QTextStream stream(&resFile);
        stream << _saveFileDirPath << endl;
    }
    std::lock_guard<std::mutex> guard(m);
    saveFileDirPath = _saveFileDirPath;
}

void MainWindow::on_setTimeInterval_triggered()
{
    timeIntervalSetDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_setSaveDirPath_triggered()
{
    setSaveDirPath dialog(this);
    dialog.exec();
}
