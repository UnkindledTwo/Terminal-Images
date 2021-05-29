#ifndef EDITORBUTTON_H
#define EDITORBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QChar>

namespace Ui {
class EditorButton;
}

class EditorButton : public QPushButton
{
    Q_OBJECT

signals:
    void buttonPressed(int row, int column);

public:
    explicit EditorButton(QWidget *parent = nullptr, int row = -1, int column = -1);
    ~EditorButton();

    int row,column;

    void mousePressEvent(QMouseEvent *e);

    QString color = "b";
    QString text = " ";

    void Press();

private:
    Ui::EditorButton *ui;
};

#endif // EDITORBUTTON_H
