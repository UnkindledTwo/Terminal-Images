#include "sizedialog.h"
#include "ui_sizedialog.h"

sizedialog::sizedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sizedialog)
{
    ui->setupUi(this);


}

sizedialog::~sizedialog()
{
    delete ui;
}

void sizedialog::on_buttonBox_accepted()
{
   }


void sizedialog::on_sizedialog_accepted()
{
    this->w = ui->wb->value();
    this->h = ui->hb->value();
}

