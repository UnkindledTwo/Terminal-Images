#include "startdialog.h"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::on_pushButton_clicked()
{
    buttonClicked = true;
}

void StartDialog::exec(){
    while(!buttonClicked){
        this->w = ui->spinBox->value();
        this->h = ui->spinBox_2->value();
    }

}

