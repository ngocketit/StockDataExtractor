#include "dialog.h"
#include "ui_dialog.h"

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QXmlQuery>
#include <QDebug>
#include <QWebPage>
#include <QWebElement>
#include <QWebFrame>

#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QWebElementCollection>
#include <QList>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSignalMapper>
#include <QVector>
#include <QPlainTextEdit>
#include <QClipboard>
#include <QFileDialog>
#include <QImage>
#include <QPainter>

#include "graph.h"
#include "symbollistdialog.h"
#include "statschart.h"

#define STATS_TXT_NAME  "txtStats"
#define DETAIL_TXT_NAME "txtDetail"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->webView->hide();

    ui->progressBar->setMaximum(0);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
    ui->progressBar->hide();

    ui->lbProgress->hide();
    ui->updateDate->setDate(QDate::currentDate());

    setWindowFlags(Qt::WindowMinimizeButtonHint|Qt::WindowMaximizeButtonHint);

    clearResultTabs();

    connect(ui->btnExtract, SIGNAL(clicked()), this, SLOT(extractData()));
    connect(ui->webView, SIGNAL(loadFinished(bool)), this, SLOT(loadDone(bool)));

    connect(ui->btnHNXList, SIGNAL(clicked()), this, SLOT(configHNXList()));
    connect(ui->btnHOSEList, SIGNAL(clicked()), this, SLOT(configHOSEList()));

    connect(ui->btnExtractHNX, SIGNAL(clicked()), this, SLOT(extractHNX()));
    connect(ui->btnExtractHOSE, SIGNAL(clicked()), this, SLOT(extractHOSE()));

    connect(ui->btnCopyStats, SIGNAL(clicked()), this, SLOT(copyAllStats()));
    connect(ui->btnCopyDetails, SIGNAL(clicked()), this, SLOT(copyAllDetails()));
}

void Dialog::configHNXList()
{
    m_settings.load();
    SymbolListDialog dlg(this);
    dlg.setLabel("HNX Symbols");
    dlg.setWindowTitle("HNX Symbols");
    dlg.setSymbols(m_settings.hnxSymbols);
    if (dlg.exec() == QDialog::Accepted)
    {
        m_settings.hnxSymbols = dlg.symbols();
        m_settings.save();
    }
}

void Dialog::configHOSEList()
{
    m_settings.load();
    SymbolListDialog dlg(this);
    dlg.setLabel("HOSE Symbols");
    dlg.setWindowTitle("HOSE Symbols");
    dlg.setSymbols(m_settings.hoseSymbols);
    if (dlg.exec() == QDialog::Accepted)
    {
        m_settings.hoseSymbols = dlg.symbols();
        m_settings.save();
    }
}

void Dialog::extractHNX()
{
    m_settings.load();
    if (m_settings.hnxSymbols.isEmpty())
    {
        QMessageBox::information(this, "HNX", "HNX symbol list is empty. Please configure it first!");
        return;
    }
    ui->txtCodes->setText(m_settings.hnxSymbols);
    ui->lblOutput->setText("Output Data: HNX");
    extractData();
}

void Dialog::extractHOSE()
{
    m_settings.load();
    if (m_settings.hoseSymbols.isEmpty())
    {
        QMessageBox::information(this, "HOSE", "HOSE symbol list is empty. Please configure it first!");
        return;
    }
    ui->txtCodes->setText(m_settings.hoseSymbols);
    ui->lblOutput->setText("Output Data: HOSE");
    extractData();
}

void Dialog::extractData()
{
    QString str = ui->txtCodes->text().trimmed();

    if (str.isEmpty())
    {
        QMessageBox::information(this, QString("Empty symbols"), QString("Please enter stock symbols separated by commas"), QMessageBox::Ok);
        ui->txtCodes->setFocus();
        return;
    }
    QStringList symbols = str.split(",");
    m_symbols.clear();

    foreach (QString code, symbols)
    {
        code = code.trimmed();
        if (!code.isEmpty())
        {
            m_symbols.append(code);
        }
    }

    if (!m_symbols.isEmpty())
    {
        start();
    } else {
        QMessageBox::information(this, QString("Emtpy"), QString("No valid symbol! Please check your input."), QMessageBox::Ok);
        ui->txtCodes->setFocus();
    }
}

