#ifndef ACCEPTDIALOG_H
#define ACCEPTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AcceptDialog; }
QT_END_NAMESPACE
class AcceptDialog : public QDialog
{
    Q_OBJECT
public:
    AcceptDialog(QWidget* parent = nullptr);
    ~AcceptDialog();
private:
    Ui::AcceptDialog* ui;
};

#endif // ACCEPTDIALOG_H
