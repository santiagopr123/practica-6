#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QVector>
#include <calculos.h>
#include <planeta.h>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QPixmap>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_1_clicked();

    void simulacion();

    void on_btn_2_clicked();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *ventana;
    QTimer *timer;
    planeta *planet;

    QVector<planeta*>contenedor;

    double delta;

    QFile copiar;

};
#endif // MAINWINDOW_H
