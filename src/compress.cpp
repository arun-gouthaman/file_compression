#include <iostream>
#include <algorithm>

#include "compress.h"

bool Compress::compare_pair(std::pair<char, int> a, std::pair<char, int> b)
{
    return a.second < b.second;
}

std::vector<std::pair<char, int>> Compress::sort_map(std::map<char, int> ip_map)
{
    std::vector<std::pair<char, int>> sort_vec;
    for (std::pair<char, int> p : ip_map)
    {
        sort_vec.push_back(p);
    }

    std::sort(sort_vec.begin(), sort_vec.end(), Compress::compare_pair);

    return sort_vec;
}

std::vector<std::pair<char, int>> Compress::get_frequency(const std::string& ip_str)
{
    std::map<char, int> freq_map;
    std::string::const_iterator str_it = ip_str.begin();
    while(str_it != ip_str.end())
    {
        freq_map[*str_it] += 1;
        str_it++;
    }

    std::vector<std::pair<char, int>> sorted_vec = sort_map(freq_map);

    for(std::pair<char, int> p : sorted_vec)
    {
        std::cout << p.first << " : " << p.second << "\n";
    }

    return sorted_vec;
}

Node* Compress::create_tree(std::vector<std::pair<char, int>> sorted_vec)
{
    int vec_size = sorted_vec.size();

    Node* ref_node = nullptr;

    for(int i=0; i<vec_size;)
    {
        Node* node1 = new Node();
        node1->ch = sorted_vec[i].first;
        node1->sum = sorted_vec[i].second;

        Node* sum_node = new Node();
        sum_node->l_node = node1;
        sum_node->sum = node1->sum;

        if(i <= vec_size-2)
        {
            Node* node2 = new Node();
            node2->ch = sorted_vec[i+1].first;
            node2->sum = sorted_vec[i+1].second;
            sum_node->sum += node2->sum;
            sum_node->r_node = node2;
        }
        else
        {
            if (ref_node)
            {
                sum_node->r_node = ref_node;
                sum_node->sum += ref_node->sum;
            }
            ref_node = sum_node;
            ++i;
            continue;
        }

        if (!ref_node)
        {
            ref_node = sum_node;
        }
        else
        {
            Node* top_sum = new Node();
            top_sum->sum = sum_node->sum + ref_node->sum;
            top_sum->l_node = sum_node;
            top_sum->r_node = ref_node;
            ref_node = top_sum;
        }
        i += 2;
    }

    return ref_node;
}

void Compress::compress(const std::string& ip_str)
{
    std::vector<std::pair<char, int>> freq_vec = get_frequency(ip_str);
    Node* head = create_tree(freq_vec);
    Node_Navigate test_node;
    test_node.traverse_from_node(head);
}