    #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    videoItem = new QGraphicsVideoItem;
  //   this->showMaximized();
    videoItem->setSize(this->size()*2); //ვიდეოს ზომის მითთება

    scene=new QGraphicsScene(this); //
    scene->addItem(videoItem); //სცენას ემატება ვიდეო ელემენტი
    mediaPlayer.setVideoOutput(videoItem); //მედია პლეერს ვუთითებთ რომ ვიდოე დაუკრას ვიდეოს ელემენტში
    ui->graphicsView->setScene(scene); // graphicsView აჩვენებს ნებისმიერი ტიპის გრაფიკას
  // mediaPlayer.setMedia(QUrl::fromLocalFile("/home/alex/Dropbox/Music/Left 4 Dead -  Intro.mp3")); //აქ ვუთითებთ ფაილს
  //  mediaPlayer.play(); //დაკვრის დაწყება
   // setCentralWidget(ui->graphicsView);
   //setWindowState(Qt::WindowFullScreen); //მთლიან ეკრანზე გაშლა
  //  QAction *activeFull = new QAction(this);
  // activeFull->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
  //  mediaPlayer.setPosition(qint64(19135)); //გადახვევა
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "გახსნა");
    mediaPlayer.setMedia(QUrl::fromLocalFile(fileName));
    mediaPlayer.play();
}

void MainWindow::on_pushButton_2_clicked()
{
    mediaPlayer.pause();
}

void MainWindow::on_pushButton_3_clicked()
{
    mediaPlayer.play();
}

//void MainWindow::on_pushButton_4_clicked()
//
   // setWindowState(Qt::WindowFullScreen);
    //this->showMaximized();
  //  ui->pushButton->hide();
//    ui->pushButton_2->hide();
 //   ui->pushButton_3->hide();
 //   ui->pushButton_4->hide();
 //   ui->pushButton_2->hide();
 //   ui->pushButton_5->hide();
 //   ui->pushButton_6->hide();
 //   setCentralWidget(ui->graphicsView);
//}

void MainWindow::on_pushButton_5_clicked()
{
    mediaPlayer.setPosition(qint64(mediaPlayer.position()+5000));   //qint64 არის ლონგ ტიპის და გამოიყენება დროსთან
}

void MainWindow::on_pushButton_6_clicked()
{
    mediaPlayer.setPosition(qint64(mediaPlayer.position()-5000));
}






void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    mediaPlayer.setVolume(value);


}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    mediaPlayer.setPosition(mediaPlayer.position()+value*1000);
}