void Dialog::clearResultTabs()
{
    for (int i = 0; i < ui->resultTab->count(); ++i)
    {
        QWidget *page = ui->resultTab->widget(i);
        if (page)
        {
            delete page;
            page = 0;
        }
        ui->resultTab->clear();
    }
}

void Dialog::start()
{
    m_currentSymbolIndex = 0;
    ui->lbProgress->show();
    ui->lbProgress->setText("");
    ui->progressBar->show();

    clearResultTabs();
    processData();
}

void Dialog::done()
{
    ui->lbProgress->setText(QString("Done!"));
    ui->progressBar->hide();
    ui->webView->stop();
    ui->lblOutput->setText("Output Data");
}

QString Dialog::formatVerticalSymbolData(const QString &symbol, const QString &data)
{
    QStringList exportData;
    exportData << symbol;

    QStringList lines = data.split("\n");
    foreach (QString line, lines)
    {
        exportData << "\t" << line << "\n";
    }
    // New item separator
    exportData << "\n\n";

    return exportData.join("");
}

void Dialog::copyAllStats()
{
    bool verticalFormat = ui->chkVertical->isChecked() ? true : false;
    if (verticalFormat)
    {
        copyDataVertically(Stats);
    }
    else
    {
        copyDataHorizontally(Stats);
    }
}

void Dialog::copyAllDetails()
{
    bool verticalFormat = ui->chkVertical->isChecked() ? true : false;
    if (verticalFormat)
    {
        copyDataVertically(Details);
    }
    else
    {
        copyDataHorizontally(Details);
    }
}

void Dialog::copyDataVertically(DataType type)
{
    if (ui->resultTab->count() == 0)
    {
        QMessageBox::information(this, "Empty", "No result to copy");
        return;
    }

    QStringList exportData;

    for (int i = 0; i < ui->resultTab->count(); ++i)
    {
        QWidget *page = ui->resultTab->widget(i);
        if (page)
        {
            QTextEdit *txtData = page->findChild<QTextEdit*>(type == Stats ? STATS_TXT_NAME : DETAIL_TXT_NAME);
            if (txtData)
            {
                QString text = txtData->toPlainText();
                if (!text.isEmpty())
                {
                    QString symbol = ui->resultTab->tabText(i);
                    exportData << formatVerticalSymbolData(symbol, text);
                }
            }
        }
    }

    QClipboard *cb = QApplication::clipboard();
    cb->setText(exportData.join(""));
}

void Dialog::copyDataHorizontally(DataType type)
{
    if (ui->resultTab->count() == 0)
    {
        QMessageBox::information(this, "Empty", "No result to copy");
        return;
    }

    QStringList symbols;
    QList<QStringList> data;
    int rowMax = 0;

    for (int i = 0; i < ui->resultTab->count(); ++i)
    {
        QWidget *page = ui->resultTab->widget(i);
        if (page)
        {
            QTextEdit *txtData = page->findChild<QTextEdit*>(type == Stats ? STATS_TXT_NAME : DETAIL_TXT_NAME);
            if (txtData)
            {
                QString text = txtData->toPlainText();
                if (!text.isEmpty())
                {
                    symbols << ui->resultTab->tabText(i);
                    QStringList rows = text.split("\n");
                    data << rows;
                    rowMax = qMax(rowMax, rows.count());
                }
            }
        }
    }

    if (!symbols.isEmpty())
    {
        int fieldCount = data.at(0).at(0).split("\t").count();
        QStringList exportData;

        foreach (QString symbol, symbols)
        {
            exportData << symbol;
            for (int i = 0; i < fieldCount; ++i)
            {
                exportData << "\t";
            }
            // Add an empty columns between data of symbols
            exportData << "\t";
        }
        // New line for the row data
        exportData << "\n";

        for (int i = 0; i < rowMax; ++i)
        {
            foreach (QStringList strList, data)
            {
                if (i < strList.count())
                {
                    exportData << strList.at(i);
                    // Why?
                    exportData << "\t";
                }
                // Padding for empty lines
                else
                {
                    for (int i = 0; i < fieldCount; ++i)
                    {
                        exportData << "\t";
                    }
                }
                // Separator between lines of different items
                exportData << "\t";
            }
            exportData << "\n";
        }

        if (!exportData.isEmpty())
        {
            QClipboard *cb = QApplication::clipboard();
            cb->setText(exportData.join(""));
        }
    }
}

