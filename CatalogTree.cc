//
// Created by bingo on 2021-04-11.
//
#include <filesystem>
#include <iostream>
#include "CatalogTree.h"

std::vector<std::string> CatalogTree::GetPathRecursive(const std::string &root) {
  std::vector<std::string> all_path;
  for (auto &p: std::filesystem::recursive_directory_iterator(root)) {
    all_path.emplace_back(p.path());
  }
  return all_path;
}
void CatalogTree::set_current_path(const std::string &path) {

}
std::string CatalogTree::current_path() {
  return std::string();
}
void CatalogTree::CreateDirectory(const std::string &dir) {
  std::filesystem::create_directories(dir);
}
void CatalogTree::delete_directory(const std::string &dir) {

}
void CatalogTree::create_file(const std::string &file) {

}
void CatalogTree::delete_file(const std::string &file) {

}
