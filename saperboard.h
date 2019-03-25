#ifndef SAPERBOARD_H
#define SAPERBOARD_H
#define MINE -1

#include <vector>
#include <QAbstractTableModel>
#include <QSize>

class SaperBoard : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(QSize qSize READ qSize WRITE setSize NOTIFY sizeChanged )
    Q_PROPERTY(int numberOfMines WRITE setMines NOTIFY minesChanged)
private:
    int numberOfMines;
    QSize qSize;
    std::vector<std::vector<int> > saperBoard;

    void initializeSaperBoard(int width, int height);
    void setUpMines(int numberOfMines );
    void setUpNeighbours();
    void countNeighbours(int x, int y);

public:
    SaperBoard(int width = 10, int height = 10, int numberofMines = 10){
        this->numberOfMines = numberofMines;
        qSize.setWidth(width);
        qSize.setHeight(height);
        this->initializeSaperBoard(this->qSize.width(), this->qSize.height());
        this->setUpMines(this -> numberOfMines);
    }
    SaperBoard(QSize s, int numberOfMines, QObject *parent = nullptr);
    ~SaperBoard(){}

    int getNumberOfMines(){return this->numberOfMines;}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QModelIndex index(int r, int c, const QModelIndex &par = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &idx) const;

public slots:
    void setSize(const QSize &s);
    void setMines(const int &mines);
signals:
    void sizeChanged(QSize);
    void minesChanged(int);
};



#endif // SAPERBOARD_H
