#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QDebug>
#include <locale>
#include <QFileDialog>
#include <dirent.h>
#include <sys/types.h>
#include "tools.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   //m_in_dir =   QFileDialog::getExistingDirectory(this, "select input directory","/home", QFileDialog::ShowDirsOnly).toStdString();

   //m_out_dir =   QFileDialog::getExistingDirectory(this, "select input directory","/home", QFileDialog::ShowDirsOnly).toStdString();
    m_in_dir = "./";
    m_out_dir = "./";

    m_valid_files =  get_dir_list(m_in_dir);

    for (const auto &f: m_valid_files) {
            auto vec = split_string(f);

            auto old_name = toupper(f);
            auto file_type = toupper(vec.at(vec.size() - 1));
            auto file_name = vec.at(0);
            if (validate(file_name, file_type)) {

                auto prefix = file_name.substr(0, 2);
                auto index = file_name.substr(2, 2);
                auto seq = file_name.substr(4);

                auto new_name = prefix + seq + "-" + index + "." + file_type;
                int error = rename((m_in_dir + f).c_str(), (m_out_dir + new_name).c_str());
                if (error != 0) {
                    printf("errno: %s", strerror(errno));
                    // TODO err
                }
            }
        }
}


MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<std::string> MainWindow::get_dir_list(std::string path)
{
        auto dir = opendir(path.c_str());
        std::vector<std::string> vec;
        struct dirent *dp;


        while ((dp = readdir(dir)) != nullptr) {
                if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
                    continue;
                }
                auto name = std::string(dp->d_name);
                vec.emplace_back(name);
            }
        return vec;
}






