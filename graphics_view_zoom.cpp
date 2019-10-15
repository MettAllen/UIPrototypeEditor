#include <QMouseEvent>
#include <QApplication>
#include <QScrollBar>
#include <qmath.h>
#include <graphics_view_zoom.h>

Graphics_view_zoom::Graphics_view_zoom(QGraphicsView* view)
    : QObject(view), view(view)
{
    view->viewport()->installEventFilter(this);
    view->setMouseTracking(true);
    modifiers = Qt::ControlModifier;
    zoom_factor_base = 1.0015;
}

void Graphics_view_zoom::gentle_zoom(double factor)
{
    view->scale(factor, factor);
    view->centerOn(target_scene_pos);

    QPointF delta_viewport_pos = target_viewport_pos - QPointF(view->viewport()->width() / 2.0, view->viewport()->height() / 2.0);
    QPointF viewport_center = view->mapFromScene(target_scene_pos) - delta_viewport_pos;

    view->centerOn(view->mapToScene(viewport_center.toPoint()));

    emit zoomed();
}

void Graphics_view_zoom::set_modifiers(Qt::KeyboardModifiers modifiers)
{
    modifiers = modifiers;

}

void Graphics_view_zoom::set_zoom_factor_base(double value)
{
    zoom_factor_base = value;
}

bool Graphics_view_zoom::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);
        QPointF delta = target_viewport_pos - mouse_event->pos();

        if (qAbs(delta.x()) > 5 || qAbs(delta.y()) > 5)
        {
            target_viewport_pos = mouse_event->pos();
            target_scene_pos = view->mapToScene(mouse_event->pos());
        }
    }
    else
        if (event->type() == QEvent::Wheel)
        {
            QWheelEvent* wheel_event = static_cast<QWheelEvent*>(event);

            if (QApplication::keyboardModifiers() == modifiers)
            {
                if (wheel_event->orientation() == Qt::Vertical)
                {
                    double angle = wheel_event->angleDelta().y();
                    double factor = qPow(zoom_factor_base, angle);
                    gentle_zoom(factor);
                    return true;
                }
            }
        }

    Q_UNUSED(object)
    return false;
}
