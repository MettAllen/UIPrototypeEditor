#include <QObject>
#include <QGraphicsView>

class Graphics_view_zoom : public QObject {
    Q_OBJECT
public:
    Graphics_view_zoom(QGraphicsView* view);
    void gentle_zoom(double factor);
    void set_modifiers(Qt::KeyboardModifiers modifiers);
    void set_zoom_factor_base(double value);

private:
    QGraphicsView* view;
    Qt::KeyboardModifiers modifiers;
    double zoom_factor_base;
    QPointF target_scene_pos, target_viewport_pos;
    bool eventFilter(QObject* object, QEvent* event);

signals:
    void zoomed();
};
