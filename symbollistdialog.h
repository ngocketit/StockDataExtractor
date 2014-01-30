#ifndef SYMBOLLISTDIALOG_H
#define SYMBOLLISTDIALOG_H

#include <QDialog>

namespace Ui {
class SymbolListDialog;
}

class SymbolListDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SymbolListDialog(QWidget *parent = 0);
    ~SymbolListDialog();
    QString symbols();
    void setSymbols(const QString &symbols);
    void setLabel(const QString &title);
    
private:
    Ui::SymbolListDialog *ui;
};

#endif // SYMBOLLISTDIALOG_H
