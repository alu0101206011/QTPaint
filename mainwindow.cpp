#include "mainwindow.h"
#include "./ui_mainwindow.h"

// MainWindow Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
    , pixmap_{711,291}
    , x_{40}
    , y_{40}
{
    ui_->setupUi(this);

    pixmap_.fill(QColor("white"));
    readSettings();
    PaintRight();

    // Connecting direction buttons with methods
    connect(ui_->upButton,&QPushButton::clicked,this,&MainWindow::PaintUp);
    connect(ui_->leftButton,&QPushButton::clicked,this,&MainWindow::PaintLeft);
    connect(ui_->downButton,&QPushButton::clicked,this,&MainWindow::PaintDown);
    connect(ui_->rightButton,&QPushButton::clicked,this,&MainWindow::PaintRight);

    // Connecting menu bar buttons
    connect(ui_->editWidth,SIGNAL(triggered()),this,SLOT(editWidth_triggered()));
    connect(ui_->editColour,SIGNAL(triggered()),this,SLOT(editColour_triggered()));
    connect(ui_->imageSave,SIGNAL(triggered()),this,SLOT(imageSave_triggered()));
    connect(ui_->optionExit,SIGNAL(triggered()),this,SLOT(optionExit_triggered()));
    connect(ui_->showHelp,SIGNAL(triggered()),this,SLOT(showHelp_triggered()));

}

// MainWindow Destructor
MainWindow::~MainWindow()
{
    writeSettings();
    delete ui_;
}

// Public method that draw a line up when you press the paintUp button
void MainWindow::PaintUp()
{
    QPainter painter(&pixmap_);
    painter.setPen(QPen(colour_,width_));
    painter.drawLine(x_,y_,x_,y_-20);
    ui_->label->setPixmap(pixmap_);
    y_-=20;
}

// Public method that draw a line left when you press the paintLeft button
void MainWindow::PaintLeft()
{
    QPainter painter(&pixmap_);
    painter.setPen(QPen(colour_,width_));
    painter.drawLine(x_,y_,x_-20,y_);
    ui_->label->setPixmap(pixmap_);
    x_-=20;
}

// Public method that draw a line down when you press the paintDown button
void MainWindow::PaintDown()
{
    QPainter painter(&pixmap_);
    painter.setPen(QPen(colour_,width_));
    painter.drawLine(x_,y_,x_,y_+20);
    ui_->label->setPixmap(pixmap_);
    y_+=20;

}

// Public method that draw a line right when you press the paintRight button
void MainWindow::PaintRight()
{
    QPainter painter(&pixmap_);
    painter.setPen(QPen(colour_,width_));
    painter.drawLine(x_,y_,x_+20,y_);
    ui_->label->setPixmap(pixmap_);
    x_+=20;
}

// Private method that edit the width pen when you press widthButton in the menu bar
void MainWindow::editWidth_triggered()
{
    width_ = QInputDialog::getInt(this, "Pen width", "Enter width:", 10, 1);
}

// Private method that edit the colour pen when you press colourButton in the menu bar
void MainWindow::editColour_triggered()
{
    colour_ = QColorDialog::getColor(Qt::black, this, "Pen color");
}

// Private method that saves an image of pixmap in the direction you choose when you press save button in the menu bar
void MainWindow::imageSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save image"), QDir::currentPath(),tr("Image Files (*.png *.jpg *.bmp);;All Files(*)"));
    if (fileName != "")
        ui_->label->grab().save(fileName);
}

// Private method that edit the width pen when you press widthButton in the menu bar
void MainWindow::optionExit_triggered()
{
    close();
}

// Private method that shows the help when you press help button in the menu bar
void MainWindow::showHelp_triggered()
{
    QString message = "\nPaint help.\n\n\n1. Save\nYou can save by clicking on the menu bar \"File/Save\" and then you can choose the file destination.\n\n2. Change colour\nYou can change the pen colour by clicking on the menu bar \"Style/Colour\".\n\n3. Change width\n You can change the pen width by clicking on the menu bar \"Style/Width\".\n\n4. Exit \nYou can exit this program by clicking on the menu bar \"File/Exit\".\n\n";
    QMessageBox::information(this,tr("Paint help"), message);
}

// Private method that saves the current configuration settings when the program is closed
void MainWindow::writeSettings()
{
    QSettings settings("Moose Soft", "Clipper");

    settings.beginGroup("MainWindow");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("penColour", colour_);
    settings.setValue("penWidth", width_);
    settings.endGroup();
}

// Private method that reads the previous configuration settings if it exists, otherwise the method applies the default values
void MainWindow::readSettings()
{
    QSettings settings("Moose Soft", "Clipper");

    settings.beginGroup("MainWindow");
    const auto geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty())
        setGeometry(200, 200, 829, 565);
    else
        restoreGeometry(geometry);

    if (settings.value("penWidth").isNull()) {
        width_ = 5;
    } else {
        width_ = settings.value("penWidth").toInt();
    }
    colour_ = settings.value("penColour").value<QColor>();

    settings.endGroup();
}