void Dialog::processData()
{
    QString symbol = m_symbols.at(m_currentSymbolIndex);

    QString path("http://s.cafef.vn/Lich-su-giao-dich-%code-6.chn?date=%date");
    path = path.replace("%code", symbol);
    path = path.replace("%date", ui->updateDate->date().toString("dd/MM/yyyy"));

    QString status = QString("Processing %1..").arg(symbol);
    ui->lbProgress->setText(status);

    QUrl url(path);
    ui->webView->load(url);
}

void Dialog::addResultTab(const QString &stats, const QString &detail)
{
    QWidget *page = new QWidget();

    // Details text edit
    QTextEdit *txtDetail = new QTextEdit;
    txtDetail->setPlainText(detail);
    txtDetail->setReadOnly(true);
    txtDetail->setObjectName(DETAIL_TXT_NAME);

    // Stats text edit
    QTextEdit *txtStats = new QTextEdit;
    txtStats->setPlainText(stats);
    txtStats->setReadOnly(true);
    txtStats->setObjectName(STATS_TXT_NAME);

    // Stats label
    QLabel *lblStats = new QLabel;
    lblStats->setText("<b>Statistics</b><br/>[Price - Volume - Percent]");

    // Detail label
    QLabel *lblDetail = new QLabel;
    lblDetail->setText("<b>Details</b><br/>[Time - Price - Volume - Total volume - Percent]");

    // Copy detail button
    QPushButton *btnCopyDetail = new QPushButton;
    btnCopyDetail->setText("Copy");

    // Save stats chart button
    QPushButton *btnSaveStatChart = new QPushButton;
    btnSaveStatChart->setText("Save chart");

    // Copy stats button
    QPushButton *btnCopyStats = new QPushButton;
    btnCopyStats->setText("Copy");

    // Graph button
    QPushButton *btnGraph = new QPushButton;
    btnGraph->setText("Graph");
    btnGraph->hide();

    // Copy stats button layout
    QHBoxLayout *btnCopyStatsLayout = new QHBoxLayout;
    btnCopyStatsLayout->addWidget(lblStats);
    btnCopyStatsLayout->addStretch(1);
    btnCopyStatsLayout->addWidget(btnSaveStatChart);
    btnCopyStatsLayout->addWidget(btnCopyStats);

    // Copy detail button layout
    QHBoxLayout *btnCopyDetailLayout = new QHBoxLayout;
    btnCopyDetailLayout->addWidget(lblDetail);
    btnCopyDetailLayout->addStretch(1);
    btnCopyDetailLayout->addWidget(btnGraph);
    btnCopyDetailLayout->addWidget(btnCopyDetail);

    // Detail layout
    QVBoxLayout *detailLayout = new QVBoxLayout;
    detailLayout->addLayout(btnCopyDetailLayout);
    detailLayout->addWidget(txtDetail);

    // Stats layout
    QVBoxLayout *statsLayout = new QVBoxLayout;
    statsLayout->addLayout(btnCopyStatsLayout);
    statsLayout->addWidget(txtStats, 30);

    // Stats chart
    StatsChart *chart = new StatsChart;
    statsLayout->addWidget(chart, 70);
    QList<ChartPiece> pieces;

    QStringList statRows = stats.split("\n");
    bool ok;
    Qt::GlobalColor colors[14] =
    {
        Qt::green, Qt::blue,
        Qt::red, Qt::yellow,
        Qt::cyan, Qt::magenta,
        Qt::darkBlue, Qt::darkGreen,
        Qt::darkRed, Qt::darkYellow,
        Qt::darkCyan, Qt::darkMagenta,
        Qt::gray, Qt::darkGray
    };

    float totalPercent = 0;
    for (int i = 0; i < statRows.count(); ++i)
    {
        QStringList parts = statRows.at(i).split("\t");
        ChartPiece piece;
        piece.label = parts.at(0);
        QString percent = parts.at(2);
        piece.percent = percent.replace("(%)", "").replace(",", ".").toFloat(&ok);
        totalPercent += piece.percent;

        if (i < 14)
        {
            piece.color = colors[i];
        }
        pieces << piece;
    }

    if (totalPercent < 50)
    {
        ChartPiece other;
        other.label = "Others";
        other.percent = 100 - totalPercent;
        other.color = Qt::gray;
        pieces << other;
    }
    chart->setPieces(pieces);

    // Main tab layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(statsLayout, 40);
    mainLayout->addLayout(detailLayout, 60);

    page->setLayout(mainLayout);

    // Stats button signal mapping
    QSignalMapper *mapperStats = new QSignalMapper(page);
    connect(btnCopyStats, SIGNAL(clicked()), mapperStats, SLOT(map()));
    mapperStats->setMapping(btnCopyStats, txtStats);
    connect(mapperStats, SIGNAL(mapped(QWidget*)), this, SLOT(copyResult(QWidget*)));

    // Stats button signal mapping
    QSignalMapper *mapperDetail = new QSignalMapper(page);
    connect(btnCopyDetail, SIGNAL(clicked()), mapperDetail, SLOT(map()));
    mapperDetail->setMapping(btnCopyDetail, txtDetail);
    connect(mapperDetail, SIGNAL(mapped(QWidget*)), this, SLOT(copyResult(QWidget*)));

    // Graph button signal mapping
    QSignalMapper *mapperGraph = new QSignalMapper(page);
    connect(btnGraph, SIGNAL(clicked()), mapperGraph, SLOT(map()));
    mapperGraph->setMapping(btnGraph, txtDetail);
    connect(mapperGraph, SIGNAL(mapped(QWidget*)), this, SLOT(drawGraph(QWidget*)));

    // Stats chart button signal mapping
    QSignalMapper *mapperStatChart = new QSignalMapper(page);
    connect(btnSaveStatChart, SIGNAL(clicked()), mapperStatChart, SLOT(map()));
    mapperStatChart->setMapping(btnSaveStatChart, chart);
    connect(mapperStatChart, SIGNAL(mapped(QWidget*)), this, SLOT(saveStatsChart(QWidget*)));

    ui->resultTab->addTab(page, m_symbols.at(m_currentSymbolIndex));
}

