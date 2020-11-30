#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mTask()
{
    ui->setupUi(this);
    //connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::on_addTaskButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addTaskButton_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"),
                                         &ok);
    if (ok && !name.isEmpty()){
        qDebug() << "Adding new task";
        Task* task = new Task(name);
        mTask.append(task);
        ui->taskLayout->addWidget(task);
    }
}
