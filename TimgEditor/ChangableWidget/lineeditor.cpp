#include "lineeditor.h"
#include "ui_lineeditor.h"

LineEditor::LineEditor(QWidget *parent) :
    QLineEdit(parent),
    ui(new Ui::LineEditor)
{
    ui->setupUi(this);
}

LineEditor::~LineEditor()
{
    delete ui;
}

void LineEditor::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_Return){
        emit EnterPressed();
    }
}
