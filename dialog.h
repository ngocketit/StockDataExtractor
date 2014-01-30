#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class QWebElement;
class QStringList;

#include <QDebug>
#include <QSettings>

#define APP_NAME    "Stock Data Extractor"
#define COMPANY     "ngocketit@gmail.com"

typedef struct _tagStockStatRow
{
    QString price;
    QString volume;
    QString weight;

    QString toString()
    {
        QStringList str;

        str.append(price);
        str.append(volume);
        str.append(weight);

        return str.join("\t");
    }

} StockStatRow;

typedef struct _tagStockDetailRow
{
    QString updateTime;
    QString price;
    QString priceChangeValue;
    QString priceChangePercent;
    QString volume1;
    QString volume2;
    QString weight;

    void print()
    {
        qDebug() << toString();
    }

    QString toString()
    {
        QStringList str;
        if (!updateTime.isEmpty())
        {
            str.append(updateTime);
        }

        if (!price.isEmpty())
        {
            str.append(price);
        }

        if (!priceChangeValue.isEmpty())
        {
            str.append(priceChangeValue);
        }

        if (!volume1.isEmpty())
        {
            str.append(volume1);
        }

        if (!volume2.isEmpty())
        {
            str.append(volume2);
        }

        if (!weight.isEmpty())
        {
            str.append(weight);
        }

        if (str.isEmpty())
        {
            return "";
        }

        return str.join("\t");
    }
} StockDetailRow;

typedef struct _tagAppSettings
{
    QString hnxSymbols;
    QString hoseSymbols;

    void save()
    {
        QSettings settings(COMPANY, APP_NAME);
        settings.setValue("hnxSymbols", hnxSymbols);
        settings.setValue("hoseSymbols", hoseSymbols);
        settings.sync();
    }

    void load()
    {
        QSettings settings(COMPANY, APP_NAME);
        hnxSymbols = settings.value("hnxSymbols", "").toString();
        hoseSymbols = settings.value("hoseSymbols", "").toString();
    }
} AppSettings;

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    enum DataType
    {
        Stats,
        Details
    };

private slots:
    void extractData();
    void processData();

    void loadDone(bool ok);
    void start();
    void done();

    StockDetailRow parseDetailRow(const QWebElement &tr);
    StockStatRow parseStatRow(const QWebElement &tr);

    void saveStatsChart(QWidget *widget);

    void addResultTab(const QString &stats, const QString &detail);
    void clearResultTabs();

    void copyResult(QWidget *widget);
    void drawGraph(QWidget *widget);

    int parseUpdateTime(const QString &time);
    int parseFigure(QString str);

    void configHNXList();
    void configHOSEList();

    void extractHNX();
    void extractHOSE();

    void copyAllStats();
    void copyAllDetails();

    void copyDataVertically(DataType type);
    void copyDataHorizontally(DataType type);

    QString formatVerticalSymbolData(const QString &symbol, const QString &data);

private:
    Ui::Dialog *ui;
    QStringList m_symbols;
    int m_currentSymbolIndex;
    AppSettings m_settings;
};

#endif // DIALOG_H
