#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"benevole.h"

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

private slots:
    void on_pushButton_2_clicked();



    void on_bouton_supp_clicked();

    void on_pushButton_clicked();

    //void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_rechercher_button_clicked();

    void on_pdf_clicked();

    void on_statsmed_clicked();

    void on_pushButton_trier_ingr_clicked();

private:
    Ui::MainWindow *ui;
    Benevole c;

};

#endif // MAINWINDOW_H
