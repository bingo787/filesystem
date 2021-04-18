#include <iostream>
#include <cstring>
#include <fstream>
#include "CatalogTree.h"

static const std::string kHelpMessage = "========== 请按照以下信息输入命令测试！============"
                                        "dir  —— 列出当前目录下的所有子目录与文件项，所有文件项后加*表示“这是一个文件”，没有则不输出；\n"
                                        "cd  —— 列出当前目录的绝对路径。\n"
                                        "cd .. —— 当前目录变为当前目录的父目录 。\n"
                                        "cd str —— 当前目录变为 str 所表示路径的目录。\n"
                                        "mkdir str ——在(当前目录下)创建一个子目录(名为str)，若存在则不进行任何操作。\n"
                                        "mkfile str ——在(当前目录下)创建一个文件(名为str) ，若存在则不进行任何操作。\n"
                                        "delete str ——删除(当前目录下)名为 str 的目录或文件，若不存在则不进行任何操作。\n"
                                        "save str  —— 将从根节点开始的目录树结构保存到文件(名为str)中。\n"
                                        "load str  —— 从名为的文件str中读取之前保存的目录树结构，并根据其重新建立当前目录树，并进行后续操作\n"
                                        "quit —— 退出程序\n";

std::vector<std::string> split(const std::string &s, const char &c) {
  std::string buff;
  std::vector<std::string> v;

  for (auto n : s) {
    if (n != c) buff += n;
    else if (n == c && !buff.empty()) {
      v.push_back(buff);
      buff.clear();
    }
  }

  if (!buff.empty()) {
    v.push_back(buff);
  }
  return v;
}

int main() {
  std::cout << kHelpMessage;

  CatalogTree catalog_tree;

  std::string input;
  std::string cmd;
  char a[100];
  while (true) {
    memset(a, 0, 100);
    std::cin.getline(a, 100);
    input = a;
    std::string param = ".";
    auto cmd_and_param = split(input, ' ');
    cmd = cmd_and_param[0];
    if (cmd_and_param.size() > 1) {
      param = cmd_and_param[1];
    }

    std::cout << "cmd: " << cmd << " param:" << param << std::endl;
    if (cmd == "quit") {
      break;
    } else if (cmd == "dir") {
      auto all_path = catalog_tree.GetPathRecursive(".");
      for (auto &p : all_path) {
        std::cout << p << std::endl;
      }

    } else if (cmd == "cd") {
      catalog_tree.SetCurrentPath(param);
      std::cout << catalog_tree.CurrentPath() << std::endl;

    } else if (cmd == "mkdir") {
      catalog_tree.CreateDirectory(param);
    } else if (cmd == "mkfile") {
      catalog_tree.CreateFile(param);
    } else if (cmd == "delete") {
      catalog_tree.DeleteDirectoryOrFile(param);
    } else if (cmd == "save") {
      std::ofstream save_file(param);

      if (save_file.is_open()) {
        auto all_path = catalog_tree.GetPathRecursive(".");
        for (auto &p : all_path) {
          save_file << p << std::endl;
        }
        save_file.close();
      }

    } else if (cmd == "load") {
      std::ifstream load_file(param);
      char line[1000];
      std::string line_str;
      if (load_file.is_open()) {
        memset(line, 0, 1000);
        while (load_file.getline(line, 1000).good()) {
         // std::cout << line << std::endl;
          line_str = line;
          if (line_str.back() == '*') {
            catalog_tree.CreateFile(line_str.substr(0, line_str.size() - 1));
          } else {
            catalog_tree.CreateDirectory(line_str);
          }
        }
        load_file.close();

      }
    }
  }

  return 0;
}