#include "acceptdialog.h"
#include "./ui_acceptdialog.h"
AcceptDialog::AcceptDialog(QWidget* parent) : QDialog(parent), ui(new Ui::AcceptDialog)
{
    ui->setupUi(this);
}
AcceptDialog::~AcceptDialog() {
    delete ui;
}
