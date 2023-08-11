
#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "pieceitem.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow),
    scene(new QGraphicsScene(this))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(scene);

    const int gridSize = 8; // размер сетки
    const int cellSize = 50; // размер ячейки

    createGrid(gridSize, cellSize);
    createPieces(gridSize, cellSize);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::createGrid(int gridSize, int cellSize)
{
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            int x = col * cellSize;
            int y = row * cellSize;

            QColor color = (row + col) % 2 == 0 ? Qt::lightGray : Qt::darkGray;
            QBrush brush(color);
            QPen pen(Qt::NoPen);

            QGraphicsRectItem* cellItem = scene->addRect(x, y, cellSize, cellSize, pen, brush);
            cellItem->setZValue(-1); // Поместить ячейку ниже шашек
        }
    }
}

void SecondWindow::createPieces(int gridSize, int cellSize)
{
    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            if ((row + col) % 2 != 0 && (row < 3 || row > 4)) { // Только для черных ячеек и не в центральных рядах
                int x = col * cellSize;
                int y = row * cellSize;

                PieceItem* pieceItem = new PieceItem(x, y, cellSize, cellSize);
                scene->addItem(pieceItem); // Добавляем объект на сцену
            }
        }
    }
}

void SecondWindow::on_pushButton_clicked()
{
    hide();
    SecondWindow window;
    window.setModal(true);
    window.exec();
}

