#include "saper.h"
#include "saperboard.h"
#include "ui_saper.h"


Saper::Saper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Saper)
{
    ui->setupUi(this);

//    this->graphicSaperBoard = new QGraphicsView();
//    QGraphicsScene scene;

//    scene.addItem(new QGraphicsItem());
//    ui->gridLayout->addWidget(this->graphicSaperBoard,0,0,1,1);

}

Saper::~Saper()
{
    delete ui;
}

void Saper::on_StartNewGameButton_clicked()
{
    //todo pobierz dane z settingsów i przekaż do konstruktora nowej tablicy
    this->saperBoard = new SaperBoard();
}
