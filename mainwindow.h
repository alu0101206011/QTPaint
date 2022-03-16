#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void PaintUp();
    void PaintLeft();
    void PaintDown();
    void PaintRight();

private:
    Ui::MainWindow *ui;
    QPixmap pixmap;
    int x, y;       // cursor coordinates
    int width;
    QColor colour;
};
#endif // MAINWINDOW_H
