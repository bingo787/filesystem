#include <iostream>
#include <string_view>
#include "CatalogTree.h"

const std::vector<std::string> split(const std::string &s, const char &c) {
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
  std::cout << "Hello, World!" << std::endl;

  //auto d = split("hhh dd",' ');


  CatalogTree catalog_tree;
  std::string cmd;
  std::string param;

  while (cmd != "quit") {
    std::cin >> cmd >> param;
    std::cout << cmd << " " << param << std::endl;

    if (cmd == "dir") {
      auto all_path = catalog_tree.GetPathRecursive(".");
      for (auto &p : all_path) {
        std::cout << p << std::endl;
      }

    } else if (cmd == "cd") {
      catalog_tree.SetCurrentPath(".");

    } else if (cmd == "cd" && param == "..") {
      catalog_tree.SetCurrentPath("..");
    } else if (0 == cmd.compare(0, 2, "cd")) {
      catalog_tree.SetCurrentPath(param);

    } else if (0 == cmd.compare(0, 5, "mkdir")) {
      catalog_tree.CreateDirectory(param);
    } else if (0 == cmd.compare(0, 5, "mkfile")) {
      catalog_tree.CreateFile(param);
    } else if (0 == cmd.compare(0, 6, "delete")) {
      catalog_tree.DeleteDirectory(param);
    } else if (0 == cmd.compare(0, 4, "save")) {

    } else if (0 == cmd.compare(0, 4, "load")) {

    }
  }

  return 0;
}