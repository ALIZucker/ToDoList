#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QSqlDatabase"
#include "QSqlQuery"
#include <QMainWindow>
#include "QLineEdit"
#include "QKeyEvent"
#include "QTableWidget"
#include "QTableWidgetItem"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineEdit *inputwork;
    QLineEdit   *edit2;
    void keyPressEvent(QKeyEvent * event);
    void showitems();


private:
    Ui::MainWindow *ui;
    QString path;



};
#endif // MAINWINDOW_H
