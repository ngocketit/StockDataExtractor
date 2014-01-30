#ifndef STATSCHART_H
#define STATSCHART_H

#include <QLabel>
#include <QList>

class QColor;

typedef struct _tagChartPiece
{
    QString label;
    Qt::GlobalColor color;
    float percent;

} ChartPiece;

class StatsChart : public QLabel
{
    Q_OBJECT
public:
    explicit StatsChart(QWidget *parent = 0);
    void setPieces(QList<ChartPiece> data);

protected:
    void paintEvent(QPaintEvent *);

private:
    QList<ChartPiece> m_pieces;
    
};

#endif // STATSCHART_H
