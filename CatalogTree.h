//
// Created by bingo on 2021-04-11.
//

#ifndef CATALOGTREE__CATALOGTREE_H_
#define CATALOGTREE__CATALOGTREE_H_

#include <string>
#include <vector>
class CatalogTree {
 public:
  std::vector<std::string> GetPathRecursive(const std::string &root);
  void set_current_path(const std::string &path);
  std::string current_path();
  void CreateDirectory(const std::string &dir);
  void delete_directory(const std::string &dir);
  void create_file(const std::string &file);
  void delete_file(const std::string &file);
};

#endif //CATALOGTREE__CATALOGTREE_H_
