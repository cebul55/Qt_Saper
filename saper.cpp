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
    saperBoard = new SaperBoard;
    ui->tableView->setModel(saperBoard);
//    ui->tableView->resizeRowsToContents();
//    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    ui->tableView->setShowGrid(true);
    ui->tableView->show();
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
