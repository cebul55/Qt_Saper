#ifndef SAPER_H
#define SAPER_H

#include "saperboard.h"

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTableView>
#include <QCursor>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>



namespace Ui {
    class Saper;
}

class Saper : public QWidget
{
    Q_OBJECT

public:
    explicit Saper(QWidget *parent = nullptr);
    ~Saper();

private slots:
    void on_StartNewGameButton_clicked();

private:
    Ui::Saper *ui;
    SaperBoard *saperBoard;

};

#endif // SAPER_H
