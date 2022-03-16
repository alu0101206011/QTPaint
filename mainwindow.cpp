#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pixmap{715,281}
    , x{40}
    , y{40}
    , width{5}
    , colour{QColor(Qt::black)}  // default colour
{
    ui->setupUi(this);
    //https://forum.qt.io/topic/70049/how-to-do-qpainter-paint-in-the-widget/2

    pixmap.fill(QColor("white"));
    PaintRight();
    connect(ui->upButton,&QPushButton::clicked,this,&MainWindow::PaintUp);
    connect(ui->leftButton,&QPushButton::clicked,this,&MainWindow::PaintLeft);
    connect(ui->downButton,&QPushButton::clicked,this,&MainWindow::PaintDown);
    connect(ui->rightButton,&QPushButton::clicked,this,&MainWindow::PaintRight);
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Exit",this,&MainWindow::close);
}

void MainWindow::PaintUp()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour,width));
    painter.drawLine(x,y,x,y-20);
    ui->label->setPixmap(pixmap);
    y-=20;
    QPushButton *a = new QPushButton;
}

void MainWindow::PaintLeft()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour,width));
    painter.drawLine(x,y,x-20,y);
    ui->label->setPixmap(pixmap);
    x-=20;
    QPushButton *a = new QPushButton;
}

void MainWindow::PaintDown()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour,width));
    painter.drawLine(x,y,x,y+20);
    ui->label->setPixmap(pixmap);
    y+=20;
    QPushButton *a = new QPushButton;
}


void MainWindow::PaintRight()
{
    QPainter painter(&pixmap);
    painter.setPen(QPen(colour,width));
    painter.drawLine(x,y,x+20,y);
    ui->label->setPixmap(pixmap);
    x+=20;
    QPushButton *a = new QPushButton;
}

MainWindow::~MainWindow()
{
//    https://stackoverflow.com/questions/16362191/qt-grab-widget-and-save-image
    ui->label->grab().save("image.png");
    delete ui;
}

