#ifndef SIZEDIALOG_H
#define SIZEDIALOG_H

#include <QDialog>

namespace Ui {
class sizedialog;
}

class sizedialog : public QDialog
{
    Q_OBJECT

public:
    explicit sizedialog(QWidget *parent = nullptr);
    ~sizedialog();

    int h,w;

private slots:
    void on_buttonBox_accepted();

    void on_sizedialog_accepted();

private:
    Ui::sizedialog *ui;
};

#endif // SIZEDIALOG_H
