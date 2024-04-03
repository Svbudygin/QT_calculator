#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include<iostream>
double sum = 0;
bool num_after_operation = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->pushButton_sign, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math()));

    ui->pushButton_div->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::on_pushButton_9_clicked()
// {
//     ui->label1->setText("9");
//     //QMessageBox::critical(this, "name", "text");
//     //QMessageBox::information(this, "name", "text");
//     //QMessageBox::about(this, "name", "text");
//     QMessageBox::StandardButton reply = QMessageBox::question(this, "name","text", QMessageBox::Yes | QMessageBox::No);
//     if (reply == QMessageBox::Yes){
//         QApplication::quit();
//     }
// }

void MainWindow::digit_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if (!num_after_operation)
    {
        std::cout << ui->pushButton_plus->isChecked() << ui->pushButton_mult->isChecked() << ui->pushButton_minus->isChecked() << ui->pushButton_div->isChecked();
        if (ui->pushButton_plus->isChecked() || ui->pushButton_mult->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_div->isChecked())
        {
            all_numbers = (button->text()).toDouble();
            num_after_operation = true;
        }
        else
            all_numbers = (ui->label1->text() + button->text()).toDouble();
    }
    else
        all_numbers = (ui->label1->text() + button->text()).toDouble();

    new_label = QString::number(all_numbers, 'g', 15);
    ui->label1->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->label1->text().contains('.')))
        ui->label1->setText(ui->label1->text() + ".");
}


void MainWindow::math()
{
    QPushButton *button = (QPushButton *)sender();
    button->setChecked(true);
    double input_number;
    input_number = (ui->label1->text()).toDouble();

    // QString new_number;
    // new_number = QString::number(0,'g', 15);
    // ui->label1->setText(new_number);

    bool check_click = false;
    if (ui->pushButton_plus->isChecked() && !(button->text() == "+"))
    {
        sum += input_number;
        ui->pushButton_plus->setChecked(false);

        check_click = true;
    }
    else if (ui->pushButton_minus->isChecked() && !(button->text() == "-"))
    {
        sum -= input_number;
        ui->pushButton_minus->setChecked(false);

        check_click = true;
    }
    else if (ui->pushButton_div->isChecked() && !(button->text() == "÷"))
    {
        sum /= input_number;
        ui->pushButton_div->setChecked(false);

        check_click = true;
    }
    else if (ui->pushButton_mult->isChecked() && !(button->text() == "x"))
    {
        sum *= input_number;
        ui->pushButton_mult->setChecked(false);

        check_click = true;
    }
    if (!check_click)
    {
        sum = input_number;
    }
    else
    {
        QString new_number;
        new_number = QString::number(sum, 'g', 15);
        ui->label1->setText(new_number);
    }
    num_after_operation = false;
}

void MainWindow::on_pushButton_equal_clicked()
{
    double input_number;
    num_after_operation = false;
    input_number = (ui->label1->text()).toDouble();
    if (ui->pushButton_plus->isChecked())
    {
        sum += input_number;
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {
        sum -= input_number;
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_div->isChecked())
    {
        sum /= input_number;
        ui->pushButton_div->setChecked(false);
    }
    else if (ui->pushButton_mult->isChecked())
    {
        sum *= input_number;
        ui->pushButton_mult->setChecked(false);
    }
    QString new_number;
    new_number = QString::number(sum, 'g', 15);
    ui->label1->setText(new_number);
}
void MainWindow::on_pushButton_AC_clicked()
{
    sum = 0;
    QString new_number;
    num_after_operation = false;
    new_number = QString::number(sum, 'g', 15);
    ui->label1->setText(new_number);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_div->setChecked(false);
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if (button->text() == "+/-")
    {
        all_numbers = (ui->label1->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label1->setText(new_label);
    }
    if (button->text() == "%")
    {
        all_numbers = (ui->label1->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->label1->setText(new_label);
    }
}