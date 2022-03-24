#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QString>
#include <QDateTime>
#include <QThread>
#include <QFile>
#include <QMouseEvent>
#include <QTimer>
#include <QDir>
#include <QCoreApplication>

#include <future>
#include <mutex>
#include <cmath>

#include "defines.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setTimeInterval(int _msecTimeInterval);
    void setSaveFileDirPath(const QString& _saveFileDirPath);
    void setMouseCoords(const MouseCoords& _mouseCoords);

private slots:
    void slotUIupdateTimerAlarm();

    void on_setTimeInterval_triggered();

    void on_setSaveDirPath_triggered();

private:
    void saveResThread();
    void readSaveResInterval();
    void readSaveFileDirPath();
    void updateUI();
    void saveResToFile();
    void setUIupdateTimer();

    Ui::MainWindow *ui;
    QTimer* uiUpdateTimer;

    int msecSaveResInterval;
    QString saveFileDirPath;

    long long int mouseTrackLength;
    MouseCoords mouseCoords;
    std::future<void> saveResThrdFuture;
    std::mutex m;

    volatile bool isRunning;

};
#endif // MAINWINDOW_H