void Dialog::saveStatsChart(QWidget *widget)
{
    QString saveFile = QFileDialog::getSaveFileName(this, tr("Save as"), QString(), tr("Image files (*.png)"));
    if (!saveFile.isEmpty()) {
        if (!saveFile.endsWith(".png")) {
            saveFile = saveFile + ".png";
        }

        QImage img(widget->size(), QImage::Format_ARGB32_Premultiplied );
        QPainter painter(&img);
        widget->render(&painter);

        if (!img.save(saveFile, 0, 100)) {
            QMessageBox::warning(this, tr("Failed"), tr("Failed to export image file"), QMessageBox::Close);
        }
    }
}

void Dialog::copyResult(QWidget *widget)
{
    QTextEdit *txt = (QTextEdit*)widget;
    if (txt)
    {
        txt->selectAll();
        txt->copy();
    }
}

int Dialog::parseUpdateTime(const QString &time)
{
    QStringList parts = time.split(":");
    int retval = 0;
    bool ok;

    if (parts.count() == 3)
    {
        int hour = parts.at(0).toInt(&ok);
        int min = parts.at(1).toInt(&ok);
        int sec = parts.at(2).toInt(&ok);

        retval = hour * 60 * 60 + min * 60 + sec;
    }

    return retval;
}

int Dialog::parseFigure(QString str)
{
    bool ok;
    str.replace(",", "");
    return str.toInt(&ok);
}

