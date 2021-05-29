#ifndef CHANGABLEWIDGET_H
#define CHANGABLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QLineEdit>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QTextEdit>

#include <QDebug>

namespace Ui {
class ChangableWidget;
}

class ChangableWidget : public QWidget
{
    Q_OBJECT

public:
    QString text() const;

    void setText(QString text);

    void Switch(int newVal = -1);

    explicit ChangableWidget(QWidget *parent = nullptr);
    ~ChangableWidget();

private slots:
    void keyPressEvent(QKeyEvent *e);

    void mouseDoubleClickEvent(QMouseEvent *e);

private:
    Ui::ChangableWidget *ui;

    QVBoxLayout *layout;
    QStackedWidget *stackedWidget;
    QLabel *label;
    QLineEdit *lineEdit;
};

#endif // CHANGABLEWIDGET_H
