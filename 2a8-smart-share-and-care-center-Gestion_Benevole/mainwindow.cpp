#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QDebug>
#include "benevole.h"
#include <iostream>
#include<QIntValidator>
#include<QComboBox>




#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QTextLength>
#include <QPainter>
#include <QDesktopServices>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include<QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include <QPdfWriter>
#include <QtPrintSupport/QPrinter>
#include<QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include <QPdfWriter>
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
















#include "connection.h"
#include <iostream>
#include <iostream>
#include <ostream>
#include <QMessageBox>
#include <QTextEdit>
#include <QIntValidator>
#include<QWidget>
#include <QTextDocument>
#include <QTextEdit>
#include <fstream>
#include <windows.h>
#include <QTextStream>
#include <QRadioButton>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <string>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QSvgGenerator>
#include<QDirModel>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QAbstractPrintDialog>
#include<QDirModel>
#include <QtPrintSupport/QPrintDialog>

#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QPdfWriter>
#include <QTextDocument>
#include <QSqlRecord>

#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QPdfWriter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_tab->setModel(c.afficher());


//    ui->le_id->setValidator(new QIntValidator(0,9999999,this)) ;
    //ui->le_tel->setValidator(new QIntValidator(0,99999999,this)) ;


    QRegExpValidator *validator = new QRegExpValidator(QRegExp("\\d{1,5}"), this);
    ui->le_id->setValidator(validator);
    ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_nom_2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_prenom->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_prenom_2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));



    ui->le_adresse->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->le_adresse_2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));

    ui->le_tel_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->le_tel->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));




    ui->comboBox->setModel(c.tester());
    ui->comboBox_2->setModel(c.tester());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{


    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString adresse=ui->le_adresse->currentText();
    QString tel=ui->le_tel->text();


    Benevole C(id,nom,prenom,tel,adresse);
    bool test=C.ajouter();

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
ui->le_tab->setModel(c.afficher());
ui->comboBox->setModel(c.tester());
 ui->comboBox_2->setModel(c.tester());
}


void MainWindow::on_bouton_supp_clicked()
{
    Benevole c;
    c.setid(ui->comboBox->currentText().toInt());
    bool test=c.supprimer(c.getid());
    QMessageBox msgBox;

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("supp effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_tab->setModel(c.afficher());
         ui->comboBox->setModel(c.tester());
          ui->comboBox_2->setModel(c.tester());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                    QObject::tr("supp non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_clicked()
{
    int id=ui->le_id_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString adresse=ui->le_adresse_2->currentText();
    QString tel=ui->le_tel_2->text();


    Benevole C(id,nom,prenom,tel,adresse);
    bool test =c.modifier(id,nom,prenom,tel,adresse);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("UPDATE effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                    QObject::tr("UPDATE non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
ui->le_tab->setModel(c.afficher());
ui->comboBox->setModel(c.tester());
 ui->comboBox_2->setModel(c.tester());
    ui->le_tab->setModel(c.afficher());

}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString name=ui->comboBox_2->currentText();
    QSqlQuery qry;
    qry.prepare("select *from BENEVOLE where id_benevole='"+name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
         ui->le_id_2->setText(qry.value(0).toString());
         ui->le_nom_2->setText(qry.value(1).toString());
          ui->le_prenom_2->setText(qry.value(2).toString());
         ui->le_tel_2->setText(qry.value(3).toString());
         ui->le_adresse_2->setCurrentText(qry.value(4).toString());

        }
    }





}

void MainWindow::on_pdf_clicked()
    {
        QPdfWriter pdf("C:/Users/pc/Desktop/FM.pdf");

                                 QPainter painter(&pdf);

                                 int i = 4000;




                                 painter.setFont(QFont("Arial", 15));
                                 painter.drawRect(0,3000,6300,2600);
                                 painter.setPen(Qt::black);
                                 painter.drawText(250,1500,"LISTE DES BENEVOLES");



                                 painter.drawRect(0,3000,9600,500);
                                 painter.setPen(Qt::black);
                                 painter.setFont(QFont("Arial", 10));
                                 painter.drawText(100,3000,"ID BENEVOLE");
                                 painter.drawText(1500,3000,"NOM");
                                 painter.drawText(3000,3000,"PRENOM");
                                 painter.drawText(4500,3000,"TEL");
                                 painter.drawText(6000,3000,"ADRESSE");

                                 QSqlQuery query;
                                 query.prepare("select * from BENEVOLE");
                                 query.exec();
                                 while (query.next())
                                 {
                                     painter.drawText(100,i,query.value(0).toString());
                                     painter.drawText(1500,i,query.value(1).toString());
                                     painter.drawText(3000,i,query.value(2).toString());
                                     painter.drawText(4500,i,query.value(3).toString());
                                     painter.drawText(6000,i,query.value(4).toString());
                                     painter.drawText(7500,i,query.value(5).toString());


                                     i = i +500;
                                 }

                                 int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                 if (reponse == QMessageBox::Yes)
                                 {
                                     QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/pc/Desktop/FM.pdf"));
                                     painter.end();
                                 }
                                 if (reponse == QMessageBox::No)
                                 {
                                     painter.end();
                                 }

    }


void MainWindow::on_rechercher_button_clicked()
{


        QString rech =ui->IDRECH->text();
            ui->le_tab->setModel(c.rechercher(rech));
    }


void MainWindow::on_pushButton_trier_ingr_clicked()
{
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));

        ui->le_tab->setModel(model);
        QSqlQuery query;


        if (ui->comboBox_3->currentText()=="NOM")
        query.prepare("SELECT *  FROM Benevole ORDER BY NOM ASC ") ;
    else
            if (ui->comboBox_3->currentText()=="PRENOM")
            query.prepare("SELECT *  FROM Benevole ORDER BY PRENOM ASC ") ;

        if (query.exec()&&query.next()) {
            model->setQuery(query);

            ui->le_tab->setModel(model);
    }
    }


void MainWindow::on_statsmed_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("select * from Benevole where adresse='Tunis' ");
     int number1=model->rowCount();
     model->setQuery("select * from Benevole where adresse='Nabeul' ");
     int number2=model->rowCount();
     model->setQuery("select * from Benevole where adresse='Sfax' ");
     int number3=model->rowCount();
     model->setQuery("select * from Benevole where adresse='Ariana' ");
     int number4=model->rowCount();
     model->setQuery("select * from Benevole where adresse='Autre' ");
     int number5=model->rowCount();


     int total=number1+number2+number3+number4+number5;

     QString a = QString("Tunis"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Nabeul"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("Sfax"+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("Ariana"+QString::number((number4*100)/total,'f',2)+"%" );
     QString e = QString("Autre"+QString::number((number5*100)/total,'f',2)+"%" );





     QPieSeries *series = new QPieSeries();


     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     series->append(e,number5);


     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice = series->slices().at(1);
              //slice1->setExploded();
              slice->setLabelVisible();
     }

     if (number3!= 0)
     {
         QPieSlice *slice = series->slices().at(2);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number4!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice = series->slices().at(3);
              //slice1->setExploded();
              slice->setLabelVisible();
     }
     if (number1!= 5)
     {
         QPieSlice *slice = series->slices().at(4);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }


             // Create the chart widget
             QChart *chart = new QChart();

             // Add data to chart with title and hide legend
             chart->addSeries(series);


             chart->setTitle("Pourcentage par adresse:"+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();





}





