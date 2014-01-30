#include "graph.h"
#include "ui_graph.h"

#include <QVector>
#include <QPen>
#include <QColor>
#include <QBrush>
#include <QFont>

Graph::Graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    draw();
}

void Graph::setData(GraphData data)
{
    if (!data.isEmpty())
    {
        m_data = data;
        draw();
    }
}

void Graph::draw()
{
    QCustomPlot *customPlot = ui->customPlot;
    customPlot->addGraph();

    QPen pen;
    pen.setColor(QColor(0, 0, 255, 200));
    customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    customPlot->graph()->setPen(pen);

    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));

    customPlot->xAxis->setLabel("Time");
    customPlot->yAxis->setLabel("Volume");

    customPlot->xAxis->setAutoTickStep(false);
    customPlot->xAxis->setAutoTicks(false);

    customPlot->xAxis->setTickVector(m_data.timeSlots);
    customPlot->xAxis->setTickVectorLabels(m_data.timeLabels);
    customPlot->xAxis->setTickLabels(true);

    customPlot->xAxis->setTicks(true);
    customPlot->xAxis->setTickStep(8);
    customPlot->xAxis->setRange(0, m_data.timeSlots.count());

    customPlot->yAxis->setAutoTicks(true);
    customPlot->yAxis->setAutoTickLabels(true);
    customPlot->yAxis->setTickStep(5000);

    customPlot->graph()->setData(m_data.timeSlots, m_data.volumes);

    customPlot->replot();
}

Graph::~Graph()
{
    delete ui;
}
