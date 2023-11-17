#pragma once
#include <string>
#include <map>
#include <vector>

#include "node.h"

class Compress
{
    public:
    static bool compare_pair(std::pair<char, int>, std::pair<char, int>);
    std::vector<std::pair<char, int>> sort_map(std::map<char, int>);
    std::vector<std::pair<char, int>> get_frequency(const std::string&);
    Node* create_tree(std::vector<std::pair<char, int>>);
    void compress(const std::string&);
    void test_tree(Node* head, int ind = 0);
};