#ifndef TIMGEDITOR_H
#define TIMGEDITOR_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QTextStream>
#include <QFile>
#include <QFileInfo>
#include <QVector>
#include <QFileDialog>
#include "Colors.h"
#include "sizedialog.h"
#include "editorbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TimgEditor; }
QT_END_NAMESPACE

class TimgEditor : public QMainWindow
{
    Q_OBJECT

public:
    TimgEditor(QWidget *parent = nullptr);
    ~TimgEditor();

    int gridWidth;
    int gridHeight;

private slots:
    void on_actionStart_triggered();

    void on_actionSave_triggered();

    void on_changeTextButton_toggled(bool checked);

    void buttonPressed(int row, int column);

    void on_changeColorButton_toggled(bool checked);

private:
    Ui::TimgEditor *ui;

    bool changeText = false;

    bool changeColor = false;

    QVector<QString> colorVector;
    QVector<QString> colorVectorString;
};
#endif // TIMGEDITOR_H
