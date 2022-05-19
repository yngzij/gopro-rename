#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <locale>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<std::string> get_dir_list(std::string path);


private:
    std::string m_in_dir;
    std::string m_out_dir;
    std::vector<std::string> m_valid_files;
    std::locale m_loc;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
