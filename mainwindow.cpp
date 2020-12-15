#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    delta = 0.1;
    ventana = new QGraphicsScene(this);
    ventana->setSceneRect(-280,-225,581,451);
    ventana->addRect(ventana->sceneRect());
    ui->graphicsView->setScene(ventana);
    ventana->setBackgroundBrush(QPixmap(":/imagenes/estrellas1.jpg"));

    timer = new QTimer();
    timer->stop();

    connect(timer, SIGNAL(timeout()),this,SLOT(simulacion()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_1_clicked()
{
    double x = ui->posx_2->text().toDouble();
    double y = ui->posy_2->text().toDouble();
    double r = ui->redio_2->text().toDouble();
    double m = ui->mas_2->text().toDouble();
    double vx = ui->velx_2->text().toDouble();
    double vy = ui->vely_2->text().toDouble();

    planet = new planeta(x,y,vx,vy,m,r);

    contenedor.push_back(planet);
}

void MainWindow::on_btn_2_clicked()
{
    for (int i=0;i<contenedor.size() ;i++ ) {
        contenedor.at(i)->actualizar(delta);
        ventana->addItem(contenedor.at(i));
    }
}

void MainWindow::simulacion()
{
    copiar.setFileName("valores.txt");
    copiar.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text);
    QTextStream stream(&copiar);
    for (int i=0;i<contenedor.size() ;i++ )
    {
        for (int j=0; j<contenedor.size(); j++ )
        {
            if(i!=j)
            {

                contenedor.at(i)->getParticula()->aceleraciones(contenedor.at(j)->getParticula()->getPosicion_x(),contenedor.at(j)->getParticula()->getPosicion_y(),contenedor.at(j)->getParticula()->getMasa());
                contenedor.at(i)->actualizar(delta);
            }
        }

    }



    for(int k = 0; k < contenedor.size(); k++)
    {
        stream<<contenedor.at(k)->getParticula()->getPosicion_x()<<"          "<< contenedor.at(k)->getParticula()->getPosicion_y()<<"          ";
    }
    stream<<endl;
    copiar.close();
}

void MainWindow::on_pushButton_clicked()
{
    timer->start(delta);
}
