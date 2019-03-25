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
        randX = std::rand() % this->qSize.width();
        randY = std::rand() % this->qSize.height();

        if(saperBoard[randX][randY] != (MINE)){
            this->saperBoard[randX][randY] = (MINE);
            numberOfMines--;
        }
    }
    this->setUpNeighbours();


        for(int i = 0; i < qSize.width(); i++){
            for(int j = 0; j < qSize.height(); j++){
                std::cout<<this->saperBoard[i][j]<<"\t";
            }
            std::cout<<"\n";
        }
}

void SaperBoard::setUpNeighbours()
{
    for(int i = 0; i < qSize.width(); i++){
        for(int j = 0; j < qSize.height(); j++){
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
            if(i >= 0 && i < this->qSize.width() && j >= 0 && j < this->qSize.height()){
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
    qSize(s){
        this->initializeSaperBoard(this->qSize.width(), this->qSize.height());
        this->setUpMines(this -> numberOfMines);
    }

int SaperBoard::rowCount(const QModelIndex &parent) const
{
      return parent.isValid() ? 0 : qSize.height();
}

int SaperBoard::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : qSize.width();
}

QVariant SaperBoard::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        {
//           return QString("Row%1, Column%2")
//                       .arg(index.row() + 1)
//                       .arg(index.column() +1);
        return (this->saperBoard[index.row()][index.column()]);
        }
        return QVariant();
}

QModelIndex SaperBoard::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid()) return QModelIndex();
      if (row >= qSize.height() || column >= qSize.width() || column < 0 || row < 0)
        return QModelIndex();
      return createIndex(row, column, nullptr);
}

QModelIndex SaperBoard::parent(const QModelIndex &idx) const
{
    return QModelIndex();
}

void SaperBoard::setSize(const QSize &s)
{
    if (qSize == s) return;
    beginResetModel();
    this->qSize = s;
    endResetModel();
    emit sizeChanged(qSize);
}

void SaperBoard::setMines(const int &mines){
    if(numberOfMines == mines )return;
    beginResetModel();
    this->numberOfMines = mines;
    endResetModel();
    emit minesChanged(numberOfMines);
}

