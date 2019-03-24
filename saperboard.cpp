#include "saperboard.h"

#include <iostream>

void SaperBoard::initializeSaperBoard(int width, int height){
    for(int i = 0; i < width; i++){
        std::vector<int> tmp;
        for(int j = 0; j < height; j++){
            tmp.push_back( 0 );
        }
        this->saperBoard.push_back(tmp);
    }



}

void SaperBoard::setUpMines(int numberOfMines)
{
    //(-1) oznacza minę
    //liczba nieujemna oznacza liczbę min w sąsiedztwie
    //jeżeli wylosujemy polę na którym już jest mina losujemy jescze raz

    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int randX, randY;

    while(numberOfMines > 0){
        randX = std::rand() % this->size.width();
        randY = std::rand() % this->size.height();

        if(saperBoard[randX][randY] != (MINE)){
            this->saperBoard[randX][randY] = (MINE);
            numberOfMines--;
        }
    }
    this->setUpNeighbours();


        for(int i = 0; i < size.width(); i++){
            for(int j = 0; j < size.height(); j++){
                std::cout<<this->saperBoard[i][j]<<"\t";
            }
            std::cout<<"\n";
        }
}

void SaperBoard::setUpNeighbours()
{
    for(int i = 0; i < size.width(); i++){
        for(int j = 0; j < size.height(); j++){
            if(this->saperBoard[i][j] == MINE){
                this->countNeighbours(i,j);
            }
        }
    }
}

void SaperBoard::countNeighbours(int x, int y)
{
    for(int i = x-1; i <= x+1; i++){
        for(int j = y-1; j <= y+1; j++){
            if(i >= 0 && i < this->size.width() && j >= 0 && j < this->size.height()){
                if(saperBoard[i][j]!= (MINE) ){
                    saperBoard[i][j]++;
                }
            }
        }
    }
}

SaperBoard::SaperBoard(QSize s, int numberOfMines, QObject *parent) :
    QAbstractTableModel(parent),
    numberOfMines(numberOfMines),
    size(s){
        this->initializeSaperBoard(this->size.width(), this->size.height());
        this->setUpMines(this -> numberOfMines);
    }

int SaperBoard::rowCount(const QModelIndex &parent) const
{
    return this->size.height();
}

int SaperBoard::columnCount(const QModelIndex &parent) const
{
    return this->size.width();
}

QVariant SaperBoard::data(const QModelIndex &index, int role) const
{
    return index.row();
}

void SaperBoard::setSize(const QSize &s)
{
    if (size == s) return;
    beginResetModel();
    this->size = s;
    endResetModel();
    emit sizeChanged(size);
}

void SaperBoard::setMines(const int &mines){
    if(numberOfMines == mines )return;
    beginResetModel();
    this->numberOfMines = mines;
    endResetModel();
    emit minesChanged(numberOfMines);
}

