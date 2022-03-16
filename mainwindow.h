#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QInputDialog>
#include <QColorDialog>

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

private slots:
    void on_editWidth_triggered();
    void on_editColour_triggered();

private:
    Ui::MainWindow *ui_;
    QPixmap pixmap_;
    int x_, y_;       // cursor coordinates
    int width_;
    QColor colour_;
};
#endif // MAINWINDOW_H
