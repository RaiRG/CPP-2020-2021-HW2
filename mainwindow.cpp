#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cstdlib>

void reactOnDelete();

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  connect(ui->deleteButton, &QPushButton::clicked, this, &reactOnDelete);
}

MainWindow::~MainWindow()
{
  delete ui;
}

class User
{
  int age;       // private
  QString name;  // private
  static int total_count;

public:
  explicit User(QString name, int age = 18)
  {
    if (age >= 18)
    {
      this->age = age;
    }
    else
    {
      this->age = 18;
    }
    this->name = name;
    total_count++;
  }
  QString getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
  static int getTotalCount()
  {
    return total_count;
  }
  static std::vector<User> users_;
  void addStudent(User newStudent)
  {
    users_.push_back(newStudent);
  }
  void delteStudentByNumber(int number)
  {
    users_.erase(users_.begin() + number);
  }
  void deleteStudentByName(QString name)
  {
    for (int i = 0; i < (int)users_.size(); i++)
    {
      if (users_[i].name == name)
        users_.erase(users_.begin() + i);
    }
  }
  int getNumberOfStudent()
  {
    return (int)users_.size();
  }
};

int User::total_count = 0;
std::vector<User> User::users_;

std::vector<std::string> Alphabet = { "A", "B", "C", "D", "E", "F", "G", "a", "b", "c", "d", "e" };

void MainWindow::on_addButton_clicked()
{
  int numberOfLet = rand() % 10;
  std::string resultName;
  for (int i = 0; i < numberOfLet; i++)
  {
    int randomLetter = rand() % 11;

    resultName += Alphabet[randomLetter];
  }
  int age = rand() % 100;

  User newUser{ QString::fromUtf8(resultName.c_str()), age };
  User::users_.push_back(newUser);
  qDebug() << "Add user!";
}

void reactOnDelete()
{
  if (User::users_.size() != 0)
  {
    int randomIndex = rand() % (User::users_.size() - 1);
    User::users_.erase(User::users_.begin() + randomIndex);
  }
  qDebug() << "Delete user!";
}

void reactOnDeleteAll()
{
  if (User::users_.size() != 0)
  {
    User::users_.clear();
  }
  qDebug() << "Delete all users!";
}
