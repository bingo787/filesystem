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
  bool SetCurrentPath(const std::string &path);
  std::string CurrentPath();
  bool CreateDirectory(const std::string &dir);
  bool DeleteDirectoryOrFile(const std::string &dir);
  bool CreateFile(const std::string &file);

};

#endif //CATALOGTREE__CATALOGTREE_H_
