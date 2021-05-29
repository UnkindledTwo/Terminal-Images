#include "changablewidget.h"
#include "ui_changablewidget.h"

ChangableWidget::ChangableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangableWidget)
{
    ui->setupUi(this);

    layout = new QVBoxLayout();
    stackedWidget = new QStackedWidget();
    label = new QLabel();
    lineEdit = new QLineEdit();

    stackedWidget->addWidget(label);
    stackedWidget->addWidget(lineEdit);

    layout->addWidget(stackedWidget);

    this->setLayout(layout);

    this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    this->setStyleSheet("border: 5px solid;");
}

ChangableWidget::~ChangableWidget()
{
    delete ui;
}

void ChangableWidget::Switch(int newVal){

    if(stackedWidget->currentIndex() == 0){ lineEdit->setText(label->text()); }
    else{ label->setText(lineEdit->text()); }
    if(newVal != -1){
        stackedWidget->setCurrentIndex(newVal);
        return;
    }
    if(stackedWidget->currentIndex() == 0){
        Switch(1);
        lineEdit->setFocus();
    }
    else{
        Switch(0);
    }
}

QString ChangableWidget::text() const{
    if(stackedWidget->currentIndex() == 0){return label->text();}
    else if(stackedWidget->currentIndex() == 1){return lineEdit->text();}
    else return "31";
}

void ChangableWidget::setText(QString text){
    label->setText(text);
    lineEdit->setText(text);
}

void ChangableWidget::keyPressEvent(QKeyEvent *e){
    if(e->key() == Qt::Key_Return)
    Switch();
}

void ChangableWidget::mouseDoubleClickEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        Switch();
    }
}
