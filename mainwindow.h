#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_plus_clicked();

    void on_proceedButton_clicked();

    void on_minus_clicked();

    void on_divide_clicked();

    void on_mutiply_clicked();

private:
    Ui::MainWindow *ui;

    Calculator _calculator;

    enum Operation {
        UNDEFINED,
        ADD,
        SUB,
        MUL,
        DIV
    } _currOperation;

    void setEnabledArithmetics(bool isEnabled);
    void setFirstArgument();
    void setDefaultButtonColors();

};
#endif // MAINWINDOW_H
