#include "timgeditor.h"
#include "ui_timgeditor.h"

TimgEditor::TimgEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimgEditor)
{
    ui->setupUi(this);

    ui->changeTextButton->setChecked(changeText);
    ui->changeColorButton->setChecked(changeColor);

    colorVector = {" ", "b", "r", "g", "y", "m", "c", "w", "B", "R", "G", "Y", "M", "C", "W"};
    colorVectorString = {"Transparent", "Black", "Red", "Green", "Yellow", "Magenta", "Cyan", "White"};

    for(int i = 0; i < colorVectorString.count(); i++){
        ui->currentColor->addItem(colorVectorString[i]);
    }
}

TimgEditor::~TimgEditor()
{
    delete ui;
}

void TimgEditor::on_actionStart_triggered()
{
    sizedialog *sd = new sizedialog(this);
    if(sd->exec()){
        gridHeight = sd->h;
        gridWidth = sd->w;

    }

    for(int i = 0; i < buttonList.count(); i++){
        buttonList.at(i)->deleteLater();
    }

    for(int i = 0; i < gridHeight; i++){
        for(int j = 0; j < gridWidth-1; j++){
            EditorButton *b = new EditorButton(this, i ,j);
            connect(b, &EditorButton::buttonPressed, this, &TimgEditor::buttonPressed);
            ui->editorgrid->addWidget(b, i, j);
            buttonList.append(b);
        }
    }
}


void TimgEditor::on_actionSave_triggered()
{
    QString out = "  ";
    QString fileName = QFileDialog::getSaveFileName(this, "Save");
    if(fileName.length() == 0) return;
    QFile file(fileName);
    file.open(QIODevice::ReadWrite);
    QTextStream stream(&file);
    for(int i = 0; i < gridHeight; i++){
        for(int j = 0; j < gridWidth; j++){
            if(j == gridWidth -1){
                out.append("n ");
                continue;
            }
            EditorButton *b = ((EditorButton*)ui->editorgrid->itemAtPosition(i, j)->widget());
            out.append(b->color + b->text);
        }
    }
    stream << out;
    file.close();
    stream.flush();
    qDebug() << out;
}

void TimgEditor::buttonPressed(int row, int column){
    if(changeText){
        EditorButton *b = ((EditorButton*)ui->editorgrid->itemAtPosition(row, column)->widget());
        if(ui->currentText->text().length() == 0) return;
        b->setText(ui->currentText->text());
        b->text = ui->currentText->text();
    }
    if(changeColor){
        EditorButton *b = ((EditorButton*)ui->editorgrid->itemAtPosition(row, column)->widget());
        b->color = colorVector.at(ui->currentColor->currentIndex());
        b->setStyleSheet(b->styleSheet() + " background-color: " + ui->currentColor->currentText() + ";");
        if(ui->currentColor->currentText() == "Transparent"){
            qDebug() << "Transparent";
            b->setStyleSheet(b->styleSheet() + " background-color:white; ");
        }
    }
}

void TimgEditor::on_changeTextButton_toggled(bool checked)
{
    changeText = checked;
    qDebug() << "Checked changed" << checked;
}

void TimgEditor::on_changeColorButton_toggled(bool checked)
{
    changeColor = checked;
    qDebug() << "Checked changed" << checked;
}

