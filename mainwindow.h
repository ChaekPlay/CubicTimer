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
#include "scramblegen.h"
#include "acceptdialog.h"
#include <QFileDialog>

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
    void removeElementFromTable(int);
private:
    Ui::MainWindow *ui;
    QTime display_timer;
    QTimer* uiUpdateTimer;
    TimeBoard timeBoard;
    ScrambleGen scrambleGenerator;
    void startTime();
    void stopTime();
    void updateDisplayTime();
    bool timeTicking = false;

protected:
    virtual void keyPressEvent(QKeyEvent*);
    virtual void keyReleaseEvent(QKeyEvent*);
private slots:
    void on_clearButton_clicked();
    void on_saveToFileButton_clicked();
    void on_loadFromFile_clicked();
};
#endif // MAINWINDOW_H
