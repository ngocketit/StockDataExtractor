#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>

namespace Ui {
class Graph;
}

#include <QVector>

typedef struct _tagGraphData
{
    QVector<double> timeSlots;
    QVector<QString> timeLabels;
    QVector<double> volumes;
    QVector<double> totalVolumes;

    bool isEmpty()
    {
        return timeSlots.isEmpty()
                && volumes.isEmpty()
                && totalVolumes.isEmpty();
    }
} GraphData;

class Graph : public QDialog
{
    Q_OBJECT
    
public:
    explicit Graph(QWidget *parent = 0);
    ~Graph();
    void setData(GraphData data);

private slots:
    void draw();
    
private:
    Ui::Graph *ui;
    GraphData m_data;
};

#endif // GRAPH_H
