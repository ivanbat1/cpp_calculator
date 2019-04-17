#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_number();
    void operations();
    void math_operations();
    void on_pushButton_equal_clicked();
    void on_pushButton_dot_released();
    void on_pushButton_ac_released();
};

#endif // MAINWINDOW_H
