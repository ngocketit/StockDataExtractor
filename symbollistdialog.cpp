#include "symbollistdialog.h"
#include "ui_symbollistdialog.h"

SymbolListDialog::SymbolListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SymbolListDialog)
{
    ui->setupUi(this);
}

void SymbolListDialog::setLabel(const QString &title)
{
    ui->lblTitle->setText(title);
}

void SymbolListDialog::setSymbols(const QString &symbols)
{
    ui->txtSymbols->setPlainText(symbols);
}

QString SymbolListDialog::symbols()
{
    return ui->txtSymbols->toPlainText();
}

SymbolListDialog::~SymbolListDialog()
{
    delete ui;
}
