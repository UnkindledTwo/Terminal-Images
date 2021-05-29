#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QMainWindow>

namespace Ui {
class StartDialog;
}

class StartDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

    int h;
    int w;

    void exec();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StartDialog *ui;

    bool buttonClicked = false;
};

#endif // STARTDIALOG_H
