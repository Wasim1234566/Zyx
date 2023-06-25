#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_btn_num1_clicked();

    void on_btn_num2_clicked();

    void on_btn_num3_clicked();

    void on_btn_num4_clicked();

    void on_btn_num5_clicked();

    void on_btn_num6_clicked();

    void on_btn_num7_clicked();

    void on_btn_num8_clicked();

    void on_btn_num9_clicked();

    void on_btn_num0_clicked();

    void on_btn_numsign1_clicked();

    void on_btn_numsign2_clicked();

    void on_btn_sign5_clicked();

    void on_btn_sign6_clicked();

    void on_btn_sign7_clicked();

    void on_btn_sign8_clicked();

    void on_btn_sign9_clicked();

    void on_btn_sign10_clicked();

    void on_btn_sign11_clicked();

    void on_btn_sign12_clicked();

    void on_btn_sign4_clicked();

    void on_btn_sign3_clicked();

    void on_btn_sign2_clicked();

    void on_btn_sign1_clicked();

private:
    Ui::MainWindow *ui;
    QString expression;
    QString result;
};
#endif // MAINWINDOW_H
