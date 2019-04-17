#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;
bool userSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_zero, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digits_number()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiplu, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_division, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));

    ui->pushButton_multiplu->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_division->setCheckable(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_number(){
   QPushButton * button = (QPushButton*)sender();
   double all_numbers;
   QString new_label;
   if ((ui->pushButton_plus->isChecked() || ui->pushButton_plus->isChecked() ||
           ui->pushButton_plus->isChecked() || ui->pushButton_plus->isChecked()) && (!userSecondNumber)){
       all_numbers = button->text().toDouble();
       userSecondNumber = true;
   }
   else {
        all_numbers = (ui->lineEdit->text() + button->text()).toDouble();
   }

   new_label = QString::number(all_numbers, 'g', 15);
   ui->lineEdit->setText(new_label);

}


void MainWindow::operations(){
   QPushButton *button = (QPushButton*)(sender());
   double all_numbers;
   QString new_label;

   if (button->text() == "+/-"){
       all_numbers = (ui->lineEdit->text()).toDouble();
       all_numbers = all_numbers * -1;
       new_label = QString::number(all_numbers, 'g', 15);
       ui->lineEdit->setText(new_label);
   }

   else if (button->text() == "%"){
       all_numbers = (ui->lineEdit->text()).toDouble();
       all_numbers = all_numbers * 0.01;
       new_label = QString::number(all_numbers, 'g', 15);
       ui->lineEdit->setText(new_label);
   }
}
void MainWindow::math_operations(){
    QPushButton *button = (QPushButton *)sender();
    num_first = (ui->lineEdit->text()).toDouble();
    ui->lineEdit->setText("");
    button->setChecked(true);

}
void MainWindow::on_pushButton_equal_clicked()
{
    double lableNumber, numSecond;
    QString new_labe;
    numSecond = (ui->lineEdit->text()).toDouble();

    if(ui->pushButton_plus->isChecked()){
        lableNumber = num_first + numSecond;
        new_labe = QString::number(lableNumber, 'g', 15);
        ui->lineEdit->setText(new_labe);
        ui->pushButton_plus->setChecked(false);

    }else if(ui->pushButton_minus->isChecked()){
        lableNumber = num_first - numSecond;
        new_labe = QString::number(lableNumber, 'g', 15);
        ui->lineEdit->setText(new_labe);
        ui->pushButton_minus->setChecked(false);

    }else if(ui->pushButton_multiplu->isChecked()){
        lableNumber = num_first * numSecond;
        new_labe = QString::number(lableNumber, 'g', 15);
        ui->lineEdit->setText(new_labe);
        ui->pushButton_multiplu->setChecked(false);

    }else if(ui->pushButton_division->isChecked()){
            lableNumber = num_first/ numSecond;
            new_labe = QString::number(lableNumber, 'g', 15);
            ui->lineEdit->setText(new_labe);
            ui->pushButton_division->setChecked(false);
    }
    userSecondNumber = false;
}

void MainWindow::on_pushButton_dot_released()
{
    if(!(ui->lineEdit->text().contains("."))){
        ui->lineEdit->setText(ui->lineEdit->text()+".");
    }
}

void MainWindow::on_pushButton_ac_released()
{
    ui->pushButton_multiplu->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_division->setChecked(false);

    userSecondNumber = false;

    ui->lineEdit->setText("0");
}
