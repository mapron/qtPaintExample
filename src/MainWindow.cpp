#include "MainWindow.h"

#include <QStyleOption>
#include <QStylePainter>

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
{
    this->setStyleSheet("QWidget { background: #222244; color: #cccc00; }");
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QStylePainter paint(this);
    paint.setPen(Qt::NoPen);

    paint.setRenderHint(QPainter::Antialiasing);

    QStyleOption opt;
    opt.initFrom(this);

    const auto grooveBrush = QColor("#555555");

    const auto backBrush = opt.palette.brush(this->backgroundRole());
    const auto foreBrush = opt.palette.brush(this->foregroundRole());

    const int thickness     = 6;
    const int minDimension  = std::min(opt.rect.width(), opt.rect.height()) - thickness;
    auto      barGrooveRect = QRect{ QPoint{ 0, 0 }, QSize{ minDimension, minDimension } };
    barGrooveRect.moveCenter(opt.rect.center());

    paint.setBrush(backBrush);
    paint.drawRect(opt.rect);

    paint.setBrush(Qt::NoBrush);
    paint.setPen(QPen(grooveBrush, thickness));
    paint.drawEllipse(barGrooveRect);

    paint.setPen(QPen(foreBrush, thickness));

    auto drawProgress = [&paint, barGrooveRect](int fromPromille, int toPromille) {
        const int qtSpecific = 16; // qt считает в 1/16 долях градуса!
        const int fromDegree = fromPromille * 360 * qtSpecific / 1000;
        const int toDegree   = toPromille * 360 * qtSpecific / 1000;

        paint.drawArc(barGrooveRect, 90 * qtSpecific - toDegree, toDegree - fromDegree);
    };

    drawProgress(0, 777);
}
