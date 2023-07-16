#include "mainwindow.h"
#include "./ui_mainwindow.h"

const short UPDATE_TIME = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->uiScoreList->setFocusPolicy(Qt::NoFocus);
    ui->clearButton->setFocusPolicy(Qt::NoFocus);
    ui->timerLabel->setFocusPolicy(Qt::StrongFocus);
    ui->scrambleLabel->setText(scrambleGenerator.generateScramble());
    uiUpdateTimer = new QTimer();
    display_timer.setHMS(0,0,0,0);
    connect(uiUpdateTimer,&QTimer::timeout, this, &MainWindow::updateDisplayTime);
    QObject::connect(&timeBoard, &TimeBoard::averageUpdated, this, &MainWindow::updateAoNOnUi);
    QObject::connect(&timeBoard, &TimeBoard::tableUpdated, this, &MainWindow::updateTable);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startTime() {
    timeTicking = true;
    uiUpdateTimer->start(UPDATE_TIME);
}

void MainWindow::stopTime() {
    timeTicking = false;
    uiUpdateTimer->stop();
    timeBoard.addToList(display_timer);
    display_timer.setHMS(0,0,0,0);
    ui->scrambleLabel->setText(scrambleGenerator.generateScramble());
}

void MainWindow::updateDisplayTime() {
    display_timer = display_timer.addMSecs(UPDATE_TIME);
    ui->timerLabel->setText(TimeFormat::generateFormatForTime(display_timer));
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(event->key() != Qt::Key_Space || timeTicking)
        return;
    ui->timerLabel->setStyleSheet("QLabel { color: red; }");
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    if(event->key() != Qt::Key_Space || event->isAutoRepeat())
        return;
    ui->timerLabel->setStyleSheet("QLabel { color: white; }");
    if(!timeTicking) {
        startTime();
        return;
    }
    stopTime();
}

void MainWindow::updateAoNOnUi(QString ao5, QString ao12) {
    ui->averageOf5Label->setText("ao5: "+ao5);
    ui->averageOf12Label->setText("ao12: "+ao12);
}

void MainWindow::updateTable(QString item) {
    if(QString("-") == item) {
        ui->uiScoreList->clear();
        return;
    }
    ui->uiScoreList->addItem(item);
}

void MainWindow::removeElementFromTable(int id) {
    ui->uiScoreList->takeItem(id);
}

void MainWindow::on_clearButton_clicked()
{
    AcceptDialog dialog;
    if(dialog.exec() == QDialog::Rejected)
        return;
    timeBoard.clearList();
}

