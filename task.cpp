#include "task.h"
#include "ui_task.h"
#include <QInputDialog>

Task::Task(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked, this, &Task::rename);
}

Task::~Task()
{
    delete ui;
}

QString Task::name() const{
    return ui->checkBox->text();
}

void Task::setName(const QString& name){
    ui->checkBox->setText(name);
}

bool Task::isComplete() const{
    return ui->checkBox->isChecked();
}

void Task::rename(){
    bool ok;
    QString value = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"),
                                         &ok);
    if (ok && !value.isEmpty()){
        setName(value);
    }
}



