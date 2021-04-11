#include <iostream>
#include "CatalogTree.h"
int main() {
  std::cout << "Hello, World!" << std::endl;

  CatalogTree catalog_tree;
  auto r = catalog_tree.GetPathRecursive(".");

  for (auto &p : r) {
    std::cout << p << std::endl;
  }

  return 0;
}