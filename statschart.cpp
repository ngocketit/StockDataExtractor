#include "statschart.h"

#include <QPainter>
#include <QPaintEvent>
#include <QFont>
#include <QColor>
#include "lib/nightcharts/nightcharts.h"

StatsChart::StatsChart(QWidget *parent) :
    QLabel(parent)
{
    setMinimumSize(100, 100);
}

void StatsChart::setPieces(QList<ChartPiece> data)
{
    m_pieces = data;
}

void StatsChart::paintEvent(QPaintEvent *e)
{
    QLabel::paintEvent(e);
    QPainter painter;
    QFont serifFont("Times", 10, QFont::Bold);

    painter.begin(this);
    //painter.fillRect(this->rect(), Qt::white);

    Nightcharts chart;
    chart.setFont(serifFont);
    chart.setType(Nightcharts::Pie);//{Histogramm,Pie,DPie};
    chart.setLegendType(Nightcharts::Vertical);//{Round,Vertical}
    chart.setCords(5, 20, this->width()/2 + 50, this->height()/1.5);

    foreach (ChartPiece piece, m_pieces)
    {
        chart.addPiece(piece.label, piece.color, piece.percent);
    }

    chart.draw(&painter);
    chart.drawLegend(&painter);
}
