#ifndef LINEEDITOR_H
#define LINEEDITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QKeyEvent>

namespace Ui {
class LineEditor;
}

class LineEditor : public QLineEdit
{
    Q_OBJECT

signals:
    void EnterPressed(int a = -1);

public:
    explicit LineEditor(QWidget *parent = nullptr);
    ~LineEditor();

    void keyPressEvent(QKeyEvent *e);

private:
    Ui::LineEditor *ui;
};

#endif // LINEEDITOR_H
