#include <Task.h>
Task::Task(QVariant label, QVariant priority): QListWidgetItem(label.toString())
{
    this->priority = priority;
}


