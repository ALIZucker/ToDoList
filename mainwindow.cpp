#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"QDebug"
#include "QSqlError"
#include "QTableWidgetItem"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inputwork=ui->lineEdit;
   edit2=ui->lineEdit_2;

    path="C:\\Users\\Feedback\\Desktop\\todoList\\uu.db";

      QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
      db.setDatabaseName(path);
      db.open();
    //  QSqlQuery query("CREATE TABLE work (group_id INTEGER PRIMARY KEY,workname TEXT NOT NULL );");
      QSqlQuery query;
      //     query.exec("INSERT INTO work (workname)VALUES('go to class');");

            query.prepare( "SELECT group_id,workname FROM work" );
            query.exec();
            if( !query.exec() )
            {
              // Error Handling, check query.lastError(), probably return
                qDebug()<<query.lastError()<<"one";
            }
             showitems();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent( QKeyEvent * e)
{
    if (e->key()==Qt::Key_Enter) {
        QSqlQuery query;
          query.exec("INSERT INTO work (workname)VALUES('"+inputwork->text()+"');");
    }else if (e->key()==Qt::Key_Shift) {
        QSqlQuery query;
          query.exec("DELETE FROM work WHERE group_id="+edit2->text()+";");
        //
    }
    showitems();
}

void MainWindow::showitems()
{

    qDebug()<<"asdasdasd";
    QSqlQuery query;
     query.prepare( "SELECT group_id,workname FROM work" );
     query.exec();
    auto table=ui->tablelists;
    table->setRowCount(50);
    table->setColumnCount(2);

    if( !query.exec() )
    {
      // Error Handling, check query.lastError(), probably return
        qDebug()<<query.lastError();
    }
     int count=0;
    // Note: if you don't return in case of an error, put this into the else{} part
    while( query.next())
    {
        qDebug() << query.value(0).toString();
           qDebug() << query.value(1).toString();
           QTableWidgetItem *item = ui->tablelists->item(count, 0);
                       if(!item) {
                           item = new QTableWidgetItem();
                           ui->tablelists->setItem(count, 0, item);
                       }
                       item->setText(query.value(0).toString());
                       /////////////////////////////////////////////////////////////////
          QTableWidgetItem *item1 = ui->tablelists->item(count, 1);
                                   if(!item1) {
                                       item1 = new QTableWidgetItem();
                                       ui->tablelists->setItem(count, 1, item1);
                                   }
                                   item1->setText(query.value(1 ).toString());



        // QTableWidgetItem *item2=new QTableWidgetItem(query.value(1).toString());
          // table->setItem(count,0,newItem);
        //  table->setItem(count,1,item2);
          count = count + 1;
    }


}

