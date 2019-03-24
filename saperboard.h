#ifndef SAPERBOARD_H
#define SAPERBOARD_H
#define MINE -1

#include <vector>
#include <QAbstractTableModel>
#include <QSize>

class SaperBoard : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(QSize size READ size WRITE setSize setMines NOTIFY sizeChanged minesChanged)
private:
    int numberOfMines;
    QSize size;
    std::vector<std::vector<int> > saperBoard;

    void initializeSaperBoard(int width, int height);
    void setUpMines(int numberOfMines );
    void setUpNeighbours();
    void countNeighbours(int x, int y);

public:
    SaperBoard(int width = 10, int height = 10, int numberofMines = 10){
        this->numberOfMines = numberofMines;
        size = QSize(width,height);
        this->initializeSaperBoard(this->size.width(), this->size.height());
        this->setUpMines(this -> numberOfMines);
    }
    SaperBoard(QSize s, int numberOfMines, QObject *parent = 0);
    ~SaperBoard(){}

    //int getWidth(){return this->width;}
    //int getHeight(){return this->height;}
    int getNumberOfMines(){return this->numberOfMines;}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

public slots:
    void setSize(const QSize &s);
    void setMines(const int &mines);
signals:
    void sizeChanged(QSize);
    void minesChanged(int);
};



#endif // SAPERBOARD_H
