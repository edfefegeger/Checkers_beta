#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QMouseEvent>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecondWindow *ui;
    QGraphicsScene* scene;

    void createGrid(int gridSize, int cellSize);
    void createPieces(int gridSize, int cellSize);
};

#endif // SECONDWINDOW_H
