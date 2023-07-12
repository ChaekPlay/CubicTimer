#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrent>
#include <QKeyEvent>
#include <vector>
#include <iostream>
#include "timeboard.h"
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateAoNOnUi(QString, QString);
    void updateTable(QString);
private:
    Ui::MainWindow *ui;
    QTime display_timer;
    QTimer* uiUpdateTimer;
    TimeBoard timeBoard;
    void startTime();
    void stopTime();
    void updateDisplayTime();
    bool timeTicking = false;
    QStringList scoreList;

protected:
    virtual void keyPressEvent(QKeyEvent*);
    virtual void keyReleaseEvent(QKeyEvent*);
};
#endif // MAINWINDOW_H
