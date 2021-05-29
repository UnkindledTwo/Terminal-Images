#include "editorbutton.h"
#include "ui_editorbutton.h"

EditorButton::EditorButton(QWidget *parent, int row, int column) :
    QPushButton(parent),
    ui(new Ui::EditorButton)
{
    ui->setupUi(this);
    this->row = row;
    this->column = column;

    this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    this->setText(" ");
    this->setStyleSheet("color: white; background-color: black;");
    this->setFixedSize(20, 50);
}

EditorButton::~EditorButton()
{
    delete ui;
}

void EditorButton::Press(){
    emit buttonPressed(row, column);
}

void EditorButton::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        Press();
    }
}
