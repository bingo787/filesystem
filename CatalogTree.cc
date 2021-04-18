//
// Created by bingo on 2021-04-11.
//
#include <filesystem>
#include <iostream>
#include <fstream>
#include "CatalogTree.h"

std::vector<std::string> CatalogTree::GetPathRecursive(const std::string &root) {
  std::vector<std::string> all_path;

  for (auto &p: std::filesystem::recursive_directory_iterator(root)) {
    std::string path = p.path();
    if (!p.is_directory()) {
      path += "*";
    }
    all_path.emplace_back(path);
  }

  return all_path;
}
bool CatalogTree::SetCurrentPath(const std::string &path) {
  std::error_code error_code;
  std::filesystem::current_path(path, error_code);
  return error_code.value();
}
std::string CatalogTree::CurrentPath() {
  return std::filesystem::current_path().string();
}
bool CatalogTree::CreateDirectory(const std::string &dir) {
  //std::cout << "create " << dir << std::endl;
  return std::filesystem::create_directories(dir);
}
bool CatalogTree::DeleteDirectoryOrFile(const std::string &dir) {

  return std::filesystem::remove_all(dir);
}
bool CatalogTree::CreateFile(const std::string &file) {
  auto f = std::ofstream(file.c_str());
  return f.good();
}
