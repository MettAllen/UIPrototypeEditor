#include "svgreader.h"
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <QDomDocument>
#include <QStringList>

SvgReader::SvgReader()
{

}

QList<QGraphicsRectItem *> SvgReader::getElements(const QString filename)
{
    QList<QGraphicsRectItem *> rectList;

    QDomDocument doc;
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return rectList;


    QDomNodeList gList = doc.elementsByTagName("g");

    for (int i = 0; i < gList.size(); i++) {
        QDomNode gNode = gList.item(i);
        QDomElement rectangle = gNode.firstChildElement("rect");

        if (rectangle.isNull()){
            continue;
        } else {

            QGraphicsRectItem *rect = new QGraphicsRectItem();

            rect->setFlag(QGraphicsItem::ItemIsMovable);

            QDomElement gElement = gNode.toElement();
            rect->setRect(rectangle.attribute("x").toInt(),
                          rectangle.attribute("y").toInt(),
                          rectangle.attribute("width").toInt(),
                          rectangle.attribute("height").toInt());


            QColor fillColor(gElement.attribute("fill", "#ffffff"));    // цвет заливки
            fillColor.setAlphaF(gElement.attribute("fill-opacity","0").toFloat());
            rect->setBrush(QBrush(fillColor));


            QColor strokeColor(gElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

            rect->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toInt()));
            rectList.append(rect);
        }
    }
    file.close();
    return rectList;
}

QRectF SvgReader::getSizes(const QString filename)
{
    QDomDocument doc;
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return QRectF(0,0,200,200);

    QDomNodeList list = doc.elementsByTagName("svg");
    if(list.length() > 0) {
        QDomElement svgElement = list.item(0).toElement();
        QStringList parameters = svgElement.attribute("viewBox").split(" ");
        return QRectF(parameters.at(0).toInt(),
                      parameters.at(1).toInt(),
                      parameters.at(2).toInt(),
                      parameters.at(3).toInt());
    }
    return QRectF(0,0,200,200);
}
