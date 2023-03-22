#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "RomeNumberAdapter.h"
#include "ArabNumberAdapter.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	ui(new Ui::MainWindow),
	_calculator()
{
	ui->setupUi(this);
	this->setDefaultButtonColors();
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::setEnabledArithmetics(bool isEnabled) {
	this->ui->plus->setEnabled(isEnabled);
	this->ui->minus->setEnabled(isEnabled);
	this->ui->mutiply->setEnabled(isEnabled);
	this->ui->divide->setEnabled(isEnabled);
}

void MainWindow::setFirstArgument() {
	if (
		this->ui->resultOutput->toPlainText().isEmpty() &&
		!this->ui->numberInput->text().isEmpty()
		)
	{
		this->ui->resultOutput->setText(this->ui->numberInput->text());
		this->setEnabledArithmetics(false);
		this->ui->proceedButton->setEnabled(true);
	}
}

void MainWindow::setDefaultButtonColors() {
	this->ui->plus->setStyleSheet("background: white");
	this->ui->minus->setStyleSheet("background: white");
	this->ui->divide->setStyleSheet("background: white");
	this->ui->mutiply->setStyleSheet("background: white");
	this->ui->proceedButton->setStyleSheet("background: white");
}

void MainWindow::on_proceedButton_clicked() {
	if (
		!this->ui->resultOutput->toPlainText().isEmpty() &&
		!this->ui->numberInput->text().isEmpty() &&
        this->_currOperation != UNDEFINED
		)
	{
        ArabNumberAdapter a(this->ui->resultOutput->toPlainText().toStdString());
        ArabNumberAdapter b(this->ui->numberInput->text().toStdString());
		std::string rome_result;
		switch (this->_currOperation) {

		case ADD: {
			rome_result = RomeNumberAdapter(this->_calculator.add(a, b));
			break;
		}
		case SUB: {
			rome_result = RomeNumberAdapter(this->_calculator.subtract(a, b));
			break;
		}
		case MUL: {
			rome_result = RomeNumberAdapter(this->_calculator.multiply(a, b));
			break;
		}
		case DIV: {
			rome_result = RomeNumberAdapter(this->_calculator.divide(a, b));
			break;
		}
        default:
            // should never get here
            break;

		}
		this->ui->resultOutput->setText(rome_result.c_str());
		this->setEnabledArithmetics(true);
	}
}

void MainWindow::on_plus_clicked() {
	setFirstArgument();
	this->_currOperation = ADD;
	setDefaultButtonColors();
	this->ui->plus->setStyleSheet("background-color: blue");
}

void MainWindow::on_minus_clicked() {
	setFirstArgument();
	this->_currOperation = SUB;
	setDefaultButtonColors();
	this->ui->minus->setStyleSheet("background-color: blue");
}

void MainWindow::on_divide_clicked() {
	setFirstArgument();
	this->_currOperation = DIV;
	setDefaultButtonColors();
	this->ui->divide->setStyleSheet("background-color: blue");
}

void MainWindow::on_mutiply_clicked() {
	setFirstArgument();
	this->_currOperation = MUL;
	setDefaultButtonColors();
	this->ui->mutiply->setStyleSheet("background-color: blue");
}
