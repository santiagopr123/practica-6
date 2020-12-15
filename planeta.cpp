#include "planeta.h"
planeta::planeta(double pos_x, double pos_y, double v_x, double v_y, double mas, double r):escala(0.035)
{
    particula = new calculos(pos_x,pos_y,v_x, v_y,mas,r);
}

void planeta::actualizar(double delta)
{
    particula->actualizar_variables(delta);
    setPos(particula->getPosicion_x()*escala,-particula->getPosicion_y()*escala);

}

void planeta::setescala(double esca)
{
    escala = esca;
}

calculos *planeta::getParticula() const
{
    return particula;
}

QRectF planeta::boundingRect() const
{
    return QRectF(-1*escala*particula->getRadio(),-1*escala*particula->getRadio(),2*escala*particula->getRadio(),2*escala*particula->getRadio());
}

void planeta::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkGreen);
    //painter->drawEllipse(boundingRect());
    if(particula->getMasa()>10000)
    {
        QPixmap pixmap(":/imagenes/dom.png");
        painter->drawPixmap(-1*escala*particula->getRadio(),-1*escala*particula->getRadio(),2*escala*particula->getRadio(),2*escala*particula->getRadio(),pixmap);
    }
    else if(particula->getMasa()<1000)
    {
        QPixmap pixmap(":/imagenes/planeta-tierra.png");
        painter->drawPixmap(-1*escala*particula->getRadio(),-1*escala*particula->getRadio(),2*escala*particula->getRadio(),2*escala*particula->getRadio(),pixmap);
    }
}