void Dialog::drawGraph(QWidget *widget)
{
    QTextEdit *txt = (QTextEdit*)widget;
    if (!txt)
    {
        return;
    }
    QString str = txt->toPlainText();
    QStringList rows = str.split("\n");

    if (!rows.isEmpty())
    {
        GraphData data;
        uint now = QDateTime::fromString("28/11/2013", "dd/MM/yyyy").toTime_t();
        int i = 0;

        foreach(QString row, rows)
        {
            QStringList parts = row.split("\t");
            if (!parts.isEmpty())
            {
                int time = parseUpdateTime(parts[0]);
                int volume = parseFigure(parts[3]);
                int totalVolume = parseFigure(parts[4]);

                data.timeSlots.append(i++);
                data.timeLabels.append(parts[0]);
                data.volumes.append(volume);
                data.totalVolumes.append(totalVolume);
            }
        }

        Graph graph(this);
        graph.setData(data);
        graph.exec();
    }
}

void Dialog::loadDone(bool ok)
{
    if (m_currentSymbolIndex > m_symbols.count() - 1)
    {
        return;
    }

    if (ok)
    {
        QWebElement document = ui->webView->page()->mainFrame()->findFirstElement("body");
        if (!document.isNull())
        {
            QWebElement tbody = document.findFirst("table#tblData tbody");
            if (!tbody.isNull())
            {
                QWebElementCollection trs = tbody.findAll("tr");
                if (trs.count() > 0)
                {
                    QStringList detailData, statsData;
                    foreach (QWebElement tr, trs)
                    {
                        StockDetailRow rowData = parseDetailRow(tr);
                        QString str = rowData.toString();
                        if (!str.isEmpty())
                        {
                            detailData.append(str);
                        }
                    }

                    // Stats data
                    tbody = document.findFirst("table#tblStats tbody");
                    if (!tbody.isNull())
                    {
                        trs = tbody.findAll("tr");
                        if (trs.count() > 0)
                        {
                            for (int i = 0; i < trs.count(); ++i)
                            {
                                // Skip header row
                                if (i == 0) continue;
                                StockStatRow statData = parseStatRow(trs.at(i));
                                QString str = statData.toString();
                                if (!str.isEmpty())
                                {
                                    statsData.append(str);
                                }
                            }
                        }
                    }

                    if (!detailData.isEmpty())
                    {
                        addResultTab(statsData.join("\n"), detailData.join("\n"));
                    }
                }
            }
        }
    } else {
        qDebug() << "Failed: " << m_symbols.at(m_currentSymbolIndex);
    }

    m_currentSymbolIndex++;

    if (m_currentSymbolIndex <= m_symbols.count() - 1)
    {
        processData();
    } else {
        done();
    }
}

StockDetailRow Dialog::parseDetailRow(const QWebElement &tr)
{
    QWebElementCollection tds = tr.findAll("td");
    StockDetailRow data;

    if (tds.count() == 5)
    {
        data.updateTime = tds.at(0).toPlainText();
        data.price = tds.at(1).toPlainText();
        QWebElement span = tds.at(1).findFirst("span");

        if (!span.isNull())
        {
            data.priceChangeValue = span.toPlainText();
            data.price.replace(data.priceChangeValue, "");
        }

        data.volume1 = tds.at(2).toPlainText();
        data.volume2 = tds.at(3).toPlainText();
        data.weight = tds.at(4).toPlainText();
    }

    return data;
}

StockStatRow Dialog::parseStatRow(const QWebElement &tr)
{
    QWebElementCollection tds = tr.findAll("td");
    StockStatRow data;

    if (tds.count() == 3)
    {
        data.price = tds.at(0).toPlainText();
        data.volume = tds.at(1).toPlainText();
        data.weight = tds.at(2).toPlainText();
    }

    return data;
}

Dialog::~Dialog()
{
    delete ui;
}
